#include "ejerciciosp9.h"



using namespace std;

/************* Ejercicio 1 *************/

pair<int,int> posicionElemento(int x,const vector<vector<int>>& mat){
    pair<int,int> posi = make_pair(-1,-1);
    for (int i =0;i<mat.size();i++) {
        for (int j=0;j<mat[0].size();j++){
            if (mat[i][j] == x) posi = make_pair(i,j);
        }
    }
    return posi;
}


/************* Ejercicio 2 *************/

int elementoFaltante( vector<int> s){
    int low=0, high=s.size()-1;
    while (low+1 < high ) {
        int mid = (low +high)/2;
        if (s[mid] > mid) high = mid;
        else low = mid;
    }
    return high;
}

/************* Ejercicio 3 *************/

//a)

int sumaElementos(vector<int> s){
    int suma =0;
    for (int i=0;i<s.size();i++){
        suma += s[i];
    }
    return suma;
}

//b )
/* Voy revisando el vector para encontrar la posición en la cuál está el
 * primer 1, por lo tanto se que la cantidad de 1`s va a ser la longitud
 * de la lista menos la primer posición del 1.
 */

int sumaElementosOrdenados(vector<int> s){
    int low=0, high=s.size()-1;
    while (low+1 < high ) {
        int mid = (low +high)/2;
        if (s[mid] == 0) low = mid;
        else high = mid;
    }
    return s.size()- high;
}

//c )

int sumaElementosOrdenados2(vector<int> s){
    int low=0, high=s.size()-1;
    while (low+1 < high ) {
        int mid = (low +high)/2;
        if (s[mid] == 15) low = mid;
        else high = mid;
    }
    return (s.size()- high)*22 + high*15;
}


/************* Ejercicio 4 *************/

//a)


int elementosSinRepetir(vector<vector<int>> m, int e) {
    int i = 0, j = m[0].size() - 1;
    while (j >= 0 && i < m.size() && m[i][j] != e) { // O(N + M)
        if (m[i][j] > e) {
            j--; // descarto la columna
        }
        else {
            i++; // descarto la fila
        }
    }
    return j >= 0 && i < m.size(); // si terminó en rango, entonces (m[i][j] == e)
}

//b)

int aparisEColuRepe(vector<vector<int>> m, int e) { // O( (N + M)
    int i = 0, j = m[0].size() - 1;
    int aparis=0;
    while (j >= 0 && i < m.size()) {
        if(m[i][j] == e) {
            aparis++;
            i++; // descarto la fila
        }
        else if (m[i][j] > e) {
            j--; // descarto la columna
        }
        else {
            i++; // descarto la fila
        }
    }
    return aparis;
}

//c)

int aparicionesE(vector<vector<int>> m, int e){ // O(N*M)
    int aparis =0;
    for (int i=0;i<m.size();i++){
        for (int j = 0; j < m[0].size(); ++j) {
            if (m[i][j]) aparis++;
        }
    }
    return aparis;
}


/************* Ejercicio 5 *************/

//a)

int aparicionesListaE(int e, vector<int> v){
    int apari=0;
    for (int i =0;i<v.size();i++){
        if (v[i] == e) apari++;
    }
    return apari;
}

//b) Voy guardando el valor del máximo y mínimo al recorrer el vector

int rangoV(vector<int> v){
    int maxi=v[0], min = v[0];
    for (int i=0;i<v.size();i++){
        if (v[i] < min) min = v[i];
        if (v[i] > maxi) maxi = v[i];
    }
    return maxi-min;
}

//c)
/*  Tengo un vector en el cuál guardo pairs <elemento, apariciones_elemento>,
 * a través de las cuáles voy manteniendo un conteo de cada elemento. Si el
 *  elemento no tiene un pair asociado entonces creo un nuevo, si ya estaba en
 *  la lista entonces le sumo 1 a su cantidad de apariciones.
 *  Al final me fijo cuál es el mayor.
 */

int elementoMasApariciones(vector<int> s){
    vector<pair<int,int>> aparis = {};
    for (int i=0;i<s.size();i++){ //O(n)
        agregarRepetis(aparis, s[i]); //O(|aparis|)
    }
    int indi_maxi=0 ;
    for (int i =0;i<aparis.size();i++){ //O(N)
        if (aparis[indi_maxi].second < aparis[i].second){
            indi_maxi =i;
        }
    }
    return aparis[indi_maxi].first;
}

