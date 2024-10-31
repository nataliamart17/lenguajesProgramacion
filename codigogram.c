#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct nodo {
    char dato[50];
    struct nodo *siguiente;
} Nodo;

// Declaración de funciones
void cargarDatos(FILE *archivo, Nodo **inicio);
Nodo *crearNodo(char contenido[MAX]);
void insertarAlInicio(Nodo **inicio, char contenido[MAX]);
void mostrarLista(Nodo *inicio);
void liberarMemoria(Nodo **inicio);
void agruparReglas(Nodo *inicio);
void eliminarRecursividadDescendente(Nodo *inicio);
void eliminarRecursividadAscendente(Nodo *inicio);
void reemplazarPatron(Nodo *inicio);
void imprimirExpresionRegular(Nodo *inicio);

int main() {
    FILE *archivo;
    Nodo *inicio = NULL;
    char nombreArchivo[MAX];

    printf("Ingrese el nombre del archivo: ");
    scanf("%s", nombreArchivo);

    if ((archivo = fopen(nombreArchivo, "r")) == NULL) {
        printf("No se pudo abrir el archivo :(\n");
        exit(0);
    }

    cargarDatos(archivo, &inicio);
    fclose(archivo);

    // Aplicación de los pasos de transformación
    agruparReglas(inicio);                 // Paso 1
    eliminarRecursividadDescendente(inicio); // Paso 2
    eliminarRecursividadAscendente(inicio);  // Paso 3
    reemplazarPatron(inicio);               // Reemplazo de {a} por a*
    imprimirExpresionRegular(inicio);       // Impresión de la expresión regular resultante

    liberarMemoria(&inicio);

    return 0;
}

// Función para cargar datos desde el archivo y crear nodos
void cargarDatos(FILE *archivo, Nodo **inicio) {
    char linea[MAX];

    while (fgets(linea, MAX, archivo) != NULL) {
        insertarAlInicio(inicio, linea);
    }
}

// Función para insertar nodo al inicio
void insertarAlInicio(Nodo **inicio, char contenido[MAX]) {
    Nodo *nuevoNodo = crearNodo(contenido);
    nuevoNodo->siguiente = *inicio;
    *inicio = nuevoNodo;
}

// Función para crear un nodo
Nodo *crearNodo(char contenido[MAX]) {
    Nodo *nuevoNodo = (Nodo *)malloc(sizeof(Nodo));
    if (nuevoNodo) {
        strcpy(nuevoNodo->dato, contenido);
        nuevoNodo->siguiente = NULL;
        return nuevoNodo;
    }
    printf("Error al crear el nodo :(\n");
    exit(0);
}

// Función para mostrar la lista de reglas
void mostrarLista(Nodo *inicio) {
    Nodo *actual = inicio;
    while (actual) {
        printf("%s", actual->dato);
        actual = actual->siguiente;
    }
}

// Función para liberar la memoria de la lista
void liberarMemoria(Nodo **inicio) {
    Nodo *temporal;
    while (*inicio) {
        temporal = *inicio;
        *inicio = temporal->siguiente;
        free(temporal);
    }
}

// Paso 1: Agrupar reglas
void agruparReglas(Nodo *inicio) {
    printf("Agrupando reglas...\n");
    // Implementación para agrupar reglas
}

// Paso 2: Eliminar recursividad descendente
void eliminarRecursividadDescendente(Nodo *inicio) {
    printf("Eliminando recursividad descendente...\n");
    // Implementación para eliminar recursividad descendente
}

// Paso 3: Eliminar recursividad ascendente
void eliminarRecursividadAscendente(Nodo *inicio) {
    printf("Eliminando recursividad ascendente...\n");
    // Implementación para eliminar recursividad ascendente
}

// Reemplazo de coincidencias de {a} por a*
void reemplazarPatron(Nodo *inicio) {
    printf("Reemplazando coincidencias de {a} por a*...\n");
    Nodo *actual = inicio;
    while (actual) {
        char *pos = strstr(actual->dato, "{a}");
        if (pos) {
            strncpy(pos, "a*", 2); 
            strcpy(pos + 2, pos + 3); // Elimina el caracter extra
        }
        actual = actual->siguiente;
    }
}

// Imprimir la expresión regular resultante
void imprimirExpresionRegular(Nodo *inicio) {
    printf("Expresión Regular Resultante:\n");
    Nodo *actual = inicio;
    while (actual) {
        printf("%s", actual->dato);
        actual = actual->siguiente;
    }
}
