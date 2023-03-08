/*====================================
AUTEUR : OGBEIWI Bright
PROJET : TP1_Snake
NOM DU FICHIER : functions.cpp
DATE : 06/03/2023
DESCRIPTION : fichier qui contient des fonctions indépendentes de toute classe
====================================*/
#include <iostream>
#include <Windows.h>

#include "functions.h"

using namespace std;

/// <summary>
/// Vide le cin si il fail
/// </summary>
void clearBuffer()
{
	cin.clear();
	cin.seekg(0, ios::end);

	if (!cin.fail()) //Si cin a pas de problem
	{
		cin.ignore(1000);
	}
	else
	{
		cin.clear(); //vide le cin
	}
}

/// <summary>
/// Change la couleur du text affichée dans la console selon le paramètre
/// </summary>
/// <param name="color">couleur de 0 à 15</param>
void setTextColor(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
	//cout << endl << "Color set to " << color << endl; //helpy
}