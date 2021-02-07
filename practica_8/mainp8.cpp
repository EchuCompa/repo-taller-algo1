#include "ejerciciosp8.h"
#include "../Labo05/ejercicios5.cpp"

using namespace std;


int main() {
    vector<vector<int>> costo = {{1,1,1,1 },
                                {5,3,2,1000},
                                {13,7,9,12},
                                {5,4,8,10}};

     cout << costoMinimo(3,3,costo) << endl;
     cout << "Lombi: " << DpcostoMinimo(costo);
    /* for (int i = 0; i < 18; ++i) {
        cout << "Valor de i " << i << " Valor de la func " << sumarPotenciaHastaFun(i) << "\n";
    }
    vector<bool> t = {true,false,true, false};
    //cout << booleanosABinario(t); */
    return 0;
}