#! /bin/bash

#Find an allocator shared object.
#OFF sudo ldconfig -p | fgrep jemalloc

#Substitute the program's allocator with dmalloc and start the program.
LD_PRELOAD="libjemalloc.so" ./leak
