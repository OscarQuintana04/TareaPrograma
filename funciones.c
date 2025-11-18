#include <stdio.h>
#include <string.h>
#include "funciones.h"

void leerCadena(char *cadena, int tam)
{
    fflush(stdin);
    fgets(cadena, tam, stdin);
    int len = strlen(cadena);
    if (len > 0 && cadena[len - 1] == '\n')
        cadena[len - 1] = '\0';
}

void ingresoProductos(char productos[][30],int pantallas[], int chips[],int tarjetas[], int sensores[],int tiempo[],int indice)
{
    int valor;

    printf("Nombre del producto [%d]: ", indice);
    leerCadena(productos[indice], 30);

    // Pantallas
    do {
        printf("Cantidad de pantallas que usa el producto: ");
        scanf(" %d", &valor);
        if (valor < 0)
            printf("La cantidad no puede ser negativa.\n");
    } while (valor < 0);
    pantallas[indice] = valor;

    // Chips
    do {
        printf("Cantidad de chips que usa el producto: ");
        scanf(" %d", &valor);
        if (valor < 0)
            printf("La cantidad no puede ser negativa.\n");
    } while (valor < 0);
    chips[indice] = valor;

    // Tarjetas
    do {
        printf("Cantidad de tarjetas que usa el producto: ");
        scanf(" %d", &valor);
        if (valor < 0)
            printf("La cantidad no puede ser negativa.\n");
    } while (valor < 0);
    tarjetas[indice] = valor;

    // Sensores
    do {
        printf("Cantidad de sensores que usa el producto: ");
        scanf(" %d", &valor);
        if (valor < 0)
            printf("La cantidad no puede ser negativa.\n");
    } while (valor < 0);
    sensores[indice] = valor;

    // Tiempo
    do {
        printf("Tiempo de produccion (en minutos) por unidad: ");
        scanf(" %d", &valor);
        if (valor < 0)
            printf("El tiempo no puede ser negativo.\n");
    } while (valor < 0);
    tiempo[indice] = valor;
}

void imprimirProductos(char productos[][30],int pantallas[],int chips[],int tarjetas[],int sensores[],int tiempo[],int cont)
{
    if (cont == 0) {
        printf("No hay productos registrados.\n");
        return;
    }

    printf("\n#\tProducto\t\tPantallas\t\tChips\t\tTarjetas\t\tsensores\t\tTiempo\n");
    printf("----------------------------------------------------------------------------------------------------------\n");
    for (int i = 0; i < cont; i++) {
        printf("%d\t%s\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",i,productos[i],pantallas[i], chips[i],tarjetas[i],sensores[i],tiempo[i]);
    }
}

int leerIndiceValido(int cont)// venta
{
    int indice;
    do {
        printf("Ingrese el numero del producto (0 a %d): ", cont - 1);
        scanf(" %d", &indice);
        if (indice < 0 || indice >= cont)
            printf("opcion invalida.\n");
    } while (indice < 0 || indice >= cont);
    return indice;
}


void eliminarProducto(char productos[][30],int pantallas[],int tarjetas[],int chips[],int sensores[],int tiempo[],int *cont){
    if (*cont == 0) {
        printf("No hay productos a eliminar.\n");
        return;
    }

    printf("\nLISTA DE PRODUCTOS:\n");
    for (int i = 0; i < *cont; i++) {
        printf("%d - %s\n", i, productos[i]);
    }

    int indice;
    do {
        printf("Indice del producto a eliminar: ");
        scanf(" %d", &indice);
        if (indice < 0 || indice >= *cont)
            printf("indice no válido.\n");
    } while (indice < 0 || indice >= *cont);

    for (int i = indice; i < *cont - 1; i++) {

        int j = 0;
        while (productos[i + 1][j] != '\0') {
            productos[i][j] = productos[i + 1][j];
            j++;
        }
        productos[i][j] = '\0';  
        pantallas[i] = pantallas[i + 1];
        tarjetas[i] = tarjetas[i + 1];
        chips[i] = chips[i + 1];
        sensores[i] = sensores[i + 1];
        tiempo[i] = tiempo[i + 1];
    }

    (*cont)--;

    printf("\nProducto eliminado correctamente.\n");
}
void calculoRecursos(int componente[], int indice, int cantidad, int stock, char texto[])
{
    int porUnidad = componente[indice];        
    int totalNecesario = porUnidad * cantidad; 

    if (porUnidad <= 0) {
        printf("Este componente no se usa para este producto.\n");
        return;
    }

    if (totalNecesario <= stock) {
        printf("Es posible producir las %d unidades. El stock de %s alcanza.\n",cantidad, texto);
    } else {
        int faltan = totalNecesario - stock;
        int maxProducible = stock / porUnidad;

        printf("No alcanza el stock de %s.\n", texto);
        printf("Se necesitan %d %s en total.\n", totalNecesario, texto);
        printf("Solo tienes %d en stock.\n", stock);
        printf("Faltan %d %s.\n", faltan, texto);
        printf("Solo puedes producir %d unidades con el stock actual.\n",maxProducible);
    }
}
