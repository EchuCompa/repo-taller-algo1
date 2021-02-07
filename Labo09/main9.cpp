#include "ejercicios9.h"


using namespace std;


int main() {
    string s = "lideraa", t= "deliras";
    //cout << esAnagrama(s,t);
    vector<string> test = {"hola", "esto", "es", "una", "prueba"};
    vector<string> funca = lengthSort(test);
    //cout << funca[0] + funca[1] + funca[2] + funca[3] + funca[4];
    string j = "holas223", m = "holas32";
    cout << stringMayor(j,m);
    vector<string> testing = {"version19", "version20", "version111", "version110"};
    natSorted(testing);
    cout << "To peola";
    return 0;
}

