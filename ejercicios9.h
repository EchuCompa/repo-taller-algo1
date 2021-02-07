#ifndef EJERCICIOS_INCLUDED_H
#define EJERCICIOS_INCLUDED_H

#include <vector>
#include <string>
#include <iostream>
#include <cmath> //Función abs
#include<tuple> //Para poder usar las tuplas

using namespace std;

bool sonAnagramas(string p1, string p2);
string ordenarString(string s);
bool esAnagrama(string p1, string p2);
int nEsimoPrimo(int n);
bool esPrimo(int n);
vector<string> lengthSort(vector<string> strings);
bool stringMayor(string p1, string p2);
void insertar(vector<string>& v, int comienzo);
int mediana(vector<int> a, vector<int> b);
int medianaDosVecOrden(vector<int> a, vector<int> b);
bool stringMayor(string p1, string p2);
void natSorted(vector<string>& v);

#endif // EJERCICIOS_INCLUDED_H


