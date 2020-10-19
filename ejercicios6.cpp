#include <iostream>
#include <cmath> //Función abs
#include<tuple> //Para poder usar las tuplas
#include "ejercicios6.h"

using namespace std;

#import <algorithm> //Para ordenar la lista

/************* Ejercicio 1 *************/
void mostrarMatriz(vector<vector<int>> mat) {
    for (int i=0;i<mat.size();i++){
        for (int j=0;j<mat[0].size();j++) {
            cout << mat[i][j] << "\t";
        }
        cout << "\n";
    }
}


/************* Ejercicio 2 *************/
//a)

int productoPunto(vector<int> v1, vector<int> v2 ) {
    if (v1.size() != v2.size() ) {
        cout << "Media pila man, producto punto sólo se hace con vectores de igual longitud";
        return  0;
    }
    int producto =0;
    for (int i =0; i<v1.size();i++) {
        producto += v1[i] * v2[i];
    }
    return producto;
}

//b) Yo se que las columnas de la matriz transpuesta son las filas de la original, además
// se que la si A x B = C -> C_ij (la posición (i,j) de C) = fila i de A * columna j de B, por
// lo que si B = A^t nos queda que C_ij = fila i de A * fila j de A. De esta forma no hace
// falta hacer la transpuesta y luego multiplicar las matrices.


vector<vector<int>> produTranspuesta(vector<vector<int>> mat) {
    int longi = mat.size();
    vector<vector<int>> producto( longi, vector<int>(longi) );
    for (int i=0;i<longi; i++) {
        for (int j=0;j<longi; j++) {
            producto[i][j] = productoPunto(mat[i], mat[j]);
        }
    }
    return producto;
}


//Fue lo que iba a hacer antes de pensar la idea de no usar directamente la transpuesta

vector<int> columnaMatriz(vector<vector<int>> mat, int colu){
    vector<int> colum;
    if (colu<0 || colu >= mat[0].size() ) {
        cout << "Esa columna no existe";
        return colum;
    }
    for (int i=0; i<mat.size(); i++) { //Me "paro" sobre la columna y recorro las filas
        colum.push_back(mat[i][colu]);
    }
    return  colum;
}

vector<vector<int>> productoMatrices(vector<vector<int>> mat1, vector<vector<int>> mat2){
    vector<vector<int>> producto( mat1.size(), vector<int>(mat2[0].size()) );
    if( mat1[0].size() != mat2.size() ) {
        cout << "No es una multiplicacion valida de matrices";
        return producto;
    }
    for (int i=0; i< mat1.size(); i++) {
        for (int j=0; j<mat2[0].size(); j++){
            vector<int> columna = columnaMatriz(mat2,j);
            producto[i][j] = productoPunto(mat1[i],columna);
        }
    }
    return  producto;
}

/************* Ejercicio 3 *************/

//Interprete escribir un algoritmo cómo hacer una función en C++ que haga lo pedido
//Devuelve una matriz de n2 filas y m2 columnas

vector<vector<int>> redimensionarMatriz(vector<vector<int>> mat, int n2, int m2) {
    vector<vector<int>> redimensionado( n2, vector<int>(m2) );
    if ( n2*m2 != mat.size()*mat[0].size() ) {
        cout << "No son redimensiones validas para esta matriz";
        return redimensionado;
    }

    int i_2 =0, j_2=0; //Las coordenadas de la nueva matriz redimensionada
    for (int i=0;i<mat.size(); i++) {
        for (int j=0;j<mat[0].size();j++) {
            redimensionado[i_2][j_2] = mat[i][j];
            j_2++;
            if (j_2 == m2) { //Llega al final de la columna de la matriz redimensionada
                j_2=0;
                i_2++;
            }
        }
    }
}


/************* Ejercicio 4 *************/
//Por la precondición que da la especificación entiendo que hay que trasponer matrices cuadradas.
//Igualmente el programa a continuación funciona para matrices no cuadradas también

