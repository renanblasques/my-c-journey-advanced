void quick_rec(int a[], int c, int f) {
    if (c >= f) {
        return;
    }

    int m = (c + f) / 2;
    int p = a[m];

    int i = c;
    int j = f;

    while (1) {
        while (a[i] < p) {
            i++;
        }
        while (a[j] > p) {
            j--;
        }
        if (i >= j) {
            break;
        }

        int t = a[i];
        a[i] = a[j];
        a[j] = t;
        i++;
        j--;
    }

    quick_rec(a, c, j);
    quick_rec(a, j + 1, f);
}

void quick(int a[], int n) {
    quick_rec(a, 0, n - 1);
}