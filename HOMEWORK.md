Download and execute the correct binary from below
- [Linux or WSL](https://github.com/Christopher-Tan/CyberFinalProject/raw/main/code/challenge-Linux)
- [macOS](https://github.com/Christopher-Tan/CyberFinalProject/raw/main/code/challenge-macOS)

1. Find the flag (hint: write a program that would brute force different buffer lengths).
2. Submit the code that you used to solve the problem, if it is bash command include it in a .sh or .txt file.

If either of the binaries above do not work (for macOS we only had access to an M1 device, and for Linux we've only tested Ubuntu and WSL, our OS versions could also potentially be different) download the c [source file](https://github.com/Christopher-Tan/CyberFinalProject/raw/main/code/challenge.c) and compile it with "gcc -fno-stack-protector -o challenge challenge.c" and then run ./challenge. NOTE: The flag is stored in plain text, so please refrain from opening the file unless you are absolutely stuck.
