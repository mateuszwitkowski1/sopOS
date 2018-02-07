#include "string"
#include "fstream"
#include "Planista.h"

using namespace std;

struct ramka{
public:
	char dane1[2];
};

class Dysk{
	public:
		char ramy[100][2];

		void wyczysc(){
			for (int i = 0; i <= 100; i++){
				ramy[i][0] = '.';
				ramy[i][1] = '.';
			}
		}

	int wczytaj(string nazwaplik){
		string ff = "aa";
		int n = 0;
		if (ramy[0][0] != '.'){
			n = 100;
			while (ramy[n][0]=='.'){
				n--;
			}
			n++;
		}
			fstream plik;
			plik.open(nazwaplik, ios::in);
			if (plik.good()){
				int poczatek = n;
				cout << "   " << poczatek << "    ";
				while (!plik.eof()){
					char a;
					char b;
					plik >> a >> b;
					ramy[n][0] = a; ramy[n][1] = b;
					n++;
				}
				ramy[n][0] = 'f'; ramy[n][1] = 'f';
				cout << "wgrano program na dysk, zawartosc dysku: " << endl;
				for (int e = 0; e < 100; e++){
					cout << ramy[e][0] << ramy[e][1] << " ";
				}
				cout << endl;
				plik.close();
				return poczatek;
			}
			else{
				cout << "blad otwarcia pliku z programem";
				return NULL;
			}
	}

	string dajramke(int ktora){
		char data[2] = { ramy[ktora][0], ramy[ktora][1] };
		string rozkaz(data,2);
		return rozkaz;
	}
};