//Yo se que las filas  de la matriz transpuesta son las columnas de la original.

//Forma medio tramposa pero sencilla de entender
void trasponer(vector<vector<int>>& mat) {
    vector<vector<int>> transpuesta(mat[0].size(), vector<int>(mat.size()) );
    for (int i=0;i<mat[0].size();i++){
        transpuesta[i] = columnaMatriz(mat,i);
    }
    mat = transpuesta;
}



/************* Ejercicio 5 *************/
bool esPico(vector<vector<int>> mat,int i,int j) {
    bool pico=true;
    for (int k =i-1; k<i+2;k++) {
        if ( k>=0 && k<mat.size() ) { //Si k está en rango
            for (int l = j - 1; l < j + 2; l++) {
                if ( (l>=0 && l<mat.size())  && (mat[k][l] > mat[i][j] ) && (l!=j || k!=i)) {
                    pico=false;
                    break;
                }
            }
        }
    }
    return pico;
}

int contarPicos(vector<vector<int>> mat){
    int picos=0;
    for (int i=0;i<mat.size();i++) {
        for (int j=0; j<mat[0].size();j++) {
            if (esPico(mat,i,j)) {
                picos++;
                cout << mat[i][j] << "  ";
            }
        }
    }
    return picos;
}

/************* Ejercicio 6 *************/

//a) Guardo los valores distintos de 0 de la matriz

tuple< tuple<int, int>, vector<tuple<int, int, int>> > aTriplas(vector<vector<int> > m) {
    tuple<int, int> dimen = make_tuple(m.size(),m[0].size());
    vector<tuple<int, int, int>> valores_no_nulos;
    for (int i =0; i<m.size();i++) {
        for (int j=0;j<m[0].size();j++) {
            if (m[i][j] != 0) {
                tuple<int, int, int> tupla_valor = make_tuple(i,j,m[i][j]);
                valores_no_nulos.push_back(tupla_valor);
            }
        }
    }
    tuple< tuple<int, int>, vector<tuple<int, int, int>> > devolucion = make_tuple(dimen, valores_no_nulos);
    return  devolucion;
}

//b) Recorro la lista de (coordenadas+valores) y reconstruyo la matriz a partir de las mismas.

vector<vector<int>> aMatriz(vector<tuple<int, int, int>> m, tuple<int, int> dim) {
    vector<vector<int>> matriz(get<0>(dim), vector<int>( get<1>(dim)) );
    for (int i=0; i<m.size();i++) {
        matriz[ get<0>(m[i]) ][ get<1>(m[i]) ] = get<2>(m[i]);
    }
    return matriz;
}

//c)

void transponerDispersa(vector<tuple<int, int, int>>& m) {
    for (int i=0; i<m.size();i++) {
        m[i] = make_tuple(get<1>(m[i]),get<0>(m[i]),get<2>(m[i])); //Invierto las posiciones i,j
    }
}

/************* Ejercicio 7 *************/

//La idea es tengo un tensor llamado "data" que tiene todos los datos, y al acceder de la
// forma " data[i][j][k] -> I: posición en N, J: posición en M; T: tiempo transcurrido


//a)
vector<vector<float>> temperatura_tiempo_promedio(vector<vector<vector<float>>> temps) {
        vector<vector<float>> temps_prome(temps.size(), vector<float>(temps[0].size() ));
        float tempe_prome;
        for (int i=0;i<temps.size();i++) {
            for (int j=0;j<temps[0].size();j++) {
                tempe_prome = 0;
                for (int k=0;k<temps[0][0].size();k++) { //Sumo todas las temperaturas en ese rango de tiempo
                    tempe_prome += temps[i][j][k];
                }
                temps_prome[i][j] = tempe_prome/temps[0][0].size();
            }
        }
    return temps_prome;
}

//b)

