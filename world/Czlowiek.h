#pragma once
#include "Zwierze.h"
#include "iostream"
#include "stdafx.h"
#include "conio2.h"

using namespace std;

class Swiat;

class Czlowiek:public Zwierze{
private:
	int czasMocy;
	
public:
	Czlowiek(Swiat* p);
	~Czlowiek(){};
	void akcja();
	void kolizja(int x, int y);
	void setSila();
	void zmniejszStat();

};

