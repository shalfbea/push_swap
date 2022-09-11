# Push_swap

Because Swap_push isn’t as natural

## About

This project is part of program in School 21 (Ecole 42).
The goal is to learn how to sort data on a stack, with a
limited set of instructions, using the lowest possible
number of actions.

## Requirements
- GNU GCC
- GNU Make

## Installation and usage

1. Download/Clone this repo
	> git clone https://github.com/shalfbea/push_swap
2. Get into the root directory of project and run make command
	> cd push_swap ;
	> make
3. (Optional) Run make bonus to get checker program for
this project

	> make bonus
3. To run program run ./push_swap <arguments>. For example:
	> ARG="5 7 9 2 4"
	> ./push_swap $ARG

Example:

<img width="549" alt="pushswap_example" src="https://user-images.githubusercontent.com/92727363/189531777-c75d80e7-674e-4708-b92d-ed0a2dc710c3.png">
Bonus example:

<img width="345" alt="pushswap_example_2" src="https://user-images.githubusercontent.com/92727363/189531729-da0777ec-ce5d-40ad-863a-7686527efaa5.png">

## Technical task
The full task can be found here: [Push_swap_subject](https://github.com/shalfbea/push_swap/blob/main/push_swap_subject.pdf)
### Code rules:
- Only using c language is allowed
- Code-style should respect the [The Norm](https://github.com/MagicHatJo/-42-Norm/blob/master/norme.en.pdf)
- No memory leaks, segmentation faults, undefined behavior
- Only allowed functions: read, write, malloc, free,
exit, [ft_printf](https://github.com/shalfbea/ft_printf) (own realisation of classic printf)
- Can also use [libft](https://github.com/shalfbea/libft) (own implementation of part of the library functions)
### Rules of realisation
- You have 2 stacks named a and b.
- At the beginning:
	1.The stack a contains a random amount of negative and/or positive numbers which cannot be duplicated.
	2. The stack b is empty.
	3. The goal is to sort in ascending order numbers into stack a.
- To do so you have the following operations at your disposal:
1. sa (swap a):
Swap the first 2 elements at the top of stack a.
Do nothing if there is only one or no elements.
2. sb (swap b): Swap the first 2 elements at the top of stack b.
Do nothing if there is only one or no elements.
3. ss : sa and sb at the same time.
pa (push a): Take the first element at the top of b and put it at the top of a.
Do nothing if b is empty.
4. pb (push b): Take the first element at the top of a and put it at the top of b.
Do nothing if a is empty.
5. ra (rotate a): Shift up all elements of stack a by 1.
The first element becomes the last one.
6. rb (rotate b): Shift up all elements of stack b by 1.
The first element becomes the last one.
7. rr : ra and rb at the same time.
8. rra (reverse rotate a): Shift down all elements of stack a by 1.
The last element becomes the first one.
9. rrb (reverse rotate b): Shift down all elements of stack b by 1.
The last element becomes the first one.
10. rrr : rra and rrb at the same time.
### Bonus:
- Write a program named checker that takes as an argument the stack a formatted as a list of integers.
- It will then wait and read instructions on the standard input, each instruction will be followed by ’\n’. Once all the instructions have been read, the program has to execute them on the stack received as an argument.
-  If after executing those instructions, the stack a is actually sorted and the stack b is empty, then the program must display "OK" followed by a ’\n’ on the standard
- In every other case, it must display "KO" followed by a ’\n’ on the standard output.
## Result
<img width="1570" alt="shalfbea_pushswap_result" src="https://user-images.githubusercontent.com/92727363/189531694-28e73172-24be-4aa0-b610-60ed80583bc3.png">
