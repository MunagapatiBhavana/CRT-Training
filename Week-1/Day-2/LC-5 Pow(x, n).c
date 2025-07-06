Implement pow(x, n), which calculates x raised to the power n (i.e., xn).

 

Example 1:

Input: x = 2.00000, n = 10
Output: 1024.00000

double myPow(double x, int n) {
    long long power = n;
    double result = 1.0;

    if (power < 0) {
        x = 1 / x;
        power = -power;
    }

    while (power > 0) {
        if (power % 2 == 1) result *= x;
        x *= x;
        power /= 2;
    }

    return result;
}

