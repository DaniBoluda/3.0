#include "lib/FUNCIONES.h"
#include <random>
#include "rlutil.h"
#include <windows.h>
#include <vector>
#include <map>

using namespace std;


void Rectangulo1P(){
    // Dibujar pared izquierda
    DibujarLineas(1, 1, 1, 9, (char)186);

// Dibujar pared derecha
DibujarLineas(120, 1, 120, 9, (char)186);

//Dibujar Linea superior
DibujarLineas(1, 1, 120, 1, (char)205);

//Dibujas Linea inferior 
DibujarLineas(1, 9, 120, 9, (char)205);
}




//Combinaciones Ganadoras


//Escalera
bool Escalera(const std::vector<int>& dados) {
    std::vector<int> Ordenados = dados;
    std::sort(Ordenados.begin(), Ordenados.end());

    if (Ordenados == std::vector<int>{1, 2, 3, 4, 5, 6}) {
        return true;
    }
    return false;
}

//Suma de Dados
int SumaDeDados(const std::vector<int>& resultados) {
    int suma = 0;
    std::map<int, int> contador;

    for (int valor : resultados) {
        suma += valor;
        contador[valor]++;
    }

    for (const auto& par : contador) {
        if (par.second >= 3) {
            return 0;
        }
    }

    return suma;
}

//Trío X++
int MayorTrio(const std::vector<int>& resultados) {

    int MayorTrio = 0;

    for (int valor = 1; valor <= 6; ++valor) {
        int contador = 0;

        for (int dado : resultados) {
            if (dado == valor) {
                contador++;
            }
        }

        if (contador >= 3 && valor > MayorTrio) {
            MayorTrio = valor;
        }
    }

    return MayorTrio;
}

//Sexteto X
int Sexteto(const std::vector<int>& resultados) {
    int Dado = resultados[0];

    
    bool sexteto = true;
    for (int i = 1; i < 6; i++) {
        if (resultados[i] != Dado || Dado == 6) {
            sexteto = false;
            break;
        }
    }

    
    if (sexteto) {
        return Dado * 50; 
    }
    else {
        return 0; 
    }
}

//Seis 6
bool Sexteto6MM(const std::vector<int>& resultados) {
    for (int valor : resultados) {
        if (valor != 6) {
            return false;
        }
    }
    return true;
}




//______________________________________________________________________     

                             //Menu 1P

void ModoUnJugador() {

    int opcion = 1, y = -2;
   
    string Nombre1P;
    int MaxPuntajeP1 = 0;
    int LanzamientosP1 = 0;

    bool volverAlMenu = false;

    while (!volverAlMenu) {
        rlutil::cls(); // Borrar la pantalla
        rlutil::setColor(rlutil::COLOR::CYAN);
        rlutil::locate(45, 3);
        cout << "QUINIENTOS MODO UN JUGADOR";
        rlutil::setColor(rlutil::COLOR::WHITE);
        rlutil::locate(50, 6);
        cout << "Ingresar Nombre: ";
        cin >> Nombre1P;


        rlutil::cls();

        Rectangulo1P();
        Esquinas();

       
        rlutil::locate(5, 3);
        cout << "TURNO DE " << Nombre1P; // Maximo(14 Letras)
        rlutil::locate(42, 3);
        cout << "RONDA NUMERO: (10)" << endl; // Aca va la variable NumRonda
        rlutil::locate(73, 3);
        cout << "PUNTUAJE TOTAL: (3000) PUNTOS" << endl; // Aca va la variable PuntuajeTotal
        rlutil::locate(45, 5);
        cout << "LANZAMIENTO #: ";
        rlutil::locate(51, 6);
        cout << LanzamientosP1;
        rlutil::locate(74, 5);
        cout << "MAXIMO PUNTAJE DE LA RONDA" << endl; // Aca va la variable  MaxPuntajeP1
        rlutil::locate(82, 6);
        cout << MaxPuntajeP1 << " PUNTOS";

        rlutil::locate(40, 10);
        cout << "Presionar 'E' Para Tirar Los Dados";

        char keyi;
        do {
            keyi = rlutil::getkey();
        } while (keyi != 'e' && keyi != 'E');

        if (keyi == 'e' || keyi == 'E') {
            cout << "EMpieza";
        }

        





        




        rlutil::setColor(rlutil::COLOR::LIGHTRED);
        rlutil::locate(45, 30);
        cout << "Presiona 'V' Para Volver Al Menu";

        char key;
        do {
            key = rlutil::getkey();
        } while (key != 'v' && key != 'V');

        if (key == 'v' || key == 'V') {
            volverAlMenu = true;
        }
    }

}






