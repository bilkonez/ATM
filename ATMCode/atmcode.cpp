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

	void povuciNovac(int iznos) {
		if (iznos > stanjeRacuna) {
			cout << "Nemate dovoljno sredstava na računu." << endl;
		}
		else {
			stanjeRacuna -= iznos;
			cout << "Uspjesno ste povukli iznos sa vaseg racuna. " << endl;
			cout << "Trenutno stanje na vasem racunu iznosi : " << stanjeRacuna << endl;
		}
	}

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

	if (!(cin >> unesiID)) {

		cout << "Uneseni ID nije pronadjen u bazi podataka. Pokusajte ponovo. ";

	}

	cout << "Unesite vas PIN : " << endl;

	if (!(cin >> unesiPIN)) {

		cout << "Uneseni PIN nije validan. Pokusajte ponovo. ";

	}


	bool pronadjen = false;
	
	for (Korisnik& korisnik : korisnici) {

		if (korisnik.ID == unesiID && unesiPIN == korisnik.PIN)
		{
			pronadjen = true;

			cout << "Vas ID : " << korisnik.ID << endl;
			cout << "Ime i prezime : " << korisnik.nameSurname << endl;
			cout << "Stanje na vasem racunu iznosi : " << korisnik.stanjeRacuna << endl;

			string povlacenjeNovca;
			int iznosZaPovlacenje;

			cout << "Da li zelite povuci novac sa vaseg racuna : (DA, NE) " << endl;
			cin >> povlacenjeNovca;

			if (povlacenjeNovca == "DA")
			{
				cout << "Odaberite iznos za povlacenje : " << endl;
				cin >> iznosZaPovlacenje;

				korisnik.povuciNovac(iznosZaPovlacenje);

			}
			else if (povlacenjeNovca == "NE")
			{
				cout << "Uredu. Prijatan dan Vam zelimo." << endl;
			}
			else
				cout << "Nepravilan unos." << endl;
		}

	}


	system("pause>0");
	return 0;



}













