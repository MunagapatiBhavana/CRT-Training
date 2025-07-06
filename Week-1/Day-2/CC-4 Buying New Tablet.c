Chef decided to buy a new tablet. His budget is B
B, so he cannot buy a tablet whose price is greater than B
B. Other than that, he only has one criterion — the area of the tablet's screen should be as large as possible. Of course, the screen of a tablet is always a rectangle.

#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int N, B;
        scanf("%d %d", &N, &B);

        int maxArea = 0;
        for (int i = 0; i < N; i++) {
            int W, H, P;
            scanf("%d %d %d", &W, &H, &P);
            if (P <= B) {
                int area = W * H;
                if (area > maxArea) {
                    maxArea = area;
                }
            }
        }

        if (maxArea == 0) {
            printf("no tablet\n");
        } else {
            printf("%d\n", maxArea);
        }
    }

    return 0;
}
