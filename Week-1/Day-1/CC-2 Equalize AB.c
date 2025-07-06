#include <stdio.h>
#include <stdlib.h>  

int main() {
    int T;
    scanf("%d", &T);  

    while (T--) {
        long long A, B, X;
        scanf("%lld %lld %lld", &A, &B, &X);

        long long diff = llabs(A - B); 

        if (diff % (2 * X) == 0) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }

    return 0;
}

