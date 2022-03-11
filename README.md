# Minitalk (Inter Process Communication)
The purpose of this project is to code a small data exchange program using UNIX signals.

# To generate text : https://www.lipsum.com/

# Signal Concepts :  (Linux System Programming, Second Edition by Robert Love)

Signals are software interrupts that provide a mechanism for handling asynchronous(not occurring at the same time ) events. 
These events can originate from outside the system, such as when the user generates the interrupt character by pressing Ctrl-C, 
or from activities within the program or kernel, such as when the process executes code that divides by zero. As a primitive form of interprocess communication (IPC), one process can also send a signal to another process.
	… the program handles the signals asynchronously. 
  
# Signals have a very precise lifecycle:
First, a signal is raised (we sometimes also say it is sent or generated). The kernel then stores the signal until it is able to deliver it.
Finally, once it is free to do so, the kernel handles the signal as appropriate.

# The kernel can perform one of three actions, depending on what the process asked it to do: 
##### 1- Ignore the signal ( There are two signals that cannot be ignored: SIGKILL and SIGSTOP)
##### 2 - Catch and handle the signal
##### 3 - Perform the default action


# Signal Identifiers 
Every signal has a symbolic name that starts with the prefix SIG. For example, SIGINT is the signal sent when the user presses Ctrl-C,
SIGABRT is the signal sent when the process calls the abort() function, and SIGKILL is the signal sent when a process is forcefully terminated.

# Global Variables (You can have one global variable per program (one for the client and one for the server), but you will have to justify their use.)
Global variables are defined outside a function, usually on top of the program. Global variables hold their values throughout the lifetime of your program and they can be accessed inside any of the functions defined for the program.
A global variable can be accessed by any function. That is, a global variable is available for use throughout your entire program after its declaration. 

# How to View and Kill Processes (ID) Using the Terminal in Mac OS X:
Use this command : ps -ax
 
# Man  signal :
##### 30    SIGUSR1      terminate process    User defined signal 1
##### 31    SIGUSR2      terminate process    User defined signal 2

# sigaction() used instead of signal() in order to get the parameter
# 'info->si_pid' the pid of the sender .
The signal() function is very basic. Because it is part of the standard C library and therefore has to reflect minimal assumptions about the capabilities of the operating system on which it runs, it can offer only a lowest common denominator to signal management. As an alternative, POSIX standardizes the sigaction() system call, which provides much greater signal management capabilities. 


https://user-images.githubusercontent.com/79755743/157832262-597d5a20-a612-45dc-84bd-64e3338919a4.mov


# PDF:

# 1 [IPC (1).pdf](https://github.com/anastabiti/Minitalk-/files/8230464/IPC.1.pdf)
# 2 [Linux system programming talking directly to the kernel and C library by Robert Love (z-lib.org).pdf](https://github.com/anastabiti/Minitalk-/files/8230465/Linux.system.programming.talking.directly.to.the.kernel.and.C.library.by.Robert.Love.z-lib.org.pdf)
# 3 [inter-process_communication_in_linux.pdf](https://github.com/anastabiti/Minitalk-/files/8230468/inter-process_communication_in_linux.pdf)




