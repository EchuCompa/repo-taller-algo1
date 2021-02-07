#include <vector>
#include <string>
#include <iostream>
#include <cmath> //Función abs
#include<tuple> //Para poder usar las tuplas
#include<numeric> //Para usar accumulate

#import <algorithm>


using namespace std;

#ifndef CLASES_ALGO_EJERCICIOS_H
#define CLASES_ALGO_EJERCICIOS_H

pair<int,int> posicionElemento(int x,const vector<vector<int>>& mat);
int elementoFaltante( vector<int> s);
int sumaElementos(vector<int> s);
int sumaElementosOrdenados(vector<int> s);
int sumaElementosOrdenados2(vector<int> s);
int elementosSinRepetir(vector<vector<int>> m, int e);
int aparicionesListaE(int e, vector<int> v);
int rangoV(vector<int> v);
int elementoMasApariciones(vector<int> s);
void agregarRepetis(vector<pair<int,int>>& aparis, int ele);
int elementoMasRepetidoAcotado(vector<int> s, int cota_inf, int cota_sup);
string ordenarString(string s);
vector<int> kNumerosMasCercanos(int k, int e, vector<int> v);
void insertarCercano(int k, int e, int elem, vector<int>& cercanos);
void cocktailSort( vector<int>& s);
vector<vector<int>> iteracionesPorVector(vector<vector<int>> vec_a_ordenar );
void mostrarVectorDeVectores(vector<vector<int>> vs);
void dosMitades(vector<int>& s);
vector<int> reconstruye(vector<int> a);

#endif //CLASES_ALGO_EJERCICIOS_H