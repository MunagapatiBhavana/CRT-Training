#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, x;
        scanf("%d %d", &n, &x);
        int N[n];
        for (int i = 0; i < n; i++) {
            scanf("%d", &N[i]);
        }

        int m = 0;
        for (int i = 0; i < n; i++) {
            if (N[i] < x) {
                m = i + 1;
            }
        }
        printf("%d\n", m);
    }
    return 0;
}
