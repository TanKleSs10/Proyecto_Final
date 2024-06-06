# Programa de Pilas y Colas en C

El siguiente es un programa en C que implementa el uso de pilas y colas utilizando listas enlazadas.

## Estructuras de Datos

### `Nodo` y `Cola`

- `struct Nodo`: Representa un nodo de una lista enlazada. Contiene un entero `dato` y un puntero `siguiente` que apunta al siguiente nodo en la lista.
- `struct Cola`: Representa una cola implementada mediante una lista enlazada. Tiene dos punteros: `frente`, que apunta al primer elemento de la cola, y `final`, que apunta al último elemento.

## Funciones

### Para operar con Colas

- `Nodo *crearNodo(int valor)`: Crea un nuevo nodo con el valor especificado.
- `void inicializarCola(Cola *q)`: Inicializa una cola, estableciendo los punteros `frente` y `final` en `NULL`.
- `int estaVacia(Cola *q)`: Verifica si la cola está vacía. Retorna 1 si está vacía y 0 si no lo está.
- `void encolar(Cola *q, int valor)`: Agrega un elemento al final de la cola.
- `int desencolar(Cola *q)`: Elimina y retorna el elemento del frente de la cola.
- `void mostrarCola(Cola *q)`: Muestra los elementos de la cola.

### Para operar con Pilas

- `void agregar(int numero)`: Agrega un elemento a la pila (push).
- `void eliminarUltimo()`: Elimina el último elemento de la pila (pop).
- `void imprimir()`: Imprime los elementos de la pila.
- `int tamanio()`: Retorna el tamaño de la pila.
- `bool vacia()`: Verifica si la pila está vacía.
- `int ultimo()`: Retorna el último elemento de la pila.

### Funciones de Utilidad

- `void limpiarPantalla()`: Limpia la pantalla de la consola.
- `void esperar()`: Muestra un mensaje y espera a que el usuario presione Enter.

## Función Principal `main()`

- Se establece la configuración regional (`locale`) para admitir caracteres especiales.
- Se inicializa una cola.
- El programa tiene un bucle principal que muestra un menú para seleccionar entre usar pilas o colas.
- Dependiendo de la elección del usuario, se ejecuta un submenú para operar con pilas o colas.
- Cada submenú permite agregar, eliminar, imprimir y realizar otras operaciones en la estructura seleccionada.
- El programa termina cuando el usuario elige la opción de salir (`-1`).
