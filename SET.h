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
    Set( int);
    bool add ( long double);
    bool remove ( long double);
    bool check ( long double);
    int amount ( void );
    int check_size ( void );
    int same_objects ( Set);
    Set operator+ ( Set );
    Set operator+= ( Set );
    Set operator- ( Set );
    Set operator-= ( Set );
    Set operator* ( Set );
    Set operator*= ( Set );
    bool operator== ( Set );
    bool operator!= ( Set );
    Set operator= ( Set );
    void delete_set ( void );
    friend ostream& operator<<( ostream &, Set &);
};

#endif // SET_H_INCLUDED
