#include "ejercicios9.h"

using namespace std;

#import <algorithm> //Para ordenar la lista

//Aplico una idea similar a un counting sort


/************* Ejercicio 1 *************/

//a)

bool sonAnagramas(string p1, string p2) {
    string p1_ord = ordenarString(p1), p2_ord =ordenarString(p2);
    return  p1_ord == p2_ord;
}

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

//b) Se que (int)'a' = 97, y hay 26 letras en el abecedario (sin la ñ).

bool esAnagrama(string p1, string p2){
    int produ_p1 =1, produ_p2 = 1;
    if (p1.size() != p2.size()) return false;
    for (int i=0;i<p1.size();i++){
        produ_p1 *= nEsimoPrimo(int(p1[i]) -96);
        produ_p2 *= nEsimoPrimo(int(p2[i]) -96);
    }
    return produ_p1 == produ_p2;
}

int nEsimoPrimo(int n) {
    int nume=2;
    int n_primo=1;
    while( n_primo< n) {
        nume++;
        if (esPrimo(nume)) n_primo++;
    }
    return nume;
}

bool esPrimo(int n) {
    if (n<=1) {
        return false;
    }
    bool primo = true;
    int i =2;
    while ( i<=sqrt(n) && primo)  {
        if (n % i == 0) {
            primo= false;
        }
        i++;    }
    return primo;
}

//c) Confirmado en la práctica que la idea es legal y "distinta".

bool hayAnagrama(string s, string t){
    vector<int> aparis_char( 112956,0);
    for (char carac : s){ //Cuento las apariciones de cada caracter
        aparis_char[int(carac)]++;
    }
    for (char carac : t){ //Resto las apariciones de cada caracter
        aparis_char[int(carac)]--;
    }
    vector<int> son_anagramas( 112956,0);
    return son_anagramas == aparis_char; //Si tenían los mismos caracteres entonces el vector aparis debería estar lleno de 0`s.
}

/************* Ejercicio 2 *************/

/*La idea sería primero recorrer una vez la lista y guardar el índice de cada palabra en un vector que contenga
 * los indíces ordenados según la longitud de la palabras que "indican". De tal modo quedaría un vector de vectores,
 * en el cuál la posición del vector representa la longitud de las palabras que indican los indices que contiene.
 * indices_ordenados = < <4> , <7,12> , <> , <2,5> >, acá el string 4 tiene longitud 0, los strings 7 y 12 tienen
 * longitud 1, ninguno tiene longitud 3, etc... */

vector<string> lengthSort(vector<string> strings){
    vector<vector<int>> indices_ordenados(41);
    for (int i=0;i<strings.size();i++) { //Guardo los indices de las palabras según su longitud
        indices_ordenados[strings[i].size()].push_back(i);
    }
    vector<string> palas_ordenadas(strings.size());
    int pala_nume =0;
    for (int j=0; j<indices_ordenados.size();j++){ //Inserto las palabras según su longitud en la lista ordenada
        for (int k =0; k<indices_ordenados[j].size();k++){
            palas_ordenadas[pala_nume] = strings[indices_ordenados[j][k]];
            pala_nume++;
        }
    }
    return palas_ordenadas;
}

/************* Ejercicio 3 *************/

//a + b)

int MedianamergeSort(vector<int>& s) {
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
    if (fusion_ordenada.size() %2 ==0){
        return   (fusion_ordenada[fusion_ordenada.size()/2] + fusion_ordenada[fusion_ordenada.size()/2 + 1] )/2;
    }
    return fusion_ordenada[(fusion_ordenada.size()-1)/2];
}

//c)

//Solución : https://cs.stackexchange.com/questions/95706/median-of-two-sorted-arrays-of-different-size-in-logarithmic-time/95715#95715

int mediana(vector<int> a, vector<int> b) {
    int mediana =medianaDosVecOrden(a,b);
    if (mediana ==-1) {
        mediana = medianaDosVecOrden(b,a); //Busca la mediana en el vector a
    }
    return mediana;
}

int medianaDosVecOrden(vector<int> a, vector<int> b) {
    int low =0, high =a.size();
    int n= a.size() + b.size();
    int mediana=-1;
    while ( low +1 <high) {
        int mid = (low+high)/2;
        int posi_b = n/2- (mid-1);
        if (a[mid] > b[posi_b] &&  a[mid] < b[posi_b+1] ){
            mediana= mid;
            break;
        }
        if (a[mid] < b[posi_b] ) {
            low=mid;
        }
        if (a[mid] > b[posi_b+1]) {
            high=mid;
        }
    }
    return mediana;
}

/************* Ejercicio 4 *************/

//a + b) Resuelto con un bello Insertion Sort + asumo que solo ingresan letras y números, sino habría que modificar un poco el código.

/*Orden  ->  vacio<a<nume
Si llego al final me fijo la longitud de ambas y comparo en base a eso.
Caso borde:
Ejemplo12a2 < Ejemplo12a12, si llego al final y comparo dos numeros, pero uno se termina y el otro
 tiene un número cómo siguiente caracter entonces me quedo con el de dos números
 */

void natSorted(vector<string>& v){
    for (int i=0;i<v.size();i++){
        insertar(v, i);
    }
}

void insertar(vector<string>& v, int comienzo){
    for (int i=comienzo;i>0 && stringMayor(v[i-1], v[i]);i--){
        swap(v[i], v[i-1]);
    }
}

bool esNume(char c){
    return (int(c) < 96);
}


bool stringMayor(string p1, string p2){ //Comprueba si p1 es mayor a p2
    bool mayor= true;
    for (int i=0;i<p1.size() && i<p2.size() && mayor ;i++) {

        if ( esNume(p1[i]) && esNume(p2[i]) ) { //El caso en el que sean dos caracteres númericos y pueda estar llegando al final
            string pala1(1,p1[i]),pala2(1,p2[i]);
            i++;
            while( (i<p1.size() || i<p2.size() ) && esNume(p1[i]) && esNume(p2[i])) {
                if (esNume(p1[i]) && i<p1.size()) pala1 += p1[i];
                if (esNume(p2[i]) && i<p2.size()) pala2 += p2[i];
                i++;
            }
            mayor = stoi(pala1) >= stoi(pala2);
        }
        else if ((!esNume(p1[i])) && (esNume(p2[i]))) { //Si p1 es una letra y p2 un número.
            mayor = false;
        } else if ( p1[i] < p2[i]  && !(esNume(p1[i]) &&  !esNume(p2[i]) )) { //Si es una letra o un número menor
            mayor = false;
        }
        else if( !(!esNume(p1[i])) && (esNume(p2[i]) || !( p1[i] <= p2[i]  && !(esNume(p1[i]) &&  !esNume(p2[i]) ) ) ) ) {
            break; //Si sucede algo inverso a las situaciones anteriores entonces ya es mayor
        }
        if (mayor && (p2.size() > p1.size()) && i==p1.size()) mayor = false;
    }

    return mayor;
}