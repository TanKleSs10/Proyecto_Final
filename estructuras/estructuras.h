#ifndef ESTRUCTURAS_H
#define ESTRUCTURAS_H

// Definición de la estructura para los nodos de la cola
typedef struct Nodo
{
    int dato;
    struct Nodo *siguiente;
} Nodo;

// Definición de la estructura para la cola
typedef struct Cola
{
    Nodo *frente;
    Nodo *final;
} Cola;

// Funciones relacionadas con la cola
void inicializarCola(Cola *q);
int estaVacia(Cola *q);
void encolar(Cola *q, int valor);
int desencolar(Cola *q);
void mostrarCola(Cola *q);

// Función para crear un nodo nuevo
Nodo *crearNodo(int valor);

#endif // ESTRUCTURAS_H
