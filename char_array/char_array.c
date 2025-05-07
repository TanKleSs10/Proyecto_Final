#include <stdio.h>
#include <stdlib.h>
#include "char_array.h"

void addElementChar(char **array, int *size, char element)
{
    char *temp = realloc(*array, (*size + 1) * sizeof(char));
    if (temp == NULL)
    {
        printf("Error al asignar memoria\n");
        exit(1);
    }
    *array = temp;
    (*array)[*size] = element;
    (*size)++;
}

void deleteElementChar(char **array, int *size)
{
    if (*size > 0)
    {
        char *temp = realloc(*array, (*size - 1) * sizeof(char));
        if (temp == NULL)
        {
            printf("Error al asignar memoria\n");
            exit(1);
        }
        *array = temp;
        (*size)--;
    }
    else
    {
        printf("No hay elementos para eliminar\n");
    }
}

void printArrayChar(char *array, int size)
{
    printf("\n\nTu arreglo es:\n");
    for (int i = 0; i < size; i++)
    {
        printf("%c ", array[i]);
    }
    printf("\n");
}
