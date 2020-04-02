#include "Multime.h"
#include <iostream>
#include <stdexcept>
 using namespace std;

Multime::Multime(){
    nr_elem = 0;
    size = 0;
}

Multime::Multime(int size): size(size) {
    nr_elem = 0;
    arr = new int[size];
    Initializare(nr_elem);
}

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

Multime::~Multime(){
    delete[] arr;
}

void Multime::Initializare(int val) {
    for (int i = val; i < size; ++i) {
        arr[i] = 0;
    }
}

void Multime::Extindere(){
    size += 1;
    int* tempArr = new int[size];
    for(int i = 0; i < size; i++)
        tempArr[i] = arr[i];
    delete[] arr;
    arr = tempArr;
    Initializare(nr_elem);
}

void Multime::Micsorare(){
    size -= 1;
    int* tempArr = new int[size];
    for(int i = 0; i < size; i++)
        tempArr[i] = arr[i];
    delete[] arr;
    arr = tempArr;

}

void Multime::Adauga(int val) {
    if (nr_elem >= size)
        Extindere();
    arr[nr_elem++] = val;
    if(nr_elem >= 2){
        Sortare();
        Unificare();
    }
}

void Multime::Sterge(int val) {
    int element =  Cautare(val, 0, nr_elem);
    for(int i = element; i < size-1; i++) {
        arr[i] = arr[i+1];
    }
    nr_elem--;
    Micsorare();
}

int Multime::Index(int index){
    if (index < 0 || index >= size)
        throw "index out of range";
    return arr[index];
}

void Multime::Unificare(){
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

void Multime::Sortare(){
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

int Multime::Cautare(int val, int stanga, int dreapta){
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

void Multime::Afisare(){
    for(int i = 0; i < nr_elem; i++)
        cout << "elementul " << i << ':' << ' ' << arr[i] << '\n' ;
}

void Multime::Golire(){
   if (nr_elem == 0) {
       return;
   }
   for(int i = 0; i < size; i++){
       arr[i] = 0;
   }
   nr_elem = 0;
}

int Multime::nrElem(){return nr_elem;}



