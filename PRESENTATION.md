# Buffer Overflow
### By: Christopher Tan and Matthew Weng

## What is a Buffer Overflow Attack? 

Buffer overflow exploits are a type of attack where hackers exploit the size capacity of a memory buffer. A buffer is a region of memory where data is stored. For example, a stored integer has a 4-byte buffer.

## Why should you care about Buffer Overflow? 

A buffer overflow attack can be extremely dangerous since it can overwrite memory, run exploits, and more. One example of a Buffer Overflow attack is the SQL Slammer which was a bug in 2003 in Microsoft SQL and doubled the size of the buffer every 9 seconds which caused internet outages across the world. Another example is the Morris Worm which attacked and compromised over 60000 machines.

![example](https://www.securecoding.com/wp-content/uploads/2020/12/1-540x152.jpg)

## How to recognize vulnerable code? 

As mentioned before, a buffer is a type of memory storage which is only meant to hold small amounts of data, a hacker can easily overflow it by giving more data than it can handle.  

The two most important aspects of code to lookout for to see if it is vulnerable is the language it is written in and if there is user input. When using low-level languages such as C that rely on allocated memory, buffers can easily be altered. User inputs can easily be malicious if there is not adequate security.

```
void main(){
	char answer[4];
	printf("Is this presentation good?");
	gets(answer);
}
```

This code should only accept `yes` or `no`. If you input something such as `somewhat`, the input would run out of bounds and it would show an error. However, if you input a 4-byte answer along with a address in memory and some binary code to run, the program could be modified. Using this, hackers can get to places in the code that are not meant to be accessible.


## How to recognize and defend against buffer overflow attacks?

A way to check if your program has been tampered with is using array bound checking which can detect altered data to make sure nothing has been corrupted. Most modern operating systems have in-built checks, and many vulnerable functions have clear warnings. In addition, see if your compiler uses canaries which places random values in each buffer. If the value is altered, the program will terminate making sure no other alterations have been made.

In the previous section, we talked about how string inputs are susceptible to buffer overflow attacks which is why some functions such as gets and printf should be avoided and safer versions such as `fgets` or `sprintf_s`. The reason why these functions mentioned are safer is due to the fact that it checks if the bounds are in the target range unlike functions such as `printf`. A similar way of this is by using the `strn-` versions of string functions which only write to the max size of the buffer instead of the `str-` versions 

Here is a small table of secure functions:

![table](https://www.synopsys.com/blogs/software-security/wp-content/uploads/2017/02/buffer-overflow-table.jpg)

There are protections provided by OSes such as ASLR(Address space layout randomization) and DEP(Data Execution Prevention). ALSR randomizes the layout of memory location of structures. The way this protects from buffer overflow attacks is that it makes it harder to guess the stack address making it harder to rewrite the program. DEP marks memory with attributes to make sure code executions can't happen there similar to checks mentioned earlier.

![ASLR](https://assets.website-files.com/5ff66329429d880392f6cba2/62750ba095367e5445140d1e_Buffer%20Overflow%20Attack-p-1080.jpeg)

In C, there are two functions that are especially vulnerable to overflow attacks: gets() and strcpy().

## C Memory Structure 

![C memory structure](https://media.geeksforgeeks.org/wp-content/uploads/memoryLayoutC.jpg)

There are five essential components to the memory layout of a C program.
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

## Common types of buffer overflow

The two most common types of buffer overflow attacks are stack-based and heap-based. 

As mentioned earlier, a stack is LIFO data structure made up of stack frames. There are only a limited number of frames that can be placed onto the stack because the memory allocated to the program is limited, as such, when too many are placed on a stack this results in a different type of error: a stack overflow. When this happens, the program usually crashes, terminates, or behaves extremely weirdly. Back to buffer overflows, for a stack-based attack, the malicious input usually overwrites part or an entire stack frame, the other group will talk more about the specifics of this exploit. Heaps are much less organized and quite different. As such, the ways of attacking them are different as well.

In C, to edit heap memory, you must use functions like malloc, calloc, and free. If the input is not stored on the stack but on the heap, then there are different ways of mapping out heap memory and choosing the correct input to overwrite the parts you need. Generally, heap attacks are not as useful because unlike stacks which interact closely with executable code, heaps don't.

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

Sources:

- https://www.securecoding.com/blog/how-to-protect-against-buffer-overflow-attack/ 
- https://www.synopsys.com/blogs/software-security/detect-prevent-and-mitigate-buffer-overflow-attacks/ 
- https://www.geeksforgeeks.org/buffer-overflow-attack-with-example/ 
- https://www.thegeekstuff.com/2013/06/buffer-overflow/ 
- https://www.excelsior.edu/article/understanding-the-dangers-of-buffer-overflow-attacks/ 
- https://stackoverflow.com/questions/648309/what-does-it-mean-by-buffer 
- https://www.imperva.com/learn/application-security/buffer-overflow/ 
- https://web.ecs.syr.edu/~wedu/seed/Book/book_sample_buffer.pdf 
- https://www.logsign.com/blog/buffer-overflow-attack-prevention/ 
