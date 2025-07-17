# 📚 CRT Training – Day 14 SQL Concepts

Today we covered advanced SQL commands and functions used for modifying table structures, managing data, access control, and handling nulls and values. Below is a summary of each concept with examples.

---

## 🔧 ALTER TABLE

Used to modify the structure of an existing table.

### ➕ Add a column:

ALTER TABLE employees ADD age INT;

## 📝 Modify a column:

ALTER TABLE employees MODIFY age VARCHAR(10);

## ❌ Drop a column:

ALTER TABLE employees DROP COLUMN age;

## 🔁 Rename a column:

ALTER TABLE employees RENAME COLUMN old_name TO new_name;

## 🗑️ DROP Command

Used to delete entire tables or objects permanently.

DROP TABLE employees;

## 🕒 FLASHBACK (Oracle only)
Used to restore a dropped table from the recycle bin.

FLASHBACK TABLE employees TO BEFORE DROP;

## 🚯 PURGE
Used to permanently delete a dropped table from the recycle bin.

PURGE TABLE employees;

## 🧹 DELETE vs. TRUNCATE vs. DROP

| Command  | Deletes Data | Removes Structure | Can be Rolled Back | Uses WHERE |
| -------- | ------------ | ----------------- | ------------------ | ---------- |
| DELETE   | ✅            | ❌                 | ✅                  | ✅          |
| TRUNCATE | ✅ (all rows) | ❌                 | ❌                  | ❌          |
| DROP     | ✅            | ✅                 | ❌                  | ❌          |

DELETE FROM employees WHERE department = 'HR';

## ✏️ UPDATE
Used to modify existing data.

UPDATE employees
SET salary = 50000
WHERE id = 101;

## 🔐 DCL Commands – GRANT and REVOKE
✅ GRANT
Gives privileges to a user.

GRANT SELECT, INSERT ON employees TO user_name;

## 🚫 REVOKE
Takes away privileges.

REVOKE INSERT ON employees FROM user_name;

## 💡 NVL Function (Oracle)
Replaces NULL with a default value.

SELECT NVL(commission, 0) FROM employees;

## 🧮 DUAL Table
A special one-row table used for functions and expressions in Oracle.

SELECT SYSDATE FROM DUAL;
SELECT 5 + 3 FROM DUAL;

## 📈 MAX vs. GREATEST
🔢 MAX() – Aggregate function
Returns the maximum value from a column.

SELECT MAX(salary) FROM employees;

## 📊 GREATEST() – Value comparison
Returns the highest value among expressions.

SELECT GREATEST(10, 20, 5) FROM DUAL; -- Output: 20

| Concept      | Use Case                                  |
| ------------ | ----------------------------------------- |
| ALTER TABLE  | Modify table structure                    |
| DROP         | Permanently delete table/object           |
| FLASHBACK    | Recover dropped table                     |
| PURGE        | Permanently remove from recycle bin       |
| DELETE       | Remove specific records                   |
| UPDATE       | Change existing data                      |
| GRANT/REVOKE | Control user access                       |
| NVL          | Handle NULL values                        |
| DUAL         | Use expressions/functions without a table |
| MAX/GREATEST | Compare values and columns                |


## 📅  Date Functions

SQL provides several functions to manipulate and extract information from date values.

### 🔹 Common Date Functions
| Function        | Description                             | Example                           |
|----------------|-----------------------------------------|-----------------------------------|
| `CURRENT_DATE`  | Returns the current system date         | `SELECT CURRENT_DATE;`            |
| `NOW()`         | Returns current date and time           | `SELECT NOW();`                   |
| `EXTRACT()`     | Extract part of a date (year, month...) | `SELECT EXTRACT(YEAR FROM order_date) FROM orders;` |
| `DATE_ADD()`    | Adds interval to a date                 | `SELECT DATE_ADD('2023-01-01', INTERVAL 7 DAY);`     |
| `DATEDIFF()`    | Days between two dates                  | `SELECT DATEDIFF('2023-08-01', '2023-07-01');`        |

---

## 🔄  Date Conversion Functions

Used to convert string to date and vice versa.

### 🔹 Examples

-- Convert string to date
SELECT STR_TO_DATE('24-07-2024', '%d-%m-%Y');

-- Format date into string
SELECT DATE_FORMAT(NOW(), '%W, %d %M %Y');  -- Output: Wednesday, 24 July 2024

##  HAVING Clause
Used to filter groups after applying aggregate functions (unlike WHERE which filters rows before grouping).

SELECT department, COUNT(*) AS employee_count
FROM employees
GROUP BY department
HAVING COUNT(*) > 5;

## 🔁 Nested Queries (Subqueries)
A query within another query. Can be used in SELECT, FROM, or WHERE clauses.

## 🔹 Example: Subquery in WHERE

SELECT name
FROM employees
WHERE salary > (SELECT AVG(salary) FROM employees);

## 🔹 Example: Subquery in FROM

SELECT dept, avg_sal
FROM (
  SELECT department AS dept, AVG(salary) AS avg_sal
  FROM employees
  GROUP BY department
) AS dept_avg;

## ⚖️  Multi-Row Operators
Used to compare a value with a set of values from a subquery.

🔹 Operators
IN

ANY

ALL

## 🔹 Example: IN

SELECT name
FROM employees
WHERE department_id IN (SELECT department_id FROM departments WHERE location = 'Bangalore');

## 🔹 Example: > ANY

SELECT name
FROM employees
WHERE salary > ANY (SELECT salary FROM employees WHERE department = 'HR');

## 🔢 6. ROWNUM / ROW_NUMBER()
🔹 ROWNUM (Oracle-specific)
Returns a number indicating the order of returned rows.

SELECT *
FROM (
  SELECT * FROM employees
)
WHERE ROWNUM <= 5;

## 🔹 ROW_NUMBER() (SQL standard)
Assigns a unique number to each row within a result set.

SELECT name, salary,
  ROW_NUMBER() OVER (ORDER BY salary DESC) AS row_num
FROM employees;

| Concept                | Used For                                 |
| ---------------------- | ---------------------------------------- |
| Date Functions         | Extracting, formatting, comparing dates  |
| Date Conversion        | Changing between string and date formats |
| HAVING Clause          | Filtering after aggregation              |
| Nested Queries         | Creating layered logic                   |
| Multi-Row Operators    | Comparing values with subquery results   |
| ROWNUM / ROW\_NUMBER() | Row-level ordering and filtering         |
