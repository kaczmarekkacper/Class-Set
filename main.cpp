/* Kacper Kaczmarek
Klasa reprezentujaca zbior liczb rzeczywistych plik main.cpp */

#include <iostream>
#include "SET.h"

using namespace std;

int main()
{
    char set;
    int sizeA, sizeB;
    int option = 0;
    long double element;
    volatile bool conditions = ( reinterpret_cast<int> (option) < 14 && reinterpret_cast<int> (option) > 0 ) ;
    cout << "How many element should Set A contain? ";
    cin >> sizeA;
    while ( cin.fail() )
    {
        cout << "Wrong value." << endl;
        cin.clear();
        cin.ignore( 1000, '\n');
        cout << "How many element should Set A contain? ";
        cin >> sizeA;
    }
    cin.ignore( 1000, '\n' );
    Set A( sizeA );
    cout << "How many element should Set B contain? ";
    cin >> sizeB;
    while ( cin.fail() )
    {
        cout << "Wrong value." << endl;
        cin.clear();
        cin.ignore( 1000, '\n');
        cout << "How many element should Set B contain? ";
        cin >> sizeB;
    }
    cin.ignore( 1000, '\n' );
    Set B( sizeB );
    Set C( sizeA+sizeB );
    do
    {
        cout << "What do you want to do with Sets?" << endl;
        cout << "1.Add element.\t2.Remove element\n";
        cout << "3.Check if element added\t4. Chceck amount\n";
        cout << "5.A+B\t 6. A+=B\n";
        cout << "7.A-B\t 8. A-=B\n";
        cout << "9.A*B\t 10. A*=B\n";
        cout << "11. A==B\t 12. A!=B\n";
        cout << "13. << A \n";
        cout << "Your choice: ";
        cin >> option;
        switch ( option )
        {
        case 1:
            cout << "Give element: ";
            cin >> element;
            while ( cin.fail() )
            {
                cout << "Wrong value." << endl;
                cin.clear();
                cin.ignore( 1000, '\n');
                cout << "Give element: ";
                cin >> element;
            }
            cin.ignore( 1000, '\n' );
            cout << "Set A or B?" << endl;
            cin >> set;
            while ( set != 'A' && set != 'B' && cin.fail() )
            {
                cout << "Wrong value." << endl;
                cin.clear();
                cin.ignore( 1000, '\n');
                cout << "Set A or B? ";
                cin >> set;
            }
            cin.ignore(1000, '\n' );
            if ( set == 'A' )
            {
                if ( A.add( element) )
                    cout << "Successfully added." << endl;
                else
                    cout << "Failed." << endl;
            }
            else
            {
                if ( B.add( element) )
                    cout << "Successfully added." << endl;
                else
                    cout << "Failed." << endl;
            }
            break;
        case 2:
            cout << "Give element: ";
            cin >> element;
            while ( cin.fail() )
            {
                cout << "Wrong value." << endl;
                cin.clear();
                cin.ignore( 1000, '\n');
                cout << "Give element: ";
                cin >> element;
            }
            cin.ignore( 1000, '\n' );
            cout << "Set A or B?" << endl;
            cin >> set;
            while ( (set != 'A' && set != 'B') || cin.fail() )
            {
                cout << "Wrong value." << endl;
                cin.clear();
                cin.ignore( 1000, '\n');
                cout << "Set A or B? ";
                cin >> set;
            }
            cin.ignore(1000, '\n' );
            if ( set == 'A' )
            {
                if ( A.remove( element) )
                    cout << "Successfully removed." << endl;
                else
                    cout << "Failed." << endl;
            }
            break;
        case 3:
            cout << "Give element: ";
            cin >> element;
            while ( cin.fail() )
            {
                cout << "Wrong value." << endl;
                cin.clear();
                cin.ignore( 1000, '\n');
                cout << "Give element: ";
                cin >> element;
            }
            cin.ignore( 1000, '\n' );
            cout << "Set A or B?" << endl;
            cin >> set;
            while ( (set != 'A' && set != 'B') || cin.fail() )
            {
                cout << "Wrong value." << endl;
                cin.clear();
                cin.ignore( 1000, '\n');
                cout << "Set A or B? ";
                cin >> set;
            }
            cin.ignore(1000, '\n' );
            if ( set == 'A' )
            {
                if ( A.check( element) )
                    cout << "Element belong to the set." << endl;
                else
                    cout << "Element doesnt belong to the set." << endl;
            }
            break;
        case 4:
            cout << "Set A or B?" << endl;
            cin >> set;
            while ( (set != 'A' && set != 'B') || cin.fail() )
            {
                cout << "Wrong value." << endl;
                cin.clear();
                cin.ignore( 1000, '\n');
                cout << "Set A or B? ";
                cin >> set;
            }
            set == 'A' ? cout << A.amount() : cout << B.amount();
            cout << endl;
            break;
        case 5:
            C = A + B;
            cout << C;
            break;
        case 6:
            A+=B;
            cout << A;
            break;
        case 7:
            C = A - B;
            cout << C;
            break;
        case 8:
            A-=B;
            cout << A;
            break;
        case 9:
            C=A*B;
            cout << C;
            break;
        case 10:
            A*=B;
            cout << A;
            break;
        case 11:
            cout << ( A == B ) << endl;
            break;
        case 12:
            cout << ( A != B ) << endl;
            break;
        case 13:
            cout << "Set A or B?" << endl;
            cin >> set;
            while ( (set != 'A' && set != 'B') || cin.fail() )
            {
                cout << "Wrong value." << endl;
                cin.clear();
                cin.ignore( 1000, '\n');
                cout << "Set A or B? ";
                cin >> set;
            }
            set == 'A' ? cout << A : cout << B;
            cout << endl;
            break;
        default:
            cout << "Choose right option." << endl;
        }
    }
    while ( !conditions );
    A.delete_set();
    B.delete_set();
    C.delete_set();
    return 0;
}
