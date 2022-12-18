#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>

using namespace std;


fstream plik;

bool Restart() {

	cout << "Restart = 1 Close = 2" << endl;

	int index;
	bool bRestart;
	cin >> index;


	if (index == 1)
	{
		system("CLS"); // Wyczyść ekran konsoli.

		bRestart = true;
		cout << "bRestart = " << bRestart << endl;
		return bRestart;

	}

	else {
		system("CLS"); // Wyczyść ekran konsoli.
		bRestart = false;

		cout << "bRestart = " << bRestart << endl;
		return bRestart;
	}



}

char* WprowadzenieZnakow(bool rest)
{
	bool bRestarted = false;
	bRestarted = rest;
	char* wiadomosc = new char[10000000];
	int seed, i, x;
	
	cout << "Wprowadz znaki: " << endl;
	if (bRestarted == true)

	{

		cin.clear(); // reset failbit
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //skip bad input
		system("CLS"); // Wyczyść ekran konsoli.

		cout << "Wprowadz znaki: ";


	}
	cin.getline(wiadomosc, 10000000);

	cout << "Wprowadz cyfrowe ziarno:\n";
	cin >> seed;

	if (!cin) // or if(cin.fail())
	{
		// user didn't input a number
		cin.clear(); // reset failbit
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //skip bad input
		system("CLS"); // Wyczyść ekran konsoli.
		cout << "Wprowadzono niepoprawne ziarno!\n";
		WprowadzenieZnakow(true);

	}


	cout << "\Wybierz co chcesz zrobic:\n";
	cout << "1 = Zakoduj wiadomosc.\n";
	cout << "2 = Odkoduj wiadomosc.\n";
	cin >> x;





	//using switch case statements
	switch (x)

		
	{
		bool bSwitch;
		//first case for encrypting a string
	case 1:
		for (i = 0; (i < 10000000 && wiadomosc[i] != '\0'); i++)
			wiadomosc[i] = wiadomosc[i] + seed; //the key for encryption is 3 that is added to ASCII value
		cout << "\nZakodowana wiadomosc: " << wiadomosc << endl;
		bSwitch = Restart();

		cout << "bSwitch is  = " << bSwitch << endl;

		if (bSwitch == true) {

			WprowadzenieZnakow(true);

		}

		break;
		//second case for decrypting a string
	case 2:
		for (i = 0; (i < 10000000 && wiadomosc[i] != '\0'); i++)
			wiadomosc[i] = wiadomosc[i] - seed; //the key for encryption is 3 that is subtracted to ASCII value

		cout << "\nOdkodowana wiadomosc: " << endl << wiadomosc;
		bSwitch = Restart();

		if (bSwitch == true) {

			WprowadzenieZnakow(true);

		
		}

		break;

	default:
		cout << "\nNieprawidlowy wybor!\n";
	}


	return wiadomosc;
}






int main()
{
	WprowadzenieZnakow(false);

	return 0;


	/*plik.open("Baza danych.txt", ios::out);


	plik << seed << endl;

	plik.close();

	plik.open("Baza danych.txt", ios::out | ios::app);

	plik << str << endl;



	plik.open("Baza danych.txt", ios::in);

	if (plik.good() == false)
	{


	cout << "Nie ma pliku!";
}

	return 0; */
}

