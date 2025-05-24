# 🧠 Critical Systems Engineering Journey

> **My personal path to mastering real-time, embedded, and high-assurance software.**  
> Focused on safety-critical systems for aerospace ✈️, automotive 🚗, medical 🏥, finance 💰, and beyond.

---

## 🎯 Objective

To become an elite systems engineer specialized in building **reliable**, **safe**, and **secure** embedded and critical software. This repository documents my learning, experimentation, and development process across C, C++, Rust, formal methods, and real-time systems.

*Aligned with my Master's in Critical Systems Software Engineering + BSc in Software Engineering.*

---

## 🗂️ Structure

```txt
.
├── 01_C_Language_Fundamentals/         # Deep dive into C, pointers, memory, toolchains
├── 02_Embedded_Systems_RTOS/           # Bare-metal + RTOS: FreeRTOS, Zephyr, STM32, etc.
├── 03_Concurrency_and_IPC/             # POSIX threads, semaphores, pipes, shared memory
├── 04_Rust_Embedded_Systems/           # Low-level Rust, no_std, embedded-hal, Cortex-M
├── 05_Cybersecurity_Firmware/          # MISRA-C, overflow prevention, firmware signing
├── 06_Formal_Methods_and_Modeling/     # TLA+, Promela/SPIN, CBMC, model checking
├── 07_Standards_and_Safety_Docs/       # DO-178C, ISO 26262, IEC 61508, FAA/EASA docs
├── 08_Projects_and_Case_Studies/       # Real-world apps, integration cases
└── README.md
```
# 🚀 Path to Mastery in Embedded & Critical Systems Software

## 🎯 Objective

To become a highly skilled, industry-ready software engineer in the fields of embedded systems and critical systems (e.g., automotive, aerospace, banking, elections, IoT), using C, C++, Rust, and formal methods, with a strong foundation in real-time and secure software development.

---

## STEP 1 — Mastering C for Systems & Embedded Programming

### 📘 Books:

* *Expert C Programming* – Peter van der Linden
* *C Programming: A Modern Approach* – K. N. King
* *21st Century C* – Ben Klemens

### 🧪 Exercises:

* Reimplement all standard C library functions from scratch: `strlen`, `strcpy`, `malloc`, `free`, `qsort`, etc.
* Implement a memory pool allocator
* Create a full stack-based virtual machine with function calls and memory isolation
* Write your own `printf` (basic version with formatting)
* Build linked list, binary tree, hash map, ring buffer from scratch (no `stdlib.h`)
* Implement your own shell with job control and background tasks
* Parse and execute a simple scripting language (recursive descent parser)

---

## STEP 2 — Embedded Systems & Real-Time Operating Systems (RTOS)

### 📘 Books:

* *Making Embedded Systems* – Elecia White
* *Real-Time Concepts for Embedded Systems* – Qing Li

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

## STEP 3 — Linux Systems Programming & POSIX Multithreading

### 📘 Books:

* *The Linux Programming Interface* – Michael Kerrisk
* *Operating Systems: Three Easy Pieces* – Remzi Arpaci-Dusseau
* *Programming with POSIX Threads* – David Butenhof

### 🧪 Exercises:

* Write a shell that handles pipes, redirection, and signals (SIGINT, SIGCHLD)
* Create a multi-process producer-consumer pipeline using shared memory + semaphores
* Implement a thread pool with task queue and dynamic scaling
* Write a file watcher using inotify API that logs changes
* Simulate a job scheduler using message queues and forked worker processes
* Use `mmap` to share data between unrelated processes
* Write a system that simulates an airport boarding system with mutex-protected zones
* Profile and analyze performance with `perf`, `valgrind`, and `gprof`

---

## STEP 4 — Rust for Embedded & Safety-Critical Code

### 📘 Books:

* *Programming Rust* – Blandy & Orendorff
* *The Embedded Rust Book* (online)
* *Rust for Rustaceans* – Jon Gjengset

### 🧪 Exercises:

* Blink LED using Rust on STM32 (via `cortex-m-rt`, `embedded-hal`, `probe-rs`)
* Write a panic-safe abstraction over hardware pins
* Implement a basic serial protocol with CRC validation
* Create a sensor reading system with log and alarm conditions
* Port FreeRTOS task concepts to async Rust tasks
* Use `unsafe` Rust to interface with memory-mapped registers — and wrap safely
* Build a watchdog timer system with safe + recoverable panic modes
* Embed Rust FFI module into a C project and vice versa

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

## ✅ Final Capstone Projects

1. **Real-Time Sensor Network (STM32 + FreeRTOS + UART logging)**
2. **Rust Secure Firmware Loader with OTA Simulation**
3. **POSIX-Based RT Simulation of a Voting System with Verifiable Logs**
4. **TLA+ Model of a Metro Train System + Working C Implementation**

---

## 🔧 Tools to Learn Along the Way

* GCC, Clang, GDB, CMake, Makefiles
* Git, GitHub Actions, Jenkins
* Static analyzers: `cppcheck`, `clang-tidy`, Frama-C
* Formal tools: TLA+, CBMC, SPARK/Ada (optional)
* Embedded: STM32CubeIDE, VSCode, probe-rs, OpenOCD
* Linux: strace, lsof, perf, valgrind, gprof, systemd
* Rust: Cargo, `no_std`, `panic-halt`, embedded-hal, cortex-m crates

---

This path is intentionally intensive and industry-aligned. Follow it with discipline, and you'll be able to tackle safety-critical systems at a top-tier level.
