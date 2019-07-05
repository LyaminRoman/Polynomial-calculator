#include <iostream>
#include <algorithm>
#include "Header.h"

using namespace std;

Polynom::Polynom(int degree, double* coef) : coef(coef), degree(degree) {}

Polynom::Polynom(const Polynom& P) : degree(P.degree)
{
	this->coef = new double[this->degree + 1];

	for (int i = 0; i <= this->degree; i++)
		this->coef[i] = P.coef[i];
}

Polynom::~Polynom()
{
	if (this->coef)
		delete[] this->coef;
	this->coef = nullptr;
	return;
}

int Polynom::GetDegree()
{
	return this->degree;
}

double Polynom::GetCoef(int i)
{
	return this->coef[i];
}

void Polynom::SetCoef(double x, int i)
{
	this->coef[i] = x;
}

void Polynom::PrintPolynomial()
{
	bool flag = false;

	for (int i = 0; i <= this->degree; i++)
	{
		if (this->coef[i] == 0) continue;

		if (this->coef[i] < 0 && flag == false) cout << " - ";
		flag = true;

		if (this->coef[i] != 1 && this->coef[i] != -1 || i == this->degree)
			cout << abs(this->coef[i]);

		if (i == this->degree) continue;

		if (i == this->degree - 1)
		{
			cout << "X";
			if (this->coef[i + 1] != 0)
			{
				this->coef[i + 1] < 0 ? cout << " - " : cout << " + ";
			}
		}
		else
		{
			cout << "X^" << this->degree - i;
			int j = i + 1;
			while (coef[j] == 0 && j != this->degree)
			{
				j++;
			}
			if (coef[j] != 0) this->coef[j] > 0 ? cout << " + " : cout << " - ";
		}
	}
	if (!flag) cout << "0";
	cout << endl;
}

void Polynom::ForAddition(const Polynom & a, double* coef) const
{
	int md = this->degree;

	for (int i = 0; i <= md; i++)
	{
		coef[i] = this->coef[i];
	}

	for (int i = 0; i <= a.degree; i++)
	{
		coef[md - i] += a.coef[a.degree - i];
	}
}

Polynom Polynom::Addition(const Polynom & a) const
{
	int md = max(a.degree, this->degree);
	double* coef = new double[md + 1];

	(this->degree > a.degree) ? this->ForAddition(a, coef) : a.ForAddition(*this, coef);

	return Polynom(md, coef);
}

Polynom Polynom::Subtraction(const Polynom & a) const
{
	int md = max(a.degree, this->degree);
	double* coef = new double[md + 1];

	for (int i = 0; i <= md; i++)
	{
		coef[i] = 0;
	}

	for (int i = 0; i <= a.degree; i++)
	{
		coef[md - i] = a.coef[a.degree - i] * (-1);
	}

	for (int i = 0; i <= this->degree; i++)
	{
		coef[md - i] += this->coef[this->degree - i];
	}

	return Polynom(md, coef);
}

Polynom Polynom::Multiplication(const Polynom & a) const
{
	int md = a.degree + this->degree;
	double* coef = new double[md + 1];

	for (int i = 0; i <= md; i++)
		coef[i] = 0;

	for (int i = 0; i <= this->degree; i++)
		for (int j = 0; j <= a.degree; j++)
		{
			int k = i + j;
			coef[k] += this->coef[i] * a.coef[j];
		}

	return Polynom(md, coef);
}