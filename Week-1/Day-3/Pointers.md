## 📚 What is a Pointer?

A **pointer** is a variable that refers to the **address of another variable**.

### 🔹 Declaration

int *ptr; // ptr is a pointer to an int

🧠 Pointer Terminology

| Term       | Meaning                             |
| ---------- | ----------------------------------- |
| `*ptr`     | Value stored at the address         |
| `&a`       | Address of variable `a`             |
| `ptr = &a` | Pointer `ptr` stores address of `a` |
| `*(&a)`    | Dereferencing the address of `a`    |

🔍 Identifier vs Variable

Identifier: Name given for refernce location which will not change

Variable: Stores the value which can change

✅ Every variable is an identifier

❌ But not every identifier is a variable

& - referencer

* - dereferencer

&a - address

*&a -  value

Property 1: Pointer access the address

Property 2: Pointer access the values also

Property 3: Using pointer we can change value of variable but not the address

Property 4: Pointer changes its reference location from one address to another

Property 5: 'n' no. of pointers can refer to same address

Property 6: When multiple pointers refering to same address, if one pointer changes the value then the other pointers gets updated value

Property 7: Pointer can access the array elements also acts as an array

## size of a pointer depends on the compiler

## Pointer Arithmetic

| Sl. No | Address updation     | value Updated    | Adress updation with value return              
| ------ | -------------------- | ---------------  | -------------------------------------- |
| 1️⃣    | `ptr++`              | (*ptr)++           | *ptr++         
| 2️⃣    | `++ptr;`             | ++ *ptr            |  *++ptr    
| 3️⃣    | `ptr--`             | (*ptr)--            | * p--           
| 4️⃣    | `--ptr`             | -- *ptr             |  * --p


## Two pointers participate only in the substraction

pointer 1 : p

pointer 2: q

q-p = addr(q) - addr(p) / sizeof datatype

To perform substraction in pointers, the data type shoule be same.

## Array Vs Pointer

Arrays allocate contiguous memory and their name acts as a fixed pointer to the first element (non-modifiable) -  static

Pointers are variables that can point anywhere and support arithmetic to traverse memory - dynamic

Arrays and pointers are closely related, but not interchangeable.

## Dynamic Memory Allocation - DMA

--> Memory allocation done at run time, in heap memory

malloc - memory allocation

  syntax: (void*)malloc (total size required)

calloc - contiguous allocation

  syntax: (void*)calloc (no.of elements, size of each element)

realloc - reallocation

  syntax: (void*)realloc (current pointer refernce, new memory required)

Deallocate memory: free(pointer)

## Dangling Pointer

    After deallocation of memory also if pointer points to the same address location , it is called dangling pointer.

Remedy for dangling pointer : Assign ptr=NULL

## How many multi dimensional pointers can we create?

There's no such limit we can create any number of multi dimensional pointers , but some articles say that we can create 11 multi dimensional pointers

