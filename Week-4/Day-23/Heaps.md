# Day-23 Heaps

# Heaps: Binary Heap Deletion and Max‑Heapify

## 1. Binary Heap Tree — Deletion that yields a sorted array

### 🧠 Scenario:
You have a **binary heap** stored in array form (max‑heap or min‑heap).  
To sort elements via heap deletion:  
- Repeatedly **extract the root** (max or min) and place it into an output array.
- The remaining heap shrinks by swapping with the **last element**, then **heapify‑down** to restore order.

### Pseudocode: Extract‑One (for Max‑Heap)

```
EXTRACT_MAX(A):
if heap_size(A) < 1:
error "heap underflow"
max = A[1] // root value (1‑based)
A[1] = A[heap_size(A)]
heap_size(A) = heap_size(A) – 1
MAX_HEAPIFY(A, 1)
return max
```

## 2. Max‑Heapify Algorithm (Restore heap property)

### Definition:
Given an array `A[1…n]` and index `i`, assuming subtrees rooted at children of `i` are already heaps, `MAX_HEAPIFY(A, i)` ensures the subtree at `i` satisfies max‑heap property.

### Pseudocode (CLRS style; 1‑based indexing):
```
MAX_HEAPIFY(A, i):
l = 2 * i
r = 2 * i + 1
if l ≤ heap_size(A) and A[l] > A[i]:
largest = l
else:
largest = i
if r ≤ heap_size(A) and A[r] > A[largest]:
largest = r
if largest ≠ i:
swap A[i] with A[largest]
MAX_HEAPIFY(A, largest)
```

### Iterative version (0‑based):
```
MAX_HEAPIFY_ITER(A, i, heap_size):
while true:
left = 2i + 1
right = 2i + 2
largest = i
if left < heap_size and A[left] > A[largest]:
largest = left
if right < heap_size and A[right] > A[largest]:
largest = right
if largest == i:
break
swap A[i] ↔ A[largest]
i = largest
```

## 3. Building a Max‑Heap from an arbitrary array

Instead of inserting elements one by one (O(n log n)), use Floyd’s method (bottom‑up) in O(n):
```
BUILD_MAX_HEAP(A):
heap_size = length(A)
for i = floor(heap_size/2) downto 1:
MAX_HEAPIFY(A, i)
```

## 4. Summary Table
```
| Operation              | Steps                                                                      |
|------------------------|-----------------------------------------------------------------------------|
| **Delete root**        | Swap root with last, reduce size, call MAX_HEAPIFY at root                |
| **Max‑Heapify (recursive)** | Compare node with children, swap with largest and recurse              |
| **Max‑Heapify (iterative)** | Loop: find larger child, swap down until correct                      |
| **Build‑Max‑Heap**     | Run `MAX_HEAPIFY` from last non‑leaf down to root
```
