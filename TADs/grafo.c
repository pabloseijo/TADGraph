#include "grafo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/////////////////////////////////////////////////////////// TIPOS DE DATOS

// Estructura privada
struct tipografo {
    int N; //número de vértices del grafo
    tipovertice VERTICES[MAXVERTICES]; //vector de vértices
    float C [MAXVERTICES][MAXVERTICES]; //matriz de adyacencia carretera
    float A [MAXVERTICES][MAXVERTICES]; //matriz de adyacencia autopista
};

//////////////////////////////////////////////////////////////// FUNCIONES

//HAY QUE MODIFICAR ESTA FUNCIÓN SI SE CAMBIA EL TIPO DE DATO tipovertice
/* 
 * Esta función devuelve 0 si los dos nodos son iguales
 * y un número distinto de 0 si son distintos
 */
int _comparar_vertices(tipovertice V1, tipovertice V2){
	return strncmp(V1.nombrePoblacion, V2.nombrePoblacion, MAXNOMBRE);
}

//Creación del grafo con 0 nodos
void crear_grafo(grafo *G) {
    *G = (struct tipografo*) malloc(sizeof (struct tipografo));
    (*G)->N = 0;
}

//Devuelve la posición del vértice Vert en el vector VERTICES del grafo G
//Si devuelve -1 es porque no encontró el vértice
int posicion(grafo G, tipovertice V) {
    int contador = 0;
    //comparo V con todos los vertices almacenados en VERTICES 
    while (contador < G->N) {
        //if (G->VERTICES[contador]==V)  //encontré la posicion de V
		if (_comparar_vertices(G->VERTICES[contador], V) == 0){
            return contador; 
        }
        contador++;
    }
    return -1;
}

//Devuelve 1 si el grafo G existe y 0 en caso contrario
int existe(grafo G) {
    return (G != NULL);
}

//Devuelve 1 si el vértice Vert existe en el grafo G
int existe_vertice(grafo G, tipovertice V) {
    return (posicion(G, V) >= 0);
}

//Inserta un vértice en el grafo, devuelve -1 si no ha podido insertarlo por estar el grafo lleno
int insertar_vertice(grafo *G, tipovertice Vert) {
    int i;
    if ((*G)->N == MAXVERTICES) {
    	// Se ha llegado al maximo numero de vertices
    	return -1;
    }
   
    (*G)->N++;
    (*G)->VERTICES[((*G)->N) - 1] = Vert;
    for (i = 0; i < (*G)->N; i++) {
        (*G)->A[i][((*G)->N) - 1] = 0;
        (*G)->A[((*G)->N) - 1][i] = 0;
    }
	return (*G)->N-1;
}

//Borra un vertice del grafo
void borrar_vertice(grafo *G, tipovertice Vert) {
    int F, C, P, N = (*G)->N;
    P = posicion(*G, Vert);
    if(P == -1){
    	return;
    }
    //if (P >= 0 && P < (*G)->N) {
    for (F = P; F < N - 1; F++){
        (*G)->VERTICES[F] = (*G)->VERTICES[F + 1];
	}
    for (C = P; C < N - 1; C++){
        for (F = 0; F < N; F++){
            (*G)->A[F][C] = (*G)->A[F][C + 1];
        }
	}
    for (F = P; F < N - 1; F++){
        for (C = 0; C < N; C++){
            (*G)->A[F][C] = (*G)->A[F + 1][C];
        }
	}
    (*G)->N--;    
}

//Crea el arco de relación entre VERTICES(pos1) y VERTICES(pos2) en la autopista
void crear_arco_autopista(grafo *G, int pos1, int pos2, float distancia) {
    (*G)->A[pos1][pos2] = distancia;
    (*G)->A[pos2][pos1] = distancia;
}

//Borra el arco de relación entre VERTICES(pos1) y VERTICES(pos2) en la autopista
void borrar_arco_autopista(grafo *G, int pos1, int pos2) {
    (*G)->A[pos1][pos2] = 0;
    (*G)->A[pos2][pos1] = 0;
}

//Crea el arco de relación entre VERTICES(pos1) y VERTICES(pos2) en la carretera
void crear_arco_carretera(grafo *G, int pos1, int pos2, float distancia) {
    (*G)->C[pos1][pos2] = distancia;
    (*G)->C[pos2][pos1] = distancia;
}

//Borra el arco de relación entre VERTICES(pos1) y VERTICES(pos2) en la carretera
void borrar_arco_carretera(grafo *G, int pos1, int pos2) {
    (*G)->C[pos1][pos2] = 0;
    (*G)->C[pos2][pos1] = 0;
}

/**
 * Devuelve la distancia entre dos vertices
 * @param G
 * @param pos1
 * @param pos2
 * @return
 */
float son_adyacentes_autopista(grafo G, int pos1, int pos2) {
    if(G->A[pos1][pos2] == 0){
        return 0;
    } else {
        return G->A[pos1][pos2];
    }
}

//Devuelve 1 si VERTICES(pos1) y VERTICES(pos2) son vértices adyacentes
float son_adyacentes_carretera(grafo G, int pos1, int pos2) {
    if(G->C[pos1][pos2] == 0){
    	return 0;
    } else {
    	return G->C[pos1][pos2];
    }
}

//Destruye el grafo
void borrar_grafo(grafo *G) {
    free(*G);
    *G = NULL;
}

//Devuelve el número de vértices del grafo G
int num_vertices(grafo G) {
    return G->N;
}

//Devuelve el vector de vértices VERTICES del grafo G
tipovertice* array_vertices(grafo G) {
    return G->VERTICES;
}

