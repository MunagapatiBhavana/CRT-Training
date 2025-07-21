#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
    int* intervalA = *(int**)a;
    int* intervalB = *(int**)b;
    return (intervalA[1] > intervalB[1]) - (intervalA[1] < intervalB[1]);
}

int findMinArrowShots(int** points, int pointsSize, int* pointsColSize) {
    if (pointsSize == 0) return 0;

    qsort(points, pointsSize, sizeof(int*), compare);

    int arrows = 1;  
    int end = points[0][1];  

    for (int i = 1; i < pointsSize; i++) {
        if (points[i][0] > end) {
            arrows++;
            end = points[i][1];  
        }
        
    }

    return arrows;
}
