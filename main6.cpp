#include <iostream>
#include "ejercicios6.h"
#include <ejercicios5.h>

using namespace std;



int main()
{
    vector <vector <int > > mat = {{6 , 12 , 18, 25} ,
                                   {7 , 14 , 21, 37} ,
                                   {8 , 16 , 24, 12} ,
                                   {9 , 18 , 27, 39}};
    //trasponer(mat);
    // mostrarMatriz(mat);
    vector<int> j = {1,2,3,4,5,6};
    //j.insert(j.begin()+j.size()-1,3);
    //mostrarVector(j);
    vector<vector<int>> v = {{}};
    //permutaciones(10,v);
    vector<vector<int>> tr = { {5,2,3,5},
                               {4,0,7,2},
                               {6,4,0,5} };
    contarPicos(tr);
    return 0;
}

