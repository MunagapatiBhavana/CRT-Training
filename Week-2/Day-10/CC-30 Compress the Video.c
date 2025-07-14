#include <stdio.h>

int main(void) {
	// your code goes here
	int t;
    scanf("%d", &t);
    while (t--) {
        int n, c = 0, p = 0, x;
        scanf("%d", &n);
        while (n--) {
            scanf("%d", &x);
            if (x != p) {
                p = x;
                c++;
            }
        }
        printf("%d\n", c);
    }
	return 0;
}

