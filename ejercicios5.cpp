#include <iostream>
#include "ejercicios5.h"

using namespace std;

/************* Ejercicio 1 *************/
bool estaOrdenadoAsc(vector<int> v){
    int i=0;
    int longitud = v.size();
    bool esMenor=true; //Tiene que empezar con un valor asignado pues sino se le asigna uno random
    while(i<=longitud-2 && esMenor){
        esMenor = v[i]<=v[i+1];
        i++;
    }
    return i==longitud-1;
}

bool estaOrdenadoDesc(vector<int> v){
    int longitud = v.size();
    int i=0;
    bool esMayor= true; //Tiene que empezar con un valor asignado pues sino se le asigna uno random
    while(i<=longitud-2 && esMayor){
        esMayor = v[i]>=v[i+1];
        i++;
    }

    return i==longitud-1;
}

bool estaOrdenado(vector<int> v){
    int longitud = v.size();
    if (longitud==0 || longitud==1)
        return true;
    else
        return estaOrdenadoDesc(v) || estaOrdenadoAsc(v);
}

/************* Ejercicio 2 *************/
bool pertenece(int elemento, vector<int> v){
    int longitud = v.size();
    if(longitud==0)
        return false;
    else {
        int i=0;
        bool sigo = true;
        while( (i<longitud) && sigo){
            sigo = v[i]!=elemento;
            i++;
        }
        return !sigo; //Al devolver i<longitud si el elemento estaba al final del vector entonces
        // devolvía false sin importar si lo encontrara o no. Por lo tanto sigo es la variable que nos
        // importa
    }
}

/************* Ejercicio 3 *************/
long long fibonacci(int k){ //Le tuve que cambiar el tipo a todos los long para que funque con k=50
    if(k==0) //Acá estaba asignando valores, no comparando. Por lo tanto hay que cambiarlo a ==
        return 0;
    else if(k==1)
        return 1;
    else{
        long long i=0;
        long long j=1;
        long long m;
        for(int nesimo=2; nesimo<=k; nesimo++){ //Cambie nesimo=2 pues estaba haciendo una pasada de más
            m = j;
            j = i+j;
            i = m;
        }
        return j;
    }
}

/************* Ejercicio 4 *************/

int sumaDoble(vector<int> s){
    int res=0;
    int i = 0;
    while(i < s.size()){
        if(s[i]>=0 && s[i]%2==0 )
            res = res + (s[i]*2);
        i++;
    }
    return res;
}

/************* Ejercicio 5 *************/
bool existePico(vector<int> v){
    int i = 1;
    bool res = false;
    while(i<v.size()-1){
        res = res || (v[i] > v[i-1] && v[i] > v[i+1]);
        i++;
    }

    return res;
}

/************* Ejercicio 6 *************/

int todosImpares(vector<int> v){
    int res=true;
    int i = v.size()-1;
    while(i >= 0) {
        res  = res && (v[i] % 2 == 1);
        i--;
    }
    return res;
}

/************* Ejercicio 7 *************/
bool esPrimo(int n){
    bool res = true;
    for(int i = 2; i < n; i ++){
        if(n % i == 0){
            res = false;
        }
    }
    return res;
}

int sumaPrimos(int n){
    int suma = 0;
    int i = n;
    if (n%2 == 0) i--; //Si n es para para que funque y evalue los impares i tiene que ser impar
    while( i > 2) {
        if (esPrimo(i)) {
            suma = suma + i;
        }
        i = i - 2;
    }
    return suma;
}



/************* Ejercicio 8 *************/
int indiceMinimoSubsec(vector<int> v, int i, int j){
    int res = v[j];
    for (int l=j; i-1 < j; l--) {
        if ( v[l] < v[res]) res=l; // Si encuentro un elemento menor me guardo el índice
    }
    return 0;
}

//Ya que se tiene que cumplir que "(∀k : Z) (l < k ≤ j −→L s[k] ≥ s[res])" si l empieza desde i entonces
// res debería ser el índiceMínimo desde el principio, por lo tanto interprete que l debe ir decreciendo.


/************* Ejercicio 9 *************/
int sumatoria(vector<int> v) {
    int suma=0;
    int par=0;
    int longi = v.size(), mitad = longi / 2;
    if (v.size()%2 ==0 && v.size() != 0) {
        par =1;
        suma -= v[mitad];
    }
    if (v.size() != 0) {
        suma += v[mitad];
        for (int k = 1; k < mitad + 1; k++) {
            suma += v[mitad + k - par ] + v[mitad - k ];
        }
    }
    return suma;
}


/************* Ejercicio 10 *************/

//No cumple el invariante, triste
/*
void ordenar(vector<int>& v){
    int i = 0;
    bool orden=true;
    while (i <v.size()-1) {
        if (!orden) {
            i=0;
            orden = true;
        }
        if (v[i] <= v[i+1]) {
            i++;
        } else {
            orden = false;
            swap(v[i], v[i+1]);
        }
    }
}
*/

void ordenar(vector<int>& v){
    int i = 0;
    int pos;
    while (i<v.size()){
        pos = indiceMinimoSubsec(v,i,v.size()-1); //Agarra el mínimo de la secuencia
        v.insert(v.begin()+i, v[pos]); //Lo inserta en la posición i
        v.erase(v.begin() + pos+1);  //Elimina el mínimo de la secuencia
        i++;
    }
}
/************* auxiliar *************/

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

string mostrarVector_real(vector<float> v){
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