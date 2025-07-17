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

