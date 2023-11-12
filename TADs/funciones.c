#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"
#include <string.h>

#define INF INT16_MAX // Un valor grande para representar la ausencia de camino


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
        scanf(" %f", &distancia);

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
            if (son_adyacentes_autopista(G, i, j) != 0) {
                printf("\t==> %s (%.2f km)\n", VECTOR[j].nombrePoblacion, son_adyacentes_autopista(G, i, j));
            }

            if (son_adyacentes_carretera(G, i, j) != 0) {
                printf("\t--> %s (%.2f km)\n", VECTOR[j].nombrePoblacion, son_adyacentes_carretera(G, i, j));
            }
        }
    }
}

/**
 * Función que carga el grafo desde un archivo
 * @param G - Grafo
 * @param argc - numero de parametros que se pasaron por linea de comandos
 * @param argv - puntero a array que contiene la informacion pasada por linea de comandos
 */
void cargar_grafo(grafo *G , int argc , char ** argv){
    //Declaramos las variables necesarias;
    FILE *f;
    tipovertice v1, v2;
    char tipoConexion[20], aux[20];
    float distancia;


    // Si el numero de parametros es menor que dos salimos de la funcion
    if(argc < 2){
        return;
    }

    //Abrimos el archivo
    if((f = fopen(argv[1], "r")) == NULL){
        printf("Error al abrir el archivo\n");
        return;
    }

    // Mover el indicador de archivo al final del archivo
    fseek(f, 0, SEEK_END);
    // Comprobar si el archivo está vacío
    if (ftell(f) == 0) {
        fclose(f);
        return;
    }
    // Mover el indicador de archivo al inicio del archivo para comenzar a leer
    rewind(f);

    //Mientras no llegue al final del archivo, vamos leyendo los datos
    while(!feof(f)) {
        //Leemos los datos
        fscanf(f, "%[^-=]%[^ ] %[^;];%f;%s\n", v1.nombrePoblacion, aux,v2.nombrePoblacion, &distancia, tipoConexion);

        if (existe_vertice(*G, v1) == 0) {
            insertar_vertice(G, v1);
        }
        if (existe_vertice(*G, v2) == 0) {
            insertar_vertice(G, v2);
        }

        //Si el vertice no existe, lo insertamos
        if(strcmp(tipoConexion,"autopista") == 0){
            crear_arco_autopista(G, posicion(*G, v1), posicion(*G, v2), distancia);
        }
        else if(strcmp(tipoConexion,"carretera") == 0){
            crear_arco_carretera(G, posicion(*G, v1), posicion(*G, v2), distancia);
        }
        else{
            continue;
        }
    }

    //Cerramos el archivo
    fclose(f);
}

/**
 * Actualizar los datos del archivo en funcion de los del grafo
 * @param G - Grafo
 * @param argc - numero de parametros que se pasaron por linea de comandos
 * @param argv - puntero a array que contiene la informacion pasada por linea de comandos
 */
void actualizar_archivo(grafo G, int argc , char ** argv){
    //Declaramos las variables necesarias;
    FILE *f;
    char nombreArchivo[20];

    // Si el numero de parametros es menor que dos salimos de la funcion
    if(argc < 2){
        strcpy(nombreArchivo, "grafo.txt");
    }
    else{
        strcpy(nombreArchivo, argv[1]);
    }

    //Abrimos el archivo
    if((f = fopen(nombreArchivo, "w")) == NULL){
        printf("Error al abrir el archivo\n");
        return;
    }

    //Recorremos el grafo
    for(int i = 0 ; i < num_vertices(G) ; i++){
        //Recorremos los arcos de cada vertice
        for(int j = 0 ; j < num_vertices(G) ; j++){
            //Si son adyacentes, obtenemos la distancia y el tipo de conexion y lo escribimos en el archivo
            if(son_adyacentes_autopista(G, i, j) != 0){
                fprintf(f, "%s=> %s;%.2f;autopista\n", array_vertices(G)[i].nombrePoblacion, array_vertices(G)[j].nombrePoblacion,
                        son_adyacentes_autopista(G, i, j));
            }
            if(son_adyacentes_carretera(G, i, j) != 0){
                fprintf(f, "%s-> %s;%.2f;carretera\n", array_vertices(G)[i].nombrePoblacion, array_vertices(G)[j].nombrePoblacion,
                        son_adyacentes_carretera(G, i, j));
            }
        }
    }

    //Cerramos el archivo
    fclose(f);
}

