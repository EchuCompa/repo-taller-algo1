#include "ejerciciosp9.h"


using namespace std;


int main() {
    vector<int> test = {0,1,2,3,4,5,6,8,9};
    //cout << elementoFaltante(test);
    vector<int> elesOrdenados = {0,1,1,1,1,1,1};
    //cout << sumaElementosOrdenados(elesOrdenados);
    vector<int> funca = {0,1,1,1,1,1,1,3,3,3,3,2,2,2,2,2,2,2,2,2};
    //cout << elementoMasApariciones(funca);
    string t = "!hola cag gfsdg gmsdfkl fdasfda gfadfdsafdas";
    //cout <<  ordenarString(t);
    //vector<int> cercanos_3 = kNumerosMasCercanos(4,3,test);
    //cout << mostrarVector(cercanos_3);
    vector<int> orden = {1,2534,543,1234124,7537,32,432,745,4321,874,58,6,8,2,65,43,5634,21,68,32313,76565,231231,76465,4323,6575,4325,7646,5434,767};
    vector<vector<int>> vectores_a_ordenar = {{1,2,3,4,5}, {5,4,3,2,1}, {1,3,5,2,4}, {1,1,1,2,2,2}, {1,2,1,2,1,2,1,2}, {1,10,50,30,25,4,6}};
    vector<vector<int>> vecs = iteracionesPorVector(vectores_a_ordenar);
    mostrarVectorDeVectores(vecs);
    vector<int> dos_ord = {1,3,5,7,9,11,13,2,4,8,10,12,14};
    //mergeSort(dos_ord);
    //cout << ('c'<'b');


    return 0;
}