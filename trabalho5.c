#include <stdio.h>
#include <stdlib.h>

void shell(int v[], int n, int *comps, int *copies);
void quick(int v[], int f, int l, int *comps, int *copies);

int main() {
    int n, *main_vector, **subvectors_quick, **subvectors_shell;
    scanf("%d", &n);

    main_vector = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf("%d", &main_vector[i]);
    }

    subvectors_quick = malloc(n * sizeof(int *));
    subvectors_shell = malloc(n * sizeof(int *));

    for (int i = 0; i < n; i++) {
        subvectors_quick[i] = malloc((i + 1) * sizeof(int));
        subvectors_shell[i] = malloc((i + 1) * sizeof(int));

        for (int j = 0; j <= i; j++) {
            subvectors_quick[i][j] = main_vector[j];
            subvectors_shell[i][j] = main_vector[j];
        }

        int comps_shell = 0, copies_shell = 0;
        int comps_quick = 0, copies_quick = 0;

        shell(subvectors_shell[i], (i + 1), &comps_shell, &copies_shell);
        quick(subvectors_quick[i], 0, i, &comps_quick, &copies_quick);

        int operations_shell = copies_shell + comps_shell;
        int operations_quick = copies_quick + comps_quick;

        if (operations_quick < operations_shell) {
            printf("Q ");
        } else if (operations_shell < operations_quick) {
            printf("S ");
        } else {
            printf("- ");
        }

        free(subvectors_quick[i]);
        free(subvectors_shell[i]);
    }

    free(subvectors_quick);
    free(subvectors_shell);
    free(main_vector);

    printf("\n");

    return 0;
}


void shell(int v[], int n, int *comps, int *copies) {
    int gap = 1;
    while(gap <= n) {
        gap *= 2;
    }
    gap = gap / 2 - 1;

    while(gap > 0) {
        for (int i = gap; i < n; i++){
            int x = v[i];
            (*copies)++;

            int j = i - gap;

            while(j >= 0 && v[j] > x) {
                (*comps)++;
                v[j + gap] = v[j];
                (*copies)++;
                j -= gap;
            }
            
            if (j >= 0) {
                 (*comps)++;
            }
            
            v[j + gap] = x;
            (*copies)++;
        }
        gap /= 2;
    }
}


void quick(int v[], int f, int l, int *comps, int *copies) {
    if (f >= l) {
        return;
    }

    int m = (l + f) / 2;
    int pivot = v[m];
    (*copies)++;
    
    int i = f;
    int j = l;

    while(1) {
        while(v[i] < pivot) {
            (*comps)++;
            i++;
        }
        (*comps)++;

        while(v[j] > pivot) {
            (*comps)++;
            j--;
        }
        (*comps)++;

        if (i >= j) {
            break;
        }

        int aux = v[i];
        v[i] = v[j];
        v[j] = aux;
        (*copies) += 3;

        i++;
        j--;
    }
    
    quick(v, f, j, comps, copies);
    quick(v, j + 1, l, comps, copies);
}