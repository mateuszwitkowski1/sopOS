#include "string"
#include <iostream>
#include "conio.h"

using namespace std;

class Proces{
public:
	string nazwa1;
	int id1;
	int pid1;
	int counter;
	int koniec = 0;
	int poczatek1 = 0;
	int aktualny_rozkaz = 1;
	int stan;
	Proces(string nazwa, int id, int pid, int poczatek){
		nazwa1 = nazwa;
		id1 = id;
		pid1 = pid;
		poczatek1 = poczatek;
		counter = 0;
		stan = 0;
	}
};