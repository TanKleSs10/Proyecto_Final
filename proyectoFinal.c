#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>

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

//** TODO: Prototipos de funciones para la pila
void agregar(int numero);  // push
void eliminarUltimo(void); // pop
void imprimir(void);
int tamanio(void);                                    // El tamaño de la pila
bool vacia(void);                                     // Indica si la pila está vacía
int ultimo(void);                                     // El último elemento. Devuelve -1 si no hay elementos
void addElement(int **array, int *size, int element); // añadir elemento al arrteglo
void printArray(int *array, int size);                // Imprime el arreglo
void deleteElement(int **array, int *size);

void limpiarPantalla()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void esperar()
{
    printf("\nPresiona Enter para continuar...");
    getchar(); // Captura el Enter de la opción previa
    getchar(); // Captura el Enter para continuar
}

int main()
{

// Cambiar codificación a UTF-8
#ifdef _WIN32
    system("chcp 65001");
#endif

    setlocale(LC_ALL, "");

    // ** Declaración de una cola
    Cola cola;
    int eleccion = 0;
    int numero = 0;
    int colaOPila;
    int salir = 0;
    int *array = NULL;
    int size = 0;

    inicializarCola(&cola);

    while (!salir)
    {
        printf("\n--Bienvenido--\n**Elige**\n1.- Usar Pilas\n2.- Usar Colas\n3.-Usar Arreglo de numeros\n -1.- Salir\n\n");
        scanf("%d", &colaOPila);

        if (colaOPila == 1)
        {
            while (colaOPila == 1)
            {
                printf("\nUsando Pilas\n"
                       "\n1.- Agregar elemento a una Pila\n"
                       "\n2.- Eliminar un elemento de Pila\n"
                       "\n3.- Imprimir Pila\n"
                       "\n4.- Imprimir tamaño\n"
                       "\n5.- Comprobar si está vacía\n"
                       "\n6.- Mostrar último elemento Pila\n"
                       "\n7.- Regresar al menú principal\n"
                       "\n-1.- Salir\n\n"
                       "\tElige:\n\n");
                scanf("%d", &eleccion);

                switch (eleccion)
                {
                case 1:
                    printf("\nIngresa el número que agregaremos a la Pila:\n");
                    scanf("%d", &numero);
                    agregar(numero);
                    esperar();
                    break;
                case 2:
                    eliminarUltimo(); // último elemento ingresado en la pila
                    esperar();
                    break;
                case 3:
                    imprimir(); // imprimir pila
                    esperar();
                    break;
                case 4:
                    printf("La pila mide %d\n", tamanio());
                    esperar();
                    break;
                case 5:
                    if (vacia())
                    {
                        printf("La pila está vacía\n");
                    }
                    else
                    {
                        printf("La pila NO está vacía\n");
                    }
                    esperar();
                    break;
                case 6:
                    printf("El último elemento es: %d\n", ultimo());
                    esperar();
                    break;
                case 7:
                    colaOPila = 0;
                    break;
                case -1:
                    limpiarPantalla();
                    salir = 1;
                    break;
                default:
                    printf("Opción no válida\n");
                    esperar();
                    break;
                }
                if (salir)
                {
                    break;
                }
                limpiarPantalla();
            }
        }
        else if (colaOPila == 2)
        {
            while (colaOPila == 2)
            {
                printf("\nUsando Colas\n"
                       "\n1.- Agregar elemento a una Cola\n"
                       "\n2.- Eliminar un elemento de una Cola\n"
                       "\n3.- Imprimir Cola\n"
                       "\n4.- Regresar al menú principal\n"
                       "\n-1.- Salir\n\n"
                       "\tElige:\n\n");
                scanf("%d", &eleccion);

                switch (eleccion)
                {
                case 1:
                    printf("Ingresa el número que agregaremos a la cola:\n");
                    scanf("%d", &numero);
                    encolar(&cola, numero);
                    esperar();
                    break;
                case 2:
                    printf("Eliminando elementos de la cola...\n");
                    while (!estaVacia(&cola))
                    {
                        int respuesta;
                        printf("¿Deseas quitar elemento de la cola? Si = 1 / No = 0 \n");
                        scanf("%d", &respuesta);

                        if (respuesta == 1)
                        {
                            printf("Desencolando %d\n", desencolar(&cola));
                            mostrarCola(&cola);
                        }
                        else
                        {
                            break;
                        }
                    }
                    esperar();
                    break;
                case 3:
                    mostrarCola(&cola);
                    esperar();
                    break;
                case 4:
                    colaOPila = 0;
                    break;
                case -1:
                    limpiarPantalla();
                    salir = 1;
                    break;
                default:
                    printf("Opción no válida\n");
                    esperar();
                    break;
                }
                if (salir)
                {
                    break;
                }
                limpiarPantalla();
            }
        }
        else if (colaOPila == 3)
        {
            while (colaOPila == 3)
            {
                printf("\nUsando Arreglo de numeros\n"
                       "\n1.- Agregar elemento al arreglo\n"
                       "\n2.- Eliminar un elemento del arreglo\n"
                       "\n3.- Imprimir arreglo\n"
                       "\n4.- Regresar al menú principal\n"
                       "\n-1.- Salir\n\n"
                       "\tElige:\n\n");
                scanf("%d", &eleccion);

                switch (eleccion)
                {
                case 1:
                    int newNumber;
                    printf("Ingresa el número que agregaremos al arreglo:\n");
                    scanf("%d", &newNumber);
                    addElement(&array, &size, newNumber);
                    colaOPila = 3;
                    esperar();
                    break;
                case 2:
                    printf("Eliminando elementos del arreglo...\n");
                    while (size >= 0)
                    {
                        int respuesta;
                        printf("\n\n-¿Deseas quitar elemento del arreglo? Si = 1 / No = 0 \n");
                        scanf("%d", &respuesta);

                        if (respuesta == 1)
                        {
                            deleteElement(&array, &size);
                            printf("\n\nEliminando...\n");
                            printArray(array, size);
                        }
                        else
                        {
                            break;
                        }
                    }
                    esperar();
                    break;
                case 3:
                    printArray(array, size);
                    esperar();
                    break;
                case 4:
                    colaOPila = 0;
                    break;
                case -1:
                    limpiarPantalla();
                    salir = 1;
                    break;
                default:
                    printf("Opción no válida\n");
                    esperar();
                    break;
                }
                if (salir)
                {
                    break;
                }
                limpiarPantalla();
            }
        }
        else if (colaOPila == -1)
        {
            limpiarPantalla();
            salir = 1;
        }
        else
        {
            printf("Opción no válida\n");
            esperar();
            limpiarPantalla();
        }
    }

    return 0;
}