vector<float> temperatura_zona_promedio(vector<vector<vector<float>>> temps) {
    vector<float> temps_zona(temps[0][0].size());
    float tempe_prome;
    for (int k=0;k<temps[0][0].size();k++) { //Dejo fija la temperatura y reviso las temps de la zona
        tempe_prome=0;
        for (int i=0;i<temps.size();i++) {
            for (int j=0;j<temps[0].size();j++) {
                tempe_prome += temps[i][j][k];
            }
        }
        temps_zona[k] = tempe_prome/ (temps.size() * temps[0].size());
    }
    return temps_zona;
}


/************* Ejercicio 8 *************/

//a)
void elevar(vector<vector<int>> &terreno, int x) {
    for (int i=0;i<terreno.size();i++) {
        for (int j=0;j<terreno[0].size();j++) {
            terreno[i][j] += x;  //Elevo la posición del terreno
        }
    }
}

//b)

int celdas_menores_a(vector<vector<int>> terreno, int debajo) {
    int celdas_debajo=0;
    for (int i=0;i<terreno.size();i++) {
        for (int j=0;j<terreno[0].size();j++) {
            if( terreno[i][j]<debajo) {  //Si la posición esta debajo del límite marcado la cuento
                celdas_debajo++;
            }
        }
    }
    return celdas_debajo;
}

//La idea es ir revisando si hay una cierta altura a la que exactamente n posiciones son menores,
// si al ir disminuyendo o aumentando esa altura (que originalmente era 0) me paso de n entonces
// significa que no existe la misma puesto habrá n+1,n-1 u otra cantidad de posiciones que sean
// menores a una altura específica.


//Hecho sin usar el ordenamiento de listas
bool sobresalen(vector<vector<int>> terreno, int n, int& mts) {
    bool sobre = false;
    int cant_celdas;
    if (n > terreno.size() * terreno[0].size() && n<0) { // Si n no cumple "la precondición"
        return  sobre;
    }
    mts =0;
    int variacion=0; //Esto va a ser un +1 o -1 según el primer chequeo
    cant_celdas = celdas_menores_a(terreno,mts);
    if ( cant_celdas < n ) {
        variacion=1;
    }
    else if ( cant_celdas > n  ){
        variacion =-1;
    }
    else { //Este caso es cuándo son iguales
        return sobre;
    }
    bool proceso = true;
    while (proceso) {
        mts += variacion;
        cant_celdas = celdas_menores_a(terreno,mts);
        if (cant_celdas == n) { // Si aumentando variación le "pegue justo".
            proceso = false;
            sobre= true;
        }
        if (( variacion == -1 && cant_celdas<n) ||  ( variacion == 1 && cant_celdas>n)) { //Si me "pase" del número sin llegar a n
            proceso=false; //Termina el proceso
        }
    }
    return sobre;


}



//Hecho usando ordenamiento de listas

// Si tengo una lista ordenada s = (-10,-9,-3,-4,2,3,4,4,6,7,8,9)
//Entonces n = 3 es viable pues si resto s[2]+1 a todas las posiciones quedan exactamente
// 3 posiciones debajo. Pero si n =7, entonces al restar n[6]+1 entonces quedan 8 posiciones,
// debajo pues n[6]==n[7], por lo tanto sería imposible encontrar un mts.

bool sobresalen_kul(vector<vector<int>> terreno, int n, int& mts){
    if (n > terreno.size() * terreno[0].size() && n<0) { // Si n no cumple "la precondición"
        return  false;
    }
    vector<int> alturas = redimensionarMatriz(terreno,1,terreno.size() * terreno[0].size() && n<0)[0];  //Convierto la matriz a un vector unidimensional
    sort(alturas.begin(),alturas.end());
    int nesima_altura = alturas[n-1];
    if (nesima_altura == alturas[n]){ //Significa que nunca va a haber exactamente n alturas menores a algo
        return false;
    }
    mts = nesima_altura+1;
    return true;


}

//c) Dividi el proceso en tres partes:

