int interpolation_search(int a[], int n, int target) {
    int left = 0;
    int right = n - 1;
    
    while ((left <= right) && (a[left] <= target) && (target <= a[right])) {

        // Verifica se os extremos são iguais, logo o que tem no meio é igual também
        if (a[right] == a[left]) {
            if (a[left] == target) {
                return 1;
            } else {
                return 0;
            }
        }

        // Interpolação - Lembrar de como calcula a temp em escalas diferentes
        int middle = left + (float)(right - left) * (target - a[left]) / (a[right] - a[left]);

        // Verificação se o target foi encontrado ou ajusta o índice
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