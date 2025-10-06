// a -> vetor
// n -> tamanho do vetor
// k -> tamanho da tabela
#include <stdlib.h>

void counting(int a[], int n, int k) {
    // Inicializa vetor de contadores
    int *b = calloc(k, sizeof(int));
    if (b == NULL) return;

    // Conta em b quantidade de cada um dos valores
    for (int i = 0; i < n; i++) {
        b[a[i]]++;
    }

    int *p = malloc(k * sizeof(int));
    if (p == NULL) return;

    int s = 0;

    // Usa o b pra calcular a posição inicial final
    for (int i = 0; i < k; i++) {
        p[i] = s;
        s += b[i];
    }

    int *f = malloc(n * sizeof(int));
    if (f == NULL) return;

    // Usa a posição inicial final pra ordenar
    for (int i = 0; i < n; i++) {
        f[p[a[i]]] = a[i];
        p[a[i]]++;
    }

    // Traz pra posição original
    for (int i = 0; i < n; i++) {
        a[i] = f[i];
    }

    free(b);
    free(f);
}