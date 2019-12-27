#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Turkish");
	ifstream dosyayioku;
	string  satir, satir1;
	ifstream satirsayisi;
	satirsayisi.open("dosya.txt");
	int satirsay = 0, sayac = 0;

	while (getline(satirsayisi, satir1))
	{
		satirsay++;
	}
	satirsayisi.close();
	vector <string>okunanSatir(satirsay);

	dosyayioku.open("dosya.txt");
	while (getline(dosyayioku, satir))
	{
		okunanSatir[sayac] = satir;
		sayac++;

	}
	dosyayioku.close();
	int a = stoi(okunanSatir[0]);
	vector<string> cevap(a);
	int sayac1 = 0;
	string s = okunanSatir[1];
	string ayrac = ",";
                                                    //https://stackoverflow.com/questions/14265581/parse-split-a-string-in-c-using-string-delimiter-standard-c
	size_t konumu = 0;
	string harf;
	while ((konumu = s.find(ayrac)) != -1) {
		harf = s.substr(0, 1);
		cevap[sayac1] = harf;
		s.erase(0, konumu + ayrac.length());
		sayac1++;
	}
	int z = 0, c = 0;
	cevap[sayac1] = s;
	vector<int>sonuclar(satirsay - 2);
	for (int j = 2; j < satirsay; j++)
	{
		string s = okunanSatir[j];
		string ayrac = ",";
		int  puan = 0;
		size_t konumu = 0;
		string harf;
		c = 0;
		while ((konumu = s.find(ayrac)) != -1) {
			s.erase(0, konumu + 1);
			harf = s.substr(0, 1);
			if (c < 5)
			{
				if (harf == cevap[c])
				{
					puan = puan + 4;
					c++;

				}
				else if (harf == " ")
				{
					puan = puan + 0;
					c++;

				}
				else
				{
					puan = puan - 1;
					c++;
				}
			}
		}
		sonuclar[z] = puan;
		z++;
		puan = 0;
	}
	int temp;
	int i, j;

	for (i = 1; i < satirsay - 2; i++)
	{
		for (j = 0; j < satirsay - 2; j++)
		{
			if (sonuclar[j] > sonuclar[i])
			{
				temp = sonuclar[j];
				sonuclar[j] = sonuclar[i];
				sonuclar[i] = temp;
			}
		}
	} int topla = 0;
	for (int gg = 0; gg < satirsay - 2; gg++)
	{

		cout << to_string(sonuclar[gg]) << endl;
		topla = sonuclar[gg] + topla;

	}

	int medyan1, medyan2;
	ofstream yaz("cıktı.txt");
	yaz << "Enküçük değer = " << sonuclar[0] << endl;
	yaz << "Enbüyük değer = " << sonuclar[satirsay - 3] << endl;
	yaz << "Ortalama = " << topla / satirsay - 3 << endl;
	yaz << "Açıklık = " << sonuclar[satirsay - 3] - sonuclar[0] << endl;
	if ((satirsay - 2) % 2 == 0)
	{
		medyan1 = sonuclar[(satirsay - 3) / 2 - 1];
		medyan2 = sonuclar[(satirsay - 3) / 2];
		yaz << "Medyan = " << medyan1 << " " << medyan2;
	}
	else
	{
		medyan1 = sonuclar[(satirsay - 3) / 2];
		yaz << "Medyan = " << medyan1;
	}


}
