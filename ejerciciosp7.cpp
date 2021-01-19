#include "ejerciciosp7.h"

using namespace std;


/************* Ejercicio 1 *************/

vector<int> copiarSecuencia (vector<int> s) {
    vector<int> r;
    int i = 0;
    while (i<s.size()) {
        r.push_back(s[i]);
        i++;
    }
    return r;
}

/************* Ejercicio 2 *************/

void incSecuencia( vector<int>& a){
    int i=0;
    while (i<a.size()) {
        a[i]++;
        i++;
    }
}

/************* Ejercicio 3 *************/

int cantApariciones(vector<int> s,int e) {
    int r =0;
    for (int i=0;i<s.size();i++){
        if (s[i] == e) {
            r++;
        }
    }
    return r;
}

/************* Ejercicio 4 *************/

//Meto las dos implementaciones en el mismo programa

void elevar_cuadrado(vector<int>& s) {
    /* for (int i=-1;i+1<s.size();i++) {
        s[i + 1] *= s[i + 1];
    } */ //Primera forma

    int i=-1;
    while ( i+1<s.size()) {
        i++;
        s[i] = s[i]*s[i];
    }

}

/************* Ejercicio 5 *************/

void duplicar_elementos( vector<int>& s) {
    cout << s.size()/2 << endl;
    for (int i=0;i<(s.size()/2);i++)  {
        s[ s.size() -1 - 2*i ] *=2;
        s[ s.size() -2 - 2*i ] *=2;
        // cout << "Valor I :" << i << endl;
    }
}



/************* Ejercicio 6 *************/

void dividirPorPromedio( vector<float>& s) {
    float sumaTotal = accumulate(s.begin(),s.end(),0); //Sumo todos los elementos del vector
    float promedio = sumaTotal/s.size();
    for (int i=0;i<s.size()/2;i++){
        // cout << promedio << endl;
        s[i] /= promedio;
        s[ s.size() -1 - i] /= promedio;
    }
}

/************* Ejercicio 7 *************/

//Invariante a)

void armarPiramide_a(int v, vector<int>& l){
    for (int i=l.size()/2;i <l.size();i++) {
        l[i] = v+ l.size() -i -1;
        l[ l.size()-1 - i] = v+ (l.size()-1 - i);
    }
}

//Invariante b)

void armarPiramide_b(int v, vector<int>& l) {
    for (int i=0; i< l.size()/2;i++){
        l[i] = v+i;
    }
    for (int i= l.size()/2; i<l.size();i++){
        l[i] = v + l.size() -i -1;
    }
}

/************* Ejercicio 8 *************/

void multiplicar(vector<int>& s ) {
    for (int i=s.size()/2; i<s.size();i+=2) {
        s[i] *= 10;
        s[i+1] *= 10;
        s[s.size()-1 -i ] *= 10;
        s[s.size()-2-i ] *= 10;
    }
}

/************* Ejercicio 9 *************/

void cerearYSumar(vector<int>& s, int& suma){
    suma = 0;
    for(int i=0; i < s.size()/4;i++) {
        suma += s[2*i] + s[2*i+1] + s[s.size() -1 -2*i] + s[s.size() -2 -2*i];
        s[2*i] =0;
        s[2*i+1] =0;
        s[s.size() -1 -2*i] =0;
        s[s.size() -2 -2*i] =0;
    }
}

