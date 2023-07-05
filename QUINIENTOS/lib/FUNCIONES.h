#ifndef FUNCIONES_H
#define FUNCIONES_H
#include <vector>

int SeisNumeros(int min, int max);

std::vector<int> LanzarDados();

void Dado(int posx, int posy, int num, int tam);

void Cuadrado(int posx, int posy, int tam);

void Titulo();

void gotoxy(int x, int y);

void DibujarLineas(int x1, int y1, int x2, int y2, char symbol);

void Esquinas();

void ModoUnJugador();

void Rectangulo1P();




//Combinaciones Ganadoras
bool Escalera(const std::vector<int>& dados);

int SumaDeDados(const std::vector<int>& resultados);

int MayorTrio(const std::vector<int>& resultados);

int Sexteto(const std::vector<int>& resultados);

bool Sexteto6MM(const std::vector<int>& resultados);

#endif
