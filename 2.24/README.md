
# question 

In Section 2.3, we described a program that copies the contents of one file to a destination file. This program works by first prompting the user for the name of the source and destination files. Write this program using either the POSIX or Windows API. Be sure to include all necessary error checking, including ensuring that the source file exists.

Once you have correctly designed and tested the program, if you used a system that supports it, run the program using a utility that traces system calls. Linux systems provide the strace utility, and macOS systems use the dtruss command. (The dtruss command, which actually is a front end to dtrace, requires admin privileges, so it must be run using sudo.) These tools can be used as follows (assume that the name of the executable file is FileCopy:

Linux: strace ./FileCopy

macOS: sudo dtruss ./FileCopy

Since Windows systems do not provide such a tool, you will have to trace through the Windows version of this program using a debugger.


#### INSTRUCTIONS
1. `gcc copy_code.c -o copy_code.o`
2. `./copy.o`
3. Follow onscreen prompts to copy your files


---
#### SystemCalls
UNIX/Linux: To view the system calls the operating system makes while
running this program, run:

`strace ./copy.o`


To create `strace_log` 
run `strace -ostrace_log ./copy.o`.

List of system calls listed in `strace_log` in order of occurrence (no
repeats) with the line of occurrence in the first bullet point:

1. `int execve(const char *filename, char *const argv[], char *const envp[]
);`

  * Line 1: `execve("./copy.o", ["./copy.o"], [/* 28 vars */]) = 0`
  * Executes the program pointed to by the filename.

2. `int brk(NULL);`

  * Line 2: `brk(0) = 0xaaaadb2e5000'
  * Changes data segment size, maybe allocates memory.

3. `int access(const char *pathname, int mode);`

  * Line 3: `faccess(AT_FDCWD, "/etc/ld.so.preload", R_OK) = -1 ENOENT (No such file or
  directory)`
  * Check a user's permissions for a file.

4. `openat(AT_FDCWD, "/etc/ld.so.cache", O_RDONLY|O_CLOEXEC) = 3`
  * Opens and possibly creates a file.

5. `fstat(3, {st_mode=S_IFREG|0644, st_size=227323, ...}) = 0`
  * Gets file status.

6. 'mmap(NULL, 227323, PROT_READ, MAP_PRIVATE, 3, 0) = 0xffff819ba000'

7. `int close(int fd);`

  * Line 9: `close(3)`
  * Closes a file descriptor so that it no longer refers to any file.

8. `int mprotect(void *addr, size_t len, int prot);`

  * Line 13: `mprotect(0x7f16f3228000, 2093056, PROT_NONE) = 0`
  * Set protection on a region of memory.

9. `int arch_prctl(int code, unsigned long addr);`

  * Line 21: `mprotect(0xffff819a2000, 61440, PROT_NONE) = 0`
  * Set architecture-specific thread state.

11. `int munmap(void *addr, size_t length);`

  * Line 25: `munmap(0xffff819ba000, 227323)          = 0`
  * Map or unmap files or devices into memory.

12. `ssize_t write(int fd, const void *buf, size_t count);`

  * Line 30: `write(1, "Enter name of source file: ", 27) = 27`
  * Write to a file descriptor. In this case, maybe it writes the text to
the screen.

13. `ssize_t read(int fd, void *buf, size_t count);`

  * Line 31: `read(0, "to.txt\n", 1024)               = 7`
  * Read from a file descriptor.

14. `void exit_group(int status);`

  * Line 53: `exit_group(0)                           = ?`
  * Exit all threads in a process. I believe 0 indicates a successful
  execution.


### strace log image 

![alt text]()
