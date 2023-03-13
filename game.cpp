/*====================================
AUTEUR : OGBEIWI Bright
PROJET : TP1_Snake
NOM DU FICHIER : game.cpp
DATE : 06/03/2023
DESCRIPTION : Permet la gestion d'une session de jeu
====================================*/

#include <iostream>
#include <iomanip>
#include <conio.h>
#include <Windows.h>

#include "rectangle.h"
#include "snake.h"
#include "apple.h"
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
	
	snake _snake();
	apple _apple();

	_h = 20;
	_w = 40;

	rectangle _board();
}

/// <summary>
/// Destructeur par default.
/// Reinitialise les variables primitives.
/// </summary>
game::~game()
{
	_dir = _hp = _score = _h = _w = 0;
	_gameOver = false;
}

#pragma endregion

#pragma region Methods

/// <summary>
/// Initialise le jeu
/// </summary>
void game::initalize()
{
	_gameOver = false;
	_hp = 3;
	_score = 0;
	_dir = STOP;

	_board.setRectangle(2, 2, _w, _h);
	createApple();
	_snake.initalize(_w/2+2, _h/2+2);	//Initialise au milieu du plateau
}

/// <summary>
/// genere une position aleatoire
/// </summary>
/// <returns></returns>
point game::randPos() const
{
	srand(time(0));
	int x, y;

	//Set X
	x = rand() % (_w - 1) + 2;

	//Set Y
	y = rand() % (_h - 3) + 4;

	point unP(x, y);
	return unP;
}

/// <summary>
/// Genere une pomme a une position aleatoire valide
/// </summary>
void game::createApple()
{
	point randP = randPos();
	_apple.setPos(randP.getX(), randP.getY());
	_apple.setColor(12);
	_apple.draw(cout);
}

/// <summary>
/// Accueil du jeu
/// </summary>
void game::startMenu()
{
	//Variables
	int userInput = 0;
	do
	{
		system("cls");

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

	} while (userInput != 3);
}

/// <summary>
/// Menu des parametres du jeu
/// </summary>
void game::parametersMenu()
{
	system("cls");

	int userInput = 0;
	bool exit = false;

	do
	{
		cout << "Parametres" << endl
			<< endl
			<< "1/ Couleur du snek" << endl
			<< "2/ Longueur du snek" << endl
			<< "3/ Vitesse du snek" << endl
			<< "4/ Dimension du plateau" << endl
			<< "5/ Retour" << endl;

		cin >> userInput;
		clearBuffer();

		switch (userInput)
		{
		case 1: //Color


			//Choix de la couleur
			userInput = 0;
			do
			{
				system("cls");		//screen clear

				cout << "Voici les couleurs disponibles " << endl
					<< endl;
				setTextColor(1);
				cout << left << setw(25) << "1 Bleu";

				setTextColor(8);
				cout << setw(25) << left << "8 Gris" << endl;

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

				//Verification de l'entrée
				cin >> userInput;
				clearBuffer();

				if (userInput < 1 || userInput > 15)
				{
					cout << endl << "Choix erroné" << endl;
					system("pause");
				}
			} while (userInput < 1 || userInput > 15);

			//Appliquer la couleur
			_snake.setSnakeColor(userInput);

			//Informer le joueur
			system("cls");
			cout << "La couleur du snake a été mise à jour" << endl;

			userInput = 0;
			system("pause");
			break;

		case 2:	//Size
			//Choix de la taille (6 - 20)
			userInput = 0;
			do
			{
				system("cls");		//screen clear
				cout << "Configurez la taille par defaut du snake entre 6 et 20 : ";

				//Verification de l'entrée
				cin >> userInput;
				clearBuffer();

				if (userInput < 6 || userInput > 20)
				{
					cout << endl << "Entrée erroné" << endl;
					system("pause");
				}
			} while (userInput < 6 || userInput > 20);

			//Application de l'entrée
			_snake.setSize(userInput);

			//Informer le joueur
			system("cls");
			cout << "La taille par defaut du snake a été mise à jour" << endl;

			userInput = 0;
			system("pause");
			break;

		case 3:	//Speed
			//Choix de la vitesse (50 - 125)
			userInput = 0;
			do
			{
				system("cls");		//screen clear
				cout << "Configurez la vitesse par defaut du snake entre 50 et 125 : ";

				//Verification de l'entrée
				cin >> userInput;
				clearBuffer();

				if (userInput < 50 || userInput > 125)
				{
					cout << endl << "Entrée erroné" << endl;
					system("pause");
				}
			} while (userInput < 50 || userInput > 125);

			//Application de l'entrée
			_snake.setSpeed(userInput);

			//Informer le joueur
			system("cls");
			cout << "La vitesse par defaut du snake a été mise à jour" << endl;
			userInput = 0;

			system("pause");
			break;

		case 4:	//Board size (w : 40-60 / h : 15 - 25)
			userInput = 0;
			exit = false;

			//Entrée des valeurs
			do
			{
				system("cls");

				cout << "Configuration du plateau de jeu" << endl
					<< "Entrez la hauteur du plateau entre 15 et 25: ";

				cin >> userInput;
				clearBuffer();

				if (userInput < 15 || userInput >25)
				{
					cout << "Entrée érronée" << endl;
					system("pause");
				}
				else
				{
					exit = true;
				}
				_h = userInput;

			} while (exit != true);
			
			exit = false;

			do
			{
				system("cls");


				cout << "Hauteur du plateau configuré" << endl
					<< "Entrez la largeur du plateau entre 40 et 60: ";

				cin >> userInput;
				clearBuffer();

				if (userInput < 40 || userInput > 60)
				{
					cout << "Entrée érronée" << endl;
					system("pause");
				}
				else
				{
					exit = true;
				}
				_w = userInput;

			} while (exit != true);

			system("cls");

			cout << "Hauteur du plateau configuré" << endl
				<< "Largeur du plateau configuré" << endl;

			userInput = 0;
			system("pause");
			break;

		case 5:	//return --dummy pour eviter de tomber dans le default
			break;

		default:
			system("cls");
			cout << "Choix érroné";
			system("pause");
			break;
		}

		system("cls");

	} while (userInput != 5);
}

