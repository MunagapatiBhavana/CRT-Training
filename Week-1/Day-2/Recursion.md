# 🔁 Recursion in C

This repository demonstrates the concept of **Recursion** in C programming. Recursion is a powerful technique where a function calls itself to solve a smaller version of the original problem.

---

## 📌 What is Recursion?

**Recursion** is the process in which a function calls itself directly or indirectly. A recursive solution involves two main parts:

- **Base Case**: Stops the recursion.
- **Recursive Case**: Function calls itself with a smaller input.

---

## 🧠 Why Use Recursion?

- Simplifies code for problems like factorial, Fibonacci, tree traversal, etc.
- Solves problems by breaking them down into smaller subproblems.

---

## 🧪 Types of Recursion

| Type | Description | Example |
|------|-------------|---------|
| **1. Direct Recursion** | Function calls itself directly | `fun() { fun(); }` |
| **2. Indirect Recursion** | Function A calls B, and B calls A | `funA() { funB(); }` |
| **3. Tail Recursion** | Recursive call is the last statement in the function | `return fun(n-1);` |
| **4. Head Recursion** | Recursive call is made before any statements | `fun(n-1); print(n);` |
| **5. Tree Recursion** | Function calls itself more than once in the same call | `fun(n-1); fun(n-2);` |
| **6. Nested Recursion** | Function call is inside another recursive call | `fun(fun(n-1));` |

---

# 🔁 Recursion in C

This repository demonstrates the concept of **Recursion** in C programming. Recursion is a powerful technique where a function calls itself to solve a smaller version of the original problem.

---

## 📌 What is Recursion?

**Recursion** is the process in which a function calls itself directly or indirectly. A recursive solution involves two main parts:

- **Base Case**: Stops the recursion.
- **Recursive Case**: Function calls itself with a smaller input.

---

## 🧠 Why Use Recursion?

- Simplifies code for problems like factorial, Fibonacci, tree traversal, etc.
- Solves problems by breaking them down into smaller subproblems.

---

## 🧪 Types of Recursion

| Type | Description | Example |
|------|-------------|---------|
| **1. Direct Recursion** | Function calls itself directly | `fun() { fun(); }` |
| **2. Indirect Recursion** | Function A calls B, and B calls A | `funA() { funB(); }` |
| **3. Tail Recursion** | Recursive call is the last statement in the function | `return fun(n-1);` |
| **4. Head Recursion** | Recursive call is made before any statements | `fun(n-1); print(n);` |
| **5. Tree Recursion** | Function calls itself more than once in the same call | `fun(n-1); fun(n-2);` |
| **6. Nested Recursion** | Function call is inside another recursive call | `fun(fun(n-1));` |

---

## 🗂️ Files in this Repo

| File Name | Description |
|-----------|-------------|
| `factorial.c` | Factorial using recursion (Direct + Tail) |
| `fibonacci.c` | Fibonacci using recursion (Tree Recursion) |
| `indirect_recursion.c` | Example of Indirect Recursion |
| `nested_recursion.c` | Example of Nested Recursion |
| `sum_of_digits.c` | Sum of digits using Head Recursion |
| `reverse_number.c` | Reverse a number using recursion |

---


## 🧾 Example: Factorial Using Recursion


int factorial(int n) {

    if (n == 0)
        return 1; // Base case
    return n * factorial(n - 1); // Recursive case
}

## 🧾 Example: Fibonacci Using Recursion

#include <stdio.h>

int fibonacci(int n) {

    if (n == 0) 
        return 0;
    else if (n == 1)
        return 1;
    else
        return fibonacci(n - 1) + fibonacci(n - 2);
}

##  🧾 Example of Indirect Recursion 

#include <stdio.h>

void funA(int n);  // Forward declaration

void funB(int n);  // Forward declaration

void funA(int n) {

    if (n > 0) {
        printf("A: %d\n", n);
        funB(n - 1);  // Calls B
    }
}

void funB(int n) {

    if (n > 0) {
        printf("B: %d\n", n);
        funA(n / 2);  // Calls A
    }
}

##  🧾 Example of Nested Recursion 

int McCarthy91(int n) {

    if (n > 100)
        return n - 10;
    else
        return McCarthy91(McCarthy91(n + 11));
}

int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    int result = McCarthy91(num);
    printf("McCarthy91(%d) = %d\n", num, result);

    return 0;
}

## 🧾 Sum of digits using Head Recursion

void sumOfDigits(int n, int *sum) {

    if (n == 0)
        return;

    sumOfDigits(n / 10, sum);  // Recursive call first (head recursion)
    *sum += n % 10;            // Process digit after recursion returns
}

## 🧾 Reverse a number using recursion

int reverseNumber(int n, int rev) {

    if (n == 0)
        return rev;
    return reverseNumber(n / 10, rev * 10 + n % 10);
}

### 🌍 Real-Time Examples of Recursion

Mathematics: Factorials, Fibonacci series, GCD

Computer Science:

Tree/Graph Traversal

Tower of Hanoi

Backtracking Problems (Sudoku, N-Queens)

Operating Systems: Process hierarchy using recursive structures

File Systems: Recursive file/directory traversal
