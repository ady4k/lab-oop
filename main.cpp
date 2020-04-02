#include <iostream>
#include "Multime.cpp"
using namespace std;

int main(){

    Multime obiect;
    Multime obiect2(2);

    obiect2.Adauga(2);
    obiect2.Adauga(67);
    obiect2.Adauga(25);
    obiect2.Adauga(9);
    obiect2.Adauga(11);
    obiect2.Afisare();
    cout << '\n';
    obiect2.Sterge(11);
    obiect2.Afisare();
    cout << '\n';
    cout << obiect2.nrElem() << '\n';
    cout << obiect2.Index(3) << '\n';
    cout << '\n';
    Multime obiect3(obiect2);
    obiect3.Afisare();
    cout << '\n';
    obiect.Adauga(5);
    obiect.Adauga(62);
    obiect.Afisare();
    cout << '\n';
    obiect2.Adauga(2);
    obiect2.Adauga(67);
    obiect2.Adauga(25);
    obiect2.Adauga(9);
    obiect2.Adauga(11);
    obiect2.Afisare();
    cout << obiect2.nrElem() << '\n';
    return 0;
}