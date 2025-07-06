#include <stdio.h>

int isPowerOfTwo(int n) {
    return (n > 0) && ((n & (n - 1)) == 0);
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int A, B;
        scanf("%d %d", &A, &B);

        if (A == B) {
            printf("YES\n");
        } else {
            int max = (A > B) ? A : B;
            int min = (A < B) ? A : B;

            if (max % min == 0 && isPowerOfTwo(max / min)) {
                printf("YES\n");
            } else {
                printf("NO\n");
            }
        }
    }

    return 0;
}

