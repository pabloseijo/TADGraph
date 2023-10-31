#ifndef FUNCIONES_H
#define FUNCIONES_H

#include "grafo.h"

//FUNCIONES DEL PROGRAMA DE PRUEBA DE GRAFOS

/**
 * introducir un vertice en el grafo
 * @param G - Grafo
 */
void introducir_vertice(grafo *G);

/**
 * eliminar un vértice del grafo
 * @param G - Grafo
 */
void eliminar_vertice(grafo *G);

/**
 * crear una relación entre dos vértices
 * @param G - Grafo
 */
void nuevo_arco(grafo *G);

/**
 * eliminar una relación entre dos vértices
 * @param G - Grafo
 */
void eliminar_arco(grafo *G);

/**
 * Función que carga el grafo desde un archivo
 * @param G - Grafo
 * @param argc - numero de parametros que se pasaron por linea de comandos
 * @param argv - puntero a array que contiene la informacion pasada por linea de comandos
 */
void cargar_grafo(grafo *G , int argc , char ** argv);

/**
 * imprimir el grafo
 * @param G
 */
void imprimir_grafo(grafo G);

/**
 * Actualizar los datos del archivo en funcion de los del grafo
 * @param G - Grafo
 * @param argc - numero de parametros que se pasaron por linea de comandos
 * @param argv - puntero a array que contiene la informacion pasada por linea de comandos
 */
void actualizar_archivo(grafo G, int argc , char ** argv);


#endif	/* FUNCIONES_H */