//Agrega la aparicion del elemento en cuestión
void agregarRepetis(vector<pair<int,int>>& aparis, int ele){
    bool agregar= true;
    for (pair<int,int>& apari : aparis){ // //O(|aparis|)
        if (apari.first == ele){
            apari = make_pair(apari.first, apari.second+1);
            agregar = false;
            break;
        }
    }
    if (agregar){
        aparis.push_back(make_pair(ele,1));
    }
}






//d)
/* Misma idea que en el ejercicio anterior solo que hay un indice para todos
 * los números que esten en el rango de v, por lo tanto su indice representa
 * que elemento es y no hay que tomarse el trabajo de buscarlo. Al final busca
 * la posicion de aparis con más apariciones y devuelve su indice.
 */

int elementoMasRepetidoAcotado(vector<int> s, int cota_inf, int cota_sup) {
    vector<int> aparis(cota_sup-cota_inf, 0);
    for (int i=0;i<s.size();i++) { //O(n)
        aparis[s[i]-cota_inf]++;
    }
    int indi_maxi=0;
    for (int i=0;i<aparis.size();i++){ //O(cota_sup-cota_inf)
        if (aparis[indi_maxi] < aparis[i]){
            indi_maxi = i;
        }
    }
    return indi_maxi-cota_inf;
}


//7) Práctica de la Mañana
bool deCuentas(vector<int> s){
    vector<int> aparis(s.size(),0);
    for (int i=0;i<s.size();i++){
        if (s[i] <0 || s[i] >s.size()) {
            return false;
        }
        aparis[s[i]]++;
    }
    bool es_cuentas = true;
    for (int i =0;i<aparis.size();i++){
        if (aparis[i] != 0){
            es_cuentas = es_cuentas && aparis[i] == i;
            if (!es_cuentas) break;
        }
    }
    return es_cuentas;
}

/************* Ejercicio 6 *************/

//Aplique una idea similar al 5)d) ya que el rango de los chars es finito

string ordenarString(string s){
    vector<int> aparis_char( 112956,0);
    for (char carac : s){ //Cuento las apariciones de cada caracter
        aparis_char[int(carac)]++;
    }
    string string_ordenado = "";
    for (int i=0;i<aparis_char.size();i++){ //Agrego las apariciones de cada caracter al nuevo string ordenado
        for (int j=0;j<aparis_char[i];j++) {
            string_ordenado += char(i);
        }
    }
    return string_ordenado;
}


/************* Ejercicio 7 *************/

/* Te vas guardando los k valores más cercanos en un vector y calculas
 *  la distancia de los nuevos valores con los últimos del vector, el mismo
 * está ordenado en base a los que están a menor distancia del e, de esta forma
 * uno los va sustituyendo por los nuevos elementos más cercanos a e. Los primeros
 * elementos son los más cercanos.
 */

vector<int> kNumerosMasCercanos(int k, int e, vector<int> v){
    vector<int> mas_cerca = {};
    for (int i=0;i < v.size();i++ ){ //O(n)
        insertarCercano(k,e,v[i], mas_cerca); //O(k)
    }
    return mas_cerca;
}

void insertarCercano(int k, int e, int elem, vector<int>& cercanos){
    bool agregar = true;
    if (cercanos.size() < k) {
        cercanos.push_back(elem);
        agregar =false;
    }
    for (int i=0;i<cercanos.size() && agregar;i++){ //O(k)
        if (abs(elem -e) < abs(cercanos[i]-e) || (abs(elem -e) == abs(cercanos[i]-e) && elem<e )   ) {
            //Si es más cercano a "e" que algún elemento
            cercanos.insert(cercanos.begin()+i, elem);
            agregar = false;
        }
    }
    if (cercanos.size() > k) { //Se elimina el elemento menos cercano a e
        cercanos.pop_back();
    }
}

/************* Ejercicio 9 *************/

//a)

void cocktailSort( vector<int>& s){
    bool ordenada = false;
    for (int i=0;i<s.size() && !ordenada;i++ ) {
        ordenada =true;
        for (int j=i;j<s.size()-1;j++) {
            if (s[j] > s[j+1]) {
                swap(s[j], s[j+1]);
                ordenada = false;
            }
        }
        for (int k=s.size()-2-i; k>0 && !ordenada;k--) {
            if (s[k-1] > s[k] ){
                swap(s[k], s[k-1]);
                ordenada=false;
            }
        }
    }
}

/************* Ejercicio 10 *************/

