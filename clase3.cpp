#include "ejercicios6.h"

using namespace std; // para ahorrarme el std

// fout.open("mi_archivo.txt", ios_base::app ); de esta forma escribimos al final del archivo

//Función clase pasada
bool esPrimo(int n) {
    if (n<=1) {
        return false;
    }
    int divisores = 0;
    for (int i =2; i<n; ++i) {
        if (n % i == 0) {
            ++divisores;
        }     }
    return divisores == 0;
}

// Ejercicio 1

void primer_ejercicio() {
    int a;
    cin >> a;
    if (esPrimo(a)) {
        cout << "El numero ingresado es primo\n";
    }
    else {
        cout << "El numero ingresado no es primo \n";
    }
}

// Ejercicio 2

void escribirArchivo(int a, int b, float f, float g){
    ofstream fout;
    fout.open("archivos_clase3/salida.txt");
    fout << a << "," << b << "," << f << "," << g;  // Escribo las variables en el archivo
    fout.close();
}

// Ejercicio 3

void leer_entrada() {
    int a;
    float f;
    ifstream fin;
    fin.open("archivos_clase3/entrada.txt");
    fin >> a >> f; //Leo los dos números y los "introduzco" en las variables
    fin.close();
    cout << a << " " << f ;
}

// Ejercicio 4

void leer_todo_numeros() {
    ifstream fin;
    fin.open("archivos_clase3/numeros.txt");
    while (!fin.eof()) { //Mientras no haya llegado al final del archivo
    float a;
    fin >> a;
    cout << a << " " ;
    }
}

// Ejercicio 5
// Rta: "a" se indefine ya que al final haces 1/0, lo cuál da un error.

//Ejercicio 6 (copyrigth a la teórica, sorry)

void swap(int& a, int& b) {
    a = a + b;
    b = a -b;
    a= a-b;
}

// Ejercicio 7

// Resuelto recursivamente
void collatz(int n, int& cantPasos) {
    ofstream fout;
    fout.open("archivos_clase3/collatz.txt", ios_base :: app); //Voy agregando cosas al final

    if (n==1) {
        fout << "  La cantidad de pasos fue " << cantPasos << " y la secuencia fue ";
    }
    else if (n%2 == 0) {
        cantPasos++; //Le sumo 1 paso
        fout << " " << n << " "  ; // Agrego el número al archivo
        collatz(n/2, cantPasos);
    }
    else {
        cantPasos++; //Le sumo 1 paso
        fout << " " << n << " "  ; // Agrego el número al archivo
        collatz(n*3 + 1, cantPasos);}
}

// Resuelto iterativamente
void collatz_iter(int n, int& numPaso){
    std:: ofstream colla;
    numPaso = 0; // Por si no ingresan un 0
    colla.open("collatz.txt");
    colla << "La secuencia de número es: ";
    while (n != 1){
        if (n % 2 == 0){
            n = n/2;
        }else{
            n = n*3 + 1;
        }
        numPaso++;
        colla << n << " ";
    }
    colla << " y la cantidad de pasos fue igual a  " << numPaso;
    colla.close();
}

//Ejercicio 8

void suma_archivos() {
    ifstream fin; //Aprendí que de esta forma puedo abrir múltiples archivos, thanks Google
    ifstream fin2;
    ofstream fout;

    fin.open("archivos_clase3/numeros.txt"); // Abro los dos archivos a leer y el nuevo archivo
    fin2.open("archivos_clase3/numeros1.txt");
    fout.open("archivos_clase3/suma.txt");
    while (! fin.eof()) {
        float a,b;
        fin >> a; //Agarro los números de cada archivo.
        fin2 >> b;
        fout << a+b << " "; //Los meto en el nuevo.
    }
    fin.close();
    fin2.close();
    fout.close();
}

// Ejercicio 9


void proximosPrimosGemelos( int& res1, int& res2) {
    while ( !(esPrimo(res1) && esPrimo(res2)) ) {
        res1++;
        res2++;
        //Le voy sumando 1 a ambos hasta que sean los dos primos

    }
}

// Resuelto recursivamente
// Para que funcione aclaro que res1 y res2 deben ser 3 y 5 inicialmente.
// Además asumi que res1 < res2 y que siempre se cumple res1 - res2 =2.

void primosGemelos(int n, int& res1, int& res2) { //Empiezo a contar desde el 0 porque soy kul
    ofstream primos;
    primos.open("archivos_clase3/primos_hermanos.txt", ios_base :: app);
    if (n == 0) {
        primos << " Valores finales: (" << res1 << " , " << res2 << ")";
        primos.close();
        // Cierro el doc e introduzco los valores finales
    }
    else {
    primos << "  (" << res1 << " , " << res2 << ")" << "  "; // Escribo los valores en el doc

    res1++; // Si no son los valores deseados entonces reviso los siguientes
    res2++;
    proximosPrimosGemelos(res1,res2);
    primosGemelos(n-1,res1,res2);
    }
}

//Resuelto iterativamente
//Acá cuento desde el 0 también

void primosGemelos_iter(int n, int& res1,int& res2){
    res1 = 3;
    res2 = 5;
    ofstream fout;
    cout << "Se ejecuta";
    fout.open("archivos_clase3/primosgemelos.txt");
    while (n>=0){
        fout <<" ("<<res1<<","<<res2<<") ";
        res1++; // Si no son los valores deseados entonces reviso los siguientes
        res2++;
        proximosPrimosGemelos(res1, res2);
        n--;
    }
    fout.close();
}

int main () {
    vector<int> j = {1,2,3,4,5,6,7,8,9};
    cout << minimo(j);
    return 0;
}