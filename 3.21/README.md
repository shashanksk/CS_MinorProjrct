# Question

The Collatz conjecture concerns what happens when we take any posi- tive integer n and apply the following algorithm:

![alt text](https://github.com/shashanksk/CS_MinorProjrct/blob/main/2.24/images/Screenshot%202022-11-09%20at%2010.56.49%20AM.png)

The conjecture states that when this algorithm is continually applied, all positive integers will eventually reach 1. For example, if n = 35, the sequence is 35, 106, 53, 160, 80, 40, 20, 10, 5, 16, 8, 4, 2, 1 Write a C program using the fork() system call that generates this sequence in the child process. The starting number will be provided from the command line. For example, if 8 is passed as a parameter on the command line, the child process will output 8, 4, 2, 1. Because the parent and child processes have their own copies of the data, it will be necessary for the child to output the sequence. Have the parent invoke the wait() call to wait for the child process to complete before exiting the program. Perform necessary error checking to ensure that a positive integer is passed on the command line.


#### INSTRUCTIONS
1. `gcc collatz_conjecture.cpp -o collatz_conjecture.o`
2. `./collatz_conjecture.o`
3. Follow onscreen prompts to copy your files

#### Runtime example
![alt text](https://github.com/shashanksk/CS_MinorProjrct/blob/main/3.21/images/Screenshot%202022-11-09%20at%2012.13.05%20PM.png)

---

#### Header files
`cctype`    - for validating input `isdigit()`
`algorithm` - for string validation `begin(),end()`
`wait.h`    - for the `wait()` system call
`types.h`   - for pid 

---

#### Functionality

1. when the line `pid = fork()` is executed a new process will be created with `fork()`
   2 processes will run 

   A - the forked process which will be the child
   B - the parent process

the pid for the parent process will be an integer > 0
and the pid for the child process will be 0

2. processes will execute simultaneously 
  - the parent process will fail the if statement `if(pid == 0)` and will run the else clause until `wait()` gets executed which will then wait till the child process completes
  - the child process with pid 0 will run the algorithm 
  ```    
  while (h != 1)
        {
            if (h % 2 == 0)
            {
                h = h / 2;
            }
            else if (h % 2 == 1)
            {
                h = 3 * (h) + 1;
            }

            printf("%d\n", h);
        }
   ```
        
3. After the child process completed the parent will release the wait() and continue execution        
