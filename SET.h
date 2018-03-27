/* Kacper Kaczmarek
 Klasa reprezentujaca zbior liczb rzeczywistych plik SET.h */


#ifndef SET_H_INCLUDED
#define SET_H_INCLUDED

using namespace std;

class Set
{
    long double *element;
    int first_free_index;
    int size;
public:
    Set( int = 0);
    ~Set();
    bool add ( long double); // dodawanie elementu do zbioru
    bool remove ( long double); // uswanie
    bool check ( long double) const; // sprawdzanie czy dany element nalezy do zbiory
    int amount() const; // zwraca ilosc zapelnionego miejsca
    int check_size() const; // sprawdza rozmiar
    int same_objects ( Set const &B ); // zwraca ile jest takich samych elementow
    Set operator+ ( Set const &B ); // dodaje elementy
    Set operator+= ( Set const &B );
    Set operator- ( Set const &B );
    Set operator-= ( Set const &B );
    Set operator* ( Set const &B );
    Set operator*= ( Set const &B );
    bool operator== ( Set const &B );
    bool operator!= ( Set const &B );
    void operator= ( Set const &B );
    friend ostream& operator<<( ostream &, Set &); // wysiwetla zbior
};

#endif // SET_H_INCLUDED
