/*====================================
AUTEUR : OGBEIWI Bright
PROJET : TP1_Snake
NOM DU FICHIER : snake.h
DATE : 06/03/2023
DESCRIPTION : Permet l'affichage et la gestion du snake
NOTE : snek
====================================*/

#include <iostream>
#include <assert.h>

#include "point.h"
#include "snake.h"

using namespace std;

#pragma region Constructor/Destructor

/// <summary>
/// Constructeur par defaut
/// </summary>
snake::snake()
{
	this->initalize();
}

/// <summary>
/// Constructeur surchargé
/// </summary>
/// <param name="x">Coordonnée X</param>
/// <param name="y">Coordonnée Y</param>
snake::snake(int x, int y)
{
	this->initalize(x, y)
}

/// <summary>
/// Destructeur par defaut
/// </summary>
snake::~snake()
{
	_size = 0;
	_speed = 0;
}
#pragma endregion

#pragma region Accessors

/// <summary>
/// Retourne la taille du snake
/// </summary>
/// <returns>La taille du snake en int</returns>
int snake::getSize() const
{
	return _size;
}

/// <summary>
/// Retourne la vitesse du snake
/// </summary>
/// <returns>La vitesse du snake en int</returns>
int snake::getSpeed() const
{
	return _speed;
}

/// <summary>
/// Change la taille du snake par une valeur donnée en parametre
/// La taille doit être entre 6 et 20
/// </summary>
/// <param name="size">Nouvelle taille</param>
void snake::setSize(int size)
{
	assert(size > 5 && size < 21);
	_size = size;
}

/// <summary>
/// Change la vitesse du snake par une valeur donnée en parametre
/// La vitesse doit être entre 50 et 125
/// </summary>
/// <param name="speed">Nouvelle vitesse</param>
void snake::setSpeed(int speed)
{
	assert(speed > 49 && speed < 126);
	_speed = speed;
}

#pragma endregion


#pragma region Methods

/// <summary>
/// Initialise le snake
/// </summary>
/// <param name="x">Coordonnée X</param>
/// <param name="y">Coordonnée Y</param>
void snake::initalize(int x, int y)
{
	_snakeArray[0].setPosition(x, y);
	_size = 6;
	_speed = 100;

	this->setSnakeColor(1);
}

/// <summary>
/// Retourne la position de la tête du snake
/// </summary>
/// <returns>La tête du snake</returns>
const point& snake::getHeadPos() const
{
	return _snakeArray[0];
}

/// <summary>
/// Retourne le point à une position donnée en parametre
/// </summary>
/// <param name="id">Index du point dans le snake</param>
/// <returns>Le point correspondant à l'index</returns>
const point& snake::getIdPos(int id) const
{
	return _snakeArray[id];
}

/// <summary>
/// Permet de changer la couleur du snake
/// </summary>
/// <param name="color">couleur de 0 à 15</param>
void snake::setSnakeColor(int color)
{
	for (int i = 0; i < 800; i++)
	{
		_snakeArray[i].setColor(color);
	}
	//cout << endl << "snake color set ! " << endl; //helpy
}

/// <summary>
/// Retourne la prochaine coordonnée de la tête du snake selon la direction donnée en parametre
/// </summary>
/// <param name="dir">La direction</param>
/// <returns>La prochaine position de la tête du snake</returns>
point snake::newPos(int dir) const
{
	
}

/// <summary>
/// Teste si la position en parametre est en conflit avec une position du snake
/// </summary>
/// <param name="pos">Point à tester</param>
/// <returns>TRUE : La position en parametre est en conflit avec le snake</returns>
bool snake::ifCollision(const point& pos) const
{
	bool retour = false;
	int i = 0;
	
	while (i != 6 && retour != true)
	{
		if (pos == _snakeArray[i])
		{
			retour = true;
		}
		i++
	}
	
	return retour;
}



#pragma endregion

#pragma region Operator Overload

/// <summary>
/// Execute la methode snake::getIdPos()
/// </summary>
const point& snake::operator[](int id) const
{
	return this->getIdPos(id);
}

#pragma endregion
