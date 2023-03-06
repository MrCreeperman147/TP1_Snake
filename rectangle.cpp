/*====================================
AUTEUR : OGBEIWI Bright
PROJET : TP1_Snake
NOM DU FICHIER : rectangle.cpp
DATE : 06/03/2023
DESCRIPTION : Permet l'affichage d'un rectangle composé de points
====================================*/
#include <assert.h>

#include "rectangle.h"
#include "point.h"

using namespace std;
//Constructor/Destructor
#pragma region Constructor/Destructor
rectangle::rectangle()
{
	_w = _h = 0;
}

rectangle::rectangle(int x, int y, int w, int h)
{
	setRectangle(x, y, w, h);
}

rectangle::rectangle(rectangle& r)
{
	setRectangle(r.getCoord().getX(), r.getCoord().getY(), r.getWidth(), r.getHeight());
}

rectangle::~rectangle()
{
	_w = _h = 0;
}
#pragma endregion

//Accessors
#pragma region Accessors

int rectangle::getWidth() const
{
	return _w;
}

int rectangle::getHeight() const
{
	return _h;
}

point& rectangle::getCoord()
{
	return _coord;
}

const point& rectangle::getCoord() const
{
	return _coord;
}


void rectangle::setWidth(int w)
{
	assert(w > 0);
	_w = w;
}


void rectangle::setHeight(int h)
{
	assert(h > 0);
	_h = h;
}

void rectangle::setSize(int w, int h)
{
	this->setHeight(h);
	this->setWidth(w);
}

void rectangle::setRectangle(int x, int y, int w, int h)
{
	_coord.setPosition(x, y);
	this->setSize(w, h);
}
#pragma endregion


//Methods
#pragma region Methods
void rectangle::draw(ostream& flux) const
{
	int i = 0;
	point pixel(_coord);
	//droite
	for (i = 0; i < _h; i++)
	{
		pixel.setY(_coord.getY() + i);
		pixel.draw(flux);
	}

	//bas
	for (i = 0; i < _w; i++)
	{
		pixel.setX(_coord.getX() + i);
		pixel.draw(flux);
	}

	//gauche
	for (i = 0; i < _h; i++)
	{
		pixel.setY((_coord.getY() + _h - 1) - i);
		pixel.draw(flux);
	}

	//haut
	for (i = 0; i < _w; i++)
	{
		pixel.setX((_coord.getX() + _w - 1) - i);
		pixel.draw(flux);
	}
}

void rectangle::read(istream& flux)
{
	char dummy;
	int x = 0;
	int y = 0;

	flux >> dummy >> x >> dummy >> y >> dummy >> _w >> dummy >> _h;
	_coord.setPosition(x, y);
}

void rectangle::print(ostream& flux) const
{
	flux << "(" << _coord.getX() << "," << _coord.getY() << ") de " << _w << " x " << _h;
}

int rectangle::surface()
{
	return _w * _h;
}

int rectangle::perimeter()
{
	return (_w + _h) * 2;
}
rectangle rectangle::operator=(rectangle& r)
{
	this->setRectangle(r.getCoord().getX(), r.getCoord().getY(), r._w, r._h);
	return *this;
}
#pragma endregion



//Operator Overload
#pragma region Operator Overload

ostream& operator<<(ostream& output, const rectangle& r)
{
	r.print(output);
	return output;
}

istream& operator>>(istream& input, rectangle& r)
{
	r.read(input);
	return input;
}

bool rectangle::operator==(rectangle& r)
{
	return _w == r._w && _h == r._h && _coord == r._coord;
}

bool rectangle::operator!=(rectangle& r)
{
	return !operator==(r);
}

bool rectangle::operator<(rectangle& r)
{
	return this->perimeter() < r.perimeter();
}

bool rectangle::operator>(rectangle& r)
{
	return this->perimeter() > r.perimeter();
}
#pragma endregion



//Functions




