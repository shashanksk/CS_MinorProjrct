# CS_MinorProjrct

The following 2 problems are part of the 2022 Minors in computer science 


## Question 1 Chapter 2 2.24

In Section 2.3, we described a program that copies the contents of one file to a destination file. This program works by first prompting the user for the name of the source and destination files. Write this program using either the POSIX or Windows API. Be sure to include all necessary error checking, including ensuring that the source file exists.

Once you have correctly designed and tested the program, if you used a system that supports it, run the program using a utility that traces system calls. Linux systems provide the strace utility, and macOS systems use the dtruss command. (The dtruss command, which actually is a front end to dtrace, requires admin privileges, so it must be run using sudo.) These tools can be used as follows (assume that the name of the executable file is FileCopy:

Linux: strace ./FileCopy

macOS: sudo dtruss ./FileCopy

Since Windows systems do not provide such a tool, you will have to trace through the Windows version of this program using a debugger.

## Question 3 Chapter 3 3.21

The Collatz conjecture concerns what happens when we take any posi- tive integer n and apply the following algorithm:

![alt text](https://github.com/shashanksk/CS_MinorProjrct/blob/main/2.24/images/Screenshot%202022-11-09%20at%2010.56.49%20AM.png)

The conjecture states that when this algorithm is continually applied, all positive integers will eventually reach 1. For example, if n = 35, the sequence is
35, 106, 53, 160, 80, 40, 20, 10, 5, 16, 8, 4, 2, 1
Write a C program using the fork() system call that generates this sequence in the child process. The starting number will be provided from the command line. For example, if 8 is passed as a parameter on the command line, the child process will output 8, 4, 2, 1. Because the parent and child processes have their own copies of the data, it will be necessary for the child to output the sequence. Have the parent invoke the wait() call to wait for the child process to complete before exiting the program. Perform necessary error checking to ensure that a positive integer is passed on the command line.

