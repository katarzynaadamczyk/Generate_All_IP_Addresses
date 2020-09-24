#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> generateallipaddresses_v1(const string &dane);
bool checkifvalid(string &adres);


int main()
{
    cout << "Witaj w programie generujacym adresy IP z podanego stringa" << endl;
    string info {};
    vector<string> wynik;
    while (info!= "0")
    {
        cout<<"Podaj stringa do rozparcelowania :) " <<endl;
        cout<<"Jesli podasz 0 to konczymy program."<<endl;
        cin>>info;
        wynik = generateallipaddresses_v1(info);
        if (wynik.size()>0)
            {
                cout<<"Wygenerowane adresy to: "<<endl;
                for (auto &i : wynik)
                {
                    cout<<i<<endl;
                }
            }
        else
            cout<<"Nie udalo sie wygenerowac ani jednego adresu - bledne dane."<<endl;
        cout<<endl<<endl;
    }


    return 0;
}

vector<string> generateallipaddresses_v1(const string &dane)
{
    if (dane.size()>3 && dane.size()<13 && dane.find_first_not_of("0123456789") == string::npos)
    {
        string adres_ip{}, kopia{dane},czesc{}, kopiaB{}, kopiaC{}, kopiaD{};
        vector<string> wynik, pom;
        for (int A = 0; A<3; ++A)
        {
            czesc = kopia.substr(0,A+1);
            kopia.erase(0,A+1);
            if (checkifvalid(czesc) && kopia.size()>2)
            {
                pom.push_back(czesc);
                for (int B = 0; B<3; B++)
                {
                    kopiaB = kopia;
                    czesc = kopiaB.substr(0,B+1);
                    kopiaB.erase(0,B+1);
                    if (kopiaB.size() == 0)
                        break;
                    if (checkifvalid(czesc)&&kopiaB.size()>1)
                    {
                        pom.push_back(czesc);
                        for (int C = 0; C<3; C++)
                        {
                            kopiaC = kopiaB;
                            czesc = kopiaC.substr(0,C+1);
                            kopiaC.erase(0,C+1);
                            if (kopiaC.size() == 0)
                                break;
                            if (checkifvalid(czesc)&&checkifvalid(kopiaC))
                            {
                                adres_ip = pom[0] + "." + pom[1] + "." +czesc + "." + kopiaC;
                                wynik.push_back(adres_ip);
                                cout<<"Dodalem adres ip = "<<adres_ip<<endl;
                            }
                        }
                    }
                    pom.pop_back();
                }
            }
            kopia = dane;
            pom.clear();
        }
        return wynik;
    }
    else
        return {};
}

bool checkifvalid(string &adres)
{
    if (adres.size()>0 && adres.size()<4 && adres.find_first_not_of("0123456789")==string::npos)
    {
        switch (adres.size())
        {
        case 1:
            return true;
        case 2:
            if (adres[0]=='0')
                return false;
            else
                return true;
        case 3:
            if (adres[0] == '1' || adres[0]=='2')
                return true;
        default:
            return false;
        }
    }
    return false;
}
