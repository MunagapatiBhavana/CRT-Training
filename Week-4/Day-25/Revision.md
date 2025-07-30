# CRT Day-25 Final Day

# Revision of some concepts discussed in whole training period

## 1. Pattern Printing

### Right Triangle Number Patterns (1 to 15)

Example pattern printing in C:

```c
#include <stdio.h>

int main()
{
    int n,i,j,cur,f;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        for(j=0;j<=i;j++){
            if(j==0){
                cur=i+1;
                f=0;
            }
            else if(j%2==0){
                f=2*(i-j+1);
            }
            else{
                f=2*(n-i-1)+1;
                
            }
            int nxt=cur+f;
            printf("%d  ",nxt);
            cur=nxt;
        }
        printf("\n");
    }
  

    return 0;
}
```

# 2. DBMS SQL Queries
Basic Queries

Select all records:

SELECT * FROM table_name;

Select specific columns:

SELECT column1, column2 FROM table_name;

Where clause:

SELECT * FROM table_name WHERE condition;

Joins

Inner Join:
```
SELECT a.col1, b.col2
FROM table1 a
INNER JOIN table2 b ON a.id = b.id;
```
Left Join:
```
SELECT a.col1, b.col2
FROM table1 a
LEFT JOIN table2 b ON a.id = b.id;
```
# 3. Views
Create a view:
```
CREATE VIEW view_name AS
SELECT column1, column2
FROM table_name
WHERE condition;
```
Query the view:

SELECT * FROM view_name;

Drop a view:

DROP VIEW view_name;

# 4. PL/SQL Basics
PL/SQL block structure:
```
DECLARE
   -- variable declarations
BEGIN
   -- executable statements
EXCEPTION
   -- exception handling
END;
```
Example:
```
DECLARE
    v_total NUMBER(10);
BEGIN
    SELECT SUM(salary) INTO v_total FROM employees;
    DBMS_OUTPUT.PUT_LINE('Total Salary: ' || v_total);
END;
```
# 5. Other Important Concepts
Transaction Control Language (TCL): COMMIT, ROLLBACK, SAVEPOINT

Data Definition Language (DDL): CREATE, ALTER, DROP

Data Manipulation Language (DML): INSERT, UPDATE, DELETE
