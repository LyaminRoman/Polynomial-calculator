#pragma once
class Polynom
{
	int degree;
	double* coef;

public:

	Polynom(int degree, double* coef);
	Polynom(const Polynom& P);

	~Polynom();

	void PrintPolynomial();
	int GetDegree();
	double GetCoef(int i);
	void SetCoef(double x, int i);

	Polynom Addition(const Polynom& a) const;
	Polynom Subtraction(const Polynom& a) const;
	Polynom Multiplication(const Polynom& a) const;

private:
	void ForAddition(const Polynom& a, double* coef) const;
};