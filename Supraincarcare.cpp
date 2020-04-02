#include "Multime.cpp"

// operatorul '>>' supraincarcat astfel incat la folosirea lui putem scrie direct marimea multimii si toate elementele care apartin acesteia
// la fiecare folosire a acestui operator se reseteaza toate proprietatile obiectului, inlocuindu-se cu altele noi
istream& operator>>(istream &in, Multime& multime){
    multime.Golire();
    int size;
    in >> size;
    int val;
    while (size > 0) {
        in >> val;
        multime.Adauga(val);
        --size;
    }
    return in;
}

// operatorul '<<' supraincarcat astfel incat la folosirea lui sa se afiseze direct toate elementele unei ultimii
// asemanator cu afisarea elementelor dintr-un vector
ostream& operator<<(ostream &out, Multime& multime){
    for(int i = 0; i < multime.nr_elem; i++)
        out << multime.arr[i] << ' ';
    return out;
}

// operatorul '=' supraincarcat astfel incat la folosirea lui, primul obiect primeste toate proprietatile si valorile celui de-al doilea
// mai intai se reseteaza primul obiect, apoi i se atribuie valorile din al doilea
Multime& Multime::operator=(const Multime& other){
    if (other.nr_elem > 0){
        Golire();

        for(int i  = 0; i < other.nr_elem; i++)
            Adauga(other.arr[i]);
    }
    return *this;
}

// operatorul '[]' supraincarcat astfel incat sa arate elementul de pe o anumita pozitie
int &Multime::operator[](int pos) {
    return arr[pos];
}

// operatorul '+' supraincarcat astfel incat rezultatul sa fie reuniunea celor 2 multimi adunate
// elementele se vor unifica si sorta automat la fiecare adaugare
// cele 2 multimi adunate raman cu aceleasi proprietati si valori, se returneaza doar rezultatul printr-un obiect temporar
Multime& Multime::operator+(const Multime& other) {
    Multime* temp = new Multime();
    for(int i = 0; i < nr_elem; i++)
        temp->Adauga(arr[i]);
    for(int i = 0; i < other.nr_elem; i++)
        temp->Adauga(other.arr[i]);
    return *temp;
}

// operatorul '-' supraincarcat astfel incat rezultatul sa fie diferenta celor 2 multimi scazute
// se foloseste un algoritm brute-force pentru identificarea elementelor comune
// cele 2 multimi adunate raman cu aceleasi proprietati si valori, se returneaza doar rezultatul printr-un obiect temporar
Multime& Multime::operator-(const Multime& other){
    int i, j;
    Multime* temp = new Multime();
    for(i = 0; i < nr_elem; i++)
        temp->Adauga(arr[i]);
    for(i = 0; i < temp->nr_elem; i++)
       for(j = 0; j < other.nr_elem; j++) {
           if (temp->arr[i] == other.arr[j]) {
               temp->StergeIndex(i);
               i--;
           }
       }
    return *temp;
}

// operatorul '>' supraincarcat astfel incat sa compare nr. de elemente din fiecare multime
// are aceleasi proprietati ca cel obisnuit
bool Multime::operator>(const Multime& other) {
    return nr_elem > other.nr_elem;
}

// operatorul '<' supraincarcat astfel incat sa comapre nr. de elemente din fiecare multime
// are aceleasi proprietati ca cel obisnuit
bool Multime::operator<(const Multime& other) {
    return nr_elem < other.nr_elem;
}