/*====================================
AUTEUR : OGBEIWI Bright
PROJET : TP1_Snake
NOM DU FICHIER : point.h
DATE : 08/02/2023
DESCRIPTION : Permet l'affichage d'un point d'une couleur donnée sur des coordonnées données dans une console
====================================*/
#pragma once


class point
{
	//Attributs
private:
	int _x;
	int _y;

	int _color;

	//Constructeur/Destructeur
public:
	point();						//default
	point(int x, int y, int color); //overloaded
	point(int x, int y);			//overloaded
	point(const point &point);		//copy

	~point();

	//Accesseurs
	point& getPoint();
	int getX() const;
	int getY() const;
	int getColor() const;

	void setX(int x);
	void setY(int y);
	void setPoint(int x, int y, int color);
	void setPosition(int x, int y);
	void setColor(int color);

	//Methodes
	void draw(std::ostream& flux) const;
	void read(std::istream& flux);
	void print(std::ostream& flux) const;

	//Operator Overload
	bool operator==(const point& pointAComparer) const;
	bool operator!=(const point& pointAComparer);

	point operator=(point& pointACopier);
	point operator+=(const point& p);
	point operator-=(const point& p);
	point operator+(const point& p);
	point operator-(const point& p);

	//friends :)
	friend int distance(point p1, point p2);
};

//operator stream
std::ostream& operator<<(std::ostream& output, const point& p);
std::istream& operator>>(std::istream& input, point& p);

//Functions
void gotToXY(int x, int y);

int openFile(std::ifstream &file, std::string fileName);

int readFile(std::istream& flux, point pointArray[]);

void drawArray(point pointArray[], int index);

bool systemQuestion(const char* question);