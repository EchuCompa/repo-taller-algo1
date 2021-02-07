#include "ejerciciosp7.h"
#include "../Labo05/ejercicios5.cpp"

using namespace std;


int main() {
    vector<int> n = {1,3,4,5,6,3,54,21,11,15,43,54,75,10,23,97};
    int suma;
    cerearYSumar(n,suma);
    cout << mostrarVector(n) << endl;
    cout << suma;
    return 0;
}