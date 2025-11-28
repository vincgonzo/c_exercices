# FIFO Exercise in C

## Description

This repository contains a simple C program that demonstrates the use of **FIFO (First-In, First-Out)**. The program implements basic FIFO functionality using named pipes (`mkfifo`). The main goal of this exercise is to demonstrate how to use FIFO for inter-process communication in a Unix-like system.

The program consists of:
- **`writer.c`**: This program writes data to a named FIFO.
- **`reader.c`**: This program reads data from the named FIFO.

Before you start the demo, you'll need to create the FIFO file and then compile the code using `make`.

## Prerequisites

- A Unix-like environment (Linux/macOS) with `gcc` installed.
- Basic knowledge of FIFO and inter-process communication.
- `make` utility installed to automate the build process.

## Getting Started

Follow these steps to set up the environment and run the demo:

### Step 1: Clone the repository

First, clone the repository to your local machine:

```bash
mkfifo sum && make
```

from that point you got the two binaries ./freader & fwriter
Open two terminal and use both of them. 

And clean everything before going with :
```bash
make clean
```
