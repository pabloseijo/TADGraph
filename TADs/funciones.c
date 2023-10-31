#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"
#include <string.h>

//FUNCIONES DEL PROGRAMA DE PRUEBA DE GRAFOS

/**
 * Opción a del menú, introducir un vertice en el grafo
 * @param G - Grafo
 */
void introducir_vertice(grafo *G) {
    //Declaramos las variables necesarias
    tipovertice v1;

    //Pedimos al usuario el vertice que quiere introducir
    printf("Introduce vertice (fin para finalizar): ");
    scanf(" %[^\r\n]", v1.nombrePoblacion);

    //Utilizamos un bucle while para introducir vertices mientras quiera el usuario
    while (strcmp(v1.nombrePoblacion, "fin") != 0 && strcmp(v1.nombrePoblacion, "FIN") != 0
    && strcmp(v1.nombrePoblacion, "Fin") != 0 && strcmp(v1.nombrePoblacion, "fIn") != 0 && strcmp(v1.nombrePoblacion, "fiN") != 0) {
        //Si el vertice ya existe, avisamos al usuario
        if (existe_vertice(*G, v1)) {
            printf("Ese vertice ya esta en el grafo\n");
        }
        //Si no existe, lo insertamos
        else {
            insertar_vertice(G, v1);
        }

        //Pedimos al usuario el vertice que quiere introducir
        printf("Introduce vertice (fin para finalizar): ");
        scanf(" %[^\r\n]", v1.nombrePoblacion);
    }
}

/**
 * Opción b del menú, eliminar un vértice del grafo
 * @param G - Grafo
 */
void eliminar_vertice(grafo *G) {
    tipovertice v1;
    //Pedimos al usuario el vertice que quiere eliminar
    printf("Introduce vertice (fin para finalizar): ");
    scanf(" %[^\r\n]", v1.nombrePoblacion);

    //Utilizamos un bucle while para eliminar vertices mientras quiera el usuario
    while (strcmp(v1.nombrePoblacion, "fin") != 0 && strcmp(v1.nombrePoblacion, "FIN") != 0
    && strcmp(v1.nombrePoblacion, "Fin") != 0 && strcmp(v1.nombrePoblacion, "fIn") != 0 && strcmp(v1.nombrePoblacion, "fiN") != 0) {
        //Si el vertice existe, lo eliminamos
        if (existe_vertice(*G, v1)) {
            borrar_vertice(G, v1);
        }
        //Si no existe, avisamos al usuario
        else {
            printf("Ese vertice no existe en el grafo\n");
        }
        //Pedimos al usuario el vertice que quiere eliminar
        printf("Introduce vertice (fin para finalizar): ");
        scanf(" %[^\r\n]", v1.nombrePoblacion);
    }
}

/**
 * Opción c del menú, crear una relación entre dos vértices
 * @param G - Grafo
 */
void nuevo_arco(grafo *G) {
    char eleccion = ' ';
    float distancia;
    tipovertice v1, v2;

    //Hacemos un bucle para que se repita la pregunta hasta que de una opcion valida
    while(strncmp(&eleccion, "A", 1) != 0 && strncmp(&eleccion, "C", 1) != 0
    && strncmp(&eleccion, "a", 1) != 0 && strncmp(&eleccion, "c", 1) != 0
    && eleccion != 'F' && eleccion != 'f'){
        printf("¿Deseas crear una Autopista (A) o una Carretera (C) (F para finalizar)? ");
        scanf(" %c", &eleccion);

        if(eleccion == 'f' || eleccion == 'F'){
            return;
        }
    }

    // Vértice origen del arco
    printf("\tIntroduce vertice origen (fin para finalizar): ");
    scanf(" %[^\r\n]", v1.nombrePoblacion);

    //Utilizamos un bucle while para añadir arcos mientras quiera el usuario
    while (strcmp(v1.nombrePoblacion, "fin") != 0 && strcmp(v1.nombrePoblacion, "FIN") != 0
    && strcmp(v1.nombrePoblacion, "Fin") != 0 && strcmp(v1.nombrePoblacion, "fIn") != 0 && strcmp(v1.nombrePoblacion, "fiN") != 0
    && eleccion != 'F' && eleccion != 'f') {
        // Comprobamos que el vertice existe
        if (!existe_vertice(*G, v1)) {
            printf("El vertice %s no existe en el grafo\n", v1.nombrePoblacion);
            return;
        }

        // Vértice destino del arco
        printf("\tIntroduce vertice destino: ");
        scanf(" %[^\r\n]", v2.nombrePoblacion);
        // Comprobamos que el vertice existe
        if (!existe_vertice(*G, v2)) {
            printf("El vertice %s no existe en el grafo\n", v2.nombrePoblacion);
            return;
        }
        // Introducimos la distancia a la que se encuentran los dos vertices
        printf("\tIntroduce la distancia: ");
        scanf("%f", &distancia);

        //Si el usuario ha elegido crear una autopista, comprobamos que no exista ya y si no existe, la creamos
        if (eleccion == 'A' || eleccion == 'a') {
            if (!son_adyacentes_autopista(*G, posicion(*G, v1), posicion(*G, v2))) {
                crear_arco_autopista(G, posicion(*G, v1), posicion(*G, v2), distancia);
            }
        }
        //Si el usuario ha elegido crear una carretera, comprobamos que no exista ya y si no existe, la creamos
        else if (eleccion == 'C' || eleccion == 'c') {
            if (!son_adyacentes_carretera(*G, posicion(*G, v1), posicion(*G, v2))) {
                crear_arco_carretera(G, posicion(*G, v1), posicion(*G, v2), distancia);
            }
        }

        //Restablecemos eleccion para preguntar al usuario de nuevo
        eleccion = ' ';

        while(strncmp(&eleccion, "A", 1) != 0 && strncmp(&eleccion, "C", 1) != 0
              && strncmp(&eleccion, "a", 1) != 0 && strncmp(&eleccion, "c", 1) != 0 && eleccion != 'F' && eleccion != 'f'){
            printf("¿Deseas crear una Autopista (A) o una Carretera (C) (F para finalizar)? ");
            scanf(" %c", &eleccion);

            if(eleccion == 'f' || eleccion == 'F'){
                return;
            }
        }

        // Vértice origen del arco
        printf("\tIntroduce vertice origen (fin para finalizar): ");
        scanf(" %[^\r\n]", v1.nombrePoblacion);
    }
}

