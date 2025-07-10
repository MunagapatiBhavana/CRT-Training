## 🔃 Sorting Techniques

### 1. Insertion Sort
- **Logic**: Build the sorted list one item at a time by inserting each element into its correct position.
- **Time Complexity**:
  - Best Case: O(n) (already sorted)
  - Worst Case: O(n²)
 
    void insertionSort(int arr[], int n) {
    
    for (int i = 1; i < n; i++) {
    
        int key = arr[i];
        int j = i - 1;

        // Move elements greater than key one position ahead
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}


### 2. Selection Sort
- **Logic**: Repeatedly find the minimum element and move it to the beginning.
- **Time Complexity**:
  - Best/Worst Case: O(n²)

  void selectionSort(int arr[], int n) {
  
    for (int i = 0; i < n - 1; i++) {
  
        int minIndex = i;

        // Find the minimum element in the unsorted part
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }

        // Swap the found minimum with the first element
        if (minIndex != i) {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}


### 3. Bubble Sort
- **Logic**: Repeatedly swap adjacent elements if they are in the wrong order.
- **Time Complexity**:
  - Best Case: O(n) (optimized version)
  - Worst Case: O(n²)

void bubbleSort(int arr[], int n) {

    for (int i = 0; i < n - 1; i++) {
        int swapped = 0;

        // Compare adjacent elements and swap if needed
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }

        // Optimization: break if no swaps in a pass
        if (swapped == 0)
            break;
    }
}

📌 Note: If in bubble sort , the array is sorted in first pass itself then instead of going for unnecessary rotations we use this condition:

  if(swapcount==0){
  
  break;
  
  }

  Then if swapcount remains 0 then we stop the rotation of sorting.

---

## 📌 Summary Table

| Algorithm           | Best Case | Worst Case | Stable | In-Place | Use When                           |
|---------------------|-----------|-------------|--------|----------|------------------------------------|
| Linear Search        | O(1)      | O(n)        | ✅     | ✅        | Unsorted data                      |
| Binary Search        | O(1)      | O(log n)    | ❌     | ✅        | Sorted data                        |
| Interpolation Search | O(1)      | O(n)        | ❌     | ✅        | Sorted + Uniform data              |
| Insertion Sort       | O(n)      | O(n²)       | ✅     | ✅        | Nearly sorted small datasets       |
| Selection Sort       | O(n²)     | O(n²)       | ❌     | ✅        | When memory write is costly        |
| Bubble Sort          | O(n)      | O(n²)       | ✅     | ✅        | Educational/Small datasets         |

---
