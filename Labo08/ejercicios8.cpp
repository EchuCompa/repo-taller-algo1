#include "ejercicios8.h"

using namespace std;

void mostrar_vector(vector<int>& v){
    string vector = "[";
    if(v.size() > 0){
        for(int i=0; i < v.size()-1; i++){
            vector = vector + to_string(v[i]) + ", ";
        }
    }

    if(v.size() != 0){
        vector = vector + to_string(v[v.size()-1]) + "]";
    }else{
        vector = vector + "]";
    }

    cout << vector << endl;
}

vector<int> construir_vector(int n, string disposicion){

    vector<int> res;
    srand (time(NULL));
    int numero;

    if (disposicion == "asc"){
        for(int i=0; i < n; i++){
            res.push_back(i);
        }
    }else if(disposicion == "desc"){
        for(int i=n-1; i >= 0; i--){
            res.push_back(i);
        }

    }else if(disposicion == "azar"){
        for(int i=0; i < n; i++){
            numero = rand() % 100;
            res.push_back(numero);
        }
    }else if(disposicion == "iguales"){
        numero = rand() % 100;
        for(int i=0; i < n; i++){
            res.push_back(numero);
        }
    }else{
        cout << "Dispocisión no válida" << endl;
    }

    return res;
}

bool hayDuplicados (vector<int>& v){
    bool res = false ; int i = 0; int j = 0;

    while ( i < v . size ()){
        j = 0;
        while ( j < v . size ()){
            if ( i != j && v [ i ] == v [ j ]){
                res = true ;
            }
            j ++;
        }
        i ++;
    }

    return res;
}


bool busqueda_binaria(vector<int> &s, int x) {
    int low = 0;
    int high = s.size() -1;
    while( low+1 < high ) {
        int mid = (low+high) / 2;
        if( s[mid] <= x ) {
            low = mid;
        } else {
            high = mid;
        }
    }
    return s[low] == x;
}




// Dado un vector de enteros, devuelve verdadero si
// existe un subconjunto tal que la suma sea igual a sum
bool algunSubconjSuma(vector<int>& vec, int sum)
{
    return aux(vec, vec.size() - 1, sum);
}

bool aux(vector<int>& vec, int i, int sum)
{
    if (sum == 0) return true;
    if (i < 0 || sum < 0) return false;
    bool prueba1 = aux(vec, i - 1, sum - vec[i]);
    bool prueba2 = aux(vec, i - 1, sum);
    return prueba1 || prueba2;
}

bool hayDuplicados2 (vector<int>& v){
    bool res = false ; int i = 0; int j = 0;

    while ( i < v . size () && !res){
        j = 0;
        while ( j < v . size () && !res){
            if ( i != j && v [ i ] == v [ j ]){
                res = true ;
            }
            j ++;
        }
        i ++;
    }

    return res;
}

void mitad0 (vector<int> lista) {
    int mitad = lista.size()/2;
    lista[mitad] = 0;
}

void todosPositivos(vector<int> lista) {
    for (int i = 0; i < lista.size(); i++) {
        lista[i] = abs(lista[i]);
    }
}
//la funcion de abajo es inviable porque es muy costoso construir el cubo necesario xd
void todosPositivos3D (vector<vector<vector<int>>> cubo) {
    for (int i = 0; i < cubo.size(); i++) {
        for (int j = 0; j < cubo[0].size(); j++) {
            for (int k = 0; k < cubo[0][0].size(); ++k) {
                cubo[i][j][k] = abs(cubo[i][j][k]);
            }
        }
    }
}

void sumarTodoDeFormaRara (vector<int> v) {
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v.size(); j++) {
            for (int k = 0; k < v.size(); k++) {
                v[i] = v[i] + v[j] + v[k];
            }
        }
    }
}
//tampoco es viable porque llora cuando quiero hacer una matriz 100000*1000000
int busquedaMatrizCuadradaFilasOrdenandas (vector<vector<int>> matriz,int x) {
    int encontrdos = 0;
    for (int i = 0; i < matriz.size(); i++) {
        encontrdos += busqueda_binaria(matriz[i],x);
    }
    return  encontrdos;
}

int hacealgopibe (vector<int> v){
    int encontrados = 0;
    for (int i = 0; i < v.size(); i++) {
        encontrados += busqueda_binaria(v, 50);
    }
    return encontrados;
}
int obtenerTamanio(vector<int> v){
    return v.size();
}
void pushear55(vector<int> &v){
    v.push_back(55);
}
void popop(vector<int>&v) {
    v.pop_back();
}
int index5(vector<int> v) {
    return v[5];
}
int indexX(vector<int> v,int x) {
    return  v[x];
}
void cambiarIndice5a55(vector<int> v){
    v[5] = 55;
}
void cambiarIndiceXa55(vector<int> v,int x){
    v[x] = 55;
}
void flipear(vector<bool> v) {
    v.flip();
}
void clerear(vector<int> v) {
    v.clear();
}