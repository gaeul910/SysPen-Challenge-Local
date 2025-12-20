# Hook Overwrite Challenge

**Concept**: Function Pointer Overwrite / Global Data Corruption

## Description
This challenge demonstrates a simple global buffer overflow that allows you to overwrite a function pointer (a "hook").
The program has a `win` function that is never called directly. Your goal is to overwrite the `target.hook` function pointer to point to `win`.

The program provides:
1. The address of the `win` function.
2. A vulnerability where it reads more data than the buffer can hold.

## Objective
Redirect execution to `win()` by overwriting `target.hook`.

## Files
- `hook_overwrite.c`: The valid C source code.
- `Makefile`: Build script.

## How to Build and Run
1. Compile the challenge:
   ```bash
   make
   ```
2. Run the challenge:
   ```bash
   ./hook_overwrite
   ```

## Hint
- The buffer is 64 bytes long.
- The `target` struct contains the buffer immediately followed by the function pointer.
- You need to fill the buffer and then write the address of `win` into the function pointer slot.
- Remember x86_64 is little-endian.
