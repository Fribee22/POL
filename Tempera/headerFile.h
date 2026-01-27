#pragma once
#include <iostream>
#include <cstdlib> 
#include <string>  
#include <ctime>   
#include <cctype>  

using namespace std;


const int ROZMIAR_TABLICY = 100;

double historiaTemp[ROZMIAR_TABLICY];
char historiaJedn[ROZMIAR_TABLICY];
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
void usunWpis();      
void modyfikujWpis();   
void generujLosowe();   


float pobierzLiczbe();
float pobierzF();
float pobierzC();
float pobierzK();
