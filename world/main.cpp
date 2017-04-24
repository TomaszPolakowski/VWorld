#include "stdafx.h"
#include "iostream"
#include "Swiat.h"
#include "conio2.h"
using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	Swiat swiat;
	
	swiat.start();
	swiat.rysujSwiat();
	while (1){
		swiat.wykonajTure();
		}
	return 0;
}