//1) Usar una matriz parte en la cuál "etiquetar" las posiciones, dividiendo a las tierras por
//isla y a las que son agua metiendolas en una "isla 0". Los bordes

//Además si encuentro que dos vecinos están en diferentes islas unifico esas islas diciendo que
//isla_1=isla_2.

//2)  Luego reviso las posiciones taggeadas y me fijo si las posiciones cumplen las caracteristícas
// de una isla. Que son 3: Tener vecinos tierra de misma isla /  tener vecinos de agua / no estar en bordes

//3) Contar las islas válidas que hay.

//PD: Para que sea isla tiene que estar rodeada de AGUA, por lo tanto no cuenta que este en un borde.

vector<int> islasDeVecinos(tuple<int,int> posi,vector<vector<int>>& terreno, vector<vector<int>>& etiquetado) {
    int i = get<0>(posi), j=get<1>(posi);
    vector<int> islas_vecis = {};
    for (int k =i-1; k<i+1;k++) {  //No me importa revisar los de más abajo porque no fueron evaluados
        if ( k>=0 && k<terreno.size() ) { //Si k está en rango
            for (int l = j-1; l < j + 2; l++) {
                    if ( (j>=0 && k<terreno.size()) && (etiquetado[k][l] != 0)  ) {
                    if (find(islas_vecis.begin(), islas_vecis.end(), etiquetado[k][l]) == islas_vecis.end()) //Si es un vecino de una nueva isla
                    islas_vecis.push_back(etiquetado[k][l]); //La isla de uno de sus vecinos
                }
            }
        }
    }
    return islas_vecis;
}


void renombrarIslas(int isla_1,int isla_2, tuple<int,int> posi, vector<vector<int>>& etiquetado) {
    for (int i=0;i<get<0>(posi);i++) {
        for (int j=0;j<etiquetado[0].size();j++) {
            if (etiquetado[i][j] == isla_1) { //Renombro las posiciones de la isla_1
                etiquetado[i][j] = isla_2;
            }
        }
    }
}

int etiquetarPosiciones(vector<vector<int>> terreno, vector<vector<int>>& etiquetado) {
    int isla=0,cant_islas=0;
    vector<int> islas_vecinos;
    for (int i=0;i<terreno.size();i++){
        for (int j=0;j<terreno[0].size();j++) {
            if (terreno[i][j] <= 0) {
                etiquetado[i][j]=0;
            }
            else {
                islas_vecinos = islasDeVecinos(make_tuple(i,j),terreno,etiquetado);
                cant_islas = islas_vecinos.size();
                if ( cant_islas == 0) { //Si no tiene ningún vecino "creo una nueva isla"
                    isla++;
                    etiquetado[i][j] = isla;
                }
                else { //Sino se suma a la isla de su vecino
                    if (cant_islas == 1) { //Si solo tiene un tipo de vecino
                        etiquetado[i][j] = islas_vecinos[0];
                    }
                    else { //Si tiene vecinos de dos islas entonces unifico ambas islas cómo una sola
                        renombrarIslas(islas_vecinos[0], islas_vecinos[1], make_tuple(i,j),etiquetado);
                        etiquetado[i][j] = islas_vecinos[1];
                    }
                }
            }
        }
    }
    return isla;
}


int islas_no_validas(vector<vector<int>>& etiquetado) {
    vector<int> islas_no_validas = {};
    for (int i =0;i<etiquetado.size();i++) {
        for (int j=0;j<etiquetado[0].size();j++) {
            if (etiquetado[i][j] != 0 && (i == etiquetado.size() || j == etiquetado[0].size()) ) { //Si la isla es un borde
                if (find(islas_no_validas.begin(), islas_no_validas.end(), etiquetado[i][j]) == islas_no_validas.end()) {
                    islas_no_validas.push_back(etiquetado[i][j]); //Agrego la isla a la lista de islas no válidas
                }
            }
        }
    }
    return islas_no_validas.size();
}


