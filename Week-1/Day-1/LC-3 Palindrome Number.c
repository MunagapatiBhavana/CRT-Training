Given an integer x, return true if x is a palindrome, and false otherwise.

 

Example 1:

Input: x = 121
Output: true
Explanation: 121 reads as 121 from left to right and from right to left

bool isPalindrome(int x) {
    if(x<0){
        return false;
    }
    int original = x;
    long long reverse = 0;
    while(x!=0){
        int rem=x%10;
        reverse = reverse * 10 + rem;
        x = x/10;
    }    
    return original == reverse;

}
