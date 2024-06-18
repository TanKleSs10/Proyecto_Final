#ifndef PILA_H
#define PILA_H

// Definición de la estructura para los nodos de la pila
typedef struct Nodo
{
    int dato;
    struct Nodo *siguiente;
} Nodo;

// Función para inicializar la pila
void inicializarPila(Nodo **superior);

// Función para agregar un elemento a la pila
void agregar(Nodo **superior, int numero);

// Función para eliminar el último elemento de la pila
void eliminarUltimo(Nodo **superior);

// Función para imprimir los elementos de la pila
void imprimir(Nodo *superior);

// Función para obtener el tamaño de la pila
int tamanio(Nodo *superior);

// Función para verificar si la pila está vacía
int vacia(Nodo *superior);

// Función para obtener el último elemento de la pila
int ultimo(Nodo *superior);

#endif // PILA_H
