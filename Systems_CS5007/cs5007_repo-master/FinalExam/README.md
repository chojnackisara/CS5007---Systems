# Final Exam

 ## Honor code: 
 
 By signing my name below, I affirm that:
 
 1. All the answers submitted by me has been written by me.
 
 2. I have not talked or otherwise communicated with anybody about 
    questions related to this take home exam. This includes, but is not limited to:
    a. All modes of communication, including face-to-face communication, text, 
       audio or video chat, emails or online posts.
    b. Asking for help from others, and providing help to others.

  3. I am aware that my submissions may be checked for plagiarism and 
     similarity with other submissions, and if I am found to have broken 
     any of these rules, I will get a 0 on the entirety of this exam, 
     and will be reported for an academic integrity violation.
  4 I have read and understand this honor code in full. 
   
  Sara Chojnacki, 001631378
  
# Take home Quiz/Exam Due Saturday 4/18  at Midnight

Answer each of the following questions in your own words. Two to three sentences each. I would recommend typing all of your
answers in a word document and when you are satisfied with your answers paste them here.

Operating System Overview
What exactly is the kernel? 

The kernel is the computer program that is the heart of an operating system. It is the first program that is loaded when the system starts and it has complete control over everything within it. It provides communication between applications and the data processing that is done at the hardware level.


C Programming
What is a pointer?

A pointer is a variable that stores the address, or location, of another variable in memory. Pointers are used to dynamically allocate memory. This means the memory is allocated at run time.


What is Pass by Value?

When a variable is passed on, pass by value means the actual value of the variable is passed on, rather than the memory address. Passing on the address, or memory location, is known as Pass by Reference.


How do you dynamically allocate memory?

Dynamically allocated memory is allocated during run time. We can just create a pointer variable to store a value, without having to use malloc() or something similar.


Assembly and Machine Representation
What are registers and how many registers do you have in x86-64
What are some of those registers reserved for?

A register is a memory location that can be accessed quickly by a computer’s CPU. It is used to accept and store data and instructions that need to be used immediately by the CPU.
x86-64 has 16 universal registers, 2 status registers, 6 code segment registers, 16 SSE registers, and 8 FPU/MMX registers. This adds up to 48, but there seems to be a lot of discrepancy on the internet about the actual number. 
The SSE registers are most often used for floating point and double operations.
%rsp - keeps track of where the stack is


What is a syscall?

A syscall, or system call, is the name for when the computer requests a service from the kernel. It allows programs to interact with the operating system of the computer.

How do the stack and the heap work?

The stack and the heap are both data structures, but the stack is linear while the heap is hierarchical. When memory is allocated, it can go on the stack or it can go on the heap. 


What are opcodes? 

An opcode is a single instruction that tells a processor what to do with the data besides it. It can consist of assembly commands such as mov, cmp, jmp, etc.


What do the following instructions do mov, cmp, jmp, and add, etc.

Mov moves data around. Cmp compares two operands. Jmp performs an unconditional jump, and transfers the flow of execution by changing the instruction pointer register. Add adds two values.


Compilers and Linkers
What does a compiler do?
Why do we use them?
What is the frontend responsible for? The backend?

The compiler translates high-level programming language code to a lower-level language (like assembly) in order to create an executable program. The frontend’s responsibility is to construct an intermediate representation of the original code from which the lower-level code (like assembly) can be generated. The backend’s responsibility is the final code generation. 


Know about Compile-Time and Link-Time Interpositioning.
What is the purpose of compile-time and link-time interpositioning and what could it be used for.

With compile time interpositioning, a library call is replaced with our own function when the code is compiled. With link time interpositioning, code from the library is put into the final executable.
Interpositioning could be used for detecting memory leaks, counting number of function calls, or generating address traces, for example.


What is a linker?
Why do we use them? *Describe the linking process

A linker is a program which links together object files of a program, generated by a compiler, into a single executable object file. This way we can have a single executable. Linking happens at the last step of compilation. The first step of linking is symbol resolution, where symbol definitions are stored in the object file’s symbol table. The second step is relocation, when the symbols are relocated from their original object file into the final executable.


Processor and Processes
What is a context switch? What information gets saved?

A context switch happens when the kernel transfers control of the CPU from a process that is executing to another that is read to execute. The state of the process or thread gets saved so that it can be restored in the future.


What are signals?

A signal is a software interrupt that is delivered to a process. The signal is used to report a special situation to the program that is being executed, usually one that makes it impossible for the program to proceed normally. 


How do you write a signal handler? What goes on when a signal is found?

A signal handler catches a signal and does something when the signal is caught. When the signal is found, the signal is “pending”, then it is “delivered” to the process that was signalled. When the signal handler runs, the signal iis normally blocked, and the signal handler executes, usually to terminate the program. 


What does a fork() do? Why is it a strange function?

Fork is a function that creates two separate processes: a child process and a parent process. The child process is identical to the parent process. Fork actually returns twice -- once to the parent, and once to the child, although it is only called once.


What does execve(...) do?

Execve is a system call command that allows us to execute an entire program as a separate process within a process. It loads the program into the space of the current process and then runs it from the entry point.


The Memory Hierarchy
What is pipelining?

Pipelining is the process where multiple instructions are accumulated through a pipeline for execution. They are separated by a pipe, and the output of one element is the input of the next one.


Why is branching bad for performance?

The design of pipelining expects instructions to be executed in a particular sequence that doesn’t change, so conditional branch instructions cause this sequence to be unknown. This can cause a “stall” until the decision is resolved, which results in everything in the pipeline behind that instruction thrown away.


What is caching?

A cache is a smaller, faster temporary storage location that acts like a staging area for data in a larger, slower area.
Caching is the process of storing copies of files in the cache so that they can be accessed more quickly.


What is a directly mapped cache?

In a directly mapped cache, each block in memory gets mapped to exactly one corresponding block in the cache. So block 1 in memory would get mapped to block 1 in the cache (if it exists in the cache), block 2 in memory would get mapped to block 2 in the cache, and so on.


Virtual Memory *What is virtual memory?

Virtual memory is a memory management approach. It allows secondary memory to be addressed like it is part of the main memory. It maps “virtual addresses” into physical addresses within computer memory.


Concurrency
What is a thread? What is a process? What is the difference?
What is fork(), wait(), a child process, zombie processes, orphan processes

A process is a program that is in execution. A thread is a segment of a process; a process could have many threads contained within it. A thread can be either running, ready, or blocked. Threads share all code and data, while processes do not. Threads are also usually less costly than processes. 
Fork is a function that creates two separate processes: a child process and a parent process. The child process is identical to the parent process. Fork actually returns twice -- once to the parent, and once to the child, although it is only called once. Wait() enforces the execution order by making the parent wait to execute until after one of more child processes are done.
A zombie process is a dead process that still appears in the process table. It is most likely the result of bugs or coding errors. An orphan process is a child process whose parent is dead. 


How do you spawn a thread, and what does it mean to join a thread?

The thread that is “launched” is a function in the program. Various attributes can be sent to the threads and arguments can be passed in as well. Joining a thread is virtually the same thing as “wait” for processes. If threads are joined with the main thread, the main thread will have to wait until the additional threads are executed.


Talk about the problems with concurrency and sharing memory.

When two or more processes are fighting over a shared resource, starvation could occur. This means that one process could use up all the resources and there would be none left for the other processes to use. A deadlock could also occur. Assume we have two processes and both try to access a shared resource at the same time, so the second is forced to wait while the first one finishes. A deadlock would happen when the second process, which is waiting, is holding on to another resource that the first needs before it can finish.


Lets us know if you have any questions. 

      













 
 