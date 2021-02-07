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

void sumarConsecu(vector<int>& s);
bool buscarEnZooms(vector<vector<int>>& M, int elem, int& fi, int& co);
#endif //CLASES_ALGO_EJERCICIOS_H