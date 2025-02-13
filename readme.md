# Get Next Line - 42 

## Introduction
The **Get Next Line** project at 42 is designed to help students master reading from file descriptors efficiently. The goal is to create a function that returns a line read from a file descriptor, handling multiple file descriptors and ensuring optimal performance.
# Concept
The main challenge of **get_next_line** (GNL) is to read from a file descriptor one line at a time without re-reading the previous content. This requires efficient memory handling, buffer management, and proper handling of edge cases.
# Mandatory Requirements
  - Implement a function:

 ```
  char *get_next_line(int fd);
 ```

  - The function should:
    - Return a line from the given file descriptor, including the newline (\n) if present.
    - Manage static variables to store data between function calls.
    - Work for any valid file descriptor, including standard input (stdin).
    - Handle multiple file descriptors simultaneously.
    - Properly allocate and free memory to prevent leaks.
# Bonus Features
The bonus part extends the project with the following:
  - The ability to handle multiple file descriptors at the same time.
  - Enhanced buffer management for performance optimization.
# Implementation Details
### Buffer Size 
  - The function should use a defined ```BUFFER_SIZE``` to read chunks of data.
  - ```BUFFER_SIZE``` is a macro that can be adjusted to improve performance.
### Static Variable
  - A static variable is used to store leftover data from previous reads.
  - This allows the function to keep track of data between function calls efficiently.
### Memory Management
  - Proper allocation (malloc) and deallocation (free) are crucial to avoid leaks.
  - Edge cases like empty files, large files, or files without newlines must be handled correctly.
## Compilation and Usage
To compile the project, use:

```console
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c -o gnl
```

To test the function:

```console
./gnl < file.txt
```

## Common Pitfalls
  - $\color{crimson}{\textbf{The end of the file is not being handled properly}}$.
  - $\color{crimson}{\textbf{Memory leaks}}$ due to improper freeing of allocated memory.
  - $\color{crimson}{\textbf{Incorrect handling of static variables}}$ leads to unwanted behavior.
  - $\color{crimson}{\textbf{Not considering different file descriptors}}$ when handling the bonus.
## Conclusion
The Get Next Line project is a great exercise in file handling, memory management, and efficient programming. By successfully implementing this function, students gain a deeper understanding of working with file descriptors and dynamic memory allocation in C.
