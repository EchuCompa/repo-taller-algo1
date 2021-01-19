# include <iostream>

int f (int x,int y ){
    if (x>y) {
        return x + y; }
    else {
        return x*y; }
}
// Aclaro que ++i <-> i += 1 <-> i = i + 1


// Ejercicio 4
bool esPrimo(int n) {
    int divisores = 0;
    for (int i =2; i<n; ++i) {
        if (n % i == 0) {
            ++divisores;
        }     }
    return divisores == 0;
}



//Ejercicio 5 (aclaración, mis fibo empiezan desde el 0 porque el 1 esta sobrevalorado ;) )

// Con recursión
int fibo(int n){
    if (n == 0) {
        return 0; }
    if (n == 1) {
        return 1; }
    return fibo(n-1) + fibo(n-2);
}

// Con while
int fibo_whil(int n){
    int i = 0;
    int val1 = 0, val2 = 1;
    int fibo = 0;
    // Val1 y Val2 van almacenando los números previos, y fibo es el número que planeo devolver
    while (i<n) {
        fibo = val1 + val2;
        val1 = val2 ;
        if (i>1) { // Hago esto para que en la segunda iteración no pase de 1 al 2
        val2 = fibo; }
        ++i;
    }
    return fibo;
}

// Con for (que es una vil copia del while)
int fibo_for(int n){
    int val1=0, val2=1;
    int fibo = 0;
    for (int i=0; i<n; ++i) {
        if (i== 0) {
            fibo = 1;  // Este es el segundo caso que hay que hacer a mano
        }
        else {
            fibo = val1 + val2;
            // std :: cout << val1 << " val1 / " << val2 << " val 2\n";  Esto lo puse para ir revisando los valores
            val1 = val2 ;
            val2 = fibo;
        }
    }
    return fibo;
}
//Otra forma de pensar Fibonacci
 /* fibo(k){
        int m = 0;
        int n =1;
        if (k == 0) {
            return 0;
        }
        if (k == 1) {
            return 1;
        }
        for (int i = 0; i < k; i ++) {
            m = n;
            n = m + n;
        }
} */

//Ejercicio 6

//Con recursión
int suma_imp(int n){
    if (n<=1){ // El igual es por si alguien es alto salame e ingresa un número negativo
        return 0;
    }
    if (n%2 == 1){ //Ergo si n es impar
        return n-2 + suma_imp(n-2);
    }
    else {  // Osea si n es par
        return n-1 + suma_imp(n-1); //Así se vuelve una suma de números impares
    }
}

//Con while
int suma_imp_whil(int n){
    int suma = 0;
    if (n %2 == 0) {
        n -= 1;    // Hago esto porque sólo me importa la suma de números impares
    }
    while (n >= 1) {
        suma += n;
        n -= 2;
    }
    return suma;
}

//Con for
int suma_imp_for(int n){
    int suma = 0;
    int lim = n/2;
    if (n %2 == 0) {
        n -= 1;    // Hago esto porque sólo me importa la suma de números impares
        suma += n;  // Esto es para no "perder" el valor
    }
    for (int i=0; i<lim; ++i ){
        suma += n-2;
    }
    return suma;
}




//Ejercicio 7 (No tomo ni al 1, ni a n cómo divisores pues no cache si había que agarrarlos)

//Con recursión
int suma_div_hasta(int n, int x){
    if (x==1) {
        return 0;
    }
    if (n % x == 0){
        return (x + suma_div_hasta(n, x-1) ) ;   }
    return suma_div_hasta(n,x-1);
}

// Fue la única forma que se me ocurrió, maldito y sensual Haskell :(  . Acepto otras soluciones
int suma_div_careta(int n) {
    return suma_div_hasta(n, n-1);
}

//Con while
int suma_div_whil(int n) {
    int suma =0, i=2; //
    while (i<n) {   //Voy de abajo para arriba
        if (n % i == 0){
            suma += i;
        }
        ++i; }
    return suma;
}

//Con for (que es el código de EsPrimo reciclado)
int  suma_div_for(int n){
    int divisores = 0;
    for (int i =2; i<n; ++i) {
        if (n % i == 0) {
            divisores += i;
        }     }
    return divisores;
}


// Ejercicio 8

//Con recursión
int num_comb(int n, int k) {
    if (k>n){
        std :: cout << "Creo que deberías hacer Álgebra 1 de vuelto, te recomiendo la guía de Tere\n";
        return 0;
    }
    if (k == 1){ // Estos son mis dos casos..
        return n;
    }
    if (n == k) { // .. base que tengo en cuenta
        return 1;
    }
    return num_comb(n-1, k) + num_comb(n-1, k-1);
}

// La lógica es que por ejemplo (20 C 3) = 20! / (3! * 17!) = 20*19*18 / 3*2*1, y a partir de eso intente
// armar esto sin tener que recurrir a una función extra llamada factorial. El problema es que tuve que usar
// los floats por el tema de conversión de tipos.

// Sino una idea que intente implementar pero no me copo mucho es tener una variable
// denominador y otra numerador, ir almacenando los valores en ellas y luego dividirlas.
// De esta forma no necesitaría usar float, pero siento que es inecesario

//Con while
int num_comb_whil(float n, float k){
    float numb_com = 1;
    if (k>n){
        std :: cout << "Creo que deberías hacer Álgebra 1 de vuelto, te recomiendo la guía de Tere\n";
        return 0;
    }
    while (1 <= k) {
        numb_com *= n/k;
        n -= 1;
        k -=1;
        std :: cout << numb_com << "\n"; // Esto es para ir chequeando los valores nomei
    }
    return numb_com;
}

int num_comb_for(float n, float k){
    float numb_com = 1;
    if (k>n){
        std :: cout << "Creo que deberías hacer Álgebra 1 de vuelto, te recomiendo la guía de Tere\n";
        return 0;
    }
    int lim = k;
    for (int i = 0; i<lim; ++i) {
        numb_com *= n/k;
        n -= 1;
        k -=1;
        // std :: cout << numb_com << "\n" << k << "\n"; Esto es para ir chequeando los valores nomei
    }
    return numb_com;
}


//Acá es donde fui testeando que no haya hecho cualquier cosa
int main () {
    //std :: cout << "El resultado es: " << f (10,25) << std :: endl ;
    //std :: cout << num_comb_whil(100,5) << "\n";
    return 0;
}

/* Ejercicio 9
 * Creo que según el tipo de problema que uno tenga cada una puede ser una mejor opción. Por lo poco que
 * fui viendo la recursión puede ser una solución con más "estilo" pero termina requiriendo de interminables
 *  pasos lo cuál me imagino que debe consumir mucha memoria (ni idea la verdad). Por otro lado la iteración
 *  aunque no siempre sea tan "clara" de ver es mucho más directa y no "da tantas vueltas". Aún así me imagino
 *  que hay problemas que tienen una solución iterativa más sencilla y viceversa.
 *  Si uno sabe cuánto tiene que durar un proceso entonces me parece que es muy superior el for ya que queda
 *  clarisimo lo que uno quiere hacer y es más sencillo de escribir. Pero si en cambio uno no sabe cuánto va a
 *  durar el proceso o cuántos pasos va a requerir el while pareciera ser la mejor opción. 
 *
 *  */