Compile it with the command below. make does not work.
gcc alarm_mutex.c -pthread -o alarm_mutex

When compiled -DDEBUG, it results in a macro that can be used for diagnostic output - calling printf with the specified argument list.
gcc backoff.c -pthread -DDEBUG -o backoff
