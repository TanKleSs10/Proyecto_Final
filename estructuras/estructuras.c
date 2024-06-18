#include <stdio.h>
#include <stdlib.h>
#include "estructuras.h"

// Función para crear un nodo nuevo
Nodo *crearNodo(int valor)
{
    Nodo *nuevo = (Nodo *)malloc(sizeof(Nodo));
    if (nuevo != NULL)
    {
        nuevo->dato = valor;
        nuevo->siguiente = NULL;
    }
    return nuevo;
}

// Función para inicializar la cola
void inicializarCola(Cola *q)
{
    q->frente = NULL;
    q->final = NULL;
}

// Función para verificar si la cola está vacía
int estaVacia(Cola *q)
{
    return (q->frente == NULL);
}

// Función para agregar elementos a la cola
void encolar(Cola *q, int valor)
{
    Nodo *nuevo = crearNodo(valor);
    if (nuevo != NULL)
    {
        if (estaVacia(q))
        {
            q->frente = nuevo;
        }
        else
        {
            q->final->siguiente = nuevo;
        }
        q->final = nuevo;
    }
}

// Función para eliminar elementos de la cola
int desencolar(Cola *q)
{
    if (!estaVacia(q))
    {
        Nodo *temp = q->frente;
        int valor = temp->dato;
        q->frente = q->frente->siguiente;
        if (q->frente == NULL)
        {
            q->final = NULL;
        }
        free(temp);
        return valor;
    }
    return -1; // Retorna -1 si la cola está vacía
}

// Función para mostrar los elementos de la cola
void mostrarCola(Cola *q)
{
    Nodo *temp = q->frente;
    while (temp != NULL)
    {
        printf("%d ", temp->dato);
        temp = temp->siguiente;
    }
    printf("\n");
}
