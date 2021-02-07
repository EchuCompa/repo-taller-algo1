#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <fstream>
#include <ctime>

using namespace std;

void mostrar_vector(vector<int>& v);
vector<int> construir_vector(int n, string disposicion);

bool hayDuplicados ( vector < int >& v );

bool aux(vector<int>& vec, int i, int sum);
bool algunSubconjSuma(vector<int>& vec, int sum);

bool busqueda_binaria(vector<int> &s, int x);

bool hayDuplicados2 ( vector < int >& v );
void mitad0 (vector<int> lista);
void todosPositivos(vector<int> lista);
void todosPositivos3D (vector<vector<vector<int>>> cubo);
int busquedaMatrizCuadradaFilasOrdenandas (vector<vector<int>> matriz,int x);
void sumarTodoDeFormaRara (vector<int> v);
int hacealgopibe (vector<int> v);

int obtenerTamanio(vector<int> v);
void pushear55(vector<int> &v);
void popop(vector<int>&v);
int index5(vector<int> v);
int indexX(vector<int> v,int x);
void cambiarIndice5a55(vector<int> v);
void cambiarIndiceXa55(vector<int> v,int x);
void flipear(vector<bool> v);
void clerear(vector<int> v);