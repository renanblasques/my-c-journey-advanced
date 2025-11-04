#include <stdio.h>
#include <stdlib.h>

int main() {
    int cap = 0, num_insertions = 0, num_removes = 0, num_searches = 0;
    scanf("%d", &cap);

    int *hash_table_element = calloc(cap, sizeof(int));
    int *hash_table_marker = calloc(cap, sizeof(int));

    scanf("%d", &num_insertions);

    for (int i = 0; i < num_insertions; i++) {
        int value, pos, initial_pos;
        scanf("%d", &value);

        initial_pos = pos = value % cap;
        while (hash_table_marker[pos] == 1) {
            pos++;
            if (pos >= cap) pos = 0;
            if (initial_pos == pos) break;
        }

        if (hash_table_marker[pos] == 0) {
            hash_table_element[pos] = value;
            hash_table_marker[pos] = 1;
        }
    }

    scanf("%d", &num_removes);

    for (int i = 0; i < num_removes; i++) {
        int value, pos, initial_pos;
        scanf("%d", &value);

        initial_pos = pos = value % cap;
        while (hash_table_marker[pos] == 1) {
            if (hash_table_element[pos] == value) {
                hash_table_element[pos] = 0;
                hash_table_marker[pos] = -1;
                break;
            }
            pos++;
            if (pos >= cap) pos = 0;
            if (pos == initial_pos) break;
        }
    }

    scanf("%d", &num_searches);

    for (int i = 0; i < num_searches; i++) {
        int target, pos, initial_pos, found = 0, found_pos;
        scanf("%d", &target);

        initial_pos = pos = target % cap;
        while (hash_table_marker[pos] == 1) {
            if (hash_table_element[pos] == target) {
                found = 1;
                found_pos = pos;
                break;
            }
            pos++;
            if (pos >= cap) pos = 0;
            if (pos == initial_pos) {
                found = 0;
                break;
            }
        }

        if (found)
            printf("%d ", found_pos);
        else
            printf("%d ", -1);
    }
    printf("\n");

    free(hash_table_element);
    free(hash_table_marker);

    return 0;
}