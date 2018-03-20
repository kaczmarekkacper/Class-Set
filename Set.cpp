/* Kacper Kaczmarek
Klasa reprezenujaca zbior liczb rzceywistych plik Set.cpp */

#include <iostream>
#include "SET.h"

using namespace std;

    Set::Set( int number )
    {
        first_free_index = 0;
        element = new long double[ number ];
        size = number;
    }
    bool Set::add ( long double new_element )
    {
        if ( size > first_free_index )
        {
            if ( !check( new_element ) )
            {
                element[first_free_index] = new_element;
                first_free_index++;
                return true;
            }
        }
        return false;

    }
    bool Set::remove ( long double new_element )
    {
        bool already_added = false;
        int index;
        for (int i=0 ; i < first_free_index ; i++ )
        {
            if ( new_element == element[i] )
            {
                already_added = true;
                index=i;
            }
        }
        if ( already_added )
        {
            swap( element[index], element[first_free_index-1] );
            first_free_index--;
        }
        return already_added;
    }

    bool Set::check ( long double new_element )
    {
        if ( first_free_index )
        {
            for ( int i=0 ; i < first_free_index ; i++ )
            {
                if ( element[i] == new_element )
                    return true;
            }
        }
        return false;
    }

    int Set::amount ( void )
    {
        return first_free_index;
    }
    int Set::check_size ( void )
    {
        return size;
    }
    int Set::same_objects ( Set B )
    {
        int how_many=0;
        for ( int i = 0 ; i < B.first_free_index ; i++ )
            if ( check( B.element[i] ) )
                how_many++;
        return how_many;
    }

    Set Set::operator+ ( Set B )
    {
        Set C( amount() + B.amount() - same_objects( B ) );
        for ( int i = 0 ; i < first_free_index ; i++ )
            C.add( element[i] );
        for ( int i = 0 ; i < B.first_free_index ; i++ )
            C.add( B.element[i] );
        return C;
    }
    Set Set::operator+= ( Set B )
    {
        if ( size >= amount() + B.amount() )
        {
            for ( int i = 0 ; i < B.first_free_index ; i++ )
                add( B.element[i] );
        }
        return *this;
    }
    Set Set::operator- ( Set B )
    {
        Set C( ( amount()>B.amount() ? amount() : B.amount() ) - same_objects( B ) );
        for ( int i = 0 ; i < first_free_index ; i++)
        {
            if ( !B.check( element[i] ))
                C.add ( element[i] );
        }
        return C;
    }
    Set Set::operator-= ( Set B )
    {

        for ( int i = 0 ; i < B.first_free_index ; i++)
            if ( check( B.element[i] ) )
                remove( B.element[i] );
        return *this;
    }
    Set Set::operator* ( Set B )
    {
        Set C( same_objects( B ) );
        for ( int i = 0 ; i < B.first_free_index ; i++)
            if ( check( B.element[i] ) )
                C.add ( B.element[i] );
        return C;
    }
    Set Set::operator*= ( Set B )
    {

        for ( int i = 0 ; i < first_free_index ; i++)
        {
            if ( !B.check( element[i] ) )
                remove( element[i] );
        }
        return *this;
    }
    bool Set::operator== ( Set B )
    {
        for ( int i = 0 ; i < B.first_free_index ; i++ )
        {
            if ( check( B.element[i] ) )
                continue;
            return false;
        }
        for ( int i = 0 ; i < first_free_index ; i++ )
        {
            if ( B.check( element[i] ) )
                continue;
            return false;
        }
        return true;
    }
    bool Set::operator!= ( Set B)
    {
        return !( *this == B );
    }
    Set Set::operator= ( Set B )
    {
        if ( size >= B.amount() )
        {
            first_free_index = 0;
            for ( int i = 0 ; i < B.amount() ; i++ )
            add( B.element[i] );
        }
        return B;
    }
    void Set::delete_set ( )
    {
        delete[] element;
    }
    ostream& operator<<( ostream &stream, Set &B )
    {
        cout << "Set:" << endl;
        for ( int i = 0 ; i < B.amount() ; i++ )
        {
            stream << B.element[i] << " ";
            if ( !(i%10) && i!=0 )
                cout << endl;
        }
        cout << endl;
        return stream;
    }
