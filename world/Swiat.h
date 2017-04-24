#include "vector"
#include "windows.h"

#include "Czlowiek.h"
#include "Wilk.h"
#include "Owca.h"
#include "Lis.h"
#include "Zolw.h"
#include "Antylopa.h"
#include "Trawa.h"
#include "Mlecz.h"
#include "Guarana.h"
#include "WilczeJagody.h"
#define ROZMIAR_SWIAT 20
#define MAX_INICJATYWA 7
#define SZANSA 0.05


class Swiat {
private:
	vector<Organizm*>tablica;
	char teren[ROZMIAR_SWIAT][ROZMIAR_SWIAT];
public:
	Swiat();
	void wykonajTure();
	void rysujSwiat();
	void start();
	void dodajOrganizm(Organizm* nowy);
	void usunOrganizm(int i);
	void wypelnijTeren();
	bool wolnePole(int x, int y);
	Organizm* znajdz(int x, int y, int &i);
	bool czyZolw(int x, int y);
	bool czyGuarana(int x, int y);
};