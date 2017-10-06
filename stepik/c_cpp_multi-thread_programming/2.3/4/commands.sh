#! /bin/bash

#Find an allocator shared object.
#OFF sudo ldconfig -p | fgrep tcmalloc

#Substitute the program's allocator with tcmalloc and start the program.
#OFF LP_PRELOAD="libtcmalloc.so.4" ./leak

#Run the program with a memory leakage monitoring.
LD_PRELOAD="libtcmalloc.so.4" HEAPCHECK=normal ./leak
