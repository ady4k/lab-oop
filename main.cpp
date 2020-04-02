#include <iostream>
#include "Supraincarcare.cpp"
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
    obiect.Adauga(13);
    obiect.Adauga(25);
    obiect.Afisare();
    cout << '\n';
    obiect2.Adauga(2);
    obiect2.Adauga(67);
    obiect2.Adauga(25);
    obiect2.Adauga(9);
    obiect2.Adauga(11);
    obiect2.Afisare();
    cout << obiect2.nrElem() << '\n';

    Multime obiect4(3);
    obiect4.Adauga(5);
    obiect4.Adauga(4);
    obiect4.Adauga(2);
    obiect4.Adauga(67);
    obiect4.Adauga(51);
    obiect4.Afisare();

    cout << obiect4;
    cout << '\n';
    //cin >> obiect4;
    //cout << obiect4;
    cout << obiect3[2];
    cout << '\n';
    obiect4 = obiect2;
    cout << obiect4;
    cout << '\n';
    Multime test;
    cout << obiect << '\n';
    cout << obiect2 << '\n';
    test = obiect + obiect2;
    cout << test << '\n';
    cout << test.nrElem() << '\n';

    Multime test2;
    test2 = test - obiect2;
    test2.Afisare();

    if (obiect > obiect2) {
        cout << "da";
    } else {
        cout << "nu";
    }
    return 0;
}