/**
 * Funcion que imprime la ruta mas corta entre dos ciudades
 * @param G - Grafo
 * @param P - Matriz de vértices previos
 * @param origen - Ciudad de origen
 * @param destino - Ciudad de destino
 * @param VECTOR - Vector de vértices del grafo
 * @param factorA - Factor de escala para autopistas
 * @param factorC - Factor de escala para carreteras
 */
void imprimir_camino(grafo G, int P[MAXVERTICES][MAXVERTICES], int origen, int destino, tipovertice *VECTOR, float factorA, float factorC) {
    if (origen != destino) {
        imprimir_camino(G, P, origen, P[origen][destino], VECTOR, factorA, factorC); // Llamada recursiva al siguiente vértice en la ruta
    }

        // Ahora se imprime la conexión con el destino final, pero se debería imprimir después de la llamada recursiva
    if(son_adyacentes_autopista(G,P[origen][destino], destino) != 0 && son_adyacentes_carretera(G,P[origen][destino],destino) != 0){
        if(son_adyacentes_autopista(G,P[origen][destino],destino) * factorA < son_adyacentes_carretera(G,P[origen][destino],destino) * factorC){
            printf("=> %s ", VECTOR[destino].nombrePoblacion); // Conexión por autopista
        }
        else{
            printf("-> %s ", VECTOR[destino].nombrePoblacion); // Conexión por carretera
        }
    }
    else if (son_adyacentes_autopista(G, P[origen][destino], destino) != 0) {
        printf("=> %s ", VECTOR[destino].nombrePoblacion); // Conexión por autopista
    } else if (son_adyacentes_carretera(G, P[origen][destino], destino) != 0) {
        printf("-> %s ", VECTOR[destino].nombrePoblacion); // Conexión por carretera
    } else {
        // Esto solo debería ocurrir si hay un error, ya que siempre debería haber una conexión entre los nodos de la ruta
        printf(" %s ", VECTOR[destino].nombrePoblacion); // Sin conexión conocida
    }
}

/**
 * Funcion que suma la distancia de la ruta mas corta entre dos ciudades
 * @param G - Grafo
 * @param P - Matriz de vértices previos
 * @param origen - Ciudad de origen
 * @param destino - Ciudad de destino
 * @param VECTOR - Vector de vértices del grafo
 * @param factorA - Factor de escala para autopistas
 * @param factorC - Factor de escala para carreteras
 * @return Distancia/Coste/Tiempo total de la ruta
 */
float sumar_camino(grafo G, int P[MAXVERTICES][MAXVERTICES], int origen, int destino, tipovertice *VECTOR, float factorA, float factorC ) {

    float distancia = 0.0;

    if (origen != destino) {
        distancia += sumar_camino(G, P, origen, P[origen][destino], VECTOR, factorA, factorC); // Llamada recursiva al siguiente vértice en la ruta
    }

    // Ahora se imprime la conexión con el destino final, pero se debería imprimir después de la llamada recursiva
    if(son_adyacentes_autopista(G,P[origen][destino], destino) != 0 && son_adyacentes_carretera(G,P[origen][destino],destino) != 0){
        if(son_adyacentes_autopista(G,P[origen][destino],destino) * factorA < son_adyacentes_carretera(G,P[origen][destino],destino) * factorC){
            distancia += son_adyacentes_autopista(G, P[origen][destino], destino) * factorA; // Conexión por autopista
        }
        else{
            distancia += son_adyacentes_carretera(G, P[origen][destino], destino) * factorC; // Conexión por carretera
        }
    }
    else if (son_adyacentes_autopista(G, P[origen][destino], destino) != 0) {
        distancia += son_adyacentes_autopista(G, P[origen][destino], destino) * factorA; // Conexión por autopista
    } else if (son_adyacentes_carretera(G, P[origen][destino], destino) != 0) {
        distancia += son_adyacentes_carretera(G, P[origen][destino], destino) * factorC; // Conexión por carretera
    } else {
        // Esto solo debería ocurrir si hay un error, ya que siempre debería haber una conexión entre los nodos de la ruta
        distancia += 0; // Sin conexión conocida
    }

    return distancia;
}

/**
 * Función que calcula la ruta más corta entre dos ciudades
 * @param G - Grafo
 */
