void insertion_sort(int v[], int n) {
    for (int j = 1; j < n; j++) {
        int x = v[j];
        int i = j - 1;

        while ((i >= 0) && (v[i] > x)) {
            v[i + 1] = v[i];
            i--;
        }

        v[i + 1] = x;
    }
}