int islas(vector<vector<int>> terreno) {
    vector<vector<int>> etiquetado( terreno.size(), vector<int>(terreno[0].size(),0) );
    int cant_islas =etiquetarPosiciones(terreno,etiquetado);
    mostrarMatriz(etiquetado);
    int cant_islas_no_validas = islas_no_validas(etiquetado);
    return cant_islas- cant_islas_no_validas;

}

/************* Ejercicio 9 *************/

//a) Mi idea es ir "bajando" desde la posición inicial en la que me encuentro para así,
// poder encontrar algún valle. Además una precondición para que mi programa no se indefina
// es que exista un valle.

//Posible problema: Que "baje" por un camino equivocado y que al llegar a una superficie plana
// no sepa cómo seguir.

//Posible mejora: Que el rango de vecinoMasBajo sea mayor y que no revise sólo sus vecinos
// "directos" sino que se fije en un rango de "4 o 6" vecinos de distancia.
tuple<int,int> vecinoMasBajo(tuple<int,int> posi,vector<vector<int>>  terreno) {
    int i = get<0>(posi), j=get<0>(posi);
    int x=i,y=j; //Posiciones del vecino más bajo
    for (int k =i-1; k<i+2;k++) {
        if ( k>=0 && k<terreno.size() ) { //Si k está en rango
            for (int l = j - 1; l < j + 2; l++) {
                if ( (l>=0 && l<terreno.size())  && (terreno[k][l] < terreno[x][y] ) ) {
                    x=k;y=l; //Se convierte en el vecino más bajo
                }
            }
        }
    }
    tuple<int,int> veci_mas_bajo = make_tuple(x,y);
    return veci_mas_bajo;
}

tuple<int,int> encontrar_valle(int i, int j,vector<vector<int>>  terreno){
    bool esValle=false;
    tuple<int,int> nueva_posi,posi_anterior = make_tuple(i,j);   //Coordenadas por donde me voy a ir moviendo
    while (!esValle) {
        nueva_posi = vecinoMasBajo(posi_anterior,terreno);
        if (nueva_posi == posi_anterior) { //Osea que es un valle
            esValle= true;
        }
        posi_anterior = nueva_posi;
    }
    return  nueva_posi;
}

//b) La idea sería hacer algo similar al punto anterior.

tuple<int,int> encontrar_valle_recur(int i, int j,vector<vector<int>>  terreno) {
    tuple<int,int> posi_anterior= make_tuple(i,j),nueva_posi= vecinoMasBajo(posi_anterior,terreno);
    if (nueva_posi == posi_anterior) { // Si es un valle
        return nueva_posi;
    }
    return encontrar_valle(get<0>(nueva_posi), get<1>(nueva_posi), terreno);
}

//c)
vector<tuple<int,int>> vecinosDebajo(tuple<int,int> posi,vector<vector<int>>  terreno) {
    int i = get<0>(posi), j=get<0>(posi);
    vector<tuple<int,int>> vecis_abajo = {}; //Lista de vecinos que están debajo de la posi inicial
    for (int k =i-1; k<i+2;k++) {
        if ( k>=0 && k<terreno.size() ) { //Si k está en rango
            for (int l = j - 1; l < j + 2; l++) {
                if ( (j>=0 && k<terreno.size())  && (terreno[k][l] < terreno[i][j] ) ) {
                    vecis_abajo.push_back(make_tuple(k,l)); //Agrega a un vecino que este debajo
                }
            }
        }
    }
    if (vecis_abajo.size() == 0) {
        vecis_abajo.push_back(make_tuple(i,j));
    }
    return vecis_abajo;
}

//A partir de esta función voy a ir siempre bajando pero puedo ir  tomando caminos
// distintos, el tema es que volví a aplicar un lindo backtrackeo al igual que el 11)b).

