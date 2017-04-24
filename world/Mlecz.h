#pragma once
#include "Roslina.h"

class Mlecz:public Roslina{
public:
	Mlecz(Swiat *p);
	~Mlecz(){};
	void rozsianie(int i, int j);
	void akcja();
};