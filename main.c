#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "estructuras/estructuras.h"
#include "pila/pila.h"
#include "arreglo/arreglo.h"
#include "char_array/char_array.h"

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

    Cola cola;
    int eleccion = 0;
    int colaOPila;
    int salir = 0;
    int *array = NULL;
    int size = 0;
    int size_char = 0;
    char *char_array = NULL;

    inicializarCola(&cola);

    while (!salir)
    {
        printf("\n--Bienvenido--\n**Elige**\n1.- Usar Pilas\n2.- Usar Colas\n3.- Usar Arreglo de números\n4.- Usar Arreglo de caracteres\n-1.- Salir\n\n");
        scanf("%d", &colaOPila);

        switch (colaOPila)
        {
        case 1:
            while (colaOPila == 1)
            {
                printf("\nUsando Pilas\n"
                       "\n1.- Agregar elemento a una Pila\n"
                       "2.- Eliminar un elemento de Pila\n"
                       "3.- Imprimir Pila\n"
                       "4.- Imprimir tamaño\n"
                       "5.- Comprobar si está vacía\n"
                       "6.- Mostrar último elemento Pila\n"
                       "7.- Regresar al menú principal\n"
                       "-1.- Salir\n\n"
                       "\tElige:\n\n");
                scanf("%d", &eleccion);

                switch (eleccion)
                {
                case 1:
                    printf("\nIngresa el número que agregaremos a la Pila:\n");
                    scanf("%d", &eleccion);
                    agregar(eleccion);
                    esperar();
                    break;
                case 2:
                    eliminarUltimo();
                    esperar();
                    break;
                case 3:
                    imprimir();
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
                    break;
                limpiarPantalla();
            }
            break;

        case 2:
            while (colaOPila == 2)
            {
                printf("\nUsando Colas\n"
                       "\n1.- Agregar elemento a una Cola\n"
                       "2.- Eliminar un elemento de una Cola\n"
                       "3.- Imprimir Cola\n"
                       "4.- Regresar al menú principal\n"
                       "-1.- Salir\n\n"
                       "\tElige:\n\n");
                scanf("%d", &eleccion);

                switch (eleccion)
                {
                case 1:
                    printf("Ingresa el número que agregaremos a la cola:\n");
                    scanf("%d", &eleccion);
                    encolar(&cola, eleccion);
                    esperar();
                    break;
                case 2:
                    while (!estaVacia(&cola))
                    {
                        printf("Eliminando elementos de la cola...\n");
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
                    printf("\naún agregas elementos a la cola\n");
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
                    break;
                limpiarPantalla();
            }
            break;

        case 3:
            while (colaOPila == 3)
            {
                printf("\nUsando Arreglo de números\n"
                       "\n1.- Agregar elemento al arreglo\n"
                       "2.- Eliminar un elemento del arreglo\n"
                       "3.- Imprimir arreglo\n"
                       "4.- Regresar al menú principal\n"
                       "-1.- Salir\n\n"
                       "\tElige:\n\n");
                scanf("%d", &eleccion);

                switch (eleccion)
                {
                case 1:
                    int newNumber;
                    printf("Ingresa el número que agregaremos al arreglo:\n");
                    scanf("%d", &newNumber);
                    addElement(&array, &size, newNumber);
                    esperar();
                    break;
                case 2:
                    while (size > 0)
                    {
                        printf("Eliminando elementos del arreglo...\n");
                        int respuesta;
                        printf("¿Deseas quitar elemento del arreglo? Si = 1 / No = 0 \n");
                        scanf("%d", &respuesta);

                        if (respuesta == 1)
                        {
                            deleteElement(&array, &size);
                            printf("Eliminando...\n");
                            printArray(array, size);
                        }
                        else
                        {
                            break;
                        }
                    }
                    printf("\naun agregas elementos al array\n");
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
                    break;
                limpiarPantalla();
            }
            break;
        case 4:
            while (colaOPila == 4)
            {
                printf("\nUsando Arreglo de Caracteres\n"
                       "\n1.- Agregar elemento al arreglo\n"
                       "2.- Eliminar un elemento del arreglo\n"
                       "3.- Imprimir arreglo\n"
                       "4.- Regresar al menú principal\n"
                       "-1.- Salir\n\n"
                       "\tElige:\n\n");
                scanf("%d", &eleccion);

                switch (eleccion)
                {
                case 1:
                    char nuevoChar;
                    printf("Ingrese el caracter a agregar: ");
                    scanf(" %c", &nuevoChar);
                    addElementChar(&char_array, &size_char, nuevoChar);
                    getchar(); // Consumir el Enter residual
                    break;
                case 2:
                    while (size_char > 0)
                    {
                        printf("Eliminando elementos del arreglo...\n");
                        int respuesta;
                        printf("¿Deseas quitar elemento del arreglo? Si = 1 / No = 0 \n");
                        scanf("%d", &respuesta);

                        if (respuesta == 1)
                        {
                            deleteElementChar(&char_array, &size_char);
                            printf("Eliminando...\n");
                            printArrayChar(char_array, size_char);
                        }
                        else
                        {
                            break;
                        }
                    }
                    printf("\naun agregas elementos al array\n");
                    esperar();
                    break;
                case 3:
                    printArrayChar(char_array, size_char);
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
                    break;
                limpiarPantalla();
            }
            break;

        case -1:
            limpiarPantalla();
            salir = 1;
            break;

        default:
            printf("Opción no válida\n");
            esperar();
            limpiarPantalla();
            break;
        }
    }

    return 0;
}
