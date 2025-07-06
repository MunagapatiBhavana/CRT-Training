Given an integer n, return the number of trailing zeroes in n!.

Note that n! = n * (n - 1) * (n - 2) * ... * 3 * 2 * 1.

 

Example 1:

Input: n = 3
Output: 0
Explanation: 3! = 6, no trailing zero.

int trailingZeroes(int n) {
    
    int count = 0;
    while(n>=5){
        n = n/5;
        count = count +n;
    }
    if(count == 0){
        printf("no trailing zero");
    }
    return count; 
    
}
