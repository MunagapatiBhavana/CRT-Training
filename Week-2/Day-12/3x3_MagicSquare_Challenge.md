# 🧠 Magic Square Puzzle: 3×3 Matrix Using Numbers 11–19

## 🎯 Objective

Fill a **3×3 matrix** using **each number from 11 to 19 exactly once**, such that the **sum of every row, column, and both diagonals** is exactly **45**.

---

## 📌 Step 1: Understand the Constraints

- Matrix size: **3×3 = 9 cells**
- Allowed numbers: **11 to 19** (inclusive)  
  Set of numbers: `11, 12, 13, 14, 15, 16, 17, 18, 19`
- **No duplicates allowed**
- Every:
  - Row
  - Column
  - Diagonal  
  must sum to **45**

---

## 🔢 Step 2: Total Sum Validation

Each row must sum to 45  
→ Total sum of the matrix = `45 × 3 = 135`

Now sum the numbers from 11 to 19:

Sum = (first + last) × count / 2
= (11 + 19) × 9 / 2
= 30 × 4.5 = 135


✅ The total adds up correctly. A valid magic square is possible using the given numbers.

---

## ✨ Step 3: Construct the Magic Square

We map a classic Lo Shu magic square (which uses 1–9) to our custom range (11–19):


**Mapped Magic Square (Final Answer):**

|     |     |     |
|-----|-----|-----|
| 18  | 11  | 16  |
| 13  | 15  | 17  |
| 14  | 19  | 12  |



---

## ✅ Step 4: Verify All Sums = 45

### Rows:
- Row 1: 18 + 11 + 16 = **45**
- Row 2: 13 + 15 + 17 = **45**
- Row 3: 14 + 19 + 12 = **45**

### Columns:
- Col 1: 18 + 13 + 14 = **45**
- Col 2: 11 + 15 + 19 = **45**
- Col 3: 16 + 17 + 12 = **45**

### Diagonals:
- Diagonal 1 (Top-left to bottom-right): 18 + 15 + 12 = **45**
- Diagonal 2 (Top-right to bottom-left): 16 + 15 + 14 = **45**

---

## 🏁 Conclusion

- ✔️ All numbers between 11 and 19 are used exactly once.
- ✔️ Every row, column, and diagonal sums to 45.
- ✔️ Valid magic square is successfully constructed!
