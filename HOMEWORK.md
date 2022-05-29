Download and execute the correct binary from below
- [Linux or WSL](https://github.com/Christopher-Tan/CyberFinalProject/raw/main/code/challenge-Linux)
- [macOS](https://github.com/Christopher-Tan/CyberFinalProject/raw/main/code/challenge-macOS)

1. Find the flag (hint: write a program that would brute force different buffer lengths).
2. Submit the code that you used to solve the problem, if it is bash command include it in a .sh or .txt file.

If neither of the binaries above work (for macOS we only had access to an M1 device, and for Linux we've only tested Ubuntu and WSL; different OS versions could also fail to compile) download the challenge.c source file from our [code repo](https://github.com/Christopher-Tan/CyberFinalProject/tree/main/code) and compile it with "gcc -fno-stack-protector -o challenge challenge.c" and then run ./challenge. NOTE: The flag is stored in plain text, so please refrain from opening the file unless you are absolutely stuck.
