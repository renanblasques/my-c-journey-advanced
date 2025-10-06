#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void read_numbers(int v[], int n) {
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }
}

void list_numbers(int v[], int n) {
    if (v == NULL) {
        printf("Não há elementos no vetor para listar!\n");
        return;
    }

    for (int i = 0; i < n - 1; i++) {
        printf("%d ", v[i]);
    }
    printf("%d\n", v[n - 1]);
}

void selection_sort(int v[], int n) {
    if (v == NULL) {
        printf("Não há elementos no vetor para ordenar!\n");
        return;
    }

    for (int i = 0; i < n - 1; i++) {
        int smallest = i;
        for (int j = i + 1; j < n; j++) {
            printf("C %d %d\n", smallest, j);
            if (v[j] < v[smallest]) {
                smallest = j;
            }
        }
        printf("T %d %d\n", i, smallest);
        int tmp = v[i];
        v[i] = v[smallest];
        v[smallest] = tmp;
    }
}

void bubble_sort(int v[], int n) {
    if (v == NULL) {
        printf("Não há elementos no vetor para ordenar!\n");
        return;
    }

    int i = n - 1;
    while (i > 0) {
        int u = -1;
        for (int j = 0; j < i; j++) {
            printf("C %d %d\n", j, j + 1);
            if (v[j] > v[j + 1]) {
                printf("T %d %d\n", j, j + 1);
                int tmp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = tmp;
                u = j;
            }
        }
        i = u;
    }
}

int main() {
    char sort_type[10];
    int n, *v;
    scanf("%s", sort_type);
    scanf("%d", &n);
    v = (int *) malloc(n * sizeof(int));

    read_numbers(v, n);

    if (strcmp(sort_type, "selecao") == 0) {
        selection_sort(v, n);
    } else if (strcmp(sort_type, "bolha") == 0) {
        bubble_sort(v, n);
    } else {
        printf("Ordenação inválida!\n");
        return 1;
    }

    list_numbers(v, n);
    free(v);

    return 0;
}