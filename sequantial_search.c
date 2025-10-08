int sequential_search(int a[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (a[i] == target) {
            return 1;
        }
    }
    return 0;
}

int ordered_search(int a[], int n, int target) {
    int i = 0;
    while (i < n && a[i] < target) {
        i++;
    }
    if (i < n && a[i] == target) {
        return 1;
    }
    return 0;
}

int sequential_search_ward(int a[], int n, int target) {
    int i = 0;
    a[n] = target;
    while (a[i] < target) {
        i++;
    }
    if (a[i] == target && i < n) {
        return 1;
    }
    return 0;
}