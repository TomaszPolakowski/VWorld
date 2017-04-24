#pragma once
#include "ctime"
#include "iostream"

class Swiat;

class Organizm {
protected:
	int sila;
	int inicjatywa;
	int x;
	int y;
	char pionek;
	bool uczestniczyl;
	Swiat* p;
public:
	Organizm(Swiat* p);
	~Organizm(){};
	virtual void akcja(){};
	virtual void kolizja(){};
	virtual void setXY(int x, int y);
	virtual void setPionek(char pionek);
	virtual void setUczestniczyl(bool n);
	virtual bool getUczestniczyl();
	virtual int getX();
	virtual int getY();
	virtual char getPionek();
	virtual int getInicjatywa();
	virtual int getSila();
	int losowanie(int &i, int &j);
	int prawdopodobienstwo(double wspolczynnik_prawdopodobienstwa);
};

