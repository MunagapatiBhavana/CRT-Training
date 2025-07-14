#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        int n, m, k;
        scanf("%d %d %d", &n, &m, &k);

        if (n == 1 && m > 2) {
            printf("%d\n", k);
        }
        else if (n > 2 && m == 1) {
            printf("%d\n", k);
        }
        else if (n == 1 && m <= 2) {
            printf("0\n");
        }
        else if (n <= 2 && m == 1) {
            printf("0\n");
        }
        else if (n >= 2 && m >= 2) {
            if (k % 2 == 0) {
                printf("%d\n", k / 2);
            } else {
                printf("%d\n", (k / 2) + 1);
            }
        }
    }

    return 0;
}

