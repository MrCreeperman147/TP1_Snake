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
	_size = 6;
	_speed = 100;
	this->initalize();
}

/// <summary>
/// Constructeur surchargé
/// </summary>
/// <param name="x">Coordonnée X</param>
/// <param name="y">Coordonnée Y</param>
snake::snake(int x, int y)
{
	_size = 6;
	_speed = 100;
	this->initalize(x, y);
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
	for (int i = 0; i < _size; i++)
	{
		_snakeArray[i].setPosition(x, y);
	}
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
/// <param name="color">couleur de 1 à 15</param>
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

	point newHead(getHeadPos());	//copie de la tête

	switch (dir)
	{
	case 1: //left
		newHead.setX(newHead.getX() - 1);
		break;

	case 2:	//right	
		newHead.setX(newHead.getX() + 1);
		break;

	case 3:	//up
		newHead.setY(newHead.getY() - 1);
		break;

	case 4:	//down
		newHead.setY(newHead.getY() + 1);
		break;
	}

	return newHead;
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
	
	while (i < _size && retour != true)
	{
		if (pos == _snakeArray[i])
		{
			retour = true;
		}
		i++;
	}
	
	return retour;
}

/// <summary>
/// Change les coordoonée de chaques points du snake selon la direction donnée en parametre
/// </summary>
/// <param name="dir">La direction du mouvement</param>
void snake::move(int dir)
{
	//Chaque point sauf la tête prend la position du point precedant
	for(int i = _size; i > 0; i--)
	{
		_snakeArray[i] = _snakeArray[i - 1];
	}
	//Ensuite on donne la nouvelle position de la tête en utilisant snake.newPos()
	point newPosi = newPos(dir);
	_snakeArray[0] = newPosi;
	_snakeArray[_size].setColor(0);
	_snakeArray[_size].draw(cout);

	
}

/// <summary>
/// Similaire à snake.move() mais agrandi le snake.
/// L'action de manger la pomme est gérée par la classe Game
/// </summary>
/// <param name="dir">La direction du snake</param>
void snake::eat(int dir)
{
	_size++;
	//Chaque point sauf la tête prend la position du point precedant
	for (int i = _size - 1; i > 0; i--)
	{
		_snakeArray[i] = _snakeArray[i - 1];
	}
	//Ensuite on donne la nouvelle position de la tête en utilisant snake.newPos()
	point newPosi = newPos(dir);
	_snakeArray[0] = newPosi;
}

/// <summary>
/// Dessine le snake
/// </summary>
/// <param name="output">Le flux de sortie</param>
void snake::draw(std::ostream& output) const
{
	for (int i = 0; i < _size; i++)
	{
		_snakeArray[i].draw(output);
	}
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

/// <summary>
/// Execute la methode snake.draw()
/// </summary>
/// <param name="output">Le flux de sortie</param>
/// <param name="snek">L'objet à sortir</param>
/// <returns></returns>
ostream& operator<<(ostream& output, const snake& snek)
{
	snek.draw(output);
	return output;
}

#pragma endregion


