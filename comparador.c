#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100
#ifdef _WIN32
    #define CLEAR_SCREEN "cls"
#else
    #define CLEAR_SCREEN "clear"
#endif


int main(int argc, char *argv[]) {
    system(CLEAR_SCREEN);
    printf("----------------------------------------\n");
    printf("COMPARADOR DE ARCHIVOS DE TEXTO\n");
    printf("Descripci%cn: Compara dos archivos de texto l%cnea por l%cnea y muestra las diferencias.\n", 162, 161, 161);
    printf("----------------------------------------\n\n");
    if (argc != 3) {
        printf("Uso: programa <archivo_entrada1> <archivo_entrada2>\n");
        return 1;
    }

    char *inputFile1 = argv[1];
    char *inputFile2 = argv[2];

    FILE *input1 = fopen(inputFile1, "r");
    FILE *input2 = fopen(inputFile2, "r");

    if (input1 == NULL) {
        printf("No se pudo abrir el archivo de entrada 1.\n");
        return 1;
    }

    if (input2 == NULL) {
        printf("No se pudo abrir el archivo de entrada 2.\n");
        return 1;
    }

    char lineInput1[MAX_LINE_LENGTH];
    char lineInput2[MAX_LINE_LENGTH];
    int counter = 0;
    int lineCounter = 1;


    // Comparar línea por línea y mostrar las diferencias
    while (fgets(lineInput1, MAX_LINE_LENGTH, input1) != NULL && fgets(lineInput2, MAX_LINE_LENGTH, input2) != NULL) {
        if (strcmp(lineInput1, lineInput2) != 0) {
            printf("\nL%cnea %d:\n",161, lineCounter);
            printf("%s", lineInput1);
            printf("%s", lineInput2);
            counter++;
        }
        lineCounter++;
    }

    //verificar si counter es mayor a 0
    if (counter == 0) {
        printf("No se ha encontrado diferencias.\n");
    }else{
    printf("==============================================\n");
    printf("CANTIDAD DE LINEAS DISTINTAS: %d\n", counter);
    }

    fclose(input1);
    fclose(input2);

    return 0;
}
