# canary

**Concept**: Stack Canary Bypass (Info Leak)
**Source**: `challenge.c`

## Vulnerability Analysis
- **Vulnerability**: Stack Buffer Overflow enabled by an Information Leak.
- **Cause**: The program reads 0x100 bytes into small 0x10 buffers using `read`.
- **Protections**: **Stack Canary**. A random value is placed on the stack before the Return Address. If this value is changed, the program crashes with `*** stack smashing detected ***` before it returns.

## Goal
Call the `get_flag()` function.

## Exploit Strategy
You cannot simply overwrite the canary with random 'A's. You must know its value.

1.  **Leak the Canary**:
    - The first `printf("Username is %s", username)` prints the string stored in `username`.
    - String functions print until they hit a generic NULL byte (`\x00`).
    - If you fill the `username` buffer *exactly* up to the canary (destroying the null terminator that usually sits there), `printf` will continue printing into the canary value on the stack.
2.  **Capture**: Read the program output to recover the canary value.
3.  **Bypass**:
    - For the second input (`user_id`), construct a payload that overflows the buffer but **writes the correct canary value back** into its slot.
    - `[Padding] + [Leaked Canary] + [Saved RBP Padding] + [Address of get_flag()]`
