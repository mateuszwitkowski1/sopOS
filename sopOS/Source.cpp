#include "Procesor.h"
int id=0;

int main(){
	string nazwa;
	Procesor Procesor;
	Planista Planista;
	Dysk Dysk;
	Dysk.wyczysc();
	int pid;
	int priorytet;
	string nazwa_pliku;
	char zmienna = 'd';
	while (zmienna != 's'){
		cout << "Aby dodac proces wpisz cokolwiek, aby rozpoczac symulacje wpisz 's'." << endl;
		cin >> zmienna;
		if (zmienna != 's'){
			cout << "Podaj nazwe, pid, priorytet procesu oraz sciezkie do pliku" << endl;
			cin >> nazwa;
			cin >> pid;
			cin >> priorytet;
			cin >> nazwa_pliku;
			int poczatek = Dysk.wczytaj(nazwa_pliku);
			Proces proces(nazwa, id, pid, poczatek);
			proces = Procesor.dodajproces(proces);
			Planista.priorytety[priorytet].push_back(proces);
			id++;
			cout << endl;
		}
	}
	cout << "Rozpoczynam symulacje" << endl;
	Procesor.start(Planista, Dysk, 8);
	system("pause");
}