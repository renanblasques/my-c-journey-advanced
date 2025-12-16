#include <stdio.h>
#include <stdlib.h>

int find_best_way(int i, int j, int rows, int cols, int **right, int **down, int **cache) {
    if (cache[i][j] != -1)
        return cache[i][j];

    if (i == rows - 1 && j == cols - 1) {
        cache[i][j] = 0;
        return cache[i][j];
    }

    int best_way = 0;

    if (j + 1 < cols) {
        int new_way = right[i][j] + find_best_way(i, j + 1, rows, cols, right, down, cache);
        if (new_way > best_way)
            best_way = new_way;
    }

    if (i + 1 < rows) {
        int new_way = down[i][j] + find_best_way(i + 1, j, rows, cols, right, down, cache);
        if (new_way > best_way)
            best_way = new_way;        
    }

    cache[i][j] = best_way;

    return cache[i][j];
}

int main() {
    int rows, cols;
    scanf("%d %d", &rows, &cols);

    int **right = malloc(rows * sizeof(int *));
    int **down = malloc(rows * sizeof(int *));
    int **cache = malloc(rows * sizeof(int *));

    for (int i = 0; i < rows; i++) {
        right[i] = calloc(cols, sizeof(int));
        down[i] = calloc(cols, sizeof(int));
    }

    for (int i = 0; i < rows; i++) {
        cache[i] = malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++)
            cache[i][j] = -1;
    }

    int horizontal_streets = rows * (cols - 1);
    int vertical_streets = cols * (rows - 1);
    int total_streets = horizontal_streets + vertical_streets;

    for (int k = 0; k < total_streets; k++) {
        int start, end, friends;
        scanf("%d %d %d", &start, &end, &friends);

        int start_i = start / cols;
        int start_j = start % cols;
        int end_i = end / cols;
        int end_j = end % cols;

        if (start_i == end_i && start_j + 1 == end_j)
            right[start_i][start_j] = friends;
        else if (start_i + 1 == end_i && start_j == end_j)
            down[start_i][start_j] = friends;

        }

    int answer = find_best_way(0, 0, rows, cols, right, down, cache);
    printf("%d\n", answer);

    for (int i = 0; i < rows; i++) {
        free(right[i]);
        free(down[i]);
        free(cache[i]);
    }

    free(right);
    free(down);
    free(cache);
        
    return 0;
}