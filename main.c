#include <stdio.h>
#include <stdlib.h>
#include "TADs/funciones.h"

/*
 * Programa que muestra el uso del TAD grafo de números enteros
 * @Author: Pablo Seijo García
 * @Date: 12 nov 2023
 * @Version: 1.0
 * @Company: USC (University of Santiago de Compostela)
 */

int main(int argc, char** argv) {
    //Grafo de números enteros
    grafo G; //grafo
    char opcion;

    //Creo el grafo
    crear_grafo(&G);

    //Cargo el grafo desde un archivo (si se ha pasado por linea de comandos)
    cargar_grafo(&G, argc, argv);

    do {
        printf("\na. Insertar nuevos vertices\n");
        printf("b. Eliminar vertice\n");
        printf("c. Crear Arco (Carretera o Autopista)\n");
        printf("e. Eliminar Arco (Carretera o Autopista)\n");
        printf("i. Imprimir grafo\n");
        printf("f. Imprimir ruta mas corta\n");
        printf("g. Imprimir ruta mas rapida\n");
        printf("h. Imprimir ruta mas economica\n");
        printf("j. Imprimir a mínima infraestrutura de conexións que fai que as cidades estean conectadas\n");
        printf("s. Salir\n");

        printf("Opcion: ");
        scanf(" %c", &opcion);

        switch (opcion) {
            case 'a':case'A':
                introducir_vertice(&G);
                break;

            case 'b':case 'B':
                eliminar_vertice(&G);
                break;

            case 'c': case 'C':
                nuevo_arco(&G);
                break;

            case 'e': case 'E':
                eliminar_arco(&G);
                break;

            case 'i': case 'I':
                imprimir_grafo(G);
                break;

            case 'f': case 'F':
                Floyd_Warshall(G, opcion);
                break;

            case 'g': case 'G':
                Floyd_Warshall(G, opcion);
                break;

            case 'h': case 'H':
                Floyd_Warshall(G, opcion);
                break;

            case 'j': case 'J':
                printf("Si calculo el arbol de expresion que conecta todas las ciudades con el minimo valor global de tiempo:\n");
                Prim(G);
                break;

            case 's': case 'S':
                opcion='s';
                break;

            default:
                printf("Opción equivocada\n");
                break;
        }

    } while (opcion != 's');

    //Actualizo el archivo con los datos del grafo
    actualizar_archivo(G, argc, argv);

    //Al salir, liberamos la memoria del TAD, lo destruimos
    borrar_grafo(&G);

    return (EXIT_SUCCESS);
}

