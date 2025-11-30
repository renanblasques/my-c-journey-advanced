#include <stdio.h>
#include <stdlib.h>

typedef struct corner {
    int down_value;
    struct corner *down_next;
    int right_value;
    struct corner *right_next;
} Corner;

int main() {
    int x, y;
    scanf("%d %d", &x, &y);
    Corner **corners;

    for (int i = 0; i < x; i++) {
        corners = malloc(x * sizeof(Corner*));
    }

    for (int j = 0; j < y; j++) {
        corners[j] = malloc(y * sizeof(Corner));
    }

    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {

        }
    }

    return 0;
}