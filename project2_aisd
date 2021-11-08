// Projekt 2, AiSD 2020 - implementacja algorytmu Enigmy
// Monika Drozd

#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Wirnik
{
	vector<int> liczby;			
	vector<int> indexy;
	vector<int> liczbyPowodujacePrzeniesienie;
	Wirnik()
	{
		przesuniecie = 0;
	}
public:
	int przesuniecie;

	inline int getLiczba(int i)
	{
		int x = (i + przesuniecie) % liczby.size();
		return liczby[x];
	}

	inline int getIndex(int i)
	{
		int x = (i + przesuniecie) % indexy.size();
		return indexy[x];
	}
	void przesun()
	{
		przesuniecie =  (przesuniecie+1) % liczby.size() ;
	}
};

int liczbaLiterWAlfabecie;

inline int przejdzPrzezWirnik(Wirnik& wirnik, int indeksWejscia, bool doPrzodu)
{
	if (doPrzodu)
	{
		int indeksWyjscia = wirnik.getLiczba(indeksWejscia - 1) - wirnik.przesuniecie;
		if (indeksWyjscia > 0) return indeksWyjscia;

		return (indeksWyjscia + wirnik.liczby.size()); //zwracana wartosc musi byc >0 bo potem w reflek. jest indeksWyjscia - 1
	}
	else
	{
		int liczba = wirnik.getIndex(indeksWejscia - 1);
		vector<int>::iterator it = wirnik.liczby.begin() + wirnik.przesuniecie;
		
		int indeksWyjscia = 1;
		while (*it != liczba)
		{
			indeksWyjscia++;
			it = (*it == wirnik.liczby.back()) ? wirnik.liczby.begin() : it + 1;
		}
		return indeksWyjscia;
	}
}


//przekazuje i pracuje na originale wirnikow nie na kopii
void przesunWirniki(vector<Wirnik>& wirniki)
{
	//pierwszy wirnik jest przesuwany zawsze
	wirniki[0].przesun();
	for (int i = 0; i < wirniki.size()-1; i++)
	{									
    //getIndex(0): sprawdzam czy liczba znajdujaca sie na samej gorze powoduje przesuniecie kolejnego wirnika
		vector<int>::iterator it = find(wirniki[i].liczbyPowodujacePrzeniesienie.begin(), wirniki[i].liczbyPowodujacePrzeniesienie.end(), wirniki[i].getIndex(0));

		if (it != wirniki[i].liczbyPowodujacePrzeniesienie.end())
		{
			wirniki[i + 1].przesun();
		}
		else break;
		if (i == 1) break;
	}
}

void szyfruj(vector<int> &liczbaKodowana,  vector<Wirnik> &wirniki, vector<int> &reflector)
{
	int wyjscieWirnika;
	wirniki[0].przesun();
	for (unsigned i = 0; i < liczbaKodowana.size(); i++)
	{
		wyjscieWirnika = liczbaKodowana[i];

		for (unsigned j = 0; j < wirniki.size(); j++)
		{
			wyjscieWirnika = przejdzPrzezWirnik(wirniki[j], wyjscieWirnika, true);  //przejscie przez wirniki w strone reflektora
		}
		
		wyjscieWirnika = reflector[wyjscieWirnika - 1];

		for (int j = wirniki.size() - 1; j >= 0; j--)
		{
			wyjscieWirnika = przejdzPrzezWirnik(wirniki[j], wyjscieWirnika, false); //powrot od reflektora do wirnikow
		}
		
		przesunWirniki(wirniki);

		//zamiast zapisywac kolejne liczby rozkodowanej liczby do zmiennej od razu je wypisuje
		printf("%d ", wyjscieWirnika);
	}
	printf("\n");
}
int main()
{
	int liczba;
	int liczbaLiter2, liczbaReflektorow, indexWirnika, przesuniecieWirnika, numerReflektora;
	vector<Wirnik> wszystkieWirniki;
	int liczbaWirnikow;

	scanf_s("%d", &liczbaLiterWAlfabecie);
	scanf_s("%d", &liczbaWirnikow);

	//wczytaj wszystkie wirniki
	for (int i = 0; i < liczbaWirnikow; i++)
	{
		//definicja wirnika
		wszystkieWirniki.push_back(Wirnik());
		for (unsigned j = 0; j < liczbaLiterWAlfabecie; j++ )
		{
			scanf_s("%d", &liczba);
			wszystkieWirniki.back().liczby.push_back(liczba);
			wszystkieWirniki.back().indexy.push_back(j + 1);
		}

		//ilosc liczb powodujacych przeniesienie, nastepnie liczby powodujace przeniesienie
		scanf_s("%d", &liczbaLiter2);
		for (unsigned j = 0; j < liczbaLiter2; j++ )
		{
			scanf_s("%d", &liczba);
			wszystkieWirniki.back().liczbyPowodujacePrzeniesienie.push_back(liczba);
		}
	}

	//wczytuje wszystkie reflektory
	vector<vector<int>> reflektory;
	scanf_s("%d", &liczbaReflektorow);
	for (int i = 0; i < liczbaReflektorow; i++ )
	{
		reflektory.push_back(vector<int>());
		for (int j = 0; j < liczbaLiterWAlfabecie; j++)
		{
			scanf_s("%d", &liczba);
			reflektory[i].push_back(liczba);
		}
	}


	vector<Wirnik> wirniki;
	vector<int> liczbaKodowana;
	int liczbaZadan;
	scanf_s("%d", &liczbaZadan);
	
	//petla liczaca kazde zadanie po kolei
	while (liczbaZadan--)
	{
		//wczytuje wirniki do zadania
		//tworze ich kopie zeby nie obracac tych 'oryginalnych'
		//wczytuje liczby przesuniec poczatkowych wirnika i wykonuje te przesuniecia
		wirniki.clear();
		scanf_s("%d", &liczbaWirnikow);

		for (unsigned i = 0; i <liczbaWirnikow; i++ )
		{
			scanf_s("%d %d", &indexWirnika, &przesuniecieWirnika);
			wirniki.push_back(wszystkieWirniki[indexWirnika]);
			wirniki.back().przesuniecie = przesuniecieWirnika - 1;
		}

		//odczytuje uzyty w zadaniu reflektor
		scanf_s("%d", &numerReflektora);

		//wczytuje cala kodowana liczbe
		liczbaKodowana.clear();
		while (scanf_s("%d", &liczba))
		{
			if (liczba == 0) break;
			liczbaKodowana.push_back(liczba);
		}
		
		//przesylam cala liczbe do rozkodowania,
		//kopia wirnikow potrzebnych do zadania (pod indeksem 0 jest najszybszy wirnik),
		//reflektor potrzebny do zadania
		szyfruj(liczbaKodowana, wirniki, reflektory[numerReflektora]);
	}

	return 0;
}
