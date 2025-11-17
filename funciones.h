/*#ifndef FUNCIONES_H
#define FUNCIONES_H */


void leerCadena(char *cadena, int tam);

void ingresoProductos(char productos[][30],int pantallas[], int chips[],int tarjetas[], int sensores[],int tiempo[],int indice);

void imprimirProductos(char productos[][30],int pantallas[],int chips[],int tarjetas[],int sensores[],int tiempo[],int cont);

int leerIndiceValido(int cont);
void eliminarProducto(char productos[][30],int pantallas[],int tarjetas[],int chips[],int sensores[],int tiempo[],int *cont);
void calculoRecursos(int componente[], int indice, int cantidad, int stock, char texto[]);

//#endif
