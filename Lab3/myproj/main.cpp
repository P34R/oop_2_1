#include <tchar.h>
#include <iostream>

#include "..\include\symbolicc++.h"

using namespace std;

int main()
{
	char x_[100];
	cout << "enter y=f(x): ";
	cin.getline(x_, 100);
	auto x = Symbolic(x_);
	auto x1 = Symbolic("x");
	cout << "df: " << df(x_,x1) << endl; //differencial
	cout << "integral: " << integrate(x_,x1) << endl; // integral ot f(x) po x
	Symbolic z("z");
	cout << int(((z - 2) ^ 2) - z * (z - 4))<< endl;
	cout << int(((z - 2) ^ 2) - z * (z - 4.0))<< endl;
	cout << double(((z - 2.0) ^ 2) - z * (z - 4))<< endl;
	/*
	Some documentation things

	Symbolic zero; // default value is 0

	Symbolic int_one1(1), int_one2 = 1; // construction from int

	Symbolic dbl_one1(1.0), dbl_one2 = 1.0; // construction from double

	Symbolic half = Symbolic(1)/2; // fraction 1/2

	Symbolic a("a"); // symbol a

	Symbolic b("b", 3); // vector (b0, b1, b2)

	Symbolic c = b(2); // copy constructor, c = b2

	Symbolic A("A", 2, 3); // matrix A with 2 rows and 3 columns

	Symbolic d = A(1, 2); // copy constructor, d = A(1, 2);

	Symbolic e = (a, c, d); // vector (a, b2, A(1, 2))

	Symbolic B = ( ( half, a ), // matrix B = [ 1/2      a   ]
						  ( c, A(0,0) ) ); // [ b2    A(0,0) ]
	*/
	Symbolic a("a");
	Symbolic b("b");
	cout << integrate(a + 1, a) << endl; 

	cout << df(b, a) << endl;            
	cout << df(b[a], a) << endl;         
	cout << df(exp(cos(b[a])), a) << endl; 
	return 0;
}