# 📘 Day 1: Time Complexity

Welcome to **Day 1** of my DSA Learning Journey!  
Today’s focus: **Time Complexity** – a fundamental concept to evaluate how efficiently an algorithm performs as input size grows.

---

## 🧠 What is Time Complexity?

Amount of time taken for execution of program in a processor.
Time Complexity refers to how the time taken by an algorithm scales with input size `n`.  
It is expressed using **Big O Notation** such as:

- `O(1)` – Constant Time  
- `O(n)` – Linear Time  
- `O(n²)` – Quadratic Time  
- ...and more

### ✨ Why It's Important

- 🔍 **Compare** the efficiency of algorithms  
- ⚙️ **Optimize** code performance  
- 📈 **Predict** scalability as data grows  

---

## 📊 Common Time Complexities

| Big O        | Name         | Description                             | Example                        |
|--------------|--------------|-----------------------------------------|--------------------------------|
| `O(1)`       | Constant      | Executes in the same time always        | Access `arr[0]`                |
| `O(log n)`   | Logarithmic   | Cuts input in half each step            | Binary Search                  |
| `O(n)`       | Linear        | Grows proportionally with input size    | Loop through an array          |
| `O(n log n)` | Linearithmic  | Slightly worse than linear              | Merge Sort, Quick Sort         |
| `O(n²)`      | Quadratic     | Nested loops                            | Bubble Sort                    |
| `O(2ⁿ)`      | Exponential   | Doubles with each additional input      | Recursive Fibonacci            |
| `O(n!)`      | Factorial     | All permutations                        | Traveling Salesman Problem     |

---

## 🛍️ Story: Rahul at the Shopping Mall

Imagine Rahul is shopping in a massive mall to find a T-shirt. His actions reflect different time complexities:

- 🟢 **O(1)** – Walks into the first store and buys the first T-shirt.  
- 🔵 **O(n)** – Visits every store one by one before picking one.  
- 🟡 **O(log n)** – Uses a sorted mall directory to skip half the options each time.  
- 🔴 **O(n²)** – Compares every T-shirt in every store with every other to find the “best.” Overkill!

---

## 💻 Code Examples in C

### 🔹 O(1) – Constant Time
```c
#include <stdio.h>
int getFirst(int arr[]) {
    return arr[0];
}
int main() {
    int arr[] = {10, 20, 30, 40};
    printf("First element: %d\n", getFirst(arr));
    return 0;
}

🔹 O(n) – Linear Time

#include <stdio.h>
void printAll(int arr[], int size) {
    for(int i = 0; i < size; i++) {
        printf("%d\n", arr[i]);
    }
}
int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int size = sizeof(arr) / sizeof(arr[0]);
    printAll(arr, size);
    return 0;
}

🔹 O(log n) – Logarithmic Time (Binary Search)

#include <stdio.h>
int binarySearch(int arr[], int size, int key) {
    int low = 0, high = size - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}
int main() {
    int arr[] = {2, 4, 6, 8, 10, 12, 14};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 10;
    int result = binarySearch(arr, size, key);
    if (result != -1)
        printf("Element found at index %d\n", result);
    else
        printf("Element not found\n");
    return 0;
}

🔹 O(n²) – Quadratic Time

#include <stdio.h>
void allPairs(int arr[], int size) {
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            printf("(%d, %d)\n", arr[i], arr[j]);
        }
    }
}
int main() {
    int arr[] = {1, 2, 3};
    int size = sizeof(arr) / sizeof(arr[0]);
    allPairs(arr, size);
    return 0;
}

🧩 Tips to Improve Time Complexity
✅ Use hash maps for fast lookup instead of brute-force

🔁 Eliminate unnecessary nested loops

🔍 Prefer binary search on sorted data

⚙️ Choose efficient algorithms (e.g., Merge Sort > Bubble Sort)

🧠 Let’s Simplify It: Time vs Space
💡 Definitions:
Time Complexity → How long code takes to run

Space Complexity → How much memory (RAM) it uses

🚌 Story: Waiting for a Bus
Imagine you're at a bus stop trying to catch a specific bus. Your behavior shows different complexities:

🔴 O(n²) – Confused Passenger:
Checks every bus, asks every person. Overthinking and time-consuming.
⏱️ Takes a lot of time, 🧠 uses too much energy

🟢 O(n) – Careful Observer:
Checks each bus as it comes. Linear checking – practical and simple.

🟢 O(log n) – Smart Commuter:
Uses a bus-tracking app. Only waits when necessary and skips irrelevant buses. Very efficient.
| Scenario                   | Time  | Space | Technique Used    |
| -------------------------- | ----- | ----- | ----------------- |
| Brute-force search         | O(n²) | O(1)  | Nested loops      |
| Hash map for lookups       | O(n)  | O(n)  | Dictionary / Set  |
| Dynamic Programming (Memo) | O(n)  | O(n)  | Memoization table |

🧠 Trade-off: Faster algorithms may use more memory (e.g., caching, DP)

✅ Final Thoughts
Focus on algorithms with better time complexity

Good time complexity doesn't always mean low memory

Balance time vs space based on problem constraints

Think like Rahul, not the confused bus passenger 😉

