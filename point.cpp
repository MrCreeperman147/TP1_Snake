/*====================================
AUTEUR : OGBEIWI Bright
PROJET : TP1_Snake
NOM DU FICHIER : point.cpp
DATE : 08/02/2023
DESCRIPTION : Permet l'affichage d'un point d'une couleur donnée sur des coordonnées données dans une console
====================================*/
#include <assert.h>
#include <Windows.h>
#include <fstream>
#include <iostream>
#include <string>
#include <conio.h>
#include <cmath>

#include "point.h"

//Constructeurs/Destructeur
#pragma region Constructeur/Destructeur

point::point()
{
	_x = 0;
	_y = 0;
	_color = 7;
}

point::point(int x, int y, int color)
{
	_x = x;
	_y = y;
	_color = color;
}

point::point(int x, int y)
{
	_x = x;
	_y = y;
	_color = 7;
}

point::point(const point &point)
{
	_x = point.getX();
	_y = point.getY();
	_color = point.getColor();
}


point::~point()
{
	_x = 0;
	_y = 0;
	_color = 0;
}

#pragma endregion


//Accesseurs
#pragma region Accesseurs

point& point::getPoint()
{
	return *this;
}

int point::getX() const
{
	return _x;
}

int point::getY() const
{
	return _y;
}

int point::getColor() const
{
	return _color;
}

void point::setX(int x)
{
	assert(x >= 0);
	_x = x;
}

void point::setY(int y)
{
	assert(y >= 0);
	_y = y;
}

void point::setColor(int color)
{
	assert(color >= 0 && color <= 15);
	_color = color;
}

void point::setPoint(int x, int y, int color)
{
	setX(x);
	setY(y);
	setColor(color);
}

void point::setPosition(int x, int y)
{
	this->setX(x);
	this->setY(y);
}

#pragma endregion

//Methods
#pragma region Methods

void point::draw(std::ostream& flux) const
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), _color);

	gotToXY(_x, _y);

	flux << "\xFE";
}

void point::read(std::istream& flux)
{
	char dummy;
	flux >> dummy >> _x >> dummy >>_y >> dummy >> dummy >> _color;
}

void point::print(std::ostream& flux) const
{
	flux << "(" << _x << "," << _y << ")" << " " << _color;
}

#pragma endregion

//Operator Overload
#pragma region Operator Overload

point point::operator=(point& pointACopier)
{
	_x = pointACopier._x;
	_y = pointACopier._y;

	_color = pointACopier._color;

	return *this;
}

bool point::operator==(const point& pointAComparer) const
{
	return _x == pointAComparer._x && _y == pointAComparer._y;
}

bool point::operator!=(const point& pointAComparer)
{
	return _x != pointAComparer._x || _y != pointAComparer._y;
}

point point::operator+=(const point& p)
{
	_x = _x + p._x;
	_y = _y + p._y;
	return *this;
}

point point::operator-=(const point& p)
{
	_x = _x - p._x;
	_y = _y - p._y;
	return *this;
}

point point::operator+(const point& p)
{
	point copyThis(*this);

	copyThis += p;

	return copyThis;
}

point point::operator-(const point& p)
{
	point copyThis(*this);

	copyThis -= p;

	return copyThis;
}

std::ostream& operator<<(std::ostream& output, const point& p)
{
	p.print(output);
	return output;
}

std::istream& operator>>(std::istream& input, point& p)
{
	p.read(input);
	return input;
}

#pragma endregion


//Functions
#pragma region Functions

int distance(point p1, point p2)
{
	return sqrt(pow(p2._x - p1._x,2) + pow(p2._y - p1._y, 2));
}

void gotToXY(int x, int y)
{
	COORD scrn;
	HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);

	scrn.X = x;
	scrn.Y = y;

	SetConsoleCursorPosition(hOutput, scrn);
}

int openFile(std::ifstream &file, std::string fileName)
{
	int numLine = 0;
	file.open(fileName);
	if (!file.is_open())
	{
		std::cout << "Houston, we got a problem with the file" << std::endl;
	}
	else if (file.peek() == std::ifstream::traits_type::eof())
	{
		std::cout << "Houston, the file seems to be empty" << std::endl;
	}
	else
	{
		/*std::string temp;

		while (!file.eof())
		{
			std::getline(file, temp);
			numLine++;
		}*/ //Helpy
		numLine = 1;
	}
	return numLine;
}

int readFile(std::istream& flux, point pointArray[])
{
	int index = 0;

	while (!flux.eof())
	{	
		pointArray[index].read(flux);
		//std::cout << "We read line " << index << std::endl; //helpy
		index++;
	}

	return index;
}

bool systemQuestion(const char* question)
{
	bool retour = false;

	std::cout << question;
	char ans = tolower(_getche());
	do
	{
		if (ans == 'o')
		{
			retour = true;
		}
		else if (ans != 'n')
		{
			std::cout << "Entrée invalide " << std::endl;
		}
	} while (ans != 'o' && ans != 'n');


	return retour;
}

void drawArray(point pointArray[], int index)
{
	for (int i = 0; i < index; i++)
	{
		pointArray[i].draw(std::cout);
	}
	std::cout << std::endl;
}
#pragma endregion


