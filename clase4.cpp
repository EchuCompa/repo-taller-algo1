# include <vector>
# include <iostream>
# include <fstream>
#include <cmath> //Para el square root
using  namespace  std;

#import <algorithm> //Para ordenar la lista

//Función clase pasada
bool esPrimo(int n) {
    if (n<=1) {
        return false;
    }
    bool primo = true;
    int i =2;
    while ( i<sqrt(n) && primo)  {
        if (n % i == 0) {
            primo= false;
        }
    i++;    }
    return primo;
}

// Ejercicio 1

// 1.1)

bool divide(vector<int> v, int n) {
    bool divi = true;
    int i =0;
    while ( i<v.size()   && divi ){
        if (v[i]%n != 0) { //Si n no divide a un elemento entonces es falso
            divi = false;
        }
        i++;
    }
    return divi;
}

// 1.2)

int maximo(vector<int> v) {
    int maxi = v[0];
    for (int i =0; i <v.size(); i++) {
        if ( maxi < v[i]) { //Si el valor es mayor al actual máximo se reemplaza el maxi
            maxi = v[i];
        }
    }
    return maxi;
}

int minimo(vector<int> v) {
    int mini = v[0];
    for (int i =0; i <v.size(); i++) {
        if ( mini > v[i]) { //Si el valor es mayor al actual máximo se reemplaza el maxi
            mini = v[i];
        }
    }
    return mini;
}
// 1.3)

bool pertenece(int elem, vector<int> v) {
    bool perte = false;
    int i =0;
    while (perte == false && i < v.size()) {
        if (v[i] == elem) { // Si un elemento de la secuencia es igual al elem buscado
            perte = true;
        }
        i++;
    }
    return perte;
}

// 1.4)

void mostrarVector(vector<int> v) {
    cout << "[";
    for (int i =0; i <v.size()-1; i++) {
        cout << v[i] << ", ";
    }
    cout << v[v.size()-1] << "]";
}

void mostrarVector_string(vector<string> v) {
    cout << "[";
    for (int i =0; i <v.size()-1; i++) {
        cout << v[i] << ", ";
    }
    cout << v[v.size()-1] << "]";
}

void  mostrarVector_pair( vector<pair<int,int> >  v){
    cout << "[";
    for (int n =0; n <v.size()-1; n++) {
        cout << " (" << v[n].first << ", " << v[n].second << ") ";
    }
    cout << " (" << v[v.size()-1].first << ", " << v[v.size()-1].second << ") ]";
}
//1.5)

void sinImpares(vector<int>& v) {
    for (int i =0; i <v.size()-1; i++) {
        if (v[i]%2 != 0 ) { //Si es impar lo modifico
            v[i] = 0;
        }
    }
}

//1.6)

vector<int> limpiarDuplicados(vector<int> v) {
    vector<int> sin_repe;
    for (int i =0; i <v.size(); i++){
        if ( !pertenece(v[i], sin_repe) ) { // Si el vector no está en la nueva secuencia
            sin_repe.push_back(v[i]);
        }
    }
    return sin_repe;
}

//1.7)

vector<int> rotar(vector<int> v, int k) {
    vector<int> vec_rotado;
    for (int i=k; i<v.size()+k; i++) { //Empiezo a contar desde el primer elem del nuevo vector
        int posi = i%v.size(); // Esto es para que al "pasarse" de rango siga con los del principio
        vec_rotado.push_back(v[posi]);
    }
    return vec_rotado;
}

//1.8)

vector<int> reverso_iter(vector<int> v) {
    vector<int> rever;
    for (int i=v.size()-1; i>-1; i--) { //Recorro la lista al reves
        rever.push_back(v[i]);
    }
    return rever;
}

//Versión recursiva
// Auspiciada por "Nacho_Vigi"

int pop_front(vector<int> &v){ //Extrae el primer valor de un vector y lo devuelve
    int r = v[0];
    v.erase(v.begin());
    return r;
}

vector<int> reverso(vector<int> v) {
    if(v.size() <= 1)
        return v;

    int front = pop_front(v);
    vector<int> r = reverso(v);
    r.push_back(front);
    return r;
}

//1.9)

vector<int> factoresPrimos(int n) {
    vector<int> facto_prim;
    for (int i = 2; i<sqrt(n);++i) {
        if (n%i == 0 && esPrimo(i)) {
            facto_prim.push_back(i);
        }
    }
    return facto_prim;
}

//Si queremos ser un poco más kul

vector<int> factoresPrimos_kul(int n) {
    vector<int> facto_prim;
    int i = 2;
    int max_divi = n;
    while (i<=n) {
        if (max_divi % i ==0 && esPrimo(i)) {
            max_divi /= i; // Disminuyo la cantidad de números que voy a probar
            if (!pertenece(i,facto_prim)) { //Para que no agregue dos veces a un primo
            facto_prim.push_back(i); }
            i--; //Para que lo vuelva a dividir por el mismo número si es posible
        }
        i++;
    }
    return facto_prim;
}

