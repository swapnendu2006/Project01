# XYZ Restaurant Order System

A simple, command-line application built in C to manage restaurant operations using a circular queue data structure. 

## Core Features
* **Add Orders:** Captures customer names, requested items, and quantities, then generates an automatic Order ID.
* **Serve Orders:** Processes pending tickets on a First-In, First-Out (FIFO) basis.
* **Live Display:** Outputs all currently pending orders into a formatted, easy-to-read table.
* **Queue Management:** Prevents overflow by enforcing a maximum capacity of 5 active orders at a time.

## Technical Concepts Demonstrated
* Array-based circular queues
* C `struct` implementation for grouping multi-type data
* Standard I/O operations and input buffer clearing
* String formatting for command-line UI tables
