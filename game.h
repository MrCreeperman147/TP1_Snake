/*====================================
AUTEUR : OGBEIWI Bright
PROJET : TP1_Snake
NOM DU FICHIER : game.h
DATE : 06/03/2023
DESCRIPTION : Permet la gestion d'une session de jeu
====================================*/
#pragma once

#include "rectangle.h"
#include "snake.h"
#include "apple.h"

class game
{
private:
	//Attributes
	bool _gameOver;

	int _dir;
	int _hp;
	int _score;

	snake _snake;
	apple _apple;

	int _w;
	int _h;
	rectangle _board;

	enum direction{STOP,LEFT,RIGHT,UP,DOWN,NONE};
public:
	//Constructors/Destructor
	game();
	~game();

	//Methods
	void initalize();

	point randPos() const;
	void createApple();

	void startMenu();
	void parametersMenu();
	void play();

	void inputKey();
	bool canMove(const point& point) const;
	int getScore() const;

	void drawScreen();

	void printScore(std::ostream& output) const;
	void printHP(std::ostream& output) const;
	void printEnd(std::ostream& output) const;
};