/// <summary>
/// La session de jeu
/// </summary>
void game::play()
{
	system("cls");
	initalize();

	//La gomme

	do
	{
		drawScreen();
		printScore(cout);
		printHP(cout);
		_apple.draw(cout);

		inputKey();
		if (_dir != STOP)
		{
			point nextHead = _snake.newPos(_dir);
			if (canMove(nextHead))
			{
				_hp--;

				if (_hp == 0)
				{
					_gameOver = true;
				}
				else
				{
					system("cls");
					_snake.initalize(_w / 2 + 2, _h / 2 + 2);
				}
			}
			else if (nextHead == _apple.getPos())
			{
				_snake.eat(_dir);
				_score++;
				createApple();

				_snake.setSpeed(_snake.getSpeed() + 1);

				if (_score % 10 == 0)
				{
					_hp++;
				}
				system("cls");
			}
			else
			{
				_snake.move(_dir);
			}
			_snake.draw(cout);
			Sleep(_snake.getSpeed());
			
		}

	} while (!_gameOver);

	printEnd(cout);
	system("pause");

}

/// <summary>
/// Les entrée joueurs
/// </summary>
void game::inputKey()
{
	int key;
	if (_kbhit())
	{
		key = _getch();

		if (key == 'q')
		{
			_gameOver = true;
			_dir = STOP;
		}
		else if (key == 224)
		{
			key = _getch();

			switch (key)
			{
			case 75:
				_dir = LEFT;
				break;

			case 72:
				_dir = UP;
				break;

			case 80:
				_dir = DOWN;
				break;

			case 77:
				_dir = RIGHT;
				break;
			}
		}
		else if (key == 32)
		{
			_dir = STOP;
		}
	}
}

/// <summary>
/// Teste si la tête du snake peut bouger
/// </summary>
/// <param name="point">La position à tester avec la tête du snake</param>
/// <returns>True : La tête peut bouger</returns>
bool game::canMove(const point& point) const
{
	bool retour = false;

	//si la tête du snake touche une des frontières du tableau ou lui-meme
	if (_snake.getHeadPos().getX() > _w - 1|| _snake.getHeadPos().getX() < 3 || _snake.getHeadPos().getY() > _h - 1 || _snake.getHeadPos().getY() < 4 || _snake.ifCollision(point))
	{
		retour = true;
	}

	return retour;
}

/// <summary>
/// Retourne le score
/// </summary>
/// <returns>Le score sous forme d'int</returns>
int game::getScore() const
{
	return _score;
}

/// <summary>
/// Dessine le plateau du snake
/// </summary>
void game::drawScreen()
{
	_board.draw(cout);
}

/// <summary>
/// Affiche le score
/// </summary>
/// <param name="output">Le flux de sortie</param>
void game::printScore(std::ostream& output) const
{
	gotToXY(1, 1);
	output << "Score : " << _score << endl;
}

/// <summary>
/// Affiche la vie du snake
/// </summary>
/// <param name="output">Le flux de sortie</param>
void game::printHP(std::ostream& output) const
{
	gotToXY(1, 2);
	output << "Points de vie restants : " << _hp << endl;
}

/// <summary>
/// Affiche l'écran de Game Over
/// </summary>
/// <param name="output">Le flux de sortie</param>
void game::printEnd(std::ostream& output) const
{
	output << " Game Over " << endl;
}

#pragma endregion
