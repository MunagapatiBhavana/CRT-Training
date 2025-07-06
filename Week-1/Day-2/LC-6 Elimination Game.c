You have a list arr of all integers in the range [1, n] sorted in a strictly increasing order. Apply the following algorithm on arr:

Starting from left to right, remove the first number and every other number afterward until you reach the end of the list.
Repeat the previous step again, but this time from right to left, remove the rightmost number and every other number from the remaining numbers.
Keep repeating the steps again, alternating left to right and right to left, until a single number remains.
Given the integer n, return the last number that remains in arr.

 

Example 1:

Input: n = 9
Output: 6
Explanation:
arr = [1, 2, 3, 4, 5, 6, 7, 8, 9]
arr = [2, 4, 6, 8]
arr = [2, 6]
arr = [6]

int lastRemaining(int n) {
    int arr[50];
    while(n>1){
        int temp[1000];  // assuming max size won't exceed 1000
        int index = 0;
        
        for (int i = 1; i < n; i += 2) {
            temp[index++] = arr[i];
        }

        // Copy temp back to arr
        for (int i = 0; i < index; i++) {
            arr[i] = temp[i];
        }

        n = index;  // update size
    }

    return arr[n] % 10;  // last digit of the final remaining number
}


