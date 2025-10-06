#include <stdio.h>

/*
 a -> vetor
 p -> posição do pai
 u -> última posição do vetor
*/

// Transforma um vetor em uma heap
void heapify(int a[], int p, int u) {
    int f = 2 * p + 1;             // Determina o primeiro filho
    if (f <= u) {                  // Verifica se o filho existe
        if (f + 1 <= u) {          // Verifica se tem outro filho
            if (a[f + 1] > a[f]) { // Verifica se o segundo filho é maior
                f++;               // Determina o filho principal
            }
        }
        if (a[p] < a[f]) {         // Verifica se o filho é maior
            int tmp = a[p];
            a[p] = a[f];
            a[f] = tmp;            // Troca o valor do pai e o filho maior
            heapify(a, f, u);      // Testa novamente, mas o pai agora é o filho
        }
    }
}

// Função do heap sort
void heap(int a[], int n) {
    // Passos até a primeira heap
    for (int i = n / 2; i >= 0; i--) {  // Do meio pra frente não tem filhos
        heapify(a, i, n - 1);
    }

    // A partir da primeira heap, troca e transforma o vetor em heap novamente
    for (int i = n - 1; i > 0; i--) {
        int tmp = a[i];
        a[i] = a[0];
        a[0] = tmp;
        heapify(a, 0, i - 1);      // i - 1 exclui o último elemento, que já é o maior
    }
}

int main() {
    int v[5] = {5, 4, 3, 2, 1};
    int n = 5;

    heap(v, n);

    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }

    return 0;
}