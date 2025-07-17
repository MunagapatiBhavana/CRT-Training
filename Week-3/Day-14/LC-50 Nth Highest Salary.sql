Table: Employee

+-------------+------+
| Column Name | Type |
+-------------+------+
| id          | int  |
| salary      | int  |
+-------------+------+
id is the primary key (column with unique values) for this table.
Each row of this table contains information about the salary of an employee.
 

Write a solution to find the nth highest distinct salary from the Employee table. If there are less than n distinct salaries, return null.

## solution 

CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  RETURN (
    WITH
      RankedEmployees AS (
        SELECT *, DENSE_RANK() OVER(ORDER BY salary DESC) AS `rank`
        FROM Employee
      )
    SELECT MAX(salary) AS SecondHighestSalary
    FROM RankedEmployees
    WHERE `rank` = N
  );
END