// Todo comienza con el nodo superior
struct Nodo *superior = NULL;

int tamanio(void)
{
    int contador = 0;
    if (superior == NULL)
        return contador;
    struct Nodo *temporal = superior;
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

int ultimo()
{
    if (superior == NULL)
        return -1;
    return superior->dato;
}

// Operación push
void agregar(int numero)
{
    printf("Agregando %d\n", numero);
    // El que se agregará; reservamos memoria
    struct Nodo *nuevoNodo = malloc(sizeof(struct Nodo));
    // Le ponemos el dato
    nuevoNodo->dato = numero;
    // Y ahora el nuevo nodo es el superior, y su siguiente
    // es el que antes era superior
    nuevoNodo->siguiente = superior;
    superior = nuevoNodo;
}

void imprimir(void)
{
    printf("Imprimiendo...\n");
    struct Nodo *temporal = superior;
    while (temporal != NULL)
    {
        printf("%d\n", temporal->dato);
        temporal = temporal->siguiente;
    }
}

// Operación pop, eliminar el de hasta arriba
void eliminarUltimo(void)
{
    printf("Eliminando el último\n");
    if (superior != NULL)
    {
        // Para liberar la memoria más tarde debemos
        // tener la referencia al que vamos a eliminar
        struct Nodo *temporal = superior;
        printf("\nDato eliminado: %d\n", temporal->dato);
        // Ahora superior es a lo que apuntaba su siguiente
        superior = superior->siguiente;

        // Liberar memoria que estaba ocupando el que eliminamos
        free(temporal);
    }
}
void addElement(int **array, int *size, int element)
{
    int *temp = realloc(*array, (*size + 1) * sizeof(int));
    if (temp == NULL)
    {
        // Manejo de error
        printf("Error al asignar memoria\n");
        exit(1);
    }
    *array = temp;
    (*array)[*size] = element;
    (*size)++;
}

void printArray(int *array, int size)
{
    printf("\n\nTu arreglo es:\n");
    for (int i = 0; i < size; i++)
    {
        printf("\n%d", array[i]);
    }
}

void deleteElement(int **array, int *size)
{
    int *temp = realloc(*array, (*size - 1) * sizeof(int));
    if (temp == NULL)
    {
        // Manejo de error
        printf("Error al asignar memoria\n");
        exit(1);
    }
    *array = temp;
    (*size)--;
}