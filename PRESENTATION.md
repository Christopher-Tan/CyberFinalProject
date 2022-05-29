# Buffer Overflow
### By:Christopher Tan and Matthew Weng

## What is a Buffer Overflow Attack? 

Buffer overflow exploits are a type of attack where hackers exploit the size capacity of a memory buffer. A buffer is a region of memory where data is stored. For example, a stored integer has a 4-byte buffer.

## Why should you care about Buffer Overflow? 

A buffer overflow attack can be extremely dangerous since it can overwrite memory, run exploits, and more. One example of a Buffer Overflow attack is the SQL Slammer which was a bug in 2003 in Microsoft SQL and doubled the size of the buffer every 9 seconds which caused internet outages across the world. Another example is the Morris Worm which attacked and compromised over 60000 machines.

## How to recognize vulnerable code and how do you counter it? 

As mentioned before, a buffer is a type of memory storage which is only meant to hold small amounts of data, a hacker can easily overflow it by giving more data than it can handle. Some ways to defend against these kinds of attacks is to be careful when using low-level languages such as C that rely on allocated memory, program non-executable buffers, and array bound checking which can detect altered data to make sure nothing has been corrupted. Most modern operating systems have in-built checks, and many vulnerable functions have clear warnings.

https://www.securecoding.com/blog/how-to-protect-against-buffer-overflow-attack/ 

## Buffer Overflow in Modern Day

https://www.sciencedirect.com/science/article/pii/S1877050919316527

In C, there are two functions that are especially vulnerable to overflow attacks: gets() and strcpy().

## C Memory Structure 

![C memory structure](https://media.geeksforgeeks.org/wp-content/uploads/memoryLayoutC.jpg)

There are five essential components to the memory layout of a c program.
1. Text Segment / Code Segment / Text - The executable instructions
2. Initialized Data Segment - Initialized global and static variables
3. Uninitialized Data Segment - Uninitialized global and static variables
4. Stack - A LIFO function call structure made of stack frames
5. Heap - Dynamic shared memory that is unordered.

Initialized meaning they were assigned a value.
```
static int a = 10; //initialized
static int b; //uninitialized
```

The essential idea is that stacks (usually) grow towards address 0, and heaps grow in the opposite direction. The variables in a stack frame also usually grow towards 0.

## Proof of Concept 
```
struct commands {
	char input[10];
	char command[3];
};

int main() {
	struct commands a = {.input={0},.command="ls "};
	printf("File: ");
	gets(a.input);
	system(strcat(a.command,a.input)); //executes ls $(input)
}
```
The code normally runs ls, however, overflowing the input buffer allows us to alter the command variable. If the program was running with root priviledges, the attacker would have full access to the machine.

## Some Examples 

https://owasp.org/www-community/attacks/Buffer_overflow_attack
