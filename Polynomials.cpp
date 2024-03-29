// Polynomials.cpp: определяет точку входа для консольного приложения.
//

#include "Header.h"
#include <iostream>
#include <conio.h>

using namespace std;

int EnterDegree(int flag)
{
	int degree;
	do {
		switch (flag)
		{
		case 1:
		{
			cout << "Enter the degree of the first polynomial" << endl;
			break;
		}
		case 2:
		{
			cout << "Enter the degree of the second polynomial" << endl;
			break;
		}
		case 3:
		{
			cout << "Enter the degree of the polynomial" << endl;
			break;
		}
		}
		cin >> degree;
	} while (degree < 1);

	return degree;
}

double* EnterCoef(int degree)
{
	cout << "Enter the coefficients" << endl;
	double *arr = new double[degree + 1];
	double c;

	for (int i = degree; i >= 0; i--)
	{
		if (i != 0)
			cout << "X^" << i << ": ";
		else
			cout << "Const: ";
		cin >> c;
		arr[degree - i] = c;
		_CrtCheckMemory();
	}
	cout << endl;

	return arr;
}

int Menu()
{
	int v = 0;
	do {
		cout << "Enter the menu item" << endl << endl;
		cout << "1 - Calculating the polynomial value for the argument" << endl;
		cout << "2 - Addition of polynomials" << endl;
		cout << "3 - Subtracting polynomials" << endl;
		cout << "4 - Multiplication of polynomials" << endl;
		cout << "0 - Exit" << endl << endl;
		cout << "Your choice: ";
		cin >> v;
		cout << endl;
	} while (!(v >= 0 && v <= 4));
	return(v);
}

int main()
{
	int deg1;
	int deg2;
	while (true)
	{
		int choice = Menu();
		if (choice == 0) exit(0);
		if (choice == 1)
		{
			int deg1 = EnterDegree(3);
			Polynom a(deg1, EnterCoef(deg1));
			system("cls");

			cout << "Entered polynomial: ";
			a.PrintPolynomial();

			cout << "Enter argument" << endl;
			double x, res = 0;
			cin >> x;

			for (int i = 0; i <= a.GetDegree(); i++)
			{
				res += a.GetCoef(i) * pow(x, a.GetDegree() - i);
			}
			cout << "The polynomial with the entered argument is " << res << endl;
			_getch();
			system("cls");
			continue;
		}

		deg1 = EnterDegree(1);
		Polynom a(deg1, EnterCoef(deg1));
		deg2 = EnterDegree(2);
		Polynom b(deg2, EnterCoef(deg2));

		system("cls");

		cout << "First entered polynomial: ";
		a.PrintPolynomial();
		cout << "Second entered polynomial:	";
		b.PrintPolynomial();

		switch (choice)
		{
		case 2:
		{
			cout << "The result of the addition of polynomials:	";
			Polynom c = a.Addition(b);
			c.PrintPolynomial();
			_getch();
			break;
		}
		case 3:
		{
			cout << "The result of the subtraction of polynomials: ";
			Polynom c = a.Subtraction(b);
			c.PrintPolynomial();
			_getch();
			break;
		}
		case 4:
		{
			cout << "The result of the multiplication of polynomials: ";
			Polynom c = a.Multiplication(b);
			c.PrintPolynomial();
			_getch();
			break;
		}
		}

		system("cls");
	}

	_getch();
	return 0;
}