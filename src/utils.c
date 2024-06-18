#include "utils.h"
#include <stdio.h>
#include <stdlib.h>

void limpiarPantalla() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void esperar() {
    printf("\nPresione Enter para continuar...");
    getchar(); // Captura el Enter de la opción previa
    getchar(); // Captura el Enter para continuar
}
