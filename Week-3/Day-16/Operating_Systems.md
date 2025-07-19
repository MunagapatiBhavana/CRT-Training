# 💻 CRT Training Day 16 - Operating System Concepts 

This repository contains detailed notes, definitions, block diagrams, examples, and sample code related to **Operating System (OS) concepts** discussed during Day 16 of CRT Training.

---

## 📚 Table of Contents

1. [🔹 OS Structure](#-os-structure)
2. [🔹 Process vs Thread](#-process-vs-thread)
3. [🔹 Process Life Cycle](#-process-life-cycle)
4. [🔹 Process Management](#-process-management)
5. [🔹 fork() System Call](#-fork-system-call)
6. [🔹 Zombie & Orphan Processes](#-zombie--orphan-processes)
7. [🔹 Context Switching](#-context-switching)
8. [🔹 Scheduling Queues](#-scheduling-queues)
9. [🔹 OS Schedulers](#-os-schedulers)
10. [🔹 Dispatcher & Dispatch Latency](#-dispatcher--dispatch-latency)
11. [🔹 Preemptive vs Non-Preemptive Scheduling](#-preemptive-vs-non-preemptive-scheduling)
12. [🔹 Multilevel Queue Scheduling](#-multilevel-queue-scheduling)
13. [🔹 Starvation & Aging](#-starvation--aging)
14. [🧠 Practice Problems & Sample Codes](#-practice-problems--sample-codes)

---

## 🔹 OS Structure

### Definition:
The **Operating System (OS) Structure** defines how different parts of the OS are organized and how they communicate.

### Types:
- **Monolithic Kernel**: Entire OS works in kernel mode (e.g., Linux).
- **Microkernel**: Only essential services in kernel (e.g., QNX).
- **Layered Architecture**: Organized in layers (e.g., THE OS).
- **Hybrid Systems**: Combines multiple structures (e.g., Windows, macOS).

---

## 🔹 Process vs Thread

| Feature     | Process                      | Thread                          |
|-------------|------------------------------|----------------------------------|
| Definition  | Program in execution         | Smallest unit of execution      |
| Memory      | Separate memory              | Shared memory with other threads|
| Communication | Inter-process communication | Shared variables                |
| Overhead    | High                         | Low                             |

---

## 🔹 Process Life Cycle

```text
New → Ready → Running → Waiting → Terminated
```

## Diagram:
```
   ┌───────┐
   │ New   │
   └──┬────┘
      ↓
   ┌───────┐
   │ Ready │◄──────────────┐
   └──┬────┘               │
      ↓                   │
   ┌───────┐     I/O wait │
   │Running│ ────────────►│
   └──┬────┘               ↓
      ↓                 ┌───────┐
   ┌───────┐             │Waiting│
   │Term'd │◄────────────┘───────┘
   └───────┘
```

## 🔹 Process Management
Creation: fork(), exec() system calls

Termination: exit() system call

States: New, Ready, Running, Waiting, Terminated

## 🔹 fork() System Call
📌 Definition:

fork() is used to create a new child process by duplicating the parent.

```
#include <stdio.h>
#include <unistd.h>

int main() {
    int pid = fork();
    if (pid == 0)
        printf("Child process\n");
    else
        printf("Parent process\n");
    return 0;
}
```

## 🔹 Zombie & Orphan Processes
Zombie: Process completed but still in process table (waiting to be reaped).

Orphan: Child process whose parent has terminated.

# 🔹 Context Switching
📌 Definition:
Switching the CPU from one process/thread to another.

Components:
Save current state

Load next process state

# 🔹 Scheduling Queues
Job Queue: All processes in system

Ready Queue: Processes in memory, ready to execute

Waiting Queue: Processes waiting for I/O

# 🔹 OS Schedulers
| Type        | Description                               |
| ----------- | ----------------------------------------- |
| Long-Term   | Selects processes from job queue → memory |
| Short-Term  | Picks process from ready queue → CPU      |
| Medium-Term | Temporarily removes/resumes processes     |


# 🔹 Dispatcher & Dispatch Latency
Dispatcher: Gives control of CPU to selected process

Dispatch Latency: Time to stop one process and start another

# 🔹 Preemptive vs Non-Preemptive Scheduling
| Type           | Description                                  |
| -------------- | -------------------------------------------- |
| Preemptive     | CPU can be taken from a process              |
| Non-Preemptive | Process keeps CPU until it finishes or waits |


🔄 Example:
Preemptive: Round Robin, SRTF

Non-Preemptive: FCFS, SJF

# 🔹 Multilevel Queue Scheduling
📌 Definition:
Multiple queues for different priority levels.

📊 Diagram:
```
+---------------------+
| System Processes    | → FCFS
+---------------------+
| Interactive         | → Round Robin
+---------------------+
| Batch Processes     | → FCFS
+---------------------+
```
# 🔹 Starvation & Aging
Starvation: A process waits indefinitely due to low priority.

Aging: Gradual increase in priority to prevent starvation.

# ✅ Problem 1: Print Process IDs
```
#include <stdio.h>
#include <unistd.h>
int main() {
    printf("PID: %d, PPID: %d\n", getpid(), getppid());
    return 0;
}
```

# ✅ Problem 2: Create Zombie

```
#include <stdio.h>
#include <unistd.h>
int main() {
    if (fork() > 0)
        sleep(30); // Parent sleeps
    else
        exit(0); // Child exits
    return 0;
}
```
```
📘 Topic: Operating System (OS) Concepts
🔹 1. OS Structures
Monolithic: Entire OS runs in kernel mode (e.g., UNIX).

Layered: OS divided into layers, each built on the one below.

Microkernel: Only core services in kernel, others in user space (e.g., Minix).

Modular: Loadable kernel modules (e.g., Linux).

Hybrid: Mix of monolithic and microkernel (e.g., Windows).

🔹 2. Process
Definition: A program in execution.

Process Control Block (PCB): Stores info like PID, state, registers.

🔹 3. Thread
Lightweight Process: Shares memory and resources of parent.

Multithreading: Multiple threads within a process improve performance.

🔹 4. Process Life Cycle
States: New → Ready → Running → Waiting → Terminated

Diagram: Circle flow showing transitions between these states.

🔹 5. Process Management
Handles creation, scheduling, and termination of processes.

🔹 6. Fork System Call
Used to create a child process.

c
Copy
Edit
#include <unistd.h>
pid_t pid = fork();
🔹 7. Zombie Process
A child process that has terminated, but its PCB still exists.

🔹 8. Orphan Process
A child whose parent has terminated. Adopted by init in UNIX.

🔹 9. Context Switching
Switching CPU from one process/thread to another.

Saves and restores states from PCB.

🧮 Scheduling & Queues
🔹 10. Process Scheduling Queues
Job Queue: All submitted jobs.

Ready Queue: Ready processes.

Device Queue: Waiting for I/O.

🔹 11. Schedulers
Long-Term: Selects jobs from job pool.

Short-Term (CPU Scheduler): Chooses among ready processes.

Medium-Term: Swaps processes in and out of memory.

🔹 12. Dispatcher
Gives control of CPU to the process chosen by scheduler.

Involves:

Context switch

Switching to user mode

Jumping to process location

🔹 13. Dispatch Latency
Time taken to stop one process and start another.

⚖️ Scheduling Policies
🔹 14. Preemptive vs Non-Preemptive
Preemptive: OS can forcibly take CPU from a process.

Non-Preemptive: CPU runs until process voluntarily releases.

🔹 15. Scheduling Algorithms
FCFS (First Come First Serve)

SJF (Shortest Job First)

RR (Round Robin)

Priority Scheduling

Multilevel Queue Scheduling

Queues based on type of process (foreground, background).

Each queue has its own scheduling algorithm.

🔹 16. Starvation & Aging
Starvation: Low priority processes may wait indefinitely.

Aging: Gradually increasing priority of waiting processes.
```

# Conclusion
The internal architecture of operating systems (like monolithic, microkernel, and layered structures),

How processes and threads are created and managed,

The process life cycle and the significance of context switching,

The importance of scheduling algorithms and how they impact performance,

Real-world issues like zombie, orphan processes, starvation, and how to address them with aging.

These concepts not only help in technical interviews and coding challenges, but also form the foundation for advanced topics like concurrency, distributed systems, and OS-level security.

By mastering these basics, you’re better equipped to design robust applications and understand how your code interacts with the system at a low level.