/*Les metí a todos un v/s=original al final de cada ordenamiento para no tener que ir modificando el vector
 * en la función cantidad de iteraciones por algoritmo, ya comprobe previamente que funcionen bien */

int indiPosMin(vector<int> v, int& iter, int comienzo){
    int indi_min = comienzo;
    iter++;
    for (int i=comienzo; i<v.size();i++) {
        if (v[i] < v[indi_min]) indi_min =i;
        iter +=7;
    }
    return indi_min;
}

int cantIterSelectionSort(vector<int>& v){
    vector<int> original = v;
    int iter =0;
    for (int i=0; i<v.size();i++){
        int indice_minimo = indiPosMin(v, iter, i);
        swap (v[i], v[indice_minimo]);
        iter += 7;
    }
    v = original;
    return iter;
}

void insertar(vector<int>& v, int& iter, int comienzo){
    iter +=4 ;
    for (int i=comienzo;i>0 && v[i] < v[i-1];i--){
        swap(v[i], v[i-1]);
        iter +=13;
    }
}

int cantIterInsertionSort(vector<int>& v){
    int iter =0;
    vector<int> original = v;
    for (int i=0;i<v.size();i++){
        insertar(v, iter, i);
    }
    v = original;
    return iter;
}

int cantIterBubbleSort( vector<int>& s){
    int iter=1;
    vector<int> original = s;
    for (int i=0;i<s.size();i++ ) {
        for (int j = 0; j < s.size() - 1; j++) {
            iter += 9;
            if (s[j] > s[j + 1]) {
                swap(s[j], s[j + 1]);
                iter += 4;
            }
        }
    }
    s = original;
    return iter;
}

/*Introducis una lista de vectores para ordenar y te devuelve que un vector de vectores con cuántas iteraciones
 * tardo cada algoritmo siendo iter_por_vector = <  <iter_inser, iter_selec, iter_bubble > > */

vector<vector<int>> iteracionesPorVector(vector<vector<int>> vec_a_ordenar ){
    vector<vector<int>> iter_por_vector(vec_a_ordenar.size(), vector<int>(3, 0) );
    for (int i =0;i<vec_a_ordenar.size();i++) {
        iter_por_vector[i][0] = cantIterInsertionSort(vec_a_ordenar[i]);
        iter_por_vector[i][1] = cantIterSelectionSort(vec_a_ordenar[i]);
        iter_por_vector[i][2] = cantIterBubbleSort(vec_a_ordenar[i]);
    }
    return iter_por_vector;
}

string mostrarVector(vector<int> v){
    string res = "[";
    for(int i = 0; i < v.size()-1; i++){
        res = res + to_string(v[i]) + ", ";
    }
    if(v.size() > 1){
        res = res + to_string(v[v.size()-1]) ;
    }
    res += "]";
    return res;
}

void mostrarVectorDeVectores(vector<vector<int>> vs){
    string vector_vectores ="[ [insertion, selection, bubble] ";
    for (int i =0;i<vs.size();i++){
        string vec= mostrarVector(vs[i]);
        vector_vectores += " ,  " +  vec ;
    }
    vector_vectores += "  ]";
    cout << vector_vectores;
}

/************* Ejercicio 12 *************/

/* La idea sería ir comparando los elementos de ambas subsecuencias ordenadas e insertar el menor elemento
 * en una nueva secuencia ordenada */

void dosMitades(vector<int>& s) {
    int i=0;
    while (s[i] < s[i+1] && i<s.size()) i++;
    int sec_b = i+1,sec_a =0;
    vector<int> fusion_ordenada = {};
    while (sec_b < s.size() || sec_a < sec_b){
        if (sec_b == s.size() || s[sec_b] > s[sec_a] ) {
            fusion_ordenada.push_back(s[sec_a]);
            sec_a++;
        }
        else if(sec_a == sec_b || s[sec_b] < s[sec_a]){
            fusion_ordenada.push_back(s[sec_b]);
            sec_b++;
        }
    }
    s = fusion_ordenada;
}

/************* Ejercicio 13 *************/

vector<int> reconstruye(vector<int> a) {
    vector<int> aparis(0, a.size());
    for (int i = 0; i < a.size(); i++) {
        aparis[a[i]] += i;
    }
    vector<int> b = {};
    for (int i = 0; i < aparis.size(); i++) {
        for (int j = 0; j < aparis[i]; j++) {
            b.push_back(i);
        }
    }
    return b;

}

