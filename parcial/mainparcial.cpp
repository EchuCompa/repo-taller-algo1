#include "ejerciciosparcial.h"
#include "../Labo05/ejercicios5.cpp"

using namespace std;


int main() {
    vector<int> st = {1,2,3,4,5,6,7,8};
    //sumarConsecu(st);
    //cout << mostrarVector(st);
    vector<vector<int>> mat = {{1,23,90,91,92},
                               {25,26,80,81,82},
                               {27,29,75,76,77},
                               {32,33,71,72,73},
                               {40,41,42,43,44}};
    int co, fi;
    cout << buscarEnZooms(mat,83,fi,co);
    return 0;
}