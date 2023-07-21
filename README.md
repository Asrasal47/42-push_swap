# 42-push_swap

## Overview
Push_swap is a data sorting project that uses a stack-based data structure and a set of limited operations to sort data efficiently.

This project manipulates various types of algorithms and requires selecting the most suitable one for optimized data sorting.

## Getting Started
Clone the repository into your local machine. To clone the repository, open your terminal and enter the following command:

```sh
git clone https://github.com/Asrasal47/push_swap.git
```

## Prerequisites
Ensure that you have the following installed on your local machine:

C Compiler (GCC recommended)

Makefile Utility

Compilation

In the root directory of the project, use the Makefile to compile the project. 

To compile, open your terminal and type:

```sh
make
```
This will create an executable named push_swap.

## Usage
To execute the push_swap program, run the following command in the terminal:

```sh
./push_swap [List of Integers]
```
The output will be a set of operations that sort the given list of integers.

## Rules
The project has 2 stacks: 'a' and 'b'.

The goal is to sort in ascending order the numbers into stack 'a'.

### Operations
The available operations include:

sa (swap a): Swap the first 2 elements at the top of stack a.

sb (swap b): Swap the first 2 elements at the top of stack b.

ss: sa and sb at the same time.

pa (push a): Take the first element at the top of b and put it at the top of a.

pb (push b): Take the first element at the top of a and put it at the top of b.

ra (rotate a): Shift up all elements of stack a by 1.

rb (rotate b): Shift up all elements of stack b by 1.

rr: ra and rb at the same time.

rra (reverse rotate a): Shift down all elements of stack a by 1.

rrb (reverse rotate b): Shift down all elements of stack b by 1.

rrr: rra and rrb at the same time.

### Testing

To test the program, you can use the provided checker program.

This program will validate whether the instructions output by the push_swap program are correctly sorting the list.

```sh
./push_swap [List of Integers] | ./checker_Mac [Same List of Integers]
```

## Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.
