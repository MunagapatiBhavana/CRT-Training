## 📚 Day-2 – Arrays in C

Welcome to the Arrays module from my CRT Training sessions!

Arrays are one of the most fundamental and widely-used data structures in programming.

### 🔍 What is an Array?
An array is a collection of elements (of the same data type) stored contiguously in memory and accessed using an index.

## 📌 Key Characteristics:
Fixed size

Indexed access (0-based in C)

Static memory allocation

## 🛠️ Array Declaration and Initialization in C

// Declaration
int numbers[5];

// Initialization
int marks[5] = {90, 85, 75, 88, 92};

## ✅ Basic Operations on Arrays

| Operation     | Description                                | Code Snippet Example                       |
| ------------- | ------------------------------------------ | ------------------------------------------ |
| **Traversal** | Access all elements in order               | `for(i=0; i<n; i++) printf("%d", arr[i]);` |
| **Insertion** | Insert at specific position (shift needed) | Use loop to shift elements right           |
| **Deletion**  | Remove from specific index (shift left)    | Use loop to shift elements left            |
| **Searching** | Find an element by value (linear/binary)   | `if (arr[i] == key)`                       |
| **Updating**  | Modify value at a given index              | `arr[index] = new_value;`                  |

## 📦 Types of Arrays

| Type                       | Description                      |
| -------------------------- | -------------------------------- |
| **1D Array**               | Single row or column of elements |
| **2D Array**               | Matrix form (rows × columns)     |
| **Multidimensional Array** | 3D or higher nested arrays       |

## 📘 Real-Life Applications of Arrays

| Use Case             | Example                               |
| -------------------- | ------------------------------------- |
| **Student Grades**   | Store and process test scores         |
| **Image Processing** | Represent pixel data in 2D array      |
| **Data Tables**      | Represent rows and columns in a table |
| **Sensor Data**      | Store sequential sensor readings      |

## 📎 Summary

Arrays are simple yet powerful.

Efficient for random access, but not for dynamic resizing.

Mastering arrays is key to understanding more advanced data structures like linked lists, stacks, and queues.