void Floyd_Warshall (grafo G, char opcion){

    /* DECLARACION DE VARIABLES */
    // Matriz de distancias
    float D[MAXVERTICES][MAXVERTICES];
    // Matriz de vértices previos
    int P[MAXVERTICES][MAXVERTICES];
    // Variables auxiliares para los bucles
    int i, j, k;
    //Inicializamos las variables de escala
    float factorA = 0, factorC = 0;

    tipovertice v1, v2; // Vértices origen y destino del arco
    int N = num_vertices(G); // Número de vértices del grafo
    tipovertice *VECTOR = array_vertices(G); // Vector de vértices del grafo

    // Establecer factores de escala según el tipo de grafo
    switch (opcion) {
        case 'f': case 'F':
            factorA = 1.0;
            factorC = 1.0;
            break;
        case 'g': case 'G':
            factorA = 1.0 / 120.0;
            factorC = 1.0 / 70.0;
            break;
        case 'h': case 'H':
            factorA = 1.0 * 0.07;
            factorC = 1.0 * 0.01;
            break;
        default:
            // Manejar casos no válidos o asignar valores predeterminados
            factorA = 1.0;
            factorC = 1.0;
            break;
    }

    // Inicialización de las matrices D y P
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            // Si i == j, la distancia es 0 y no hay vértice previo
            if (i == j) {
                D[i][j] = 0;
                P[i][j] = -1; // No hay vértice previo para el mismo nodo
            }
            else if(son_adyacentes_autopista(G,i,j) != 0 && son_adyacentes_carretera(G,i,j) != 0){
                if(son_adyacentes_autopista(G,i,j) * factorA < son_adyacentes_carretera(G,i,j) * factorC){
                    D[i][j] = son_adyacentes_autopista(G,i,j) * factorA; // Distancia directa de i a j
                    P[i][j] = i; // El vértice previo es i mismo
                }
                else{
                    D[i][j] = son_adyacentes_carretera(G,i,j) * factorC; // Distancia directa de i a j
                    P[i][j] = i; // El vértice previo es i mismo
                }
            }
            // Sino, si son adyacentes por carretera, la distancia es la directa
            else if (son_adyacentes_carretera(G,i,j) != 0) {
                D[i][j] = son_adyacentes_carretera(G,i,j) * factorC; // Distancia directa de i a j
                P[i][j] = i; // El vértice previo es i mismo
            }
            // Sino, si son adyacentes por autopista, la distancia es la directa
            else if (son_adyacentes_autopista(G,i,j) != 0) {
                D[i][j] = son_adyacentes_autopista(G,i,j) * factorA; // Distancia directa de i a j
                P[i][j] = i; // El vértice previo es i mismo
            }
            // Sino, no hay conexión directa
            else {
                D[i][j] = INF; // No hay conexión directa
                P[i][j] = -1;
            }
        }
    }

    // Algoritmo de Floyd-Warshall
    for (k = 0; k < N; k++) {
        // Actualizar las matrices D y P
        for (i = 0; i < N; i++) {
            for (j = 0; j < N; j++) {
                // Si la distancia de i a j es mayor que la de i a k más la de k a j y no son infinitas las distancias
                // de i a k y de k a j, actualizamos la distancia de i a j y el vértice previo
                if (D[i][k] != INF && D[k][j] != INF && D[i][j] > D[i][k] + D[k][j]) {
                    D[i][j] = D[i][k] + D[k][j]; // Actualizar la distancia
                    P[i][j] = P[k][j]; // Actualizar el vértice previo
                }
            }
        }
    }

    /* PREGUNTAMOS AL USUARIO */

    //Vértice origen del arco
    printf("Introduce vertice origen: ");
    scanf(" %[^\r\n]", v1.nombrePoblacion);
    if (!existe_vertice(G, v1)) {
        printf("El vertice %s no existe en el grafo\n", v1.nombrePoblacion);
        return;
    }

    //Vértice destino del arco
    printf("Introduce vertice destino: ");
    scanf(" %[^\r\n]", v2.nombrePoblacion);
    if (!existe_vertice(G, v2)) {
        printf("El vertice %s no existe en el grafo\n", v2.nombrePoblacion);
        return;
    }

    /* IMPRIMIMOS */

    // Establecer factores de escala según el tipo de grafo
    switch (opcion) {
        case 'f': case 'F':
            printf("La ruta mas corta entre %s y %s es de %.2f km\n", v1.nombrePoblacion, v2.nombrePoblacion,
                   sumar_camino(G, P, posicion(G, v1), posicion(G, v2), VECTOR, factorA, factorC));
            printf("\tRuta: ");
            imprimir_camino(G, P, posicion(G, v1), posicion(G, v2), VECTOR, factorA, factorC);
            printf("\n");
            break;
        case 'g': case 'G':
            printf("La ruta mas rapida entre %s y %s es de %.2f horas\n", v1.nombrePoblacion, v2.nombrePoblacion,
                   sumar_camino(G, P, posicion(G, v1), posicion(G, v2), VECTOR, factorA, factorC ));
            printf("\tRuta: ");
            imprimir_camino(G, P, posicion(G, v1), posicion(G, v2), VECTOR, factorA, factorC);
            printf("\n");
            break;
        case 'h': case 'H':
            printf("La ruta mas economica entre %s y %s es de %.2f €\n", v1.nombrePoblacion, v2.nombrePoblacion,
                   sumar_camino(G, P, posicion(G, v1), posicion(G, v2), VECTOR, factorA, factorC));
            printf("\tRuta: ");
            imprimir_camino(G, P, posicion(G, v1), posicion(G, v2), VECTOR, factorA, factorC);
            printf("\n");
            break;
        default:
            imprimir_camino(G, P, posicion(G, v1), posicion(G, v2), VECTOR, factorA, factorC);
            printf("\n");
            break;
    }



}

