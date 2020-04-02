#ifndef LAB_OOP_MULTIME_H
#define LAB_OOP_MULTIME_H


class Multime {
private:
    int size;
    int nr_elem;
    int* arr;

    void Extindere();
    void Micsorare();
    void Initializare(int val);
public:
    Multime();
    Multime(int size);
    Multime(const Multime &other);
    ~Multime();

    int nrElem();
    int Index(int index);
    void Adauga(int val);
    void Sterge(int val);
    void Unificare();
    void Sortare();
    int Cautare(int val, int stanga, int dreapta);
    void Afisare();
};


#endif //LAB_OOP_MULTIME_H
