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
    for(int i = 0; i < other.nr_elem; i++)
        Adauga(other.arr[i]);
    return *this;
}

Multime& Multime::operator-(const Multime& other){
    int i = 0;
    int j = 0;
   /* while(i < nr_elem && j < other.nr_elem) {
        if (arr[i] < other.arr[j]) {
            i++;
        } else if (arr[i] > other.arr[j]) {
            j++;
        } else if (arr[i] == other.arr[i]) {
            Sterge(arr[i]);
            j++;
        }
    }
    while(i < nr_elem) {
        if (arr[i] == other.arr[j]) {
            Sterge(arr[i]);
            break;
        } else {
            i++;
        }
    }
    while(j < other.nr_elem) {
        if (arr[i] == other.arr[j]) {
            Sterge(arr[i]);
            break;
        } else {
            j++;
        }
    }
    */
   for(i = 0; i < nr_elem; i++)
       for(j = 0; j < other.nr_elem; j++) {
           if (arr[i] == other.arr[j]) {
               Sterge(arr[i]);
               i--;
           }
       }
    return *this;
}

bool Multime::operator>(const Multime& other) {
    return nr_elem > other.nr_elem;
}

bool Multime::operator<(const Multime& other) {
    return nr_elem < other.nr_elem;
}