//Esquinas
void Esquinas() {
    //Esquina superior izquierda
    rlutil::locate(1, 1);
    cout << (char)201;

    //Esquina superior derecha
    rlutil::locate(120, 1);
    cout << (char)187;

    //Esquina inferior izquierda
    rlutil::locate(1, 9);
    cout << (char)200;

    //Esquina inferior derecha
    rlutil::locate(120, 9);
    cout << (char)188;
}

//Titulo

void Titulo() {

    rlutil::setColor(rlutil::COLOR::WHITE); // COLOR TEXTO MENU

    rlutil::hidecursor(); // Sin Cursor

    rlutil::cls(); //Limpiar Consola

    rlutil::setColor(rlutil::COLOR::RED); // Titulo
    rlutil::locate(2, 2);
    cout << "          xxxxxxx    x     x    x    xx      x   x    xxxxxxx    xx      x    xxxxxxx    xxxxxxx    xxxxxxx             ";
    rlutil::locate(2, 3);
    cout << "          x     x    x     x         x x     x        x          x x     x       x       x     x    x                   ";
    rlutil::locate(2, 4);
    cout << "          x     x    x     x    x    x  x    x   x    x          x  x    x       x       x     x    x                   ";
    rlutil::locate(2, 5);
    cout << "          x     x    x     x    x    x   x   x   x    xxxxxxx    x   x   x       x       x     x    xxxxxxx             ";
    rlutil::locate(2, 6);
    cout << "          x     x    x     x    x    x    x  x   x    x          x    x  x       x       x     x          x             ";
    rlutil::locate(2, 7);
    cout << "          x    xx    x     x    x    x     x x   x    x          x     x x       x       x     x          x             ";
    rlutil::locate(2, 8);
    cout << "          xxxxxxxxx  xxxxxxx    x    x      xx   x    xxxxxxx    x      xx       x       xxxxxxx    xxxxxxx             ";



    // Dibujar pared izquierda
    DibujarLineas(1, 1, 1, 9, (char)186);

    // Dibujar pared derecha
    DibujarLineas(120, 1, 120, 9, (char)186);

    //Dibujar Linea superior
    DibujarLineas(1, 1, 120, 1, (char)205);

    //Dibujas Linea inferior 
    DibujarLineas(1, 9, 120, 9, (char)205);

    //////////////////////////////////////////

    //Dibujar Linea superior (Opciones)
    DibujarLineas(47, 11, 73, 11, (char)205);

    //Dibujar Linea Inferior  (Opciones)
    DibujarLineas(47, 25, 73, 25, (char)205);

    //Dibujar Linea superior (Opciones)
    DibujarLineas(47, 40, 30, 60, (char)186);

    //Dibujar Linea superior (Opciones)
//Mofidica estas 4 para hacer la decoracion de las opciones, (1,2,3,4,(char)...); Siendo 1 el inicio de la linea del Eje X (------)
//3 es el final de la linea, por ejemplo 10 15, seria una linea q empieza en la fila 10 y termine en la 15, una linea de 2
//2 es el inicio en el eje Y y 4 el fin por ejemplo una linea que empiece en la fila 3 y termine en la 10
/*
*-------|
* 
* 
* 
* |
* |
* |
* |
* |
* |
* |
* ***********
*/
}




//Genera 6 numeros aleatorios Utilizando las funcion srand, incluida en la bilioteca estandar de c++, (Iniciar la semilla srand(time(0)) para numeros aleatorios.)
int SeisNumeros(int min, int max) {
    return rand() % (max - min + 1) + min;
}

