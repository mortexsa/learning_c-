#include <iostream>
#include "ZFraction.h"
using namespace std;

int main()
{
	int pgcd;
    ZFraction a(4,4);      //Déclare une fraction valant 4/5
    ZFraction b(4);        //Déclare une fraction valant 2/1 (ce qui vaut 2)
    ZFraction c,d;         //Déclare deux fractions valant 0
    cout <<"a vaut : "<< a <<" et b vaut : "<<b<<"\n\n\n\n\n\n\n"<<endl; 
    b += a;
    cout <<"a vaut : "<< a <<" et b vaut : "<<b<<"\n\n\n\n\n\n\n"<<endl; 
    c = a + b;
    cout <<"a vaut : "<< a <<" et b vaut : "<<b<<" et c vaut : "<<c<<endl; 
    /*c = a+b;               //Calcule 4/5 + 2/1 = 14/5

    d = a*b;               //Calcule 4/5 * 2/1 = 8/5

    cout << a << " + " << b << " = " << c << endl;

    cout << a << " * " << b << " = " << d << endl;

    if(a > b)
        cout << "a est plus grand que b." << endl;
    else if(a==b)
        cout << "a est egal a b." << endl;
    else
        cout << "a est plus petit que b." << endl;
*/
    return 0;
}