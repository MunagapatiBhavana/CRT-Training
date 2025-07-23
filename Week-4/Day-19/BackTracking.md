# 📘 CRT Day 19: Backtracking & DP Problems
# 🚀 Topics Covered:
Placing 1–25 in 5×5 matrix using horse (knight's) moves

Maximum sum sub-square using DP

When to apply Backtracking

Backtracking vs Brute Force

Rat in a Maze problem

N-Queens problem

Meaningful word after removing each letter

# 1. 🐴 Knight's Tour with Numbers 1–25 in a 5×5 Matrix (Backtracking)
🔍 Problem:
Fill a 5×5 board with numbers 1 to 25 using only knight's moves like in chess.

💡 Approach:
Start at any cell (commonly top-left).

Move in all 8 possible knight moves recursively.

Mark visited positions and backtrack if stuck.

💻 Code Logic:

// Use backtracking with 8 knight moves

// For each move, check bounds and unvisited status

// Base case: if number == 25, print solution

# 2. 🧮 Maximum Sum Sub-square (DP)
🔍 Problem:
Find the maximum sum sub-square of size k x k in a matrix using Dynamic Programming.

💡 Approach:
Precompute sums in a prefix-sum matrix.

Use precomputed sums to find sub-square sums in O(1) time.

💻 Code Logic:

// Build prefixSum[i][j] = sum of matrix[0..i][0..j]

// For each sub-square of size k, compute:

// sum = prefix[x2][y2] - prefix[x1-1][y2] - prefix[x2][y1-1] + prefix[x1-1][y1-1]

# 3. ❓ When to Apply Backtracking
✅ Use Backtracking When:
The solution is built incrementally.

You need all valid configurations (not just one).

Constraints are present (e.g., no overlapping, must be valid moves).

Exponential possibilities that need pruning.

Examples: N-Queens, Sudoku, Maze Problems, Word reductions.

# 4. 🔁 Backtracking vs Brute Force
| **Brute Force**          | **Backtracking**                |
| ------------------------ | ------------------------------- |
| Tries *all* combinations | Prunes invalid paths early      |
| High time complexity     | More optimized with constraints |
| Simple logic             | Requires recursive structure    |

# 5. 🐀 Rat in a Maze (Backtracking)
💡 Idea:
Move only right or down (or 4 directions if allowed).

Mark visited, explore path, and backtrack if stuck.

# 6. 👑 N-Queens Problem
💡 Idea:
Place one queen per row.

Backtrack if column or diagonal conflict occurs.

# 7. ✂️ Word Reduction: Remove One Letter at a Time to Get Valid Word
🔍 Problem:
Given a word like "startling", remove one letter at a time to still form a valid word at each stage.

Example Path:

startling → starting → staring → string → sting → sing → sin → in → i
💡 Approach (Backtracking):
At each step, remove one letter and check if resulting word is valid.

Continue recursively until 1 letter remains and is still valid.

✅ Code Logic in C:

// Step 1: Store a dictionary of valid words (array or hash set).

// Step 2: Write a recursive function:

//         - Base case: length == 1 and word is valid → print path

//         - Try removing each letter, form new word, check validity

// Step 3: Backtrack on invalid branches

🔣 Sample Dictionary for Demo:

"startling", "starting", "staring", "string", "sting", "sing", "sin", "in", "i"

✅ Example C Backtracking Snippet:
```
void backtrack(char *word, char path[][20], int depth) {
    if (strlen(word) == 1 && is_valid(word)) {
        strcpy(path[depth], word);
        for (int i = depth; i >= 0; i--)
            printf("%s\n", path[i]);
        return;
    }

    if (!is_valid(word)) return;

    strcpy(path[depth], word);

    for (int i = 0; i < strlen(word); i++) {
        char next[20];
        strcpy(next, word);
        memmove(&next[i], &next[i+1], strlen(next) - i);
        backtrack(next, path, depth + 1);
    }
}
```
