# Queues and Circular Queues in C

This repository contains C implementations of **Linear Queue** and **Circular Queue** using arrays. It demonstrates the core operations such as enqueue, dequeue, peek, and display.

---

## 📌 What is a Queue?

A **Queue** is a linear data structure that follows the **FIFO (First In First Out)** principle. The first element added to the queue will be the first one to be removed.

### ✅ Queue Operations
- **Enqueue** – Add an element to the rear
- **Dequeue** – Remove an element from the front
- **Peek** – View the front element
- **IsEmpty / IsFull** – Check queue status

---

## 🔁 What is a Circular Queue?

A **Circular Queue** solves the limitation of linear queues by connecting the end of the queue back to the front, making it circular. This ensures better memory usage.

### ✅ Circular Queue Operations
- Handles overflow better than linear queue
- Wraps around when rear reaches the end of the array
- Efficient space usage

---

## 🧠 Why Circular Queue Over Linear Queue?

In a **Linear Queue**, once the queue is full, you cannot enqueue more elements even if there’s space at the front (because `front` has moved forward). A **Circular Queue** solves this by wrapping the rear pointer back to the start of the array.

---

## 🧪 Code Files

| File Name | Description |
|----------|-------------|
| `linear_queue.c` | Implementation of Linear Queue using array |
| `circular_queue.c` | Implementation of Circular Queue using array |

---

## 💡 Real-Time Examples

### 📦 Queues
- **Call Center System**: Incoming calls are handled in the order received.
- **Printer Queue**: Print jobs are handled in the order they arrive.
- **Customer Service**: First person in line gets served first.

### 🔄 Circular Queues
- **CPU Scheduling (Round-Robin)**: Processes are rotated in a circular manner.
- **Traffic Signal Controller**: Signals switch in a circular order.
- **Streaming Buffer**: Circular buffer helps store data streams efficiently.

---

## 🧮 Sample Output (Linear Queue)

Queue created with size 5

Enqueue: 10

Enqueue: 20

Dequeue => 10

Peek => 20


## 🧮 Sample Output (Circular Queue)

Circular Queue created with size 5

Enqueue: 10

Enqueue: 20

Enqueue: 30

Enqueue: 40

Enqueue: 50

Dequeue => 10

Enqueue: 60 // Reuses freed space

