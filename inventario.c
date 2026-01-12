#include <stdio.h>
#include <string.h>

#define MAX 100
#define MAX_MARCA 50

typedef struct {
    char marca[MAX_MARCA];
    float valore;
} Macchina;

int main() {
    Macchina inventario[MAX];
    int n, i;
    float costoTotale = 0;

    printf("Quante macchine vuoi inserire? ");
    scanf("%d", &n);
    getchar(); // pulizia buffer

    for (i = 0; i < n; i++) {
        printf("\nMacchina %d\n", i + 1);

        printf("Marca: ");
        fgets(inventario[i].marca, MAX_MARCA, stdin);
        inventario[i].marca[strcspn(inventario[i].marca, "\n")] = '\0';

        printf("Valore: ");
        scanf("%f", &inventario[i].valore);
        getchar();

        costoTotale += inventario[i].valore;
    }

    printf("\n--- INVENTARIO ---\n");
    for (i = 0; i < n; i++) {
        printf("Marca: %s | Valore: %.2f\n",
               inventario[i].marca,
               inventario[i].valore);
    }

    printf("\nCosto totale: %.2f\n", costoTotale);

    return 0;
}
