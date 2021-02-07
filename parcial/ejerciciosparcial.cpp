#include "ejerciciosparcial.h"


using namespace std;

void sumarConsecu(vector<int>& s){
    vector<int> aux = s;
    for (int i=1;i<s.size();i++){
        s[i] += aux[i-1];
    }
}

bool buscarEnZooms(vector<vector<int>>& M, int elem, int& fi, int& co){
    int j=0;
    int i=M.size()-1;
    bool res = false;
    while ( i>=0 && !( M[i][0] < elem && elem < M[i][M[0].size()-1] )  ){
        i--;
    }
    while ( j < M[0].size() && i>=0 && M[i][j] != elem  ) {
            j++;
        }
    if (  j < M[0].size() && i>=0 ){
        fi = i;
        co = j;
        res = true;
    }
    return res;
}



/*
  1  |  23    |  90    |   91   |  92     |
----------------------------------
  25  |  26    |  80    |   81   |   82    |
----------------------------------
  27  |  29    |  75    |  76    |   77    |
----------------------------------
   32 |  33    |  71     |  72    |   73    |
 ---------------------------------
  40   |   41   |   42   |   43   |   44    |
 -------------------------------------


 */