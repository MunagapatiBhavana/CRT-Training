## JOINS

## 🔹 1. Left Outer Join
✅ Definition:
A Left Outer Join returns all records from the left table and the matched records from the right table. If there is no match, NULLs are returned for columns from the right table.

📘 Syntax:

SELECT *
FROM table1
LEFT OUTER JOIN table2
ON table1.common_column = table2.common_column;

## 🧪 Example:

``` 
Table: Employees  
+----+----------+
| ID | Name     |
+----+----------+
| 1  | Alice    |
| 2  | Bob      |
| 3  | Charlie  |
+----+----------+
```
``` 
Table: Salaries  
+----+--------+
| ID | Salary |
+----+--------+
| 1  | 50000  |
| 3  | 60000  |
+----+--------+
``` 
Query:
SELECT Employees.Name, Salaries.Salary
FROM Employees
LEFT OUTER JOIN Salaries ON Employees.ID = Salaries.ID;

## 🔎 Output:
``` 
+----------+--------+
| Name     | Salary |
+----------+--------+
| Alice    | 50000  |
| Bob      | NULL   |
| Charlie  | 60000  |
+----------+--------+
```
## 🔹 2. Right Outer Join
✅ Definition:
A Right Outer Join returns all records from the right table and the matched records from the left table. If there is no match, NULLs are returned for columns from the left table.

📘 Syntax:

SELECT *
FROM table1
RIGHT OUTER JOIN table2
ON table1.common_column = table2.common_column;

## 🧪 Example:

SELECT Employees.Name, Salaries.Salary
FROM Employees
RIGHT OUTER JOIN Salaries ON Employees.ID = Salaries.ID;

## 🔎 Output:
``` 
+----------+--------+
| Name     | Salary |
+----------+--------+
| Alice    | 50000  |
| Charlie  | 60000  |
+----------+--------+
```
## Note: 
(If Salary table had an unmatched ID, it would appear with NULL for Name.)

## 🔹 3. Full Outer Join
✅ Definition:
A Full Outer Join returns all records from both tables, and matches where possible. If there's no match on either side, NULLs will be placed for the missing side.

📘 Syntax:

SELECT *
FROM table1
FULL OUTER JOIN table2
ON table1.common_column = table2.common_column;

## 🧪 Example:

SELECT Employees.Name, Salaries.Salary
FROM Employees
FULL OUTER JOIN Salaries ON Employees.ID = Salaries.ID;

## 🔎 Output:
``` 
+----------+--------+
| Name     | Salary |
+----------+--------+
| Alice    | 50000  |
| Bob      | NULL   |
| Charlie  | 60000  |
+----------+--------+
```
## Note :

If Salary had extra rows (e.g., ID = 4), it would also appear with NULL for Name.

## ✅ Summary Table:
``` 

| Join Type        | Returns                                  |
| ---------------- | ---------------------------------------- |
| Left Outer Join  | All from left table + matched from right |
| Right Outer Join | All from right table + matched from left |
| Full Outer Join  | All records from both tables             |
```
