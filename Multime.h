#ifndef LAB_OOP_MULTIME_H
#define LAB_OOP_MULTIME_H
using namespace std;

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
    explicit Multime(int size);
    Multime(const Multime &other);
    ~Multime();

    int nrElem();
    int Index(int index);
    void Adauga(int val);
    void Sterge(int val);
    void StergeIndex(int index);
    void Unificare();
    void Sortare();
    int Cautare(int val, int stanga, int dreapta);
    void Afisare();
    void Golire();

    friend istream& operator>>(istream &in, Multime& multime);
    friend ostream& operator<<(ostream &out, Multime& multime);
    Multime& operator=(const Multime& other);
    int& operator[](int pos);
    Multime& operator+(const Multime& other);
    Multime& operator-(const Multime& other);
    bool operator<(const Multime& other);
    bool operator>(const Multime& other);

};


#endif //LAB_OOP_MULTIME_H
