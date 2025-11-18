#include <stdio.h>
#include <string.h>
#include "funciones.h"

int main()
{
    int opc;
    int cont = 0; 

    char productos[5][30];
    int pantallas[5], chips[5], tarjetas[5], sensores[5], tiempo[5];

    int stock_pantallas = 0;
    int stock_chips = 0;
    int stock_tarjetas = 0;
    int stock_sensores = 0;
    int tiempo_disponible = 0;

    do {
        printf("\n----------MENU----------\n");
        printf("1. Ingresar productos\n");
        printf("2. Ingresar stock de recursos\n");
        printf("3. Editar producto\n");
        printf("4. Eliminar producto\n");
        printf("5. Revisar productos\n");
        printf("6. Calcular produccion posible\n");
        printf("7. Salir\n");
        printf(">>> ");

        scanf(" %d", &opc);

        switch (opc)
        {
        case 1:
            if (cont == 5) {
                printf("Ya no se pueden ingresar mas productos (maximo 5).\n");
            } else {
                int seguir = 1;

                do {
                    printf("\n--- Ingreso de producto %d ---\n", cont);
                    ingresoProductos(productos, pantallas, chips, tarjetas, sensores, tiempo, cont);
                    cont++;

                    if (cont == 5) {
                        printf("Llegaste al máximo de 5 productos.\n");
                        break;
                    }

                    printf("Desea ingresar otro producto: 1.Si / 2.No: ");
                    scanf(" %d", &seguir);

                    if (seguir != 1 && seguir != 2) {
                        printf("Opción invalida, se asumira 2 (No).\n");
                        seguir = 2;
                    }

                } while (seguir == 1 && cont < 5);
            }
            break;

        case 2:
            if (cont == 0) {
                printf("Primero debe ingresar al menos un producto.\n");
            } else {
                int valor;
                printf("\n--- Ingreso de stock de recursos ---\n");

                // Pantallas
                do {
                    printf("Cantidad en stock de pantallas: ");
                    scanf(" %d", &valor);
                    if (valor < 0)
                        printf("La cantidad no puede ser negativa.\n");
                } while (valor < 0);
                stock_pantallas = valor;

                // Chips
                do {
                    printf("Cantidad en stock de chips: ");
                    scanf(" %d", &valor);
                    if (valor < 0)
                        printf("La cantidad no puede ser negativa.\n");
                } while (valor < 0);
                stock_chips = valor;

                // Tarjetas
                do {
                    printf("Cantidad en stock de tarjetas: ");
                    scanf(" %d", &valor);
                    if (valor < 0)
                        printf("La cantidad no puede ser negativa.\n");
                } while (valor < 0);
                stock_tarjetas = valor;
              
                do {
                    printf("Cantidad en stock de sensores: ");
                    scanf(" %d", &valor);
                    if (valor < 0)
                        printf("La cantidad no puede ser negativa.\n");
                } while (valor < 0);
                stock_sensores = valor;

                // Tiempo disponible total
                do {
                    printf("Tiempo total disponible (en minutos): ");
                    scanf(" %d", &valor);
                    if (valor < 0)
                        printf("El tiempo no puede ser negativo.\n");
                } while (valor < 0);
                tiempo_disponible = valor;

            }
            break;

        case 3: // Editar producto
            if (cont == 0) {
                printf("No se han ingresado productos.\n");
            } else {
                imprimirProductos(productos, pantallas, chips, tarjetas, sensores, tiempo, cont);
                int indice = leerIndiceValido(cont);

                printf("\n--- Editar producto en indice %d ---\n", indice);
                ingresoProductos(productos, pantallas, chips, tarjetas, sensores, tiempo, indice);
            }
            break;

        case 4: 
            eliminarProducto(productos, pantallas, tarjetas, chips, sensores, tiempo, &cont);

            break;

        case 5: // Revisar productos
            imprimirProductos(productos, pantallas, chips, tarjetas, sensores, tiempo, cont);
            break;

        case 6: // Calcular producción
            if (cont == 0) {
                printf("No se han ingresado productos.\n");
            } else {

                imprimirProductos(productos, pantallas, chips, tarjetas, sensores, tiempo, cont);

                int indice;
                do {
                    printf("Ingrese numero del producto (0 a %d): ", cont - 1);
                    scanf(" %d", &indice);
                    if (indice < 0 || indice >= cont)
                        printf("Indice inválido.\n");
                } while (indice < 0 || indice >= cont);

                int total;
                printf("Cuantas unidades desea producir?: ");
                scanf(" %d", &total);

                int tiempo_total;
                printf("Tiempo disponible (minutos): ");
                scanf(" %d", &tiempo_total);

                printf("\nPantallas: ");
                calculoRecursos(pantallas, indice, total, stock_pantallas, "pantalla/s");

                printf("Chips: ");
                calculoRecursos(chips, indice, total, stock_chips, "chip/s");

                printf("Tarjetas: ");
                calculoRecursos(tarjetas, indice, total, stock_tarjetas, "tarjeta/s");

                printf("Sensores: ");
                calculoRecursos(sensores, indice, total, stock_sensores, "sensor/es");

                printf("Tiempo: ");
                calculoRecursos(tiempo, indice, total, tiempo_total, "minutos");
            }
            break;

        case 7:
            printf("FIN DEL PROGRAMA...\n");
            break;

        default:
            printf("Opción invalida.\n");
            break;
        }

    } while (opc != 7);

    return 0;
}
