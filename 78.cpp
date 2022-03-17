#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string SkrOp(string mess) 
{
    int S[8] = { int('A'), int('G'), int('L'), int('M'), int('R'), int('O'), int('T'), int('Y') };
    int length = mess.length();
    int rest = length % 8;
    
    for (int i = 0; i < 8-rest; i++)
	{
        mess += ".";
    }
    length = mess.length();
    
    for (int i = 0; i < length; i++) 
	{
        S[i % 8] = (S[i % 8] + int(mess[i])) % 128;
    }
    
    for (int j = 0; j < 8; j++) 
	{
        cout << S[j] << " ";
    }
    
    cout << endl;
    cout << mess.length()<<endl;
    string res= "";
    
    for (int i = 0; i < 8; i++) 
	{
        res+= char(65 + S[i] % 26);
    }
    return wynik;
}

string cut(string mess) 
{
    int S[8] = { int('A'), int('G'), int('L'), int('M'), int('R'), int('O'), int('T'), int('Y') };

    int length = mess.length();
    int rest = length % 8;

    for (int i = 0; i < 8 - rest; i++) 
	{
        mess += ".";
    }
    
    length = mess.length();
    
    for (int i = 0; i < length; i++) 
	{
        S[i % 8] = (S[i % 8] + int(mess[i])) % 128;
    }
    
    string res= "";
    
    for (int i = 0; i < 8; i++) 
	{
        res+= char(65 + S[i] % 26);
    }
    return wynik;
}

string decip(int d, int n, int cip[8])
 {
    string res="";
    
    for (int i = 0; i < 8; i++) 
	{
        res+= char(cip[i] * d % n);
    }
    return wynik;
}

int main()
{
    ifstream FileIn1;
    ifstream FileIn2;
    ofstream FileOut;

    FileIn1.open("podpisy.txt");
    FileIn2.open("wiadomosci.txt");
    FileOut.open("epodpis_wynik.txt");
    
    string lyr1;

    getline(FileIn2, lyr1);
    FileIn2.close();
    FileIn2.open("wiadomosci.txt");
    cout << SkrOp(lyr1)<<endl;
    cout << endl;
    for (int i = 0; i < 11; i++) 
	{
        int tab[8];
        string lyr;
        getline(FileIn2, lyr);
        for (int j = 0; j < 8; j++) 
		{
            int temp;
            FileIn1 >> temp;
            tab[j] = temp;
        }
        cout << decip(3, 200, tab)<<endl;  
    }
    FileIn1.close();
    FileIn2.close();
    FileIn1.open("podpisy.txt");
    FileIn2.open("wiadomosci.txt");
    cout << endl;
    for (int i = 0; i < 11; i++) 
	{
        int tab[8];
        string lyr;
        getline(FileIn2, lyr);
        for (int j = 0; j < 8; j++) 
		{
            int temp;
            FileIn1 >> temp;
            tab[j] = temp;
        }

        if (decip(3, 200, tab) == cut(lyr)) 
		{
            cout << i + 1 << endl;
        }
    }
    
}
