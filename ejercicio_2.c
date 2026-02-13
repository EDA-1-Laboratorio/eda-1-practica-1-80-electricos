#include <stdio.h>

// Definimos un tamaño máximo para facilitar la gestión de memoria en esta práctica
#define MAX 20

void generarEspiral(int n, int matriz[MAX][MAX]) {

    // Inicializar matriz en 0 (marca de celda no visitada)
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            matriz[i][j] = 0;

    // Direcciones: Derecha → Abajo → Izquierda → Arriba
    int dx[] = {0, 1, 0, -1};
    int dy[] = {1, 0, -1, 0};

    int direccion = 0; // empezamos hacia la derecha
    int fila = 0;
    int col = 0;

    for (int valor = 1; valor <= n * n; valor++) {

        matriz[fila][col] = valor;

        int nuevaFila = fila + dx[direccion];
        int nuevaCol = col + dy[direccion];

        // Detectar choque con borde o celda ya visitada
        if (nuevaFila < 0 || nuevaFila >= n ||
            nuevaCol < 0 || nuevaCol >= n ||
            matriz[nuevaFila][nuevaCol] != 0) {

            direccion = (direccion + 1) % 4;

            nuevaFila = fila + dx[direccion];
            nuevaCol = col + dy[direccion];
        }

        fila = nuevaFila;
        col = nuevaCol;
    }
}

void imprimirMatriz(int n, int matriz[MAX][MAX]) {
    printf("\n--- Matriz Espiral de %dx%d ---\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%4d ", matriz[i][j]); // %4d para alinear columnas
        }
        printf("\n");
    }
}

int main() {
    int n;
    int matriz[MAX][MAX];

    printf("Ingrese el tamaño N de la matriz (max %d): ", MAX);
    scanf("%d", &n);

    if (n > MAX) {
        printf("Error: El tamaño excede el máximo permitido.\n");
        return 1;
    }

    generarEspiral(n, matriz);
    imprimirMatriz(n, matriz);

    return 0;
}
// PREGUNTA: ¿Qué sucede si se omite la verificación if (top <= bottom) -linea 21- dentro del bucle?