bool CaminoAlValle(tuple<int,int> posicion_actual,vector<vector<int>>  terreno, vector<tuple<int,int>>& recorrido) {
    vector<tuple<int,int>> posis_debajo = vecinosDebajo(posicion_actual, terreno);
    if (posis_debajo[0] == posicion_actual) {
        for (tuple<int,int> t : recorrido) { //Imprime el recorrido en la terminal
            cout << "( " << get<0>(t) << ", " << get<1>(t) << " ) ";
        }
        cout << " ] " << endl;
        return true;
    }
    else {
        for (tuple<int,int> posi : posis_debajo) { //Voy probando de bajar por cualquiera de las posiciones posibles
            recorrido.push_back(posi); //Agrego la posición al recorrido
            if (CaminoAlValle(posi, terreno, recorrido)) {
                return true;
            }
            recorrido.pop_back(); //Quito la posición del recorrido
        }
    }
    return false; //Si es que no encuentro ningún valle
}

/************* Ejercicio 10 *************/

//Aclaración: Claramente que luego de hacer el 11 podría hacer este ejercicio usando la misma
//estrategia de guardar las coordenadas y evaluar de ese modo. Pero este código fue previo a la
// "revelación de las coordenadas", así que lo dejo cómo esta.

//Mi idea es analizar todas las lineas ganadoras posibles y ver si en las mismas
//encuentro tres figuras iguales.

/***
   v >  |             |    <      Cada ">" representa la dirección
     >  |             |    <      de la línea a chequear.
     >  |     ^       |    ^      No supe cómo representar las diagonales :(

Siempre voy desde los bordes por cómo pense la funcion "hayGanadorEnDirección"
***/

bool hayGanadorEnDireccion(vector<vector<char>> tablero, tuple<int,int> posi, tuple<int,int> dire, bool& vacio) {
    bool ganador= true;
    int x=get<0>(posi),y=get<1>(posi); //Posición desde la que comienzo
    int i=get<0>(dire),j=get<1>(dire); //Dirección hacia la que me muevo
    char figu = tablero[x][y];
    for (int k=0;k<2;k++) { //Reviso si ambas posiciones tienen el mismo caracter
        ganador = ganador && (tablero[x+i][y+j] == figu);
        i += i;
        j += j;
        vacio = vacio && (tablero[x+i][y+j] != ' ' ); //Esto es para revisar "de chapa"
                                         // si en algún lugar del tablero hay una vacía
    }
    if (figu== ' ') { //Por si eran todas posiciones vacias
        return !ganador;
    }
    return ganador;
}

//Precondición: Tiene que ser un tablero 3x3, con chars "X","O" o " ".



void revisarTablero(vector<vector<char>> tablero) {
    bool completo = true; //Para ver si están todas las posiciones ocupadas
    int lineas_ganadoras =0;
    char char_ganador = ' ';
    for (int i=0;i<3;i++) {
        //Reviso las lineas verticales
        if (hayGanadorEnDireccion(tablero, make_tuple(0,i),make_tuple(0,1), completo) ) {
            lineas_ganadoras +=1;
            char_ganador = tablero[0][i];
        }
        //Reviso las lineas horizontales
        if (hayGanadorEnDireccion(tablero, make_tuple(i,0),make_tuple(1,0), completo) ) {
            lineas_ganadoras +=1;
            char_ganador = tablero[0][i];
        }

    }
    //Reviso las diagonales a "manopla"
    if (hayGanadorEnDireccion(tablero, make_tuple(0,0),make_tuple(1,-1), completo) ) {
        lineas_ganadoras +=1;
        char_ganador = tablero[0][0];
    }
    if (hayGanadorEnDireccion(tablero, make_tuple(0,2),make_tuple(-1,-1), completo) ) {
        lineas_ganadoras +=1;
        char_ganador = tablero[0][2];
    }
    //Ahora solo queda revisar los "casos" posibles que pueden haber surgido
    if (lineas_ganadoras>1) {
        cout << "Me diste un tablero inalcanzable querido, para inalcanzanble tengo"
        << "a la calidad de mis clases de consulta de Álgebra el cuatri pasado.";
    }
    if (lineas_ganadoras==1) {
        cout << "Gano el equipo de los simbolos: " << char_ganador;
    }
    if (completo && lineas_ganadoras == 0) {
        cout << "Fue un empate, muy bien jugado ambos";
    }
    if (!completo && lineas_ganadoras == 0){
        cout << "Juego en progreso. Este duelo de épicas proporciones no ha terminado.";
    }
}


