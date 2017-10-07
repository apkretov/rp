#! /bin/bash

#Trace all system calls.
strace ./server
ltrace ./server

#Log errors.
./server 2> ./server.log

#Connect to the server.
telnet 127.0.0.1 12345

#List "server"-named processes. #What does aux mean in `ps aux`? @ https://unix.stackexchange.com/questions/106847/what-does-aux-mean-in-ps-aux
ps aux | fgrep server

#List files specific to a process. #Linux lsof command tutorial for beginners (10 examples) @ https://www.howtoforge.com/linux-lsof-command/
lsof -p [PID]

#Disconnect from the server.
telnet>q

#Connect to a process.
strace -p [PID]
ltrace -p [PID]
gdb -p [PID]
