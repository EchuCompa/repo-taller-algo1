#include "ejerciciosp8.h"

using namespace std;


/************* Ejercicio 4 *************/

//c)
int mesetaMasLarga (vector <int > & v ) {
    int maxMeseta =0;
    int comienzo=0;
    for (int i=0;i<v.size();i++) {
        if (v[i] != v[comienzo]) {
            if ( maxMeseta < i-comienzo) {
                maxMeseta = i-comienzo;
            }
            comienzo = i+1;
        }
    }
    return maxMeseta ;
}

/************* Ejercicio 6 *************/

int sumarPotenciaHastaFun (int n) {
    int res = 0;
    int i = 1;
    while (i < n) {
        res = res + i;
        i = i * 2;
    }
    return res ;
}

//c) Si n=2^x+ 1

int sumarPotenciasHasta(int n){
    return 2*n-3;
}



/************* Ejercicio 7 *************/

//a)
int determinanteMatrizTriangular(vector<vector<int>> mat){
    int deter= 1;
    for (int i=0; i<mat.size();i++) {
        deter *= mat[i][i];
    }
}

//b)
bool esTriangular(vector<vector<int>> mat) {
    for (int i = 0; i < mat.size(); i++) {
        for (int j = 0; j < i; j++) {
            if (mat[i][j] != 0) {
                return false;
            }
        }
    }
    return true;
}

/************* Ejercicio 8 *************/

//8)b)
/*Se que  si A x B = C -> C_ij (la posición (i,j) de C) = fila i de A * columna j de B,
 *debido a la espeficicación del ejercicio.
 * PD: Funciones robadas vilmente de la clase 6 de matrices
 */

vector<vector<int>> productoMatrices(const vector<vector<int>>& mat1, const vector<vector<int>>& mat2){
    vector<vector<int>> producto( mat1.size(), vector<int>(mat2[0].size()) );
    for (int i=0; i< mat1.size(); i++) {
        for (int j=0; j<mat2[0].size(); j++){
            vector<int> columna = columnaMatriz(mat2,j);
            producto[i][j] = productoPunto(mat1[i],columna);
        }
    }
    return  producto;
}



vector<int> columnaMatriz(vector<vector<int>> mat, int colu){
    vector<int> colum;
    for (int i=0; i<mat.size(); i++) { //Me "paro" sobre la columna y recorro las filas
        colum.push_back(mat[i][colu]);
    }
    return  colum;
}

int productoPunto(vector<int> v1, vector<int> v2 ) {
    int producto =0;
    for (int i =0; i<v1.size();i++) {
        producto += v1[i] * v2[i];
    }
    return producto;
}


/************* Ejercicio 9 *************/

//9)b)
//La idea es ir acumulando la suma a medida que voy recorriendo las posiciones

void sumasAcumuladas(vector<vector<int>>& mat, int N){
    int suma_acum=0;
    for (int i=0;i<=N-1;i++){
        for (int j=0;j<=N-1;j++){
            suma_acum += mat[i][j];
            mat[i][j] = suma_acum;
        }
    }
}

/************* Ejercicio 10 *************/

int elementosImparesConsecu(vector<int> v){
    int contador=0, maximo=0;
    for (int i=0;i<v.size();i++) {
        if (v[i] % 2 == 1) {
            contador++;
        }
        else {
            if (contador > maximo) {
                maximo= contador;
            }
            contador =0;
        }
    }
    return maximo;
}

/************* Ejercicio 11 *************/

void restarAcumulado(vector<int>& v) {
    int suma_acumu =0;
    for (int i=0;i<v.size();i++){
        suma_acumu += v[i];
        v[i] -= suma_acumu;
    }
}

/************* Ejercicio 12 *************/

//La cantidad de caminos es N Combinatorio N/2, dato feroz
//PD: Gracias Lombi por la guía.

//https://www.mathblog.dk/project-euler-81-find-the-minimal-path-sum-from-the-top-left-to-the-bottom-right-by-moving-right-and-down/
//Link con la idea explicada

/* Esto es súper ineficiente ya que no usa los valores calculados previamentes,  puesto que
 * a partir de cada return(CostoMinimo(...) vuelvo a hacer todos los cálculos y operaciones.
 *  La clave sería usar los valores calculados en las cuentas anteriores.
 */
