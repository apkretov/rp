Programming with POSIX® Threads @ http://www.rulit.me/books/programming-with-posix-threads-get-206366.html

Оглавление

Addison-Wesley Professional Computing Series
Quote acknowledgments:
Preface
  Intended audience
  About the author
  Acknowledgments
1 Introduction
  1.1 The "bailing programmers"
  1.2 Definitions and terminology
    1.2.1 Asynchronous
    1.2.2 Concurrency
    1.2.3 Uniprocessor and multiprocessor
    1.2.4 Parallelism
    1.2.5 Thread safety and reentrancy
    1.2.6 Concurrency control functions
  1.3 Asynchronous programming is intuitive ...
    1.3.1 ... because UNIX is asynchronous
    1.3.2 ... because the world is asynchronous
  1.4 About the examples in this book
  1.5 Asynchronous programming, by example
    1.5.1 The baseline, synchronous version
    1.5.2 A version using multiple processes
    1.5.3 A version using multiple threads
    1.5.4 Summary
  1.6 Benefits of threading
    1.6.1 Parallelism
    1.6.2 Concurrency
    1.6.3 Programming model
  1.7 Costs of threading
    1.7.1 Computing overhead
    1.7.2 Programming discipline
    1.7.3 Harder to debug
  1.8 To thread or not to thread?
  1.9 POSIX thread concepts
    1.9.1 Architectural overview
    1.9.2 Types and interfaces
    1.9.3 Checking for errors
2 Threads
  2.1 Creating and using threads
  2.2 The life of a thread
    2.2.1 Creation
    2.2.2 Startup
    2.2.3 Running and blocking
    2.2.4 Termination
    2.2.5 Recycling
3 Synchronization
  3.1 Invariants, critical sections,and predicates
  3.2 Mutexes
    3.2.1 Creating and destroying a mutex
    3.2.2 Locking and unlocking a mutex
      3.2.2.1 Nonblocking mutex locks
    3.2.3 Using mutexes for atomicity
    3.2.4 Sizing a mutex to fit the job
    3.2.5 Using more than one mutex
      3.2.5.1 Lock hierarchy
      3.2.5.2 Lock chaining
  3.3 Condition variables
    3.3.1 Creating and destroying a condition variable
    3.3.2 Waiting on a condition variable
    3.3.3 Waking condition variable waiters
    3.3.4 One final alarm program
  3.4 Memory visibility between threads
4 A few ways to use threads
  4.1 Pipeline
  4.2 Work crew
  4.3 Client/Server
5 Advanced threaded programming
  5.1 One-time initialization
  5.2 Attributes objects
    5.2.1 Mutex attributes
    5.2.2 Condition variable attributes
    5.2.3 Thread attributes
  5.3 Cancellation
    5.3.1 Deferred cancelability
    5.3.2 Asynchronous cancelability
    5.3.3 Cleaning up
  5.4 Thread-specific data
    5.4.1 Creating thread-specific data
    5.4.2 Using thread-specific data
    5.4.3 Using destructor functions
  5.5 Realtime scheduling
    5.5.1 POSIX realtime options
    5.5.2 Scheduling policies and priorities
    5.5.3 Contention scope and allocation domain
    5.5.4 Problems with realtime scheduling
    5.5.5 Priority-aware mutexes
      5.5.5.1 Priority ceiling mutexes
      5.5.5.2 Priority inheritance mutexes
  5.6 Threads and kernel entities
    5.6.1 Many-to-one (user level)
    5.6.2 One-to-one (kernel level)
    5.6.3 Many-to-few (two level)
6 POSIX adjusts to threads
  6.1 fork
    6.1.1 Fork handlers
  6.2 exec
  6.3 Process exit
  6.4 Stdio
    6.4.1 flockfile and funlockfile
    6.4.2 getchar unlocked and putchar unlocked
  6.5 Thread-safe functions
    6.5.1 User and terminal identification
    6.5.2 Directory searching
    6.5.3 String token
    6.5.4 Time representation
    6.5.5 Random number generation
    6.5.6 Group and user database
  6.6 Signals
    6.6.2 Signal masks
    6.6.3 pthread_kill
    6.6.4 sigwait and sigwaitinfo
    6.6.5 SIGEV_THREAD
    6.6.6 Semaphores: synchronizing with a signal-catching function
7 "Real code"
  7.1 Extended synchronization
    7.1.1 Barriers
    7.1.2 Read/write locks
  7.2 Work queue manager
  7.3 But what about existing libraries?
    7.3.1 Modifying libraries to be thread-safe
    7.3.2 Living with legacy libraries
8 Hints to avoid debugging
  8.1 Avoiding incorrect code
    8.1.1 Avoid relying on "thread inertia"
    8.1.2 Never bet your mortgage on a thread race
    8.1.3 Cooperate to avoid deadlocks
    8.1.4 Beware of priority inversion
    8.1.5 Never share condition variables between predicates
    8.1.6 Sharing stacks and related memory corrupters
  8.2 Avoiding performance problems
    8.2.1 Beware of concurrent serialization
    8.2.2 Use the right number of mutexes
      8.2.2.1 Too many mutexes will not help
    8.2.3 Never fight over cache lines
9 POSIX threads mini-reference
  9.1 POSIX1003.1c-1995 options
  9.2 POSIX1003.1c-1995 limits
  9.3 POSIX1003.1c-1995 interfaces
    9.3.1 Error detection and reporting
    9.3.2 Use of void* type
    9.3.3 Threads
    9.3.4 Mutexes
    9.3.5 Condition variables
    9.3.6 Cancellation
    9.3.7 Thread-specific data
    9.3.8 Realtime scheduling
    9.3.9 Fork handlers
    9.3.10 Stdio
    9.3.11 Thread-safe functions
    9.3.12 Signals
    9.3.13 Semaphores
10 Future standardization
  10.1 X/OpenXSH5(UNIX98)
    10.1.1 POSIX options for XSH5
    10.1.2 Mutex type
    10.1.3 Set concurrency level
    10.1.4 Stack guard size
    10.1.5 Parallel I/O
    10.1.6 Cancellation points
    10.2.1 Barriers
    10.2.2 Read/write locks
    10.2.3 Spinlocks
    10.2.4 Condition variable wait clock
    10.2.5 Thread abort
  10.3 POSIX 1003.14
Bibliography
Thread resources on the Internet
  Newsgroups
  Web sites