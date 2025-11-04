#include <stdio.h>
#include <stdlib.h>

int binary_search(int vec[], int size_vec, int target);
void quick_sort(int v[], int f, int l);

int main() {
    int size_vec, *vec, n_searches, target;
    scanf("%d", &size_vec);

    vec = malloc(size_vec * sizeof(int));

    for (int i = 0; i < size_vec; i++) {
        scanf("%d", &vec[i]);
    }

    quick_sort(vec, 0, size_vec - 1);

    scanf("%d", &n_searches);

    for (int i = 0; i < n_searches; i++) {
        scanf("%d", &target);
        printf("%d\n", binary_search(vec, size_vec, target));
    }

    return 0;
}

int binary_search(int a[], int n, int target) {
    int left = 0;
    int right = n - 1;
    while (left <= right) {
        int middle = (left + right) / 2;

        if (target == a[middle])
            return 1;
        else if (target > a[middle])
            left = middle + 1;
        else
            right = middle - 1;
    }

    return 0;
}

void quick_sort(int v[], int f, int l) {
    if (f >= l) return;

    int m = (l + f) / 2;
    int pivot = v[m];
    int i = f;
    int j = l;
    
    while(1) {
        while(v[i] < pivot) i++;
        while(v[j] > pivot) j--;

        if (i >= j) break;

        int aux = v[i];
        v[i] = v[j];
        v[j] = aux;

        i++;
        j--;
    }

    quick_sort(v, f, j);
    quick_sort(v, j + 1, l);
}