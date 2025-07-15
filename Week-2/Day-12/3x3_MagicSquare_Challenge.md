### 🧠 Magic square puzzle
 
 Fill a 3x3 matrix with numbers between 11 and 19 such that:

Each row, column, and diagonal sums to 45.

This is essentially a magic square, but with a custom number range: 11 to 19.

🎯 Step 1: Understand the constraints
Matrix size: 3×3 = 9 cells

Valid numbers: 11–19 inclusive ⇒ Total 9 numbers:
11, 12, 13, 14, 15, 16, 17, 18, 19

No repeats allowed.

Magic square condition: all rows, columns, and diagonals sum to 45

🔢 Step 2: Total sum check
If each row sums to 45, and there are 3 rows, the total matrix sum =
45 × 3 = 135

Let’s check sum of all numbers from 11 to 19:

11 + 12 + 13 + 14 + 15 + 16 + 17 + 18 + 19 = (11 + 19) * 9 / 2 = 135

✅ Total adds up correctly — this confirms that the set can form a valid magic square!

✨ Step 3: Create the Magic Square

┌────┬────┬────┐
│ 18 │ 11 │ 16 │
├────┼────┼────┤
│ 13 │ 15 │ 17 │
├────┼────┼────┤
│ 14 │ 19 │ 12 │
└────┴────┴────┘

✅ Step 4: Verify all sums = 45

Rows:
Row 1: 18 + 11 + 16 = 45

Row 2: 13 + 15 + 17 = 45

Row 3: 14 + 19 + 12 = 45

Columns:
Col 1: 18 + 13 + 14 = 45

Col 2: 11 + 15 + 19 = 45

Col 3: 16 + 17 + 12 = 45

Diagonals:
18 + 15 + 12 = 45

16 + 15 + 14 = 45

✅ All sums are correct!

🎉 Final Answer
┌────┬────┬────┐
│ 18 │ 11 │ 16 │
├────┼────┼────┤
│ 13 │ 15 │ 17 │
├────┼────┼────┤
│ 14 │ 19 │ 12 │
└────┴────┴────┘
