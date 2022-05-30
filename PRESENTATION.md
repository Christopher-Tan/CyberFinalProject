# Buffer Overflow
### By:Christopher Tan and Matthew Weng

## What is a Buffer Overflow Attack? 

Buffer overflow exploits are a type of attack where hackers exploit the size capacity of a memory buffer. A buffer is a region of memory where data is stored. For example, a stored integer has a 4-byte buffer.

## Why should you care about Buffer Overflow? 

A buffer overflow attack can be extremely dangerous since it can overwrite memory, run exploits, and more. One example of a Buffer Overflow attack is the SQL Slammer which was a bug in 2003 in Microsoft SQL and doubled the size of the buffer every 9 seconds which caused internet outages across the world. Another example is the Morris Worm which attacked and compromised over 60000 machines.

![example](https://www.securecoding.com/wp-content/uploads/2020/12/1-540x152.jpg)

## How to recognize vulnerable code? 

As mentioned before, a buffer is a type of memory storage which is only meant to hold small amounts of data, a hacker can easily overflow it by giving more data than it can handle.  

The two most important aspects of code to lookout for to see if it is vulnerable is the language it is written in and if there is user input. When using low-level languages such as C that rely on allocated memory, buffers can easily be altered. User inputs can easily be malicious if there is not adequate security.

```
void Presentation(){
	char answer[4];
	printf("Is this presentaiton good");
	gets(answer);
}
```

In this code, it would only accept `yes` and `no`. If you input something such as `somewhat`, it would be out of bound and would just show an error. However, you you put a 4-byte answer along with a address in memory, the program could be modified. Using this, hackers can get to other places in the code not meant to be accessible.


## How to regognize buffer overflow and defend against buffer overflow?

A way to check if your program has been tampered with is using array bound checking which can detect altered data to make sure nothing has been corrupted. Most modern operating systems have in-built checks, and many vulnerable functions have clear warnings. In addition, see if you compiler uses canaries which places random values in each buffer. If the value is altered, the program will shut don making sure no other alterations have been made.

In the previous section, we talked about how string inputs are susceptible to buffer overflow attacks which is why some functions such as gets and printf should be avoided and safer versions such as `fgets` or `sprintf_s`. The reason why these functions mentioned are safer is due to the fact that it checks if the bounds are in the target range unlike functions such as `printf`. A similar way of this is adding `strn-` versions of the function which only write to the max size of the buffer. 

Here is a small table of secure functions:

![table](https://www.synopsys.com/blogs/software-security/wp-content/uploads/2017/02/buffer-overflow-table.jpg)

There are protections provided by OSes which is ASLR(Address space layout randomization) and DEP(Data Execution Prevention). ALSR randomized the layout of memory location of structures. The way this protects from buffer overflow attacks is that it makes it harder to guess the stack address making it harder to harm the program. DEP marks memory with attributes to make sure code executions can't happen there similar to checks mentioned earlier.

![ASLR](https://assets.website-files.com/5ff66329429d880392f6cba2/62750ba095367e5445140d1e_Buffer%20Overflow%20Attack-p-1080.jpeg)

https://www.securecoding.com/blog/how-to-protect-against-buffer-overflow-attack/ 
https://www.synopsys.com/blogs/software-security/detect-prevent-and-mitigate-buffer-overflow-attacks/ 


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

## Common types of buffer overflow

The two most common types of buffer overflow attacks are stack-based and heap-based. 

As mentioned earlier, a stack is LIFO data structure. A stack frame has a limited amount of memory so when a function call occurs more than the capacity a fatal error occurs called stack overflow. When this happens, it goes into the next stack frame and can alter its values and outputs. 

## Buffer Overflow in Modern Day

Not sure
https://www.sciencedirect.com/science/article/pii/S1877050919316527

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


