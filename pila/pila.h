#ifndef PILA_H
#define PILA_H

#include <stdbool.h>

// Prototipos de funciones de la pila
void agregar(int numero);  // push
void eliminarUltimo(void); // pop
void imprimir(void);
int tamanio(void);         // El tamaño de la pila
bool vacia(void);          // Indica si la pila está vacía
int ultimo(void);          // El último elemento. Devuelve -1 si no hay elementos

#endif // PILA_H
