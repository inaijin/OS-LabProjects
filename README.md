# Operating System Lab Projects F2023

This repository contains a collection of projects completed as part of the Operating System Lab Course (F2023). The projects involve modifying and extending the xv6 operating system to add various features, ranging from basic console enhancements to advanced memory management techniques.

## Project Descriptions

1. [Experiment 1: Introduction to xv6](#experiment-1-introduction-to-xv6)
2. [Experiment 2: System Calls](#experiment-2-system-calls)
3. [Experiment 3: Process Scheduling](#experiment-3-process-scheduling)
4. [Experiment 4: Synchronization](#experiment-4-synchronization)
5. [Experiment 5: Memory Management](#experiment-5-memory-management)

## [Experiment 1: Introduction to xv6](https://github.com/inaijin/OS-LabProjects/tree/main/CA1_Introduction_To_Xv6)

### Task 1: Boot Message
**Description**: Display the names of group members as a message when the system boots up.

### Task 2: Console Features
**Description**: Add the following keyboard shortcuts to the console:
- `Ctrl+N`: Removes all digits from the console.
- `Ctrl+R`: Reverses the current line.
- `Tab`: Substitutes the current line with a command from history (if exists).
- `Ctrl+B`: Moves the cursor one character to the left.
- `Ctrl+F`: Moves the cursor one character to the right.
- `Ctrl+L`: Clears the console.
- `Arrow Up`: Shows the previous command in history.
- `Arrow Down`: Shows the next command in history.

### Task 3: User Program
**Description**: Implement a `strdiff` program to find the difference between two strings. The result is printed in the `strdiff_result.txt` file.
```text
strdiff a b
```

## [Experiment 2: System Calls](https://github.com/inaijin/OS-LabProjects/tree/main/CA2_System_Calls)

### Task 1: System Call Using Registers
**Description**: Add a `find_digit_root` system call to find the largest prime factor of a given number. The integer parameter is passed in the `ebx` register.
```c
int find_digit_root(void);
```

### Task 2: System Call Using Stack
**Description**: Add the following system calls:
- `copy_file`: Copies a file to another location.
```c
int copy_file(char *path, int size);
```
- `get_uncle_count`: Returns the number of uncle processes of the current process.
```c
void get_uncle_count(void);
```
- `get_process_lifetime`: Returns the lifetime of the current process.
```c
int get_process_lifetime(void);
```

## [Experiment 3: Process Scheduling](https://github.com/inaijin/OS-LabProjects/tree/main/CA3_Scheduling)

### Task 1: Multi-Level Feedback Queue (MLFQ)
**Description**: Implement an MLFQ scheduler with three queues:
- First queue: Round-robin with a time quantum of 1 tick.
- Second queue: Last-Come-First-Served (LCFS).
- Third queue: Best-Job-First (BJF).

### Task 2: Aging
**Description**: Start all processes in the second queue (except `init` and `sh`). If a runnable process hasn't been executed for 8000 ticks, it is moved to the first queue.

### Task 3: System Calls
**Description**: Add the following system calls:
- `change_scheduling_queue`: Changes the scheduling queue of a process.
```c
int change_scheduling_queue(int pid, int queue);
```
- `set_bjf_params_process`: Sets the BJF parameters for a process.
```c
int set_bjf_params_process(int pid, float priority_ratio, float arrival_time_ratio, float executed_cycles_ratio);
```
- `set_bjf_params_system`: Sets the BJF parameters for the system.
```c
int set_bjf_params_system(float priority_ratio, float arrival_time_ratio, float executed_cycles_ratio);
```
- `print_process_info`: Prints process information in a table.
```c
void print_process_info(void);
```

These system calls can be accessed using the `schedule` user program:
```text
usage: schedule command [arg...]
Commands and Arguments:
  info
  set_queue <pid> <new_queue>
  set_process_bjf <pid> <priority_ratio> <arrival_time_ratio> <executed_cycle_ratio>
  set_system_bjf <priority_ratio> <arrival_time_ratio> <executed_cycle_ratio>
  set_priority_bjf <pid> <priority>
```

## [Experiment 4: Synchronization](https://github.com/inaijin/OS-LabProjects/tree/main/CA4_Synchronization)

### Task 1: Number of System Calls
**Description**: Count the number of system calls across 4 cores using the `getnsyscalls` program. Spin locks are used to prevent process interruption during counting.
```c
int getnsyscalls();
```

### Task 2: Priority Lock
**Description**: Implement a priority lock following the spin lock policy. Add the following system calls:
```c
void acquirepriority(struct prioritylock* lk);
void releasepriority(struct prioritylock* lk);
```

## [Experiment 5: Memory Management](https://github.com/inaijin/OS-LabProjects/tree/main/CA5_Memory%20Managment)

### Shared Memory System
**Description**: Add a shared memory system with the following system calls:
```c
char* openshmem(int id);
int closeshmem(int id);
```

## Special Thanks

- **MehdiJmlkh** for the help in coding.
- **Shahriar-0** for the readme inspiration.


## Contributing
Feel free to fork this repository, open issues, or submit pull requests. Any contributions are welcome!
