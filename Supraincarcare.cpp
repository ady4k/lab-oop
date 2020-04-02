#include "Multime.cpp"

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

ostream& operator<<(ostream &out, Multime& multime){
    for(int i = 0; i < multime.nr_elem; i++)
        out << multime.arr[i] << ' ';
    return out;
}

Multime& Multime::operator=(const Multime& other){
    if (other.nr_elem > 0){
        Golire();

        for(int i  = 0; i < other.nr_elem; i++)
            Adauga(other.arr[i]);
    }
    return *this;
}


int &Multime::operator[](int pos) {
    return arr[pos];
}

Multime& Multime::operator+(const Multime& other){

}

Multime& Multime::operator-(const Multime& other){

}