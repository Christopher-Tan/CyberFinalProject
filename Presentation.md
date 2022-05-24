# Buffer Overflow
### By:Christopher Chin and Matthew Weng

## What is a Buffer Overflow Attack?

Buffer overflow is a type of attack where hackers exploit the storage capacity of a memory buffer. A buffer is a region of memory where data is temporarily stored. An example of this a video will have a buffer of the next minute of videos so the computer doesn't need to load it all at once. 

## Why should you care about Buffer Overflow?

A buffer overflow attack can be very harmful since it can exploit buffers by overwriting the memory, run exploits, and more. An example of Buffer Overfflow attack is the SQL Slammer which was a bug in 2003 in the Microsoft SQL and doubled the size of the buffer every 9 seconds which caused internet outrages across the world. Another example is the Morris Worm which attacked and comprimised over 60000 machines.

## How code is vulnerable is to it and how do you counter it?

As mentioned before, a buffer is a type of memory storage which is only meant to hold small amounts of data, a hacker can easily overflow it by giving more data than it can handle. Some ways to defend against these kinds of attacks is to be careful when using low-level languages such as C that rely on allocated memory, program non-executable buffers, and array bound checking which can detect altered data to make sure nothing has been corrupted. 

## C Memory Structure 

1. Text segment  (i.e. instructions)
	*
2. Initialized data segment 
	*
3. Uninitialized data segment  (bss)
	*
4. Heap 
	*
5. Stack
	*
	*
 
 
https://www.geeksforgeeks.org/memory-layout-of-c-program/

## Example 

```
struct commands {
	char input[10]; // Max Input
	char command[3]; // Length of Command
};

int main() {
	struct commands a = {.input={0},.command="ls "};
	printf("File: ");
	gets(a.input);
	system(strcat(a.command,a.input));
}

```
If you run this code in terminal, you get `File: `. And if you put in ` .. ` you can get the last saved in the pervious directory. However, if you put in `o [6 spaces] sud`, the code will loop and run sudo which is obviously not the intent of the code.
