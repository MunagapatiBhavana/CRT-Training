
# 📘 Day 4 - Strings and Character Arrays in C

## 🧵 Topics Covered

### ✅ Basic Differences
- Difference between `string` and `character array`

### ✅ String Functions
- `strlen()` – Get the length of a string
- `strcpy()` – Copy one string to another
- `strcpy()` with limit
- `strcat()` – Concatenate two strings
- `strcat()` with limit
- `strcmp()` – Compare two strings
- `strcmpi()` – Compare strings (case-insensitive)
- `strrev()` – Reverse a string
- `strupr()` – Convert string to uppercase
- `strlwr()` – Convert string to lowercase
- `strchr()` – Find character in string
- `strstr()` – Find substring in string

### ✅ String Concepts
- Lexicographical order (e.g., comparing `a7b5c4`)
- Tokenization (`strtok()` function)
- Regular Expressions
  - `[a-z]`, `[A-Z]`, `[abc]`

### ✅ String Programs
- `isPalindrome()` – Check if string is a palindrome
- Anagram – Check if two strings are anagrams
- Pangram – Check if a string contains every letter of the alphabet

---

## 💡 Notes

- Functions like `strupr`, `strlwr`, and `strrev` are non-standard and may not work in GCC without custom implementation.
- Always include `#include <string.h>` and `#include <ctype.h>` where necessary.
- Be cautious with buffer overflow – prefer using bounded versions like `strncpy`, `strncat`.

---

## 📌 Example

```c
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char str1[] = "Hello";
    char str2[] = "hello";

    if (strcmpi(str1, str2) == 0)
        printf("Strings are equal (case-insensitive).\n");
    else
        printf("Strings are not equal.\n");

    return 0;
}
```

---

## 🗂️ Practice Tasks
- Write your own `strcmpi()` function.
- Implement a custom `strrev()` if your compiler doesn't support it.
- Create programs to check for palindrome, anagram, and pangram.

---

## 🛠️ Tools Used
- C Language
- GCC / Turbo C
- VS Code / Code::Blocks

---
