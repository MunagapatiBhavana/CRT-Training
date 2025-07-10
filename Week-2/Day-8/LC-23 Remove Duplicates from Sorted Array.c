int removeDuplicates(int* nums, int numsSize) {
    if (numsSize == 0)
        return 0;

    int i = 0; // index of unique elements
    for (int j = 1; j < numsSize; j++) {
        if (nums[j] != nums[i]) {
            i++;
            nums[i] = nums[j];
        }
    }
    return i + 1; // length of array with unique elements
}
