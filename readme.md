# Push_Swap

This is the first algorithm project I completed at 42. 

### Instructions

You have at your disposal a set of int values, 2 stacks and a set of instructions to manipulate both stacks. The goal of the project is two write 2 programs in C:
- The first, named checker which takes integer arguments and reads instructions on the standard output. Once read, checker executes them and displays OK if integers are sorted. Otherwise, it will display KO.
- The second one called push_swap which calculates and displays on the standard output the smallest progam using Push_swap instruction language that sorts integer arguments received.

#### Game rules
The game is composed of 2 stacks named a and b.
- To start with:
	- a contains a random number of either positive or negative numbers without any duplicates.
	- b is empty
- The goal is to sort in ascending order numbers into stack a.
- To do this you have the following operations at your disposal:

	sa : swap a - swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements).

	sb : swap b - swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements).

	ss : sa and sb at the same time.

	pa : push a - take the first element at the top of b and put it at the top of a. Do nothing if b is empty.

	pb : push b - take the first element at the top of a and put it at the top of b. Do nothing if a is empty.

	ra : rotate a - shift up all elements of stack a by 1. The first element becomes the last one.

	rb : rotate b - shift up all elements of stack b by 1. The first element becomes the last one.

	rr : ra and rb at the same time.

	rra : reverse rotate a - shift down all elements of stack a by 1. The last element becomes the first one.

	rrb : reverse rotate b - shift down all elements of stack b by 1. The last element becomes the first one.

	rrr : rra and rrb at the same time

#### The "checker" program
- You have to write a program named checker, which will get as an argument the stack a formatted as a list of integers. The first argument should be at the top of the stack (be careful about the order). If no argument is given checker stops and displays nothing.
- Checker will then wait and read instructions on the standard input, each instruction will be followed by ’\n’. Once all the instructions have been read, checker will execute them on the stack received as an argument.
- If after executing those instructions, stack a is actually sorted and b is empty, then checker must display "OK" followed by a ’\n’ on the standard output. In every other case, checker must display "KO" followed by a ’\n’ on the standard output.
- In case of error, you must display Error followed by a ’\n’ on the standard error. Errors include for example: some arguments are not integers, some arguments are bigger than an integer, there are duplicates, an instruction don’t exist and/or is incorrectly formatted.


#### The "push_swap" program
- You have to write a program named push_swap which will receive as an argument the stack a formatted as a list of integers. The first argument should be at the top of the stack (be careful about the order).
- The program must display the smallest list of instructions possible to sort the stack a, the smallest number being at the top.
- Instructions must be separaed by a ’\n’ and nothing else.
- The goal is to sort the stack with the minimum possible number of operations. During evaluation we’ll compare the number of instructions your program found with a maximum number of operation tolerated. If your program either displays a list too big or if the list isn’t sorted properly, you’ll get no points.
- In case of error, you must display Error followed by a ’\n’ on the standard error. Errors include for example: some arguments aren’t integers, some arguments are bigger than an integer, and/or there are duplicates.

### What I learned
- Algorithm optimization.
- A lot of refactoring to make code DRY.