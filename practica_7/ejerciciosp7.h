#include <vector>
#include <string>
#include <iostream>
#include <cmath> //Función abs
#include<tuple> //Para poder usar las tuplas
#include<numeric> //Para usar accumulate

using namespace std;

#ifndef CLASES_ALGO_EJERCICIOS_H
#define CLASES_ALGO_EJERCICIOS_H

//1)
vector<int> copiarSecuencia (vector<int> s);
//2)
void incSecuencia( vector<int>& a);
//3)
int cantApariciones(vector<int> s,int e);
//4)
void elevar_cuadrado(vector<int>& s);
//5)
void duplicar_elementos( vector<int>& s);
//6)
void dividirPorPromedio( vector<float>& s) ;
//7)
void armarPiramide_a(int v, vector<int>& l);
void armarPiramide_b(int v, vector<int>& l);
//8)
void multiplicar(vector<int>& s );
//9)
void cerearYSumar(vector<int>& s, int& suma);
#endif //CLASES_ALGO_EJERCICIOS_H