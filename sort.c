void selection_sort(int a[], int n) {
    for (int j = 0; j < n - 1; j++) {
        int m = j;
        for (int i = j + 1; i < n; i++) {
            if (a[i] < a[m]) {
                m = i;
            }
        }
        int tmp = a[j];
        a[j] = a[m];
        a[m] = tmp;
    }
}

void insertion_sort(int a[], int n) {
    for (int j = 1; j < n; j++) {
        int x = a[j];
        int i = j - 1;
        while (i >= 0 && a[i] > x) {
            a[i + j] = a[i];
            i--;
        }
        a[i + 1] = x;
    }
}

void bubble_sort(int a[], int n) {
    for (int i = n - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (a[j] > a[j + 1]) {
                int tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
            }
        }
    }
}

void bubble_sort_flag(int a[], int n) {
    int flag = 1;
    while (flag) {
        for (int i = 0; i < n - 1; i++) {
            flag = 0;
            if (a[i] > a[i + 1]) {
                int tmp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = tmp;
                flag = 1;
            }
        }
    }
}

void bubble_sort_ward(int a[], int n) {
    int i = n - 1;
    while (i > 0) {
        int u = -1;
        for (int j = 0; j < i; j++) {
            if (a[j] > a[j + 1]) {
                int tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
                u = j;
            }
        }
        i = u;
    }
}