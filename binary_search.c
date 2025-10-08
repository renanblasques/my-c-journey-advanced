int binary_search(int a[], int n, int target) {
    int left = 0;
    int right = n - 1;
    while (left <= right) {
        int middle = (left + right) / 2;
        if (target == a[middle]) {
            return 1;
        } else if (target > a[middle]) {
            left = middle + 1;
        } else {
            right = middle - 1;
        }
    }
    return 0;
}