# CRT - 24 String Algorithms

This repository contains well-documented C implementations of the **KMP (Knuth-Morris-Pratt)** pattern matching algorithm and the **Trie (Prefix Tree)** data structure. These are essential for efficient string processing tasks in coding interviews and competitive programming.

---

## 📘 1. KMP Algorithm

### 🔍 Problem Statement
Given a **pattern** and a **text**, find all occurrences of the pattern in the text efficiently.

### 🚀 Idea
KMP avoids rechecking characters by preprocessing the pattern using the **LPS (Longest Prefix Suffix)** array.

### ✅ Steps:
1. Compute the LPS array.
2. Use it to skip unnecessary comparisons during the search.

### 💻 C Code:

```c
#include <stdio.h>
#include <string.h>

void computeLPSArray(char* pat, int M, int* lps) {
    int len = 0;
    lps[0] = 0;

    int i = 1;
    while (i < M) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i++] = len;
        } else {
            if (len != 0)
                len = lps[len - 1];
            else
                lps[i++] = 0;
        }
    }
}

void KMPSearch(char* pat, char* txt) {
    int M = strlen(pat);
    int N = strlen(txt);

    int lps[M];
    computeLPSArray(pat, M, lps);

    int i = 0, j = 0;
    while (i < N) {
        if (pat[j] == txt[i]) {
            i++; j++;
        }

        if (j == M) {
            printf("Found pattern at index %d\n", i - j);
            j = lps[j - 1];
        } else if (i < N && pat[j] != txt[i]) {
            if (j != 0) j = lps[j - 1];
            else i++;
        }
    }
}

int main() {
    char txt[] = "ABABDABACDABABCABAB";
    char pat[] = "ABABCABAB";
    KMPSearch(pat, txt);
    return 0;
}
```

# 📘 2. Trie (Prefix Tree)
📖 Problem Statement
Efficient storage and lookup of a large set of strings (e.g., dictionary words).

🧠 Idea
Each node represents a character, and paths from the root to leaf nodes represent words.

✅ Common Operations:
Insert

Search

Prefix check

# 📌 Properties of Trie
```
| Property                 | Description                                                                                             |
| ------------------------ | ------------------------------------------------------------------------------------------------------- |
| **Tree-based structure** | Each node represents a character of a word.                                                             |
| **Root node**            | Represents an empty string.                                                                             |
| **Children**             | Each node can have up to 26 children (for lowercase English letters).                                   |
| **No duplicate keys**    | Each word is stored uniquely.                                                                           |
| **End of word marker**   | A boolean flag (`isEndOfWord`) indicates the end of a valid word.                                       |
| **Time Complexity**      | - Insert: O(L) <br> - Search: O(L) <br> - Prefix search: O(L), where L is the length of the word/prefix |
| **Space Complexity**     | Can be high for large datasets (can be optimized using Ternary Search Trees or Compressed Tries).       |
```
# ✅ Applications of Trie
```
| Application                              | Explanation                                                                             |
| ---------------------------------------- | --------------------------------------------------------------------------------------- |
| **1. Dictionary/Autocomplete Systems**   | Efficiently store and suggest words based on prefix (e.g., Google search autocomplete). |
| **2. Spell Checking**                    | Quickly verify whether a word exists in a dictionary.                                   |
| **3. IP Routing (Longest Prefix Match)** | Used in routers to match IP prefixes (common in networking).                            |
| **4. Word Games / Boggle Solver**        | Used to check if a word exists in a given character board.                              |
| **5. Pattern Matching**                  | Helps in string matching with wildcards or prefixes.                                    |
| **6. Search Engines**                    | Used for keyword suggestion and indexing.                                               |
| **7. Data Compression (e.g., LZW)**      | Trie-like structures are used for storing dictionary strings.                           |
| **8. Genome Sequencing**                 | Store and search for DNA/RNA sequences efficiently.                                     |
```
```
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define CHAR_SIZE 26

struct TrieNode {
    struct TrieNode* children[CHAR_SIZE];
    bool isEndOfWord;
};

struct TrieNode* createNode() {
    struct TrieNode* node = (struct TrieNode*)malloc(sizeof(struct TrieNode));
    node->isEndOfWord = false;
    for (int i = 0; i < CHAR_SIZE; i++)
        node->children[i] = NULL;
    return node;
}

void insert(struct TrieNode* root, const char* word) {
    struct TrieNode* curr = root;
    while (*word) {
        int index = *word - 'a';
        if (curr->children[index] == NULL)
            curr->children[index] = createNode();
        curr = curr->children[index];
        word++;
    }
    curr->isEndOfWord = true;
}

bool search(struct TrieNode* root, const char* word) {
    struct TrieNode* curr = root;
    while (*word) {
        int index = *word - 'a';
        if (curr->children[index] == NULL)
            return false;
        curr = curr->children[index];
        word++;
    }
    return curr != NULL && curr->isEndOfWord;
}

int main() {
    struct TrieNode* root = createNode();

    insert(root, "hello");
    insert(root, "world");

    printf("%s\n", search(root, "hello") ? "Found" : "Not Found");
    printf("%s\n", search(root, "hell") ? "Found" : "Not Found");
    return 0;
}
```

