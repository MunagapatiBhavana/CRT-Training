### 📘 Day-9: Sorting Algorithms in C 

## Continuation of Day-8

## 🔹 Quick Sort
Quick Sort is a divide-and-conquer algorithm. It picks a pivot and partitions the array such that:

Elements < pivot are on the left

Elements > pivot are on the right

Then it recursively sorts the subarrays.

## 🔸 Lomuto Partition Scheme (1 Index)

int partitionLomuto(int arr[], int low, int high) {

    int pivot = arr[high]; // Last element as pivot
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            // Swap arr[i] and arr[j]
            int temp = arr[i]; arr[i] = arr[j]; arr[j] = temp;
        }
    }
    // Swap arr[i+1] and pivot
    int temp = arr[i+1]; arr[i+1] = arr[high]; arr[high] = temp;
    return i + 1;
}

## 🔸 Hoare Partition Scheme (2 Indices)

int partitionHoare(int arr[], int low, int high) {

    int pivot = arr[low];
    int i = low - 1;
    int j = high + 1;

    while (1) {
        do { i++; } while (arr[i] < pivot);
        do { j--; } while (arr[j] > pivot);

        if (i >= j)
            return j;

        // Swap arr[i] and arr[j]
        int temp = arr[i]; arr[i] = arr[j]; arr[j] = temp;
    }
}

### ⚖️ When to Use Which:

| Partition Type   | Use Case             | Advantages   | Disadvantages                      |
| ---------------- | -------------------- | ------------ | ---------------------------------- |
| Lomuto (1 index) | Simpler to implement | Easy to code | Can perform poorly with duplicates |
| Hoare (2 index)  | Generally faster     | Fewer swaps  | Slightly trickier to implement     |

✅ Use Hoare when performance is key and input has many duplicate values.

✅ Use Lomuto for easier debugging or teaching.

### 🔹 Merge Sort
Merge Sort also uses divide-and-conquer and works by:

Dividing the array into two halves

Sorting each half recursively

Merging the sorted halves

void merge(int arr[], int l, int m, int r) {

    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];
    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
        arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(int arr[], int l, int r) {

    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

## 🔹 qsort() in C

qsort() is a built-in function in stdlib.h for quick sorting arrays.

## ✅ Syntax:

void qsort(void* base, size_t nitems, size_t size, int (*compar)(const void*, const void*));

## Example:

int compare(const void* a, const void* b) {

    return (*(int*)a - *(int*)b);
}

int main() {

    int arr[] = {4, 2, 6, 1, 5};
    int n = sizeof(arr)/sizeof(arr[0]);

    qsort(arr, n, sizeof(int), compare);

    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
}

## ⏱ Time Complexities

| Algorithm      | Best Case                                                | Average Case | Worst Case | Space Complexity | Stable |
| -------------- | -------------------------------------------------------- | ------------ | ---------- | ---------------- | ------ |
| Quick Sort     | O(n log n)                                               | O(n log n)   | O(n²)      | O(log n)         | ❌ No   |
| Merge Sort     | O(n log n)                                               | O(n log n)   | O(n log n) | O(n)             | ✅ Yes  |
| `qsort()` in C | Depends on implementation, often Quick Sort or IntroSort | O(n log n)   | O(n²)      | O(log n)         | ❌ No   |

## 🔹 Sample Code (Quick Sort with Lomuto)

void quickSort(int arr[], int low, int high) {

    if (low < high) {
        int pi = partitionLomuto(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

Use Quick Sort (Hoare) for performance on large datasets.

Use Merge Sort when stable sort is needed or in linked lists.

Use qsort() for quick sorting needs with minimal coding.

Understand partition logic well—choosing pivot and index strategy impacts performance.
