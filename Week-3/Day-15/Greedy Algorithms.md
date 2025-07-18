#  CRT Day 15 - Greedy Algorithms 

This repository contains compact implementations and explanations for classic greedy algorithm problems discussed in CRT training.

## ✅ Topics Covered

1. Early Start Time (Activity Selection)
2. Shortest Interval First
3. Minimum Overlaps
4. Greedy Coin Change
5. Fractional Knapsack Problem
6. Job Sequencing with Deadlines

---

## 🧠 Greedy Strategy Summary

- **Greedy algorithms** make locally optimal choices at each step hoping they lead to a globally optimal solution.
- Common in scheduling, optimization, and resource allocation problems.

---
## 🧩 early_start_time.c (Activity Selection - based on earliest start time)

#include <stdio.h>

#include <stdlib.h>

typedef struct {

    int start, end;
} Activity;

int cmp(const void *a, const void *b) {

    return ((Activity*)a)->start - ((Activity*)b)->start;
}

int main() {

    Activity arr[] = {{1, 3}, {2, 5}, {0, 6}, {6, 9}, {5, 7}};
    int n = sizeof(arr) / sizeof(arr[0]);

    qsort(arr, n, sizeof(Activity), cmp);
    printf("Activities selected based on early start:\n");
    printf("(%d, %d)\n", arr[0].start, arr[0].end);
    
    int last_end = arr[0].end;
    for (int i = 1; i < n; i++) {
        if (arr[i].start >= last_end) {
            printf("(%d, %d)\n", arr[i].start, arr[i].end);
            last_end = arr[i].end;
        }
    }
    return 0;
}

## 🧩 shortest_interval.c (Interval with shortest duration)

#include <stdio.h>

#include <stdlib.h>

typedef struct {

    int start, end;
} Interval;

int cmp(const void *a, const void *b) {

    Interval *x = (Interval*)a;
    Interval *y = (Interval*)b;
    return (x->end - x->start) - (y->end - y->start);
}

int main() {

    Interval arr[] = {{1, 4}, {2, 3}, {0, 6}, {5, 7}};
    int n = sizeof(arr)/sizeof(arr[0]);
    qsort(arr, n, sizeof(Interval), cmp);

    printf("Shortest intervals first:\n");
    for (int i = 0; i < n; i++)
        printf("(%d, %d)\n", arr[i].start, arr[i].end);

    return 0;
}

## 🧩 min_overlaps.c (Select max activities → min overlaps) 
// Same as activity selection by early finish time
#include <stdio.h>

#include <stdlib.h>

typedef struct {

    int start, end;
} Interval;

int cmp(const void *a, const void *b) {

    return ((Interval*)a)->end - ((Interval*)b)->end;
}

int main() {

    Interval arr[] = {{1, 3}, {2, 4}, {3, 5}, {0, 6}};
    int n = sizeof(arr)/sizeof(arr[0]);
    qsort(arr, n, sizeof(Interval), cmp);

    printf("Minimum Overlapping Activities:\n");
    int count = 1, end = arr[0].end;
    printf("(%d, %d)\n", arr[0].start, arr[0].end);

    for (int i = 1; i < n; i++) {
        if (arr[i].start >= end) {
            printf("(%d, %d)\n", arr[i].start, arr[i].end);
            end = arr[i].end;
            count++;
        }
    }
    return 0;
}

## 🧩 coin_change_greedy.c

#include <stdio.h>

int main() {

    int coins[] = {10, 5, 2, 1};
    int n = sizeof(coins)/sizeof(coins[0]);
    int amount = 93;

    printf("Coins used to make %d:\n", amount);
    for (int i = 0; i < n; i++) {
        while (amount >= coins[i]) {
            printf("%d ", coins[i]);
            amount -= coins[i];
        }
    }
    return 0;
}

## 🧩 fractional_knapsack.c

#include <stdio.h>
#include <stdlib.h>

typedef struct {

    int weight, profit;
    double ratio;
} Item;

int cmp(const void *a, const void *b) {

    return (((Item*)b)->ratio - ((Item*)a)->ratio) > 0 ? 1 : -1;
}

int main() {

    Item items[] = {{10, 60}, {20, 100}, {30, 120}};
    int n = 3, capacity = 50;
    double totalProfit = 0;

    for (int i = 0; i < n; i++)
        items[i].ratio = (double)items[i].profit / items[i].weight;

    qsort(items, n, sizeof(Item), cmp);

    for (int i = 0; i < n && capacity > 0; i++) {
        if (items[i].weight <= capacity) {
            totalProfit += items[i].profit;
            capacity -= items[i].weight;
        } else {
            totalProfit += items[i].ratio * capacity;
            break;
        }
    }

    printf("Maximum Profit: %.2f\n", totalProfit);
    return 0;
}

## 🧩 job_sequencing_deadline.c

#include <stdio.h>

#include <stdlib.h>

typedef struct {

    int id, deadline, profit;
} Job;

int cmp(const void *a, const void *b) {

    return ((Job*)b)->profit - ((Job*)a)->profit;
}

int main() {

    Job jobs[] = {{1, 2, 100}, {2, 1, 19}, {3, 2, 27}, {4, 1, 25}, {5, 3, 15}};
    int n = 5;
    int slot[100] = {0};  // max deadline = 100
    int totalProfit = 0;

    qsort(jobs, n, sizeof(Job), cmp);

    for (int i = 0; i < n; i++) {
        for (int j = jobs[i].deadline; j > 0; j--) {
            if (!slot[j]) {
                slot[j] = 1;
                totalProfit += jobs[i].profit;
                break;
            }
        }
    }

    printf("Maximum Profit from Jobs: %d\n", totalProfit);
    return 0;
}

