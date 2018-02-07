#include <iostream>
#include "conio.h"
#include "Dysk.h"
#include "Pamiec.h"

using namespace std;

class Procesor{
private:
		int a;
		int b;
		int c;
		int d;

	void move(string source, string destination){
		cout << "mv";
	}
	void add(string operand1, string operand2){
		cout << "ad";
	}
	void substract(string operand1, string operand2){
		cout << "sb";
	}
	void increment(string cel){
		cout << "in";
	}
	void decrement(string cel){
		cout << "dc";
	}
	void compare(string operand1, string operand2){
		cout << "cm";
	}
	void fork(string rozkaz){
		cout << "fr";
	}

public:
	Pamiec pamiec;
	Procesor(){
		pamiec.zerowanie();
	}

		void start(Planista plan, Dysk dysk, int i){




		int c = plan.priorytety[i].size();
		if (c != 0){
			Proces proces = wykonaj(*plan.priorytety[i].begin(), dysk);
			int stan = pamiec.tab[proces.id1 + 8];
			if (stan==3){
				plan.priorytety[i].pop_front();
				cout << "wykonalem proces: " << proces.id1 << ", o nazwie: " << proces.nazwa1 << endl;
			}
			if (stan == 1 || stan == 2){
				int numer = proces.id1 + 6;
				pamiec.tab[numer + 3] = a;
				pamiec.tab[numer + 4] = b;
				pamiec.tab[numer + 5] = c;
				pamiec.tab[numer + 6] = d;
			}
			if (stan == 2){ 
				cout << "proces" << proces.id1 << "oczekuje" << endl;
			}
			if(stan==1){
				plan.priorytety[i].pop_front();
				if (i == 8)	plan.priorytety[i].push_back(proces);
				else  plan.priorytety[i + 1].push_back(proces);
				cout << "wykonalem 4 rozkazy procesu: " << proces.id1 << endl;
			}

			start(plan, dysk, 8);
		}
		else{
			if (i!=0)	start(plan, dysk, i - 1);
			else cout << "wykonano wszystkie procesy";
		}
		}

		Proces dodajproces(Proces proces){
			int id = proces.id1;
			int counter = proces.counter;
			pamiec.tab[id + 6] = counter;
			pamiec.tab[id + 7] = proces.poczatek1;
			cout << pamiec.tab[id + 6] + pamiec.tab[id + 7];
			pamiec.tab[id + 8] = 1;
			pamiec.tab[id + 9] = 0;
			pamiec.tab[id + 10] = 0;
			pamiec.tab[id + 11] = 0;
			pamiec.tab[id + 12] = 0;
			proces.stan = 1;
			for (int i = 0; i < 100; i++)cout << pamiec.tab[i];
			return proces;
			
		}

		Proces wykonaj(Proces proces, Dysk dysk){
			int wykonane = 4;
			d = pamiec.tab[proces.id1+7]+pamiec.tab[proces.id1+6];
			cout << d << "!!!!!!!!";
			while (wykonane != 0){
				cout << wykonane << " " << d;
				string rozkaz=dysk.dajramke(d);
				if (rozkaz == "ff"){
					proces.stan = 3;
					return proces;
				}
				else if (rozkaz == "mv"){
					d++;
					string source = dysk.dajramke(d);
					d++;
					string destination = dysk.dajramke(d);
					move(source, destination);
				}
				else if (rozkaz == "ad"){
					d++;
					string operand1 = dysk.dajramke(d);
					d++;
					string operand2 = dysk.dajramke(d);
					add(operand1, operand2);
				}
				else if (rozkaz == "sb"){
					d++;
					string operand1 = dysk.dajramke(d);
					d++;
					string operand2 = dysk.dajramke(d);
					substract(operand1, operand2);
				}
				else if (rozkaz == "ic"){
					d++;
					string cel = dysk.dajramke(d);
					increment(cel);
				}
				else if (rozkaz == "dc"){
					d++;
					string cel = dysk.dajramke(d);
					decrement(cel);
				}
				else if (rozkaz == "cm"){
					d++;
					string operand1 = dysk.dajramke(d);
					d++;
					string operand2 = dysk.dajramke(d);
					compare(operand1,operand2);
				}
				else if (rozkaz == "cm"){
					d++;
					string operand1 = dysk.dajramke(d);
					d++;
					string operand2 = dysk.dajramke(d);
					compare(operand1, operand2);
				}
				else if (rozkaz == "jp"){
					d++;
					string operand = dysk.dajramke(d);
					int liczba;
					liczba = strtol(operand.c_str(), NULL, 10);
					d = d + liczba;
				}
				else{
					d++;
					cout << "nieprawidlowy rozkaz, blad w programie!";
				}
				wykonane--;
				pamiec.tab[proces.id1 + 8] = proces.stan;
				pamiec.tab[proces.id1 + 6] = d;
			}
			return proces;
		}

	/*void dzialania(string rozkaz){
		string rozkaz1 = rozkaz.substr(0,2);
		cout << rozkaz1;
		if (rozkaz1 == "mv") move(rozkaz);
		else if (rozkaz1 == "ad") add(rozkaz);
		else if (rozkaz1 == "sb") substract(rozkaz);
		else if (rozkaz1 == "ic") increment(rozkaz);
		else if (rozkaz1 == "dc") decrement(rozkaz);
		else if (rozkaz1 == "cm") compare(rozkaz);
		else if (rozkaz1 == "jp") jump(rozkaz);
		else if (rozkaz1 == "fr") fork(rozkaz);
		else if (rozkaz1 == "ad") end(rozkaz);
		else if (rozkaz1 == "je") read(rozkaz);
		else cout << "blad- nie ma takiego rozkazu";
	}*/
};