int costoMinimo(int x, int y,const vector<vector<int>>& costos) {
    if (x == 0 && y==0){
        return costos[0][0];
    }
    if ( x <0 || y<0) {
        return 0;
    }
    return costos[x][y] + min(costoMinimo(x-1,y, costos) ,costoMinimo(x,y-1, costos));
}

int min(int a, int b){
    //Esta fealdad es para que no devuelva 0 cuándo es una opción puesto que sino
    // va a ser el camino que elija en los bordes.
    if (a==0) {
        return b;
    }
    if (b==0) {
        return a;
    }
    if (a<b) {
        return a;
    }
    return b;
}

int caminosPosibles(int x, int y) {
    if (x == 0 && y==0){
        return 1;
    }
    if ( x <0 || y<0) {
        return 0;
    }
    return caminosPosibles(x-1,y) + caminosPosibles(x,y-1);
}


//Idea más peola y eficiente, gracias por tanto Lombi :)
int DpcostoMinimo(const vector<vector<int>>& costos) {
    int N = costos.size();
    vector<vector<int>> dp(N, vector<int>(N, 0));

    dp[0][0] = costos[0][0];
    for (int f = 1; f < N; f++) dp[f][0] = dp[f - 1][0] + costos[f][0];
    for (int c = 1; c < N; c++) dp[0][c] = dp[0][c - 1] + costos[0][c];

    for (int f = 1; f < N; f++) {
        for (int c = 1; c < N; c++) {
            dp[f][c] = min(dp[f - 1][c], dp[f][c - 1]) + costos[f][c];
        }
    }

    return dp[N - 1][N - 1];
}


/************* Ejercicio 13 *************/

//a + b)

vector<vector<int>> elevarMatrizN(const vector<vector<int>>& mat1, int n){
    vector<vector<int>> mat_elevada = mat1;
    vector<vector<int>> mat_multipli = mat1;
    int i =1;
    while (n>1){
        if ( n% (2*i) ==0) {
            mat_elevada = productoMatrices(mat_elevada, mat_elevada);
            mat_multipli= mat_elevada;
            n /= 2;
            i *= 2;
        }
        else {
            mat_elevada = productoMatrices(mat_elevada, mat_multipli);
             n -= i;
        }
    }
    return mat_elevada;
}

/************* Ejercicio 14 *************/

//a + b)
/* Primero convierto el vector de booleanos a un número binario, para luego ir guardando
 * los índices de las apariciones de cada número distinto. Si ese número ya apareció antes
 * entonces guardo su indice en el vector que aparece ese elemento. Al final del proceso
 * reviso los elementos que tengo y los índices asociados a cada elemento. Si un elemento
 * tiene solamente un indice significa que aparecio una vez meramente.
 */

vector<bool> boolsDistintos(vector<vector<bool>> mat) {
    vector<vector<int>> apariciones;
    for (int i=0;i<mat.size();i++) {
        int numero = booleanosABinario(mat[i]);
        int indi = indice(apariciones, numero);
        if (indi == -1){ //Agrego el elemento si no estaba en aparaiciones
            apariciones.push_back( {numero, i});
        }
        else { //Agrego el indice de la segunda aparicion del elemento
            apariciones[indi].push_back(i);
        }
    }
    int j=0;
    int indi_distinto =0;
    while (j < apariciones.size()) {
        if (apariciones[j].size() == 2 ) { //Si el elemento solo tuvo una aparicion, ergo es el único
            indi_distinto = apariciones[j][1];                 //sin pareja
        }
    }
    return mat[indi_distinto];
}

//Vector {true,false,false,true} = 1001 = 8+1= 9
int booleanosABinario(const vector<bool>& bools){
    int nume=0;
    for (int i=0;i<bools.size();i++){
        nume += 2^(bools.size()-1-  i);
    }
    return nume;
}

int indice(const vector<vector<int>>& apari, int ele){
    int indi=-1;
    for (int i =0;i < apari.size(); i++) {
        if (apari[i][0] == ele) {
            indi =i;
        }
    }
    return indi;
}

//c)
/*Cuento la cantidad de trues en una columna, si el número es impar significa que en esa columna
 * el vector de booleanos distinto tiene un elemento true, si es par entonces el elemento es false
 */

vector<bool> boolsDistintosCheto(vector<vector<bool>> mat){
    vector<bool> distinto = {};
    for (int i=0; i <mat[0].size();i++){
        int cant_trues =0;
        for (int j =0; j<mat.size();j++) {
            cant_trues += mat[i][j];
        }
        distinto.push_back(cant_trues%2);
    }
    return distinto;
}
