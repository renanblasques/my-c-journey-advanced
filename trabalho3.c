#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void insertion_sort(int v[], int n, int *swaps, int *comps);
void merge(int v[], int l, int m, int r, int *swaps, int *comps);
void merge_sort(int v[], int l, int r, int *swaps, int *comps);

int main() {
    int vec_qty, *vec_sizes;
    scanf("%d", &vec_qty);
    vec_sizes = (int *)malloc(vec_qty * sizeof(int));

    if (vec_sizes == NULL) {
        printf("Erro ao alocar memória para o vetor de tamanhos.\n");
        return 1;
    }

    for (int i = 0; i < vec_qty; i++) {
        int size;
        scanf("%d", &size);
        vec_sizes[i] = size;
    }

    for (int i = 0; i < vec_qty; i++) {
        int *v1 = (int *)malloc(vec_sizes[i] * sizeof(int));
        int *v2 = (int *)malloc(vec_sizes[i] * sizeof(int));
        int comps = 0, swaps = 0;

        if (v1 == NULL || v2 == NULL) {
            printf("Erro ao alocar memória para o vetor.\n");
            free(vec_sizes);
            return 1;
        }

        for (int j = 0; j < vec_sizes[i]; j++) {
            int elem;
            scanf("%d", &elem);
            v1[j] = elem;
            v2[j] = elem;
        }

        insertion_sort(v1, vec_sizes[i], &swaps, &comps);
        printf("I %d %d %d\n", vec_sizes[i], swaps, comps);

        comps = swaps = 0;
        merge_sort(v2, 0, vec_sizes[i] - 1, &swaps, &comps);
        printf("M %d %d %d\n", vec_sizes[i], swaps, comps);

        free(v1);
        free(v2);
    }

    free(vec_sizes);

    return 0;
}

void insertion_sort(int v[], int n, int *swaps, int *comps) {
    for (int j = 1; j < n; j++) {
        int x = v[j];
        (*swaps)++;
        int i = j - 1;

        while (i >= 0) {
            (*comps)++;
            if (v[i] > x) {
                v[i + 1] = v[i];
                (*swaps)++;
                i--;
            } else {
                break;
            }
        }

        v[i + 1] = x;
        (*swaps)++;
    }
}

void merge(int v[], int l, int m, int r, int *swaps, int *comps) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int *tmp1 = (int *)malloc(n1 * sizeof(int));
    int *tmp2 = (int *)malloc(n2 * sizeof(int));

    if (tmp1 == NULL || tmp2 == NULL) {
        printf("Erro ao alocar memória.\n");
        return;
    }

    for (int i = 0; i < n1; i++) {
        tmp1[i] = v[l + i];
        (*swaps)++;
    }

    for (int i = 0; i < n2; i++) {
        tmp2[i] = v[m + 1 + i];
        (*swaps)++;
    }

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        (*comps)++;
        if (tmp1[i] <= tmp2[j]) {
            v[k++] = tmp1[i++];
        } else {
            v[k++] = tmp2[j++];
        }
        (*swaps)++;
    }

    while (i < n1) {
        v[k++] = tmp1[i++];
        (*swaps)++;
    }

    while (j < n2) {
        v[k++] = tmp2[j++];
        (*swaps)++;
    }

    free(tmp1);
    free(tmp2);
}

void merge_sort(int v[], int l, int r, int *swaps, int *comps) {
    if (l >= r) {
        return;
    }

    int m = (l + r) / 2;
    merge_sort(v, l, m, swaps, comps);
    merge_sort(v, m + 1, r, swaps, comps);

    merge(v, l, m, r, swaps, comps);
}
