#include "Multime.h"
#include <iostream>
#include <stdexcept>
 using namespace std;

// constructor fara parametrii
// initializeaza nr. de elemente si marimea cu 0
Multime::Multime() {
    nr_elem = 0;
    size = 0;
}

// constructor cu parametru pentru marimea multimii
// initializeaza nr. de elemente cu 0 si elementele din multime
Multime::Multime(int size): size(size) {
    nr_elem = 0;
    arr = new int[size];
    Initializare(nr_elem);
}
// constructor de copiere, primeste ca parametru un obiect deja existent
// se copiaza toate proprietatile si valorile in obiectul construit
Multime::Multime(const Multime &other): size(other.size) {
    nr_elem = size;
    if (size <= 0){
        arr = nullptr;
    } else {
        arr = new int[size];
        for(int i = 0; i < size; i++) {
            arr[i] = other.arr[i];
        }
    }
}

// deconstructor pentru eliberarea memoriei folosite dupa distrugerea obiectelor
Multime::~Multime() {
    delete[] arr;
}

// toate valorile din multime sunt automat initializate cu 0
// pentru a evita potentialele erori de executare
void Multime::Initializare(int val) {
    for (int i = val; i < size; ++i) {
        arr[i] = 0;
    }
}

// functie care aloca memorie multimii pentru inca un element
// folosit atunci cand numarul elementelor depaseste marimea memorii alocate
void Multime::Extindere() {
    size += 1;
    if (size >= 2) {
        int *tempArr = new int[size];
        for (int i = 0; i < size; i++)
            tempArr[i] = arr[i];
        delete[] arr;
        arr = tempArr;
        Initializare(nr_elem);
    } else {
        arr = new int[size];
        Initializare(nr_elem);
    }
}

// functie care dealoca memoria folosita de catre un element care a fost sters
// folosit atunci cand stergem un element din multime
void Multime::Micsorare() {
    size -= 1;
    int* tempArr = new int[size];
    for(int i = 0; i < size; i++)
        tempArr[i] = arr[i];
    delete[] arr;
    arr = tempArr;

}

// functie folosita pentru adaugarea unui numer in multime
// daca acest element nu are loc in multime, i se va aloca automat un spatiu in memorie
// la fiecare element nou, multimea se sorteaza crescator si se unifica numerele comune
void Multime::Adauga(int val) {
    if (nr_elem >= size)
        Extindere();
    arr[nr_elem++] = val;
    if(nr_elem >= 2){
        Sortare();
        Unificare();
    }
}

// functie folosita pentru stergerea unui numar din multime
// mai intai se cauta daca elementul exista in multime
// la fiecare element sters, se dealoca un spatiu pt un element
void Multime::Sterge(int val) {
    int element =  Cautare(val, 0, nr_elem);
    for(int i = element; i < size-1; i++) {
        arr[i] = arr[i+1];
    }
    nr_elem--;
    Micsorare();
}

// functie folosita pentru stergerea elementului de pe o anumita pozitie
// folosita in unele functii atunci cand se cunoaste pozitia elementului pentru a evita apelarea functiei de cautare
// se dealoca automat spatiu din memorie
void Multime::StergeIndex(int index) {
    for(int i = index; i < size-1; i++) {
        arr[i] = arr[i+1];
    }
    nr_elem--;
    Micsorare();
}

// functie care arata elementul de pe o anumita pozitie
// daca elementul nu se afla in multime, va arunca o exceptie
int Multime::Index(int index) {
    if (index < 0 || index >= size)
        throw "index out of range";
    return arr[index];
}

// functie care unifica toate numerele comune din multime
// spre ex: [1, 3, 5, 5, 6, 6, 8] --> [1, 3, 5, 6, 8]
// la fiecare unificare se dealoca spatiul din memorie pentru elementele sterse
void Multime::Unificare() {
    for(int i = 0; i < nr_elem-1; i++) {
        if(arr[i] == arr[i+1]) {
            for(int j = i; j < nr_elem-1; j++) {
                arr[j] = arr[j+1];
            }
            Micsorare();
            nr_elem--;
        }
    }
}

// functie care sorteaza toate elementele din multime
// este folosit algoritmul de BubbleSort optimizat
void Multime::Sortare() {
    bool ok;
    for(int i = 0; i < nr_elem; i++) {
        ok = false;
        for (int j = 0; j < nr_elem - 1; j++)
            if (arr[j] > arr[j + 1]) {
                int aux = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = aux;
                ok = true;
            }
        if (ok == false)
            break;
    }
}

// functie pentru cautarea unui anumit nr in multime
// este folosit algoritmul pentru Cautarea Binara
int Multime::Cautare(int val, int stanga, int dreapta) {
    if (dreapta >= stanga) {
        int mijloc = (stanga + dreapta)/ 2;

        if(arr[mijloc] == val)
            return mijloc;

        if(arr[mijloc] > val)
            return Cautare(val, stanga, mijloc - 1);
        return Cautare(val, mijloc + 1, dreapta);
    }
    throw "element not in index";
}

// in general pentru testat, folosita cand nu aveam '<<' supraincarcat
// afiseaza toate nr. din multime
void Multime::Afisare() {
    for(int i = 0; i < nr_elem; i++)
        cout << "elementul " << i << ':' << ' ' << arr[i] << '\n' ;
}

// functie care goleste toata multimea, reseteaza proprietatila si dealoca toata memoria alocata
void Multime::Golire() {
   if (nr_elem == 0) {
       return;
   }
   for(int i = 0; i < size; i++){
       StergeIndex(i);
   }

}

// functie care arata nr. de elemente din multime (cardinalul)
int Multime::nrElem() {return nr_elem;}



