#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

using namespace std;

int sayac = 0;

class Dict {
private:

	set<string> words;
	vector<string> secrets;
	vector<string> tmp;
	set<string> tmp2;

public:
	
	
	Dict() {
	};

	void openfile() {

		int j, i;
		fstream dataFile;
		string buff[2500];

		char filename[30];

		cout << "Enter file name to open:" << endl;
		cin >> filename;



		dataFile.open(filename, std::fstream::in);

		for (i = 0; !dataFile.eof(); i++) {
			dataFile >> buff[i];
		
			sayac++;
		}

		secretsbul(buff, sayac);

	}

	void secretsbul(string buffer[], int count) {

		int t, i, j, say = 0,k=0;
		string temp;

		for (i = 0; i < count; i++) {
			words.insert(buffer[i]);

		}

		tmp.assign(words.begin(), words.end());


		for (t = 1; t < count; t++)
		{
			say = 0;
			temp = tmp[t];
			for (i = 0; i < 5; i++) {
				for (j = i + 1; j < 5; j++) {

					if (temp[i] == temp[j])
						say++;

				}

			}

			if (say == 0) {
				tmp2.insert(tmp[t]); ;
				k++;
			}
		}
		secrets.assign(tmp2.begin(), tmp2.end());
		
	}

	string kelimesec() {

		int sayi;
		srand(time(NULL));

		sayi = rand() % secrets.size();
		
		return secrets[sayi];

	}

	bool sozlukbak(string tahmin, int count) {

		int i, saya = 0;
		for (i = 0; i < count; i++) {

			if (tmp[i] == tahmin)
				saya++;

		}

		if (saya == 0)
			return 0;
		else
			return 1;
	}


};

class Word {

private:
	int tah, ip, yersayac, essayac, j, i;


	string tahmin = " ";
	string cevap;



public:

	
	
	Word() {

		tah = 0;
		ip = 0;
		yersayac = 0;
		essayac = 0;
		

	};

	~Word() {};

	void oyunoyna() {
		Dict kaya;
		kaya.openfile();
		cout << endl;
		cout << endl;
		cout << "BIL BAKALIM A HOSGELDINIZ" << endl;
		cout << endl;
		cout << "5 harfli bir kelime tuttum." << endl;
		cout << endl; 
		cout << endl;

		cevap = kaya.kelimesec();

		while (tahmin != cevap) {
			essayac = 0;
			yersayac = 0;

			cout << "Tahmininiz Nedir? " << endl;
			cin >> tahmin;
			tah++;
			if (tahmin == "xxxxx") {
				cout << "Ipucu: Gizli Kelime ==> " << cevap << endl;
				ip++;
			}
			if (kaya.sozlukbak(tahmin, sayac) == 1) {

				for (i = 0; i < 5; i++) {
					for (j = 0; j < 5; j++) {

						if (tahmin[j] == cevap[i]) {
							essayac++;
							break;
						}
					}

					if (tahmin[i] == cevap[i]) {
						yersayac++;
					}

				}


				if (yersayac != 5 && tahmin != "xxxxx") {
					cout << essayac << " harf eslesti" << endl;

					cout << yersayac << " harf dogru yerinde" << endl;

				}
			}

			else if (tahmin != "xxxxx") {
				cout << "Bu kelime sozlukte yok!!!" << endl;
				tah--;
			}

		}


		cout << endl;
		cout << endl;
		if (ip == 0)
		{
			cout << "TEBRIKLER BILDINIZ!!!  " << tah << " tahminde dogru sonuca ulastiniz!" << endl;
		}
		else
			cout << "TEBRIKLER BILDINIZ!!!  " << tah << " tahminde ipucu kullanarak dogru sonuca ulastiniz !" << endl;
		cout << endl;

	}
};


void main()
{
	Word kata;

	kata.oyunoyna();

	cout << endl;
	cout << endl;

	system("PAUSE");
}