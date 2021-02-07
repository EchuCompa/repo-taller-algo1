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

int mesetaMasLarga (vector <int > & v );
int sumarPotenciaHastaFun (int n);
int sumarPotenciasHasta(int n);
int determinanteMatrizTriangular(vector<vector<int>> mat);
bool esTriangular(vector<vector<int>> mat);
int productoPunto(vector<int> v1, vector<int> v2 );
vector<int> columnaMatriz(vector<vector<int>> mat, int colu);
vector<vector<int>> productoMatrices(const vector<vector<int>>& mat1, const vector<vector<int>>& mat2);
int elementosImparesConsecu(vector<int> v);
int costoMinimo(int x, int y,const vector<vector<int>>& costos);
int DpcostoMinimo(const vector<vector<int>>& costos);
int min(int a, int b);
vector<vector<int>> elevarMatrizN(const vector<vector<int>>& mat1, int n);
int booleanosABinario(const vector<bool>& bools);
int indice(const vector<vector<int>>& apari, int ele);
vector<bool> boolsDistintosCheto(vector<vector<bool>> mat);
#endif //CLASES_ALGO_EJERCICIOS_H