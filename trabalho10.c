#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DNA_LENGTH 1000

int overlap_value(char *left, char *right) {
    int left_size = strlen(left);
    int right_size = strlen(right);

    if (strstr(left, right) != NULL)
        return right_size;
    
    if (strstr(right, left) != NULL)
        return left_size;


    int min_size = left_size < right_size ? left_size : right_size;
    int overlap = 0;

    for (int k = 1; k <= min_size; k++) {
        int match = 1;

        for (int l = 0; l < k; l++) {
            if (left[left_size - k + l] != right[l]) {
                match = 0;
                break;
            }
        }

        if (match)
            overlap = k;
    }

    return overlap;
}

int main() {
    int n;
    scanf("%d", &n);

    char **reads = malloc(n * sizeof(char *));
    for (int i = 0; i < n; i++) {
        reads[i] = malloc(MAX_DNA_LENGTH * sizeof(char));
        scanf("%s", reads[i]);
    }

    while (n > 1) {
        int max_overlap = 0;
        int best_i = 0, best_j = 1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j)
                    continue;

                int current_overlap = overlap_value(reads[i], reads[j]);

                if (current_overlap > max_overlap) {
                    max_overlap = current_overlap;
                    best_i = i;
                    best_j = j;
                }
            }
        }

        char *merged;

        if (strstr(reads[best_i], reads[best_j]) != NULL) {
            merged = malloc(strlen(reads[best_i]) + 1);
            strcpy(merged, reads[best_i]);
        } else if (strstr(reads[best_j], reads[best_i]) != NULL) {
            merged = malloc(strlen(reads[best_j]) + 1);
            strcpy(merged, reads[best_j]);
        } else {
            int len = strlen(reads[best_i]) + strlen(reads[best_j]) - max_overlap;
            merged = malloc(len + 1);

            strcpy(merged, reads[best_i]);
            strcat(merged, reads[best_j] + max_overlap);
        }

        free(reads[best_i]);

        if (best_j != best_i)
            free(reads[best_j]);

        char **new_reads = malloc((n - 1) * sizeof(char *));
        new_reads[0] = merged;

        int k = 1;
        for (int i = 0; i < n; i++) {

            if (i == best_i || i == best_j)
                continue;

            new_reads[k] = reads[i];
            k++;
        }

        free(reads);
        reads = new_reads;
        n--;
    }

    printf("%s\n", reads[0]);

    free(reads[0]);
    free(reads);

    return 0;
}
