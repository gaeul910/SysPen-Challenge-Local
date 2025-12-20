# buf_overflow

**Concept**: Basic Stack Buffer Overflow (Ret2Win)
**Source**: `challenge.c`

## Vulnerability Analysis
- **Vulnerability**: Stack Buffer Overflow.
- **Cause**: The code uses `scanf("%s", id)` and `scanf("%s", user)`. `scanf` with the `%s` format specifier does not check the length of the input, acting similarly to `gets`.
- **Buffer Size**: The buffers `id` and `user` are only 16 bytes (`0x10`) long.
- **Protections**: Likely disabled (No Canary, No PIE).

## Goal
Overwrite the return address on the stack to jump to the `flag()` function.

## Exploit Strategy
1.  **Analyze**: Use GDB to find the offset between the start of the `user` buffer and the return address on the stack.
2.  **Target**: Find the address of the `flag()` function using `nm`, `objdump -d`, or GDB (`info functions`).
3.  **Payload**: Construct a byte-string payload:
    ```
    [Padding bytes to fill buffer & saved EBP] + [Address of flag() in Little Endian]
    ```
4.  **Send**: Pipe this payload into the program.