//1.10) Para no agregar más condiciones asumo que si todos los elementos son iguales
// entonces la lista esta ordenada

bool estaOrdenado(vector<int> v) {
    bool crece = true, decrece=true;
    int i=0;
    while ( (crece || decrece) && i<v.size()-1 ) {
        if (v[i]-v[i+1] <0) {
            decrece = false;
        }
        else {
            crece = false;
        }
        i++;
    }
    return  crece || decrece;
}

//1.11)

void negar(vector<bool>& v) {
    for (int i=0; i<v.size(); i++) {
        v[i] = !v[i];
    }
}

//1.12)

//Es súper ineficiente y medio feito. La otra idea era ir agregando cada aparición de un elemento
// a un vector con las apariciones y que sus indices indiquen las apariciones de que elemento son.
// ele = <3, -5, 10, 23> ; apari = <5, 2, 4, 1>  y en base a eso ir modificandolo. De esta forma
// sólo tengo que recorrer una vez la lista, pero la pregunta es "¿Eso no podría llegar a ser peor
// ya que tengo que encontrar el índice de un elemento cada vez que lo busco?". Ni idea. Pinta que es
// peor por lo que me dijeron en la clase. Mejor ir sumando las apariciones y recorrer muchas veces
// la lista pero meramente sumando.
// O hacer un apari = < (3,0) (-5,0) (10,0) (23,0) > e ir sumando las apariciones, pero misma
// dudeli de antes. 

//Versión no tan piola

vector< pair<int, int> > apariciones(vector<int> v) {
    // vector<int> elem_sin_repetir = limpiarDuplicados(v); //Acá los tengo desordenados y no me sirve para el 2.4)
    vector<int> elem_sin_repetir;
    // Recorro desde el minimo al máximo y sólo agrego los que pertencen a v, así me quedan ordenados
    for (int i=minimo(v); i<=maximo(v);i++) {
        if (pertenece(i, v)) {
            elem_sin_repetir.push_back(i);
        }
    } //Esto ahora carece de sentido, lel. Antes era lógico.
    vector< pair<int, int> > apari_elem;
    int apari, nume;
    for (int  i=0; i<elem_sin_repetir.size(); i++) { //Repito el proceso para cada elemento distinto de la lsta
        apari=0;
        nume = elem_sin_repetir[i];
        for (int j=0; j<v.size(); j++) { //Cuento las apariciones del elemento en el vector
            if (v[j] ==  nume) {
                apari++;
            }
        }
        apari_elem.push_back(make_pair(nume,apari)); //Creo la tupla y la ingreso
    }
    return apari_elem;
}

// Versión auspiciada por "ordena tu lista antes y es una masita"
// Créditos : Martín Lombardo

vector< pair<int, int> > apariciones_kul(vector<int> v) {
    sort(v.begin(), v.end()); //Ordeno la lista de menor a mayor
    vector< pair<int, int> > apari_elem;
    int apari, nume;
    bool nuevo_ele= true;
    for (int  i=0; i<v.size(); i++) { //Repito el proceso para cada elemento distinto de la lsta
        if ( nuevo_ele== false && (nume != v[i] || i == v.size()-1) ) {
            cout << nume << "  " << apari << "  ";
            nuevo_ele = true;
            apari_elem.push_back(make_pair(nume,apari)); //Creo la tupla y la ingreso
        }

        if (nuevo_ele) { //Si estoy trabajando con un nuevo elemento reseteo el proceso
            apari =1;
            nume = v[i];
            nuevo_ele = false;
        }
        else {
            apari++;
        }
    }
    return apari_elem;
}


//Ejercicio 2

//2.1)

bool palindromo(string pala) { //Chequea si una palabra es un palindromo
    bool pali = true;
    for (int i =0; i<pala.size()/2;i++) {
        if (! (pala[i] == pala[pala.size()-1-i]) ) { //Chequea si las letras "opuestas" son iguales
            pali= false;
        }
    }
    return pali;
}

void mayus(string& s) { //Convierte un string a mayusculas
    for (int i=0; i<s.size();i++){
        s[i] = toupper(s[i]);
    }
}

 void palindromos(string rutaArchivoIn, string rutaArchivoOut) {
     ifstream pali;
     ofstream pali2;
     pali.open(rutaArchivoIn);
     pali2.open(rutaArchivoOut);
     while (!pali.eof()) { // Leo las palabras de palindromos
         string pala;
         pali >> pala;
         if (palindromo(pala)) { // Si es un palindromo lo agrego a mi archivo
             mayus(pala);
             pali2 << pala << "  ";
         }
     }
     pali2.close();
     pali.close();
    }

