#pragma once
#include "Roslina.h"

class WilczeJagody:public Roslina{
public:
	WilczeJagody(Swiat *p);
	~WilczeJagody(){};
	void rozsianie(int i, int j);

};