/************* Ejercicio 11 *************/

//a) Quise hacer que el chequeo sea un poco más general, por lo tanto uno ingresa un
//tablero de cualquier longitud y revisa si hay alguna reina amenazando a otra.


//La idea es revisar primero si hay dos reinas en una misma fila o columna
// Luego sabiendo que si tenemos dos reinas con coordenadas (x,y) e (i,j)
// yo se que si abs(x-i)/abs(y-j) = 1. (pendiente de una recta)


bool hayReinasAmenzandose(vector<vector<char>> tablero) {
    vector<tuple<int,int>> reinas;
    for (int i=0;i<tablero.size();i++) { //Me guardo las posiciones de las reinas
        for (int j=0;i<tablero[0].size();j++) {
            if (tablero[i][j] == 'r') {
                reinas.push_back(make_tuple(i,j));
            }
        }
    }
    int x,y; //Posiciones de la reina "actual"
    int k,l; //Posiciones de la reina "a comparar"
    for (int i=0;i<reinas.size()-1;i++) {
        x = get<0>(reinas[i]);
        y = get<1>(reinas[i]);
        for (int j=i+1;j<reinas.size();j++) { //Comparo una reina con todas las siguientes
            k = get<0>(reinas[j]);
            l = get<1>(reinas[j]);
            if (x==k || l==y ||  abs(x-k)==abs(y-l) ){
                return true;
            }
        }
    }
    return false;
}

//b) Mi idea sería probar distintas soluciones "viables" y si es que ninguna funciona
// entonces para este tablero no existe solución. Las caracteristicas de la solución son:
// |Solu| = n ^ (∀ tupla1,tupla2 ϵ Solu ->L [ (tupla1)_1 != (tupla2)_1 ^ (tupla1)_2 != (tupla2)_2] )
//Osea que solu = (0,x_1), (1,x_2),........(n, x_n), siendo el conjunto de
// X = (x_1,x_2,....x_n) todas las permutaciones de los n números.


//Está permutaciones es para vos Haskell♥
void insertarEnTodasLasPosis(vector<vector<int>>& permus, int x) {
    vector<vector<int>> permus_modificado;
    vector<int> permu_a_modificar;
    for (int i=0;i<permus.size();i++) {
        for (int j=0;j<=permus[i].size();j++) { //Le agrego el elemento x en todas las posiciones
            permu_a_modificar = permus[i];
            permu_a_modificar.insert(permu_a_modificar.begin()+j,x); //Inserto x en la posición j
            permus_modificado.push_back(permu_a_modificar);
        }
    }
    permus =permus_modificado;
}

void permutaciones(int n, vector<vector<int>>& permus) {
    if(n==0) {
        insertarEnTodasLasPosis(permus,n);
        /* for (vector<int> permu : permus) {  //Para imprimir las permutaciones
            cout << "[ ";
            for (int nume : permu) {
                cout << nume << "  ";
            }
            cout << " ]";
        }
    */
    }
    else {
        insertarEnTodasLasPosis(permus, n);
        permutaciones(n - 1, permus);
    }

}

//Igual medio que permutaciones se rompe con n=10, así que no funca esta forma :(
// A menos que cambie la forma de hacer permutaciones y no cree un vector tan largo
// pero no vale la pena el esfuerzo al ya tener una segunda forma que funciona bien.

