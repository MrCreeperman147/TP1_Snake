/*====================================
AUTEUR : OGBEIWI Bright
PROJET : TP1_Snake
NOM DU FICHIER : apple.h
DATE : 06/03/2023
DESCRIPTION : Permet l'affichage et la gestion des pommes
====================================*/
#pragma once

class apple
{
private:
	//Attributes
	point _apple;

public:
	//Constructors/Destructor
	apple();
	apple(int x, int y);

	//Accessors
	void setPos(int x, int y);
	const point& getPos() const;

	//Methods
	void draw(std::ostream& output) const;
	void setColor(int color);

};
//Overload
std::ostream& operator<<(std::ostream& output, const apple& apple);