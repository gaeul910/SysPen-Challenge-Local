# nx (No-Execute)

**Concept**: Buffer Overflow with NX Protection
**Source**: `challenge.c`

## Vulnerability Analysis
- **Vulnerability**: Stack Buffer Overflow.
- **Cause**: `read(0, username, 100)` is called on a buffer `username` that is only 32 bytes (`0x20`) large.
- **Protections**: **NX (No-Execute)** bits are enabled. This means the stack is marked as non-executable memory. You cannot jump to shellcode placed on the stack.

## Goal
Call the `flag()` function.

## Exploit Strategy (Ret2Win / ROP)
Although NX prevents executing *new* code on the stack, it does **not** prevent jumping to *existing* code in the binary (Read-Only/Executable segment).

1.  **Offset**: Find the padding offset to the Return Address.
2.  **Address**: Find the address of the `flag()` function.
3.  **Payload**:
    ```
    [Padding] + [Address of flag()]
    ```
    Since `flag()` does not take arguments, we can simply jump to it (Ret2Win). If arguments were required, we would need a ROP gadget (`pop rdi; ret`).
