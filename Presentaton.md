# Buffer Overflow
### By:Christopher Chin and Matthew Weng

## What is a Buffer Overflow Attack?

Buffer overflow is a type of attack where hackers exploit the storage capacity of a memory buffer. A buffer is a region of memory where data is temporarily stored. An example of this a video will have a buffer of the next minute of videos so the computer doesn't need to load it all at once. 

## Why should you care about Buffer Overflow?

A buffer overflow attack is an attack 

## How code is vulnerable is to it and how do you counter it?

As mentioned before, a buffer is a type of memory storage which is only meant to hold small amounts of data, a hacker can easily overflow it by giving more data than it can handle. Some ways to defend against these kinds of attacks is to be careful when using low-level languages such as C that rely on allocated memory, program non-executable buffers, and array bound checking which can detect altered data to make sure nothing has been corrupted. 

## C Memory Structure 

https://www.geeksforgeeks.org/memory-layout-of-c-program/

## Proof of Concept 


