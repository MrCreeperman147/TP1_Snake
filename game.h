/*====================================
AUTEUR : OGBEIWI Bright
PROJET : TP1_Snake
NOM DU FICHIER : game.h
DATE : 06/03/2023
DESCRIPTION : Permet la gestion d'une session de jeu
====================================*/
#pragma once

#include "snake.h"
#include "apple.h"
#include "rectangle.h"

class game
{
private:
	//Attributes
	bool _gameOver;

	int _dir;
	int _hp 
	int _score;

	snake _snake;
	apple _apple;

	rectangle _board;
	int _w = 40;
	int _h = 40;

	enum direction{STOP,LEFT,RIGHT,UP,DOWN,NONE};
public:
	//Constructors/Destructor

	//Accessors

	//Methods

	//Friends :)

	//Overload
};