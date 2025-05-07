#include "arreglo.h"
#include <stdio.h>
#include <stdlib.h>

void addElement(int **array, int *size, int element)
{
    int *temp = realloc(*array, (*size + 1) * sizeof(int));
    if (temp == NULL)
    {
        printf("Error al asignar memoria\n");
        exit(EXIT_FAILURE);
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
        printf("%d\n", array[i]);
    }
}

void deleteElement(int **array, int *size)
{
    if (*size <= 0)
        return;

    int *temp = realloc(*array, (*size - 1) * sizeof(int));
    if (temp == NULL)
    {
        printf("Error al asignar memoria\n");
        exit(EXIT_FAILURE);
    }
    *array = temp;
    (*size)--;
}
