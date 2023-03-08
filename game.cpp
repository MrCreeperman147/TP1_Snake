/*====================================
AUTEUR : OGBEIWI Bright
PROJET : TP1_Snake
NOM DU FICHIER : game.cpp
DATE : 06/03/2023
DESCRIPTION : Permet la gestion d'une session de jeu
====================================*/

#include <iostream>
#include <iomanip>

#include "point.h"
#include "rectangle.h"
#include "snake.h"
#include "functions.h"
#include "game.h"



using namespace std;

#pragma region Constructors/Destructor

/// <summary>
/// Constructeur par defaut.
/// Initialise les variables primitives à 0.
/// </summary>
game::game()
{
	_dir = _hp = _score = 0;
	_gameOver = false;
}

/// <summary>
/// Destructeur par default.
/// Reinitialise les variables primitives.
/// </summary>
game::~game()
{
	_dir = _hp = _score = 0;
	_gameOver = false;
}

#pragma endregion

#pragma region Methods

/// <summary>
/// Initialise le jeu
/// </summary>
void game::initalize()
{

}

point game::randPos() const
{

}

void game::createApple()
{

}

/// <summary>
/// Accueil du jeu
/// </summary>
void game::startMenu()
{
	//Variables
	int userInput;
	do
	{
		cout << "S N E K" << endl
		<< endl
		<< "1/ Play" << endl
		<< "2/ Settings" << endl
		<< "3/ RageQuit" << endl;

		cin >> userInput;
		clearBuffer();

		switch (userInput)
		{
		case 1: //play
			play();
			break;

		case 2:	//settings
			parametersMenu();
			break;

		case 3:	//quit
			cout << "Merci d'avoir jouer" << endl;
			break;

		default://none of the 3 cases
			break;
		}

		system("pause");
		system("cls");

	} while (userInput != 3);
}

/// <summary>
/// Menu des parametres du jeu
/// </summary>
void game::parametersMenu()
{
	int userInput;

	do
	{
		cin >> userInput;
		clearBuffer();

		cout << "Parametres" << endl
			<< endl
			<< "1/ Couleur du snek" << endl
			<< "2/ Longueur du snek" << endl
			<< "3/ Vitesse du snek" << endl
			<< "4/ Dimension du plateau" << endl
			<< "5/ Retour" << endl;

		switch (userInput)
		{
		case 1:
			userInput = 0;

			cout << "Voici les couleurs disponibles " << endl
				<< endl;
			setTextColor(1);
			cout << left << setw(25) << "1 Bleu";

			setTextColor(8);
			cout << setw(25) << left << "8 Gris" << endl ;

			setTextColor(2);
			cout << left << setw(25) << "2 Vert";

			setTextColor(9);
			cout << setw(25) << left << "9 Bleu clair" << endl;

			setTextColor(3);
			cout << left << setw(25) << "3 Bleu-gris";

			setTextColor(10);
			cout << setw(25) << left << "10 Vert clair" << endl;

			setTextColor(4);
			cout << left << setw(25) << "4 Rouge";

			setTextColor(11);
			cout << setw(25) << left << "11 Cyan" << endl;

			setTextColor(5);
			cout << left << setw(25) << "5 Violet";

			setTextColor(12);
			cout << setw(25) << left << "12 Rouge clair" << endl;

			setTextColor(6);
			cout << left << setw(25) << "6 Jaune";

			setTextColor(13);
			cout << setw(25) << left << "13 Violet clair" << endl;

			setTextColor(7);
			cout << left << setw(25) << "7 Blanc";

			setTextColor(14);
			cout << setw(25) << left << "14 Jaune clair" << endl;

			setTextColor(15);
			cout << left << setw(25) << "15 Blanc brillant";
			
			setTextColor(7);
			cout << endl << endl << "Choisissez votre couleur : ";
			cin >> userInput;
			clearBuffer();

			
			break;

		case 2:
			break;

		case 3:
			break;

		case 4:
			break;

		case 5:
			break;

		default:
			break;
		}

		system("cls");

	} while (userInput != 5);
}
#pragma endregion
