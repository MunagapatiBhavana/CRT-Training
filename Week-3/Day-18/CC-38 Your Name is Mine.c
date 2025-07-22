#include <stdio.h>
#include <string.h>

int isSubsequence(char *a, char *b) {
    int i = 0, j = 0;
    while (a[i] != '\0' && b[j] != '\0') {
        if (a[i] == b[j]) {
            i++;
        }
        j++;
    }
    return (a[i] == '\0');  
}

int main() {
    int T;
    scanf("%d", &T);
    
    while (T--) {
        char M[25001], W[25001];
        scanf("%s %s", M, W);
        
        if (isSubsequence(M, W) || isSubsequence(W, M)) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    
    return 0;
}
