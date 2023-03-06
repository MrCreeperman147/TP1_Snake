#pragma once

#include <iostream>

#include "point.h"
class rectangle
{
	//Attribute
private:
	point _coord; //Point coin superieur gauche
	int _w;
	int _h;

public:
	//Constructor/Destructor
	rectangle();									//default
	rectangle(int x, int y, int w = 1, int h = 1);	//overloaded all attributes
	rectangle(rectangle& r);						//copy

	~rectangle();

	//Accessors
	int getWidth() const;
	int getHeight() const;

	point& getCoord();
	const point& getCoord() const;

	void setWidth(int w);
	void setHeight(int h);
	void setSize(int w, int h);
	void setRectangle(int x, int y, int w, int h);

	//Methods
	void draw(std::ostream& flux) const;
	void read(std::istream& flux);
	void print(std::ostream& flux) const;

	int surface();
	int perimeter();
	//Operator Overload
	rectangle operator=(rectangle& r);

	bool operator==(rectangle& r);
	bool operator!=(rectangle& r);
	bool operator<(rectangle& r);
	bool operator>(rectangle& r);



	//Friends :)
};
//Operator Stream
std::ostream& operator<<(std::ostream& output, const rectangle& r);
std::istream& operator>>(std::istream& input, rectangle& r);

//Functions