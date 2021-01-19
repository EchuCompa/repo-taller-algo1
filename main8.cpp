#include "ejercicios8.h"

using namespace std;

int main() {

    ofstream fout;
    fout.open("ultimopunto.csv");
    
    fout << "n\t" << "tiempo" << endl;
    for (int n = 10; n < 115; n+=10) {

        vector<int> v = construir_vector(n,"azar");
        vector<bool> b(n,false);

        double t0 = clock();
        //int res = hayDuplicados(v);
        /*obtenerTamanio(v);
        pushear55(v);
        popop(v);
        index5(v);
        indexX( v,n-1);
        cambiarIndice5a55(v);
        cambiarIndiceXa55(v,n-1);
        flipear(b);
        clerear(v);*/
        algunSubconjSuma(v,150);
        double t1 = clock();

        double tiempo = (double (t1-t0)/CLOCKS_PER_SEC);
        fout << n << "\t" << tiempo << endl;
        cout << n << endl;
    }
    fout.close();
    return 0;
}