# 📘 Day 3 - CRT Training: 2D Arrays in C

Welcome to Day 3 of CRT Training! Today, we explore **2D Arrays** in C — how they work, how to access elements, and how to perform basic operations like printing, row sums, and column sums.

---

## 📚 What is a 2D Array?

A 2D array in C is like a table or matrix with rows and columns.  
It is declared as:

data_type array_name[rows][columns];

There are 2 types of arrays:
    Row Major Order - mostly used in C,C++,java programming languages
    Column Major Order - mostly used in PASCAL, FORTRAN

## Python used both RMO and CMO    
## RMO and CMO both are same but the memory allocation is different 

## Ex-1: Printing elements in RMO array

int a[3][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};

for(int i=0;i<3;i++){

  for(int j=0;j<4;j++){
  
    printf("%d", a[i][j]);
    
   }
}

## Ex-2: Sum of Each Row in an array


for(int i=0;i<m;i++){

  int sum=0;
  
  for(int j=0;j<n;j++){

    sum+= a[i][j];
    
   }
   
   printf("%d", sum);
   
}

## Ex-3: Sum of Each Column in an array

for(int j=0;j<n;j++){

  int sum=0;
  
  for(int i=0;i<m;i++){

    sum+= a[i][j];
    
   }
   
   printf("%d", sum);
   
}

## Ex-4: Transpose of a matrix

for(int j=0;j<n;j++){

  
  for(int i=0;i<m;i++){

     printf("%d", a[i][j]);
    
   }
   
   printf("\n");
}

## Ex-5: Rotate a matrix with 90 degrees clockwise direction

for(int j=0;j<n;j++){

  
  for(int i=m-1;i>=0;i--){

     printf("%d", a[i][j]);
    
   }
   
   printf("\n");
}

## Ex-6: Rotate a matrix with 180 degrees anti-clockwise direction

for(int i=n-1;i>=0;i++){

  for (int j=0;j<m;j++){
  
    printf("%d",a[i][j]);
    
    }
  }

  