bool haySolucionParaNReinas(int n) {
    vector<vector<int>> permus ={{}};
    permutaciones(n,permus);
    bool funca;
    for (vector<int> permu : permus) {
        funca = true;
        for (int colu =0;colu<n;colu++ ) {
            for (int colu_2=colu+1;colu_2<n;colu_2++) { //Permu[colu] representa la fila en la que está ubicada la reina
                if ( permu[colu]==permu[colu_2] ||  abs(colu-colu_2)==abs(permu[colu]-permu[colu_2]) ) {
                    funca=false;
                }
            }
        }
        if (funca) {

            cout << "Una solución válida es: \n [ "; //Imprimo la solución
            for (int colu =0;colu<n;colu++ ) {
                cout << " ( " << permu[colu] << " , " << colu << " ) ";
            }
            cout << "  ]";
            return true;
        }
    }
    return false;
}

//Otra opción mucho más cheta es ir fijandome directamente si la nueva reina cumple  la "regla de las
// diagonales",si usando la nueva configuración y probando todas sus posibles combinaciones, no llego a nada
//entonces "backtrackeo" y comienzo con una configuración que varía en la última elección.


//∀ tupla1,tupla2 ϵ reinas ->L [ (tupla1)_1 != (tupla2)_1 ^ (tupla1)_2 != (tupla2)_2] )
// ( (tupla1)_1 - (tupla2)_1)


//Auspiciadisimo brutalmente por Lombi
bool ubicarReinaEnIesimaColumna(vector<tuple<int,int>> posi_reinas, int colu, int n){
    if (colu ==n) {
        cout << "[ ";
        for (tuple<int,int> t : posi_reinas) { //Imprime la solución en la terminal
            cout << "( " << get<0>(t) << ", " << get<1>(t) << " ) ";
        }
        cout << " ] " << endl;
        return true;
        // return false; Acá devuelvo todas las soluciones
    }
    vector<tuple<int,int>> nueva_posi_reinas;
    for (int i=0;i<n;i++) {
        nueva_posi_reinas = posi_reinas;
        nueva_posi_reinas.push_back(make_tuple(colu,i)); //Agrego la nueva reina
        bool funca=true;
        for (int j=0;j<nueva_posi_reinas.size()-1;j++){ //Reviso que sea una reina válida
            int x = get<0>(nueva_posi_reinas[j]);
            int y = get<1>(nueva_posi_reinas[j]);
            if (x==colu || y==i ||  abs(x-colu)==abs(y-i)) {
                funca=false;
                break;
            }
        }
        if (funca) { //Si es una posición válida entonces busco en la siguiente columna
            if (ubicarReinaEnIesimaColumna(nueva_posi_reinas,colu+1,n)){
                return true;
            }
        }
    }
    return false;  //Si no hay ninguna configuración válida entonces devuelvo false
}

//Versión optimada por referencia
bool ubicarReinaEnIesimaColumna_opti(vector<tuple<int,int>>& posi_reinas, int colu, int n){
    if (colu ==n) {
        cout << "[ ";
        for (tuple<int,int> t : posi_reinas) {
            cout << "( " << get<0>(t) << ", " << get<1>(t) << " ) ";
        }
        cout << " ] " << endl;

        return true;
        // return false; Acá devuelvo todas las soluciones
    }
    for (int i=0;i<n;i++) {
        posi_reinas.push_back(make_tuple(colu,i)); //Agrego la nueva reina a mi configuración
        bool funca=true;
        for (int j=0;j<posi_reinas.size()-1;j++){
            int x = get<0>(posi_reinas[j]);
            int y = get<1>(posi_reinas[j]);
            if (x==colu || y==i ||  abs(x-colu)==abs(y-i)) {
                funca=false;
                break;
            }
        }
        if (funca) {
            if (ubicarReinaEnIesimaColumna_opti(posi_reinas,colu+1,n)){
                return true;
            }
        }
        posi_reinas.pop_back(); //Elimino la última posición agregada para probar otra combinación
    }
    return false;
}