// 2.2) Asumo que ambos tienen la misma longitud

void promedios(string rutaArchivoIn1, string rutaArchivoIn2, string rutaArchivoOut) {
    ifstream prome1;
    ifstream prome2;
    ofstream prome_tot;
    prome1.open(rutaArchivoIn1);
    prome2.open(rutaArchivoIn2);
    prome_tot.open(rutaArchivoOut);
    while (!prome2.eof()) {
        float num1,num2;
        prome1 >> num1;
        prome2 >> num2;
        prome_tot << (num1+num2)/2 << "  ";
    }
    prome1.close();
    prome2.close();
    prome_tot.close();
}

// 2.3)  ACÁ ESTA EL EJERCICIO TOBI, TODO TUYO BRO

//Podría hacer que evalue cuándo lee, pero paja pues ya tengo hecha la función.

vector<int> lee_lista_archivo(string rutaArchivo) {
    vector<int> lista_nume;
    ifstream fin;
    fin.open(rutaArchivo);
    while (!fin.eof()) { //Guardo todas las apariciones en una lista
        int apar;
        fin >> apar;
        lista_nume.push_back(apar);
    }
    return lista_nume;
}

void cantidadApariciones(string rutaArchivoIn, string rutaArchivoOut) {
    vector<int> lista_nume = lee_lista_archivo(rutaArchivoIn); //Obtengo la lista de números
    ofstream aparis;
    aparis.open(rutaArchivoOut);

    vector< pair<int, int> > lista_apari = apariciones_kul(lista_nume); //Reviso la lista
    aparis << "La lógica es (número , apariciones)  ";
    for (int i =0; i<lista_apari.size(); i++) { //Guardo las apariciones
        aparis << "( " << lista_apari[i].first << ",  " << lista_apari[i].second << " ) ";
    }
}

//2.4)

void estadisticas(string rutaArchivo) {
    vector<int> lista_longi_palas;
    ifstream fin;
    fin.open(rutaArchivo);
    while (!fin.eof()) { //Guardo todas las longitudes de las palabras en una lista
        string apar;
        fin >> apar;
        lista_longi_palas.push_back(apar.size()); //Agrego las longitudes de las palabras
    }
    vector< pair<int, int> > lista_apari = apariciones(lista_longi_palas);
    for (int i =0; i<lista_apari.size(); i++) { //Imprimo las apariciones
        cout << "Palabras de longitud " << lista_apari[i].first << ": "
        << lista_apari[i].second << "\n" ;
    }
}

// 2.5)
// Hice lo primero que se me ocurrio, ya a las 3:44 am el cerebro no funca :(

vector<int> interseccion_listas(vector<int> v1, vector<int> v2) {
    vector<int> inter;
    //Este if medio choclito es para revisar todos los elementos de ambas listas y que no se me escape ninguno
    // Por lo que voy a revisar los elementos de la lista con más elementos.
    if (v1.size() > v2.size()) {
        for (int i = 0; i < v1.size(); i++) {
            if (pertenece(v1[i], v1) && pertenece(v1[i], v2)) { //Si pertenece a ambas listas lo guardo
                inter.push_back(v1[i]);
            }
        }
    }
    else {
        for (int i = 0; i < v2.size(); i++) {
            if (pertenece(v2[i], v1) && pertenece(v2[i], v2)) {
                inter.push_back(v2[i]);
            }
        }
    }
    return inter;
}


void intersecion() {
    string archivo1,archivo2;
    cout << "Ingrese el nombre del primer archivo: \n";
    cin >> archivo1;
    cout << "Ingrese el nombre del segundo archivo: \n";
    cin >> archivo2;
    archivo1 =  "archivos_clase4/" + archivo1 + ".txt"; //le agrego el path y extension
    archivo2 =  "archivos_clase4/" + archivo2 + ".txt";
    vector<int> lista1= lee_lista_archivo(archivo1);
    vector<int> lista2 = lee_lista_archivo(archivo2);
    vector<int>  intersec =  interseccion_listas(lista1,lista2);
    mostrarVector(intersec);
}



int main() {
    //palindromos("archivos_clase4/palindromos.txt", "archivos_clase4/palindromos2.txt");
    //promedios("archivos_clase4/promedios1.txt", "archivos_clase4/promedios2.txt", "archivos_clase4/promedios_tot.txt");
    //cantidadApariciones("archivos_clase4/apariciones.txt","archivos_clase4/apariciones_tot.txt" );
    //estadisticas("archivos_clase4/estadisticas.txt");
    //intersecion();
    int div= 0, div2 = 0;
    cout << div << "   " << div2;

    return 0;
}