/**
 * Función que la minima ruta de conexion para que todas las ciudades esten conectadas
 * @param G - Grafo
 */
void Prim(grafo G){
    /* DECLARACION DE VARIABLES */

    int numArcos = 0; // Número de arcos del grafo
    float distanciaTotal = 0; // Distancia total de la ruta
    int numVertices = num_vertices(G); // Número de vértices del grafo
    int i, j; // Variables auxiliares para los bucles

    char *tipo; // Tipo de conexión
    tipo = (char *) malloc(2 * sizeof(char)); // Reservamos memoria para el tipo de conexión

    float factorA = 1.0/120.0, factorC = 1.0/70.0; // Factores de escala para autopistas y carreteras

    int Selected[numVertices]; // Array de vértices seleccionados
    for (i = 0; i < numVertices; i++) Selected[i] = 0; //Incializamos el array de vértices seleccionados

    /* ALGORITMO DE PRIM */

    //Iniciamos el algortimo con el primer vértice
    Selected[0] = 1;

    //Mientras no hayamos seleccionado todos los vértices
    while(numArcos < numVertices - 1){
        //Inicializamos el minimo a infinito
        float minimo = INF;
        int vx = 0, vy = 0;

        //Busco el arco x-y con valor minimo, con Selected(vx) = 1 y Selected(vy) = 0
        for (i = 0 ; i < numVertices; i++){
            if(Selected[i] == 1){
                for(j = 0; j<numVertices; j++){
                    if(Selected[j] != 1){
                        //Si son adyacentes por autopista y carretera, comprobamos cual es menor
                        if(son_adyacentes_autopista(G,i,j) != 0 && son_adyacentes_carretera(G,i,j) != 0){
                            //Si son adyacentes por autopista, comprobamos si es menor que el minimo
                            if(son_adyacentes_autopista(G,i,j) * factorA < minimo){
                                minimo = son_adyacentes_autopista(G,i,j) * factorA;
                                vx = i;
                                vy = j;
                                strcpy(tipo, "==");
                            }
                            //Si son adyacentes por carretera, comprobamos si es menor que el minimo
                            if(son_adyacentes_carretera(G,i,j) * factorC < minimo){
                                minimo = son_adyacentes_carretera(G,i,j) * factorC;
                                vx = i;
                                vy = j;
                                strcpy(tipo, "--");
                            }
                        }
                        //Si son adyacentes por autopista, comprobamos si es menor que el minimo
                        else if(son_adyacentes_autopista(G,i,j) != 0){
                            if(son_adyacentes_autopista(G,i,j) * factorA < minimo){
                                minimo = son_adyacentes_autopista(G,i,j) * factorA;
                                vx = i;
                                vy = j;
                                strcpy(tipo, "==");
                            }
                        }
                        //Si son adyacentes por carretera, comprobamos si es menor que el minimo
                        else if(son_adyacentes_carretera(G,i,j) != 0){
                            if(son_adyacentes_carretera(G,i,j) * factorC < minimo){
                                minimo = son_adyacentes_carretera(G,i,j) * factorC;
                                vx = i;
                                vy = j;
                                strcpy(tipo, "--");
                            }
                        }
                    }
                }
            }
        }

        //Vx-vy es el arco con valor minimo que añade vy al conjunto de vértices seleccionados
        Selected[vy] = 1;
        numArcos++;
        //Imprimimos el arco
        printf("%-10s %-5s %-10s : %10.2f horas\n", array_vertices(G)[vx].nombrePoblacion, tipo, array_vertices(G)[vy].nombrePoblacion, minimo);
        //Sumamos la distancia al total
        distanciaTotal += minimo;
    }

    printf("Tiempo del arbol de expansion de coste minimo: %.2f horas\n", distanciaTotal);
    //Liberamos memoria
    free(tipo);
}