//Con esta funcion creamos un Vector de 6 Vacio, utilizando la funcion de SeisNumeros se  llena el vector con los numeros aleatorios(almacena los dados)
/*Push_back hace que LanzarDados se Almacene en Resultados*/
std::vector<int> LanzarDados() {
    std::vector<int> Resultados;
    for (int i = 0; i < 6; i++) {
        int numero = SeisNumeros(1, 6);
        Resultados.push_back(numero);
    }
    return Resultados;
}




//Genera Lineas, siendo x1 La linea principal del Eje X
//x2 Siendo el punto final de la linea x1
//y1 Seria La linea del eje Y
//y2 Siendo el punto final de la linea y2
//DIbujando el caracter seleccionado 
void DibujarLineas(int x1, int y1, int x2, int y2, char symbol) {
    for (int x = x1; x <= x2; x++) {
        for (int y = y1; y <= y2; y++) {
            rlutil::locate(x, y);
            std::cout << symbol;
        }
    }
}

//Genera el recuadro de los dados
void Cuadrado(int posx, int posy, int tam) {
    for (int y = 1; y <= tam / 2; y++) {
        for (int x = 1; x <= tam; x++) {
            rlutil::locate(x + posx, y + posy);
            cout << (char)219;
        }
    }
}


//Genera Graficamente 6 Dados 
void Dado(int posx, int posy, int num, int tam) {
    Cuadrado(posx, posy, tam);

    switch (num) {
    case 1:
        rlutil::locate(posx + tam / 2 + 1, posy + tam / 4 + 1);
        cout << (char)254;
        break;

    case 2:
        rlutil::locate(posx + tam / 4 + 1, posy + tam / 4 / 4 + 1);
        cout << (char)220;

        rlutil::locate(posx + tam - tam / 4, posy + tam / 2 - tam / 4 / 4);
        cout << (char)223;
        break;

    case 3:
        rlutil::locate(posx + tam / 4 + 1, posy + tam / 4 / 4 + 1);
        cout << (char)220;

        rlutil::locate(posx + tam / 2 + 1, posy + tam / 4 + 1);
        cout << (char)254;

        rlutil::locate(posx + tam - tam / 4, posy + tam / 2 - tam / 4 / 4);
        cout << (char)223;
        break;

    case 4:
        rlutil::locate(posx + tam / 4 + 1, posy + tam / 4 / 4 + 1);
        cout << (char)220;

        rlutil::locate(posx + tam - tam / 4, posy + tam / 4 / 4 + 1);
        cout << (char)220;

        rlutil::locate(posx + tam - tam / 4, posy + tam / 2 - tam / 4 / 4);
        cout << (char)223;

        rlutil::locate(posx + tam / 4 + 1, posy + tam / 2 - tam / 4 / 4);
        cout << (char)223;
        break;

    case 5:
        rlutil::locate(posx + tam / 4 + 1, posy + tam / 4 / 4 + 1);
        cout << (char)220;

        rlutil::locate(posx + tam - tam / 4, posy + tam / 4 / 4 + 1);
        cout << (char)220;

        rlutil::locate(posx + tam / 2 + 1, posy + tam / 4 + 1);
        cout << (char)254;

        rlutil::locate(posx + tam - tam / 4, posy + tam / 2 - tam / 4 / 4);
        cout << (char)223;

        rlutil::locate(posx + tam / 4 + 1, posy + tam / 2 - tam / 4 / 4);
        cout << (char)223;
        break;

    case 6:
        rlutil::locate(posx + tam / 4 + 1, posy + tam / 4 / 4 + 1);
        cout << (char)220;

        rlutil::locate(posx + tam - tam / 4, posy + tam / 4 / 4 + 1);
        cout << (char)220;

        rlutil::locate(posx + tam / 2 + 1, posy + tam / 4 / 4 + 1);
        cout << (char)220;

        rlutil::locate(posx + tam / 2 + 1, posy + tam / 2 - tam / 4 / 4);
        cout << (char)223;

        rlutil::locate(posx + tam - tam / 4, posy + tam / 2 - tam / 4 / 4);
        cout << (char)223;

        rlutil::locate(posx + tam / 4 + 1, posy + tam / 2 - tam / 4 / 4);
        cout << (char)223;
        break;

    default:
        break;
    }
}


