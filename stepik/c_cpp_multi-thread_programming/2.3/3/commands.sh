#! /bin/bash

#Generate an ASCII picture of a cow saying something provided by the user.
#OFF cowsay dmalloc 

#Log the memory allocated but not freed. -d 0 resets a prior setting. -p log-non-free speci
#OFF dmalloc -d 0 -p log-non-free -l leak.log 

#Set the environment variables that dmalloc displayed.
eval `dmalloc -d 0 -p log-non-free -l leak.log`

#Find an allocator shared object.
#OFF sudo ldconfig -p | fgrep dmalloc

#Substitute the program's allocator with dmalloc and start the program.
LP_PRELOAD="libdmalloc.so" ./leak
