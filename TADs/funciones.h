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
 * imprimir el grafo
 * @param G
 */
void imprimir_grafo(grafo G);


#endif	/* FUNCIONES_H */

