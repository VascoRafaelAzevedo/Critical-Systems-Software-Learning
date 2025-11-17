# Low Level Software Journey

> **My personal path to real-time, embedded, and high-assurance software.**  
> Focused on safety-critical systems for aerospace ✈️, automotive 🚗, medical 🏥, and beyond.

---

## 🎯 Objective

To become a software engineer specialized in building **reliable**, **safe**, and **secure** software. This repository documents my learning, experimentation, and development process across C, C++, Rust, formal methods, and real-time systems.

*Aligned with a future Master's in Critical Systems Software Engineering + BSc in Software Engineering.*

---

## 🗂️ Structure

```txt
.
├── 01_C_Language/                      # Deep dive into C, pointers, memory, toolchains, etc.
├── 02_Cpp_Language_Fundamentals/       # Dive into C++, pointers, memory, toolchains
├── 03_Embedded_Systems_RTOS/           # Bare-metal + RTOS: FreeRTOS, Zephyr, STM32, etc.
├── 04_Concurrency_and_IPC/             # POSIX threads, semaphores, pipes, shared memory
├── 05_Rust/                            # Low-level Rust, no_std, embedded-hal, Cortex-M
├── 06_Safety_Verification              # MISRA-C, overflow prevention, firmware signing
├── 07_Advanced_Topics/                 # More advanced topics related to safety critical systems 
├── 08_Standards_and_Safety_Docs/       # DO-178C, ISO 26262, IEC 61508, FAA/EASA docs
└── README.md
```
# 🚀 Path to Embedded & Critical Systems Software

## STEP 1 — Mastering C++ 

### 📘 Books:

* *Programming Principles and Practice Using C++* – Bjarne Stroustrup
* *C++ Concurrency in Action* - Anthony Williams
* *C++ Lambda Story* - Bartłomiej Filipek

### 🧪 Exercises:

* Reimplement standard C library functions from scratch: `std::string`, `std::vector`, etc.
* Implement a memory pool allocator
* Create a full stack-based virtual machine with function calls and memory isolation
* Write your own `printf` (basic version with formatting)
* Build linked list, binary tree, hash map, ring buffer from scratch
* Parse and execute a simple scripting language (recursive descent parser)


## STEP 2 — Linux Systems Programming, Multithreading & Computer Architecture

### 📘 Books:

* *Operating Systems: Three Easy Pieces* – Remzi Arpaci-Dusseau
* *But How do It Know – J. Clark Scott

### 🧪 Exercises:

* Write a shell that handles pipes, redirection, and signals (SIGINT, SIGCHLD)
* Create a multi-process producer-consumer pipeline using shared memory + semaphores
* Implement a thread pool with task queue and dynamic scaling
* Implement your own shell with job control and background tasks
* Write a file watcher using inotify API that logs changes
* Simulate a job scheduler using message queues and forked worker processes
* Use `mmap` to share data between unrelated processes
* Write a system that simulates an airport boarding system with mutex-protected zones
* Profile and analyze performance with `perf`, `valgrind`, and `gprof`

---

## STEP 3 — Embedded Systems & Real-Time Operating Systems (RTOS)

### 📘 Books:

* *Real-Time Software Design For Embedded Systems – Hassan Gomaa
* *Making Embedded Systems* – Elecia White

### 🧪 Exercises:

* Write GPIO toggling with direct register access on STM32 or simulated via QEMU
* Write a software debounce logic for buttons
* Implement polling vs. interrupt-based I/O drivers
* Design an RTOS-like cooperative scheduler in C (task structs, yield, wait)
* Extend the scheduler to support preemption via SysTick
* Use FreeRTOS: create 3 tasks with different priorities, one using semaphores
* Implement mutex, binary semaphore, counting semaphore in baremetal C
* UART communication driver with circular buffer and interrupt handling
* Build a real-time data logger (sensor input + timestamped UART output)

---

## STEP 4 — Rust

### 📘 Books:

* The Rust Programing Language* – Blandy & Orendorff
* *Zero To Production In Rust* - Luca Palmieri

---

## STEP 5 — Safety, Verification, and Compliance

### 📘 Books:

* *Embedded Systems Security* – Kleidermacher
* *Practical TLA+* – Hillel Wayne
* *Introduction to Formal Methods* – Jean-Raymond Abrial (optional advanced)

### 🧪 Exercises:

* Write a bootloader in C with signature verification of firmware updates
* Use `clang-tidy`, `cppcheck`, and `PC-lint` to find violations in C codebase
* Implement a secure logging system with integrity checks
* Use TLA+ to model and validate:

  * Elevator system
  * Traffic light controller
  * Producer-consumer ring buffer
* Write C code that meets MISRA-C:2012 guidelines and validate with tools
* Simulate a triple-redundancy fault-tolerant sensor network in C or Rust

---

## STEP 6 — Advanced Topics & Industry Tools

### 📘 Books:

* *Linux for Embedded and Real-Time Applications* – Doug Abbott
* *Software Engineering for Embedded Systems* – Safranek, Hall, etc.

### 🧪 Exercises:

* Build a real-time CAN bus data parser and logger (simulated)
* Set up Jenkins/GitHub Actions pipeline with tests + coverage + analysis for C code
* Use Docker + QEMU to create reproducible test environments
* Create a live CI/CD system for your embedded projects
* Use Frama-C to prove correctness of a queue and scheduler
* Reimplement a subset of a POSIX scheduler in Rust using async/await

---

## 🔧 Tools to Learn Along the Way

* GCC, Clang, GDB, CMake, Makefiles
* Git, GitHub Actions, Jenkins
* Static analyzers: `cppcheck`, `clang-tidy`, Frama-C
* Formal tools: TLA+, CBMC, SPARK/Ada (optional)
* Embedded: STM32CubeIDE, VSCode PlatformIO, probe-rs, OpenOCD
* Linux: strace, lsof, perf, valgrind, gprof, systemd
* Rust: Cargo, `no_std`, `panic-halt`, embedded-hal, cortex-m crates

---
