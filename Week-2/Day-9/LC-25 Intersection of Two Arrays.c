#include <stdlib.h>
#include <stdbool.h>

bool exists(int* arr, int size, int value) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == value)
            return true;
    }
    return false;
}

int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int* result = (int*)malloc(sizeof(int) * (nums1Size < nums2Size ? nums1Size : nums2Size));
    int count = 0;

    for (int i = 0; i < nums1Size; i++) {
        for (int j = 0; j < nums2Size; j++) {
            if (nums1[i] == nums2[j]) {
                // Add only if not already added (to ensure unique values)
                if (!exists(result, count, nums1[i])) {
                    result[count++] = nums1[i];
                }
                break; // break to avoid counting duplicates from nums2
            }
        }
    }

    *returnSize = count;
    return result;
}
