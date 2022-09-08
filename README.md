# 0x19. C - Stacks, Queues - LIFO, FIFO

## Description

In this project, we created a simple interpreter for Monty ByteCodes. The interpreter reads a bytecode file and executes the bytecode commands.

**Entry Functions**

| File   | Function | Description     |
| ------ | -------- | --------------- |
| main.c | main     | control program |

**Essential Functions**

| File       | Function                  | Description                                                                              |
| ---------- | ------------------------- | ---------------------------------------------------------------------------------------- |
| op_call.c  | call the correct function | searches an array of structs and calls the appropriate function using a function pointer |
| tokenize.c | tokenize                  | parse the line from getline() into tokens                                                |

## Examples

### Usage

./monty [BYTE_CODE_FILE]

#### A bytecode file (file1) containing the following:

- push 1
- push 2
- push 3
- pall

##### Will produce the following:

_./monty file1_

- 3
- 2
- 1
