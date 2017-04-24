#pragma once
#include "Roslina.h"

class Trawa:public Roslina{
public:
	Trawa(Swiat *p);
	~Trawa(){};
	void rozsianie(int i, int j);
};