/*====================================
AUTEUR : OGBEIWI Bright
PROJET : TP1_Snake
NOM DU FICHIER : snake.h
DATE : 06/03/2023
DESCRIPTION : Permet l'affichage et la gestion du snake
NOTE : snek
====================================*/
#pragma once
class snake
{
private:
	//Attributes
	point _snakeArray[800];	//Un vector serai mieux mais demanderai de jouer avec des pointeurs de points
	int _size;
	int _speed;


public:
	//Constructors/Destructor
	snake();	
	snake(int x, int y);
	~snake();

	//Accessors
	int getSize() const;
	int getSpeed() const;

	void setSize(int size);
	void setSpeed(int speed);

	//Methods
	void initalize(int x = 0, int y = 0);

	const point& getHeadPos() const;
	const point& getIdPos(int id) const;

	void setSnakeColor(int color);

	point newPos(int dir) const;
	bool ifCollision(const point& pos) const;

	void move(int dir);
	void eat(int dir);

	void draw(std::ostream& output) const;

	//Overload
	const point& operator[](int id) const;
};

std::ostream& operator<<(ostream& output, const snake& snek);
