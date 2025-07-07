# Day 5

---

## 🧠 Topics Covered

### 📌 1. Structures in C
- A **structure** is a user-defined data type that allows grouping variables of different types.
- 
- Syntax:
  ```c
  struct Book {
      char title[50];
      int pages;
      float price;
  };

### 📌 2. Structure Pointers

You can create a pointer to a structure to access members using -> operator.

struct Book b1 = {"C Programming", 300, 299.99};

struct Book *ptr = &b1;

printf("%s", ptr->title);

### 📌 3. Memory Allocation in C

| Function    | Description                                     | Initializes Memory | Use Case                                    |
| ----------- | ----------------------------------------------- | ------------------ | ------------------------------------------- |
| `malloc()`  | Allocates memory block                          | No                 | Dynamic allocation when size is known       |
| `calloc()`  | Allocates memory for array and initializes to 0 | Yes                | Safer when you want zero-initialized memory |
| `realloc()` | Reallocates memory                              | N/A                | Resizing dynamically allocated memory       |


### 📌 4. Structure Padding and Packing

Padding: The compiler may add empty bytes to align data in memory for performance reasons.

Packing: Disabling padding using compiler-specific directives (e.g., #pragma pack(1)).

Trade-off: Padding improves performance but increases memory usage; packing saves space but may reduce sp

### 📌 5. Singly Linked List (SLL)
➕ Insertion Operations:

void insertAtStart(int data) {

    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

void insertAtEnd(int data) {

    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

void insertAtPosition(int data, int pos) {

    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = data;

    if (pos == 1) {
        newNode->next = head;
        head = newNode;
        return;
    }

    struct Node* temp = head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) return;

    newNode->next = temp->next;
    temp->next = newNode;
}
