#ifndef EJERCICIOS_INCLUDED_H
#define EJERCICIOS_INCLUDED_H

#include <vector>
#include <string>
#include <iostream>
#include <cmath> //Función abs
#include<tuple> //Para poder usar las tuplas

using namespace std;
//1)
void mostrarMatriz(vector<vector<int>> mat);
//2)
int productoPunto(vector<int> v1, vector<int> v2 );
vector<vector<int>> produTranspuesta(vector<vector<int>> mat);
//3)
vector<vector<int>> redimensionarMatriz(vector<vector<int>> mat, int n2, int m2);
//4)
void trasponer(vector<vector<int>>& mat);
//5)
int contarPicos(vector<vector<int>> mat);
//6)
tuple<tuple<int, int>, vector<tuple<int, int, int>>> aTriplas(vector<vector<int> > m);
vector<vector<int>> aMatriz(vector<tuple<int, int, int>> m, tuple<int, int> dim);
void transponerDispersa(vector<tuple<int, int, int>>& m);
//7)
vector<vector<float>> temperatura_tiempo_promedio(vector<vector<vector<float>>> temps);
vector<float> temperatura_zona_promedio(vector<vector<vector<float>>> temps);
//8)
void elevar(vector<vector<int>> &terreno, int x);
bool sobresalen(vector<vector<int>> terreno, int n, int& mts);
int islas(vector<vector<int>> terreno);
//9)
tuple<int,int> encontrar_valle(int i, int j,vector<vector<int>>  terreno);
tuple<int,int> encontrar_valle_recur(int i, int j,vector<vector<int>>  terreno);

//11)

bool haySolucionParaNReinas(int n);
void permutaciones(int n, vector<vector<int>>& permus);

bool ubicarReinaEnIesimaColumna(vector<tuple<int,int>> posi_reinas, int colu, int n);
bool ubicarReinaEnIesimaColumna_opti(vector<tuple<int,int>>& posi_reinas, int colu, int n);
#endif // EJERCICIOS_INCLUDED_H


