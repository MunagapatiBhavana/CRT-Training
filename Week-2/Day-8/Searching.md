### 🔍 Day 8 - Searching Techniques

Today’s session focused on understanding various searching algorithms used to locate elements in arrays or lists. 

## 🔹 1. Linear Search
Definition: It checks each element one by one from the beginning until the desired element is found or the list ends.

int linearSearch(int arr[], int n, int key) {

    for (int i = 0; i < n; i++) {
        if (arr[i] == key)
            return i;  // found at index i
    }
    return -1;  // not found
}

Best Case: Element is at the first position → O(1)

Worst Case: Element is not present or at the last position → O(n)

Use When:

Data is unsorted

Dataset is small

Need simple implementation

## 🔹 2. Binary Search
Definition: Efficient search on sorted arrays by repeatedly dividing the search interval in half.

int binarySearch(int arr[], int n, int key) {

    int low = 0, high = n - 1;
    
    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == key)
            return mid;
        else if (key < arr[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;  // not found
}


Steps:

Compare the target value with the middle element.

If equal, return.

If less, search left subarray.

If more, search right subarray.

Time Complexity:

Best Case: Element is in the middle → O(1)

Worst/Average Case: O(log n)

Use When:

Array is sorted

Faster search is needed

## 🔹 3. Binary Search using Recursion
Same logic as binary search, but implemented using recursive calls instead of loops.

int binarySearchRecursive(int arr[], int low, int high, int key) {

    if (low > high)
        return -1;  // not found

    int mid = (low + high) / 2;

    if (arr[mid] == key)
        return mid;
    else if (key < arr[mid])
        return binarySearchRecursive(arr, low, mid - 1, key);
    else
        return binarySearchRecursive(arr, mid + 1, high, key);
}


Base case: start > end → not found

Mid check and recursive call on left or right half.

## 🔹 4. Interpolation Search
Definition: Improved binary search for uniformly distributed sorted data. Predicts position using formula:

pos = low+ (key−arr[low])×(high−low) / arr[high]−arr[low]

int interpolationSearch(int arr[], int n, int key) {

    int low = 0, high = n - 1;

    while (low <= high && key >= arr[low] && key <= arr[high]) {
        int pos = low + ((double)(high - low) / 
                         (arr[high] - arr[low])) * (key - arr[low]);

        if (arr[pos] == key)
            return pos;
        else if (arr[pos] < key)
            low = pos + 1;
        else
            high = pos - 1;
    }
    return -1;  // not found
}

 
Time Complexity:

Best/Average Case: O(log log n) for uniform data

Worst Case: O(n) (if data is non-uniform or badly distributed)

Use When:

Data is sorted and uniformly distributed

| Search Method        | Best Case | Worst Case | Data Type        | Use Case                           |
| -------------------- | --------- | ---------- | ---------------- | ---------------------------------- |
| Linear Search        | O(1)      | O(n)       | Unsorted/Sorted  | Small data, unsorted lists         |
| Binary Search        | O(1)      | O(log n)   | Sorted           | Fast search in sorted arrays       |
| Binary Search (Rec)  | O(1)      | O(log n)   | Sorted           | Recursive implementations          |
| Interpolation Search | O(1)      | O(n)       | Sorted (uniform) | Faster than binary in uniform data |
