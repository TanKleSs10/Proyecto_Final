#include "pila.h"
#include "../estructuras/estructuras.h"
#include <stdio.h>
#include <stdlib.h>

// Todo comienza con el nodo superior
static Nodo *superior = NULL;

int tamanio(void)
{
    int contador = 0;
    if (superior == NULL)
        return contador;
    Nodo *temporal = superior;
    while (temporal != NULL)
    {
        contador++;
        temporal = temporal->siguiente;
    }
    return contador;
}

bool vacia(void)
{
    return superior == NULL;
}

int ultimo(void)
{
    if (superior == NULL)
        return -1;
    return superior->dato;
}

// Operación push
void agregar(int numero)
{
    printf("Agregando %d\n", numero);
    Nodo *nuevoNodo = crearNodo(numero);
    if (nuevoNodo == NULL)
    {
        printf("Error al crear el nodo\n");
        exit(EXIT_FAILURE);
    }
    nuevoNodo->siguiente = superior;
    superior = nuevoNodo;
}

void imprimir(void)
{
    printf("Imprimiendo...\n");
    Nodo *temporal = superior;
    while (temporal != NULL)
    {
        printf("%d\n", temporal->dato);
        temporal = temporal->siguiente;
    }
}

// Operación pop, eliminar el de hasta arriba
void eliminarUltimo(void)
{
    if (superior != NULL)
    {
        printf("Eliminando el último\n");
        Nodo *temporal = superior;
        printf("\nDato eliminado: %d\n", temporal->dato);
        superior = superior->siguiente;
        free(temporal);
    }
    else
    {
        printf("\naun agregas elementos a la pila\n");
    }
}
