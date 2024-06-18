#include "pila.h"
#include <stdio.h>
#include <stdlib.h>

void inicializarPila(Nodo **superior)
{
    *superior = NULL;
}

void agregar(Nodo **superior, int numero)
{
    Nodo *nuevoNodo = (Nodo *)malloc(sizeof(Nodo));
    if (nuevoNodo == NULL)
    {
        fprintf(stderr, "Error: No se pudo asignar memoria para el nuevo nodo.\n");
        exit(EXIT_FAILURE);
    }
    nuevoNodo->dato = numero;
    nuevoNodo->siguiente = *superior;
    *superior = nuevoNodo;
}

void eliminarUltimo(Nodo **superior)
{
    if (*superior != NULL)
    {
        Nodo *temporal = *superior;
        *superior = (*superior)->siguiente;
        free(temporal);
    }
}

void imprimir(Nodo *superior)
{
    Nodo *temporal = superior;
    while (temporal != NULL)
    {
        printf("%d\n", temporal->dato);
        temporal = temporal->siguiente;
    }
}

int tamanio(Nodo *superior)
{
    int contador = 0;
    Nodo *temporal = superior;
    while (temporal != NULL)
    {
        contador++;
        temporal = temporal->siguiente;
    }
    return contador;
}

int vacia(Nodo *superior)
{
    return superior == NULL;
}

int ultimo(Nodo *superior)
{
    if (superior == NULL)
    {
        return -1;
    }
    return superior->dato;
}
