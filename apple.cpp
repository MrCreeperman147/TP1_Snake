/*====================================
AUTEUR : OGBEIWI Bright
PROJET : TP1_Snake
NOM DU FICHIER : apple.cpp
DATE : 06/03/2023
DESCRIPTION : Permet l'affichage et la gestion des pommes
====================================*/

#include <iostream>

#include "point.h"
#include "apple.h"

using namespace std;

#pragma region Constructors/Destructor

/// <summary>
/// Constructeur par defaut
/// </summary>
apple::apple()
{
	point _apple(0,0, 12);
}

/// <summary>
/// Constructeur surchargé
/// </summary>
/// <param name="x">Coordonnée X</param>
/// <param name="y">Coordonnée Y</param>
apple::apple(int x, int y)
{
	point _apple(x, y, 12);
}

#pragma endregion

#pragma region Accessors

/// <summary>
/// Configure la position de la pomme
/// </summary>
/// <param name="x">Coordonnée X</param>
/// <param name="y">Coordonnée Y</param>
void apple::setPos(int x, int y)
{
	_apple.setPosition(x, y);
}

/// <summary>
/// Retourne la position de la pomme
/// </summary>
/// <returns></returns>
const point& apple::getPos() const
{
	return _apple;
}

#pragma endregion

#pragma region Methods

/// <summary>
/// Dessine la pomme
/// </summary>
/// <param name="output">Le flux de sortie</param>
void apple::draw(std::ostream& output) const
{
	_apple.draw(output);
}

void apple::setColor(int color)
{
	_apple.setColor(color);
}

#pragma endregion

#pragma region Overload

/// <summary>
/// Execute la methode apple.draw()
/// </summary>
/// <param name="output">Le flux de sortie</param>
/// <param name="apple">La pomme à afficher</param>
/// <returns></returns>
ostream& operator<<(ostream& output, const apple& apple)
{
	apple.draw(output);
	return output;
}

#pragma endregion

