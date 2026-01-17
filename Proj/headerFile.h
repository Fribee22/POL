#pragma once
#include <iostream>
#include <cstdlib>
using namespace std;

double historiaTemp[100];
char historiaJedn[100];
int dataCounter = 0;


float FtoC(float F);
float FtoK(float F);
float CtoF(float C);
float CtoK(float C);
float KtoC(float K);
float KtoF(float K);

void menu();

int check(float temp, char stopnie);

void zapisz(float stara, char staraJ, float nowa, char nowaJ);

void pokazHistorie();