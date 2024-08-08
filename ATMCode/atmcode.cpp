#include <iostream>
#include <string>

using namespace std;

/*
	Simple ATM system with few options. 

	Options on the list : 

	1. Check Withdrawable amount
	2. Withdraw
	3. Deposit

	In this showcase I am going to use a DATABASE created by myself. (if we can call it DB xD)

*/



struct Korisnik {

	int ID;
	string nameSurname;
	int PIN;
	int stanjeRacuna;

};


int main() {

	Korisnik korisnici[] = {

		{4000, "Bill Charles", 4231, 14000},
		{4001, "Jason King" ,  4232, 42400},
		{4002, "Kevin Hart", 4233, 43929},
		{4003,"Dwayne Rock", 4234, 10000},
		{4004, "Semsudin Poplava", 4325, 100000}

	};

	int unesiID;
	int unesiPIN;

	cout << "Unesite ID vase kartice : " << endl;
	cin >> unesiID;

	if (!(unesiID == korisnici->ID)) {

		cout << "Uneseni ID nije pronadjen u bazi podataka. Pokusajte ponovo. ";
		system("pause");
		return 0;

	}

	cout << "Unesite vas PIN : " << endl;
	cin >> unesiPIN;

	if (!(unesiPIN == korisnici->PIN)) {

		cout << "Uneseni PIN nije validan. Pokusajte ponovo. ";
		system("pause");
		return 0;

	}

	bool pronadjen = false;
	
	for (Korisnik& korisnik : korisnici) {

		if (korisnik.ID == unesiID && unesiPIN == korisnik.PIN)
		{
			pronadjen = true;

			cout << "Vas ID : " << korisnik.ID << endl;
			cout << "Ime i prezime : " << korisnik.nameSurname << endl;
			cout << "Stanje na vasem racunu iznosi : " << korisnik.stanjeRacuna << endl;

			string odluka;
			int iznosZaPovlacenje;
			int iznosZaUplatu;
			int novoStanje;

			cout << "Da li zelite povuci novac ili uplatiti novac na vas racun : (isplata, uplata) " << endl;
			cin >> odluka;

			if (odluka == "isplata")
			{
				cout << "Odaberite iznos za povlacenje : " << endl;
				cin >> iznosZaPovlacenje;

				if (iznosZaPovlacenje > korisnik.stanjeRacuna)
				{
					cout << "Nemate dovoljno sredstava na racunu. " << endl;
				}
				else if (iznosZaPovlacenje == 0) {
					cout << "Pogresan unos. Ne mozete povuci 0 sa vaseg racuna." << endl;
				}
				else if (iznosZaPovlacenje < korisnik.stanjeRacuna)
				{
					novoStanje = korisnik.stanjeRacuna - iznosZaPovlacenje;
					cout << "Uspjesno ste povukli novac sa racuna. Trenutno stanje na racunu iznosi : " << novoStanje << endl;

				}
				else {
					"Pogresan unos.";
				}


			}
			else if (odluka == "uplata")
			{
				cout << "Utipkajte iznos koji zelite uplatiti : " << endl;
				cin >> iznosZaUplatu;

				if (iznosZaUplatu < 10) {

					cout << "Vasa uplata mora biti veca od 10KM." << endl;

				}
				else if (iznosZaUplatu >= 10) {

					novoStanje = iznosZaUplatu + korisnik.stanjeRacuna;
					cout << "Uplata uspjesno izvrsena. Stanje na vasem racunu iznosi : " << novoStanje << endl;

				}

			}
			else
				cout << "Nepravilan unos." << endl;
		}

	}

	system("pause");
	return 0;

}













