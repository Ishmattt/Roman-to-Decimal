#include<iostream>
#include<string>
using namespace std;

class romawii
{

public:

  romawii (string = "");
  void inputRomawi (string);
  void konversi ();
  void printRoman ();
  

private:

  string romawi;
  int decimal;

};

romawii::romawii (string a)
{

  romawi = a;
  decimal = 0;

}

void romawii::inputRomawi (string a)
{

  romawi = a;
  decimal = 0;

}

void romawii::konversi ()
{

  char romans[7] = { 'M', 'D', 'C', 'L', 'X', 'V', 'I' };
  int decimals[7] = { 1000, 500, 100, 50, 10, 5, 1 };
  int j, posisi;
  int lenght = romawi.length ();

  for (int i = 0; i < lenght - 1; i++)

    {

    for (posisi = 0; posisi < 7; posisi++)
	if (romawi.at (i) == romans[posisi])
	  break;

      {

	for (j = 0; j < posisi; j++)
	  if (romawi.at (i + 1) == romans[j])

	    break;

	if (j == posisi)
	  decimal += decimals[posisi];
	else
	  decimal -= decimals[posisi];

      }

    }



  for (j = 0; j < 7; j++)
    if (romawi.at (lenght - 1) == romans[j])
      break;
      
  decimal += decimals[j];

}

void romawii::printRoman ()
{

  cout << "\n\n\tromawi " << romawi<<"\n\tekuivalen dengan: "<<decimal;

}


int main ()
{

  cout << "\n\n\tkonverter Romawi ke Desimal";
  romawii wii;
  string testing[3] = { "MCXIV", "CCCLIX", "MDCLXVI" };

  for (int i = 0; i < 3; i++)

    {
      wii.inputRomawi (testing[i]);
      wii.konversi ();
      wii.printRoman ();

    }


  return 0;
}