/**
 * Opción d del menú, eliminar una relación entre dos vértices
 * @param G - Grafo
 */
void eliminar_arco(grafo *G) {
    //Declaramos las variables necesarias
    tipovertice v1, v2;
    char tipoConexion[20];

    //Pedimos al usuario el tipo de conexión que quiere eliminar
    printf("Tipo de conexion a eliminar (A/C): ");
    scanf("%s", tipoConexion);

    //Comprobamos que el tipo de conexión sea correcto
    if (strcmp(tipoConexion, "A") != 0 && strcmp(tipoConexion, "C") != 0
        && strcmp(tipoConexion, "a") != 0 && strcmp(tipoConexion, "c") != 0) {
        printf("Tipo de conexion no reconocido.\n");
        return;
    }

    //Vértice origen del arco
    printf("Introduce vertice origen: ");
    scanf(" %[^\r\n]", v1.nombrePoblacion);
    if (!existe_vertice(*G, v1)) {
        printf("El vertice %s no existe en el grafo\n", v1.nombrePoblacion);
        return;
    }

    //Vértice destino del arco
    printf("Introduce vertice destino: ");
    scanf(" %[^\r\n]", v2.nombrePoblacion);
    if (!existe_vertice(*G, v2)) {
        printf("El vertice %s no existe en el grafo\n", v2.nombrePoblacion);
        return;
    }

    //Si el tipo de conexión es autopista, comprobamos que son adyacentes y si lo son, borramos el arco
    if (strcmp(tipoConexion, "A") == 0 || strcmp(tipoConexion, "a") == 0) {
        if (son_adyacentes_autopista(*G, posicion(*G, v1), posicion(*G, v2))) {
            borrar_arco_autopista(G, posicion(*G, v1), posicion(*G, v2));
        }
    }
    //Si el tipo de conexión es carretera, comprobamos que son adyacentes y si lo son, borramos el arco
    else if (strcmp(tipoConexion, "c") == 0 || strcmp(tipoConexion, "c") == 0) {
        if (son_adyacentes_carretera(*G, posicion(*G, v1), posicion(*G, v2))) {
            borrar_arco_carretera(G, posicion(*G, v1), posicion(*G, v2));
        }
    }
}


/**
 * Opción i del menú, imprimir el grafo
 * @param G
 */
void imprimir_grafo(grafo G) {
    tipovertice *VECTOR; //Para almacenar el vector de vértices del grafo
    int N; //número de vértices del grafo

    //Para recorrerla, simplemente vamos a recorrer la matriz de adyacencia
    N = num_vertices(G);
    VECTOR = array_vertices(G);

    int i, j;
    printf("El grafo actual es:\n");
    for (i = 0; i < N; i++) {
        //Imprimo el vértice
        printf("Vertice(%d): %s\n", i, VECTOR[i].nombrePoblacion);
        //Chequeo sus arcos y los imprimo
        for (j = 0; j < N; j++) {
            if (son_adyacentes_autopista(G, i, j)) {
                printf("\tAutopista: %s --> %s\n", VECTOR[i].nombrePoblacion, VECTOR[j].nombrePoblacion);
            }

            if (son_adyacentes_carretera(G, i, j)) {
                printf("\tCarretera: %s --> %s\n", VECTOR[i].nombrePoblacion, VECTOR[j].nombrePoblacion);
            }
        }
    }
}

