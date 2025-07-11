## 📘 README: Power Function Using Recursion and Bitwise Optimization

## 🔍 Introduction
The power function computes 
𝑎
𝑏
a 
b
  (a raised to the power b).
We can calculate it using different techniques:

Simple recursion

Optimized divide-and-conquer

Bitwise operations for efficiency

## 🧮 Method 1: Simple Recursion

int power(int a, int b) {

    if (b == 0) return 1;
    return a * power(a, b - 1);
}

Base Case: 

𝑎^0 = 1
 
❌ Not efficient for large b due to high recursion depth.

## ⚡ Method 2: Optimized Recursion (Exponentiation by Squaring)

int powerOptimized(int a, int b) {

    if (b == 0) return 1;
    int temp = powerOptimized(a, b / 2);
    if (b % 2 == 0)
        return temp * temp;
    else
        return a * temp * temp;
}

Reduces the number of multiplications to O(log b)

Uses divide-and-conquer

✅ Great for performance

## 🧠 Method 3: Using Bitwise Operators (Right Shift)

int powerBitwise(int a, int b) {

    int result = 1;
    while (b > 0) {
        if (b & 1) { // If b is odd
            result *= a;
        }
        a *= a;
        b >>= 1; // Divide b by 2
    }
    return result;
}

Uses:

b & 1 to check if b is odd

b >>= 1 (right shift) to divide exponent by 2

Fastest iterative approach

🚀 Very efficient — avoids recursion completely

## ⏱ Time Complexity Comparison
| Method                   | Time Complexity |
| ------------------------ | --------------- |
| Simple Recursion         | O(b)            |
| Optimized Recursion      | O(log b)        |
| Bitwise Iterative Method | O(log b)        |

## ✅ Summary
Use simple recursion for basic understanding or small exponents.

Use optimized recursion (logarithmic) for better performance.

Use bitwise method for the fastest, iterative approach without function calls.
