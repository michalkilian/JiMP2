#include "XXX.h"

XXX::XXX() : name_{new char[1024]} {

}


//1. konstruktor kopiujący
XXX::XXX(const XXX& xxx) {
    size_t sz = strlen(xxx.name_);
    name_ = new char[sz];
    strcpy(name_,xxx.name_);
    //Teraz nowy obiekt pokazuje na nowy fragment pamięci,
    //ale ze skopiowaną informacją
}

//2.konstruktor przenoszący:
XXX::XXX(XXX &&xxx) : name_{nullptr} {
    swap(name_,xxx.name_);
    //Bardzo popularna szutczka
    //wiemy, ze za chwilę xxx zostanie zniszczony
    //za pomocą destrukotra, więc inicjalizujemy
    //this na nullptr i wymieniamy się z xxx
    //delete nullptr jest bezpieczna operacją i nic się nie stanie...
}

//3. operator przypisania kopiujący
XXX & XXX::operator=(const XXX& xxx) {
    //jeśli ktoś wpadł na pomysł x = x;
    if (this == &xxx) {
        return *this;
    }
    //w przyciwynym wypadku mamy x = y;
    //musimy sami zwolnic pamięć po x (czyli this):
    delete[] name_;
    //i wreszcie kopiowanie, ten kod jest
    //jest identyczny więc można by go wydzielić do innej metody...
    size_t sz = strlen(xxx.name_);
    name_ = new char[sz];
    strcpy(name_,xxx.name_);
}


//4. operator przypisania przenoszący
XXX & XXX::operator=(XXX &&xxx) {
    //jeśli ktoś wpadł na pomsył x = move(x);
    if (this == &xxx) {
        return xxx;
    }
    //w przyciwynym wypadku mamy x = move(y);
    //musimy sami zwolnic pamięć po x (czyli this):
    delete[] name_;
    //i wreszcie przenosimy stan, ten kod jest
    //jest identyczny więc można by go wydzielić do innej metody...
    name_ = nullptr;
    swap(name_,xxx.name_);
}

XXX::~XXX() {
    delete [] name_;
}