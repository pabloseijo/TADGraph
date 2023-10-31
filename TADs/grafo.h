#ifndef GRAFO_H

#define GRAFO_H

#define MAXVERTICES 100 /*maximo numero de nodos*/
#define MAXNOMBRE 30 /*maximo numero de caracteres en el nombre de un nodo*/

/*
 * Implementación estática del TAD grafo con una matriz
 * de adjacencias con máximo número de vértices MAXVERTICES 
 */

/////////////////////////////////////////////////////////// TIPOS DE DATOS

//Información que se almacena en cada vértice
typedef struct{
    char nombrePoblacion[MAXNOMBRE];
}tipovertice;

typedef struct tipografo * grafo;

//////////////////////////////////////////////////////////////// FUNCIONES


//Creación del grafo con 0 nodos
void crear_grafo(grafo *G);

//Devuelve la posición del vértice Vert en el vector VERTICES del grafo G
//Si devuelve -1 es porque no encontró el vértice
int posicion(grafo G, tipovertice Vert);

//Devuelve 1 si el grafo G existe y 0 en caso contrario
int existe(grafo G);

//Devuelve 1 si el vértice Vert existe en el grafo G
int existe_vertice(grafo G, tipovertice Vert);

//Inserta un vértice en el grafo
// Devuelve la posición en el que ha sido insertado el
// vértice o -1 si no se ha conseguido insertar el vértice
int insertar_vertice(grafo *G, tipovertice Vert);

//Borra un vértice del grafo
void borrar_vertice(grafo *G, tipovertice Vert);

//Crea el arco de relación entre VERTICES(pos1) y VERTICES(pos2) en la autopista
void crear_arco_autopista(grafo *G, int pos1, int pos2, float distancia);

//Borra el arco de relación entre VERTICES(pos1) y VERTICES(pos2) en la autopista
void borrar_arco_autopista(grafo *G, int pos1, int pos2);

//Crea el arco de relación entre VERTICES(pos1) y VERTICES(pos2) en la carretera
void crear_arco_carretera(grafo *G, int pos1, int pos2, float distancia);

//Borra el arco de relación entre VERTICES(pos1) y VERTICES(pos2) en la carretera
void borrar_arco_carretera(grafo *G, int pos1, int pos2);

/**
 * Devuelve la distancia entre dos vertices
 * @param G - Grafo
 * @param pos1 - Posicion del vertice 1
 * @param pos2 - Posicion del vertice 2
 * @return
 */
float son_adyacentes_autopista(grafo G, int pos1, int pos2);

/**
 * Devuelve la distancia entre dos vertices
 * @param G - Grafo
 * @param pos1  - Posicion del vertice 1
 * @param pos2 - Posicion del vertice 2
 * @return
 */
float son_adyacentes_carretera(grafo G, int pos1, int pos2);

//Destruye el grafo
void borrar_grafo(grafo *G);

//Devuelve el número de vértices del grafo G
int num_vertices(grafo G);

//Devuelve el vector de vértices VERTICES del grafo G
tipovertice* array_vertices(grafo G);

#endif	/* GRAFO_H */
