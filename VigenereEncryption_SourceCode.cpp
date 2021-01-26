/****************************************************************************
**						SAKARYA ÜNÝVERSÝTESÝ
**				BÝLGÝSAYAR VE BÝLÝÞÝM BÝLÝMLERÝ FAKÜLTESÝ
**					BÝLGÝSAYAR MÜHENDÝSLÝÐÝ BÖLÜMÜ
**					 PROGRAMLAMAYA GÝRÝÞÝ DERSÝ
**
**					ÖDEV NUMARASI…...:04
**					ÖÐRENCÝ ADI......:Davud Samed Tombul
**					ÖÐRENCÝ NUMARASI.:B171210007
**					DERS GRUBU.......:ÖrgünEðitim 1D
****************************************************************************/


#include <iostream>//Cout gibi temel komutlarý kullanmak için gerekli kütüphane.
#include<locale.h>//Türkçe karakterleri kullanabilmemiz için gerekli kütüphane.
#include <string>
#include<iomanip>//Setw manipulatörünü kullanbilmemiz için gerekli kütüphane.



using namespace std;//Her seferinde std::cout vs yazarak zaman kaybetmemek için kullandýðýmýz komut.

					//Gireceðimiz metni þifreleyecek ve þifresini çözecek fonksiyonlarýn bildirimini içeren class'ýmýz.
class Sifre
{
public:

	void Sifrele(const string &yazi, const string &key, string &sifreliyazi);

	void SifreyiCoz(const string &sifreliyazi, const string &key, string &yazi);

private:

};

//Gireceðimiz metni þifreleyecek parametreli fonksiyonumuz.
void Sifre::Sifrele(const string &yazi, const string &anahtarKelime, string &sifremetin)
{
	int yeni;
	int t, k;

	for (t = 0, k = 0; t < yazi.length(); ++t, k++)
	{
		if (k >= anahtarKelime.length())
			k = 0;

		if (yazi[t] >= 'A' && yazi[t] <= 'Z')
			yeni = ((yazi[t] - 64) + (anahtarKelime[k] - 64)) % 26;

		else
			yeni = yazi[t] - 64;
		sifremetin.append(string(1, (char)(yeni + 64)));
	}
}

//Þifreli metnin þifresini çözecek fonksiyonumuz.
void Sifre::SifreyiCoz(const string &sifremetin, const string &anahtarKelime, string &yazi)
{
	int yenile;
	int q, w;

	for (q = 0, w = 0; q < sifremetin.length(); ++q, w++)
	{
		if (w >= anahtarKelime.length())
			w = 0;

		if (sifremetin[q] >= 'A' && sifremetin[w] <= 'Z')
			yenile = ((sifremetin[q] - 64) + 26 - (anahtarKelime[w] - 64)) % 26;

		else
			yenile = sifremetin[q] - 'A';

		yazi.append(string(1, (char)(yenile + 64)));
	}
}

int main()
{
	//Türkçe karakter kullanabilmemiz için gerekli komut.
	setlocale(LC_ALL, "Turkish");

	//Sifre class'ýndan sifree adlý nesneyi üretiyoruz.
	Sifre sifree;

	string sifre, desifre;


	char yazi[500];

	char anahtarKelime[500];


	cout << setw(30) << "Alfabe" << endl << "A B C D E F G H I J K L M N O P Q R S T U V W X Y Z" << endl << endl;

	cout << "Gireceðiniz tüm karakterlerin büyük harfli ve alfabeden seçilmiþ olmasýna dikkat ediniz..." << endl << endl;

	cout << "Þifrelemek Ýstediðiniz Metni Yazýnýz: ";


	cin.getline(yazi, 256);


	cout << "Anahtar Kelimeyi Yazýnýz :";

	cin.getline(anahtarKelime, 256);


	sifree.Sifrele(yazi, anahtarKelime, sifre);


	sifree.SifreyiCoz(sifre, anahtarKelime, desifre);


	cout << "Þifreli Metin: " << sifre << setw(50) << "Þifresi Çözülmüþ Metin: " << desifre << endl;


	system("pause");

	return 0;
}
