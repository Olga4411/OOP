#include<iostream>
using namespace std;

class Fraction
{
	int integer;//целая часть
	int numerator;//числитель
	int denominator;//знаменатель
public:
	int get_integer()const
	{
		return integer;
	}
	int get_numerator()const
		{
			return numerator;
		}
	int get_denominator()const
		{
			return denominator;
		}
	void set_integer(int integer)
	{
		this->integer = integer;
	}
	void set_numerator(int numerator)
	{
		this->numerator = numerator;
	}
	void set_denominator(int denominator)
	{
		if (denominator == 0)denominator = 1;// Фильтрация данных
		this->denominator = denominator;
	}

	//Constructors

	Fraction()
	{
		this->integer = 0;
		this->numerator = 0;
		this->denominator = 1;
		cout << "DefaultConstructor:" << this << endl;
	}
	Fraction(int integer)
	{
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
		cout << "1argConstructor:" << this << endl;
	}
	Fraction(int numerator,int denominator)
	{
		this->integer = 0;
		this->numerator = numerator;
		this->set_denominator(denominator);
		cout << "Constructor:\t" << this << endl;
	}

	Fraction(int integer , int numerator, int denominator)
	{
		this->integer = integer;
		this->numerator = numerator;
		this-> set_denominator(denominator);
		cout << "Constructor:\t" << this << endl;

	}
	Fraction (const Fraction& other)// принимает константную ссылку
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyConstructor:" << this << endl;
	}
	~Fraction()
	{
		cout << "Destructor:\t" << this << endl;
	}
	//Operators:
	Fraction& operator = (const Fraction& other)// Оператор присваивания
	{
		this->integer = other.integer;
	this-> numerator = other.numerator;
	this->denominator = other.denominator;
	cout << "CopyAssignment:\t" << this << endl;
	return *this;
	}

	
	// Metohds
	void print()const
	{
		if (integer)cout << integer;
		if (integer && numerator)cout << "(";
		if (numerator)cout << numerator << "/" << denominator;
		if (integer && numerator)cout << ")";
		if (integer == 0 && numerator == 0) cout << 0;
		cout << endl;
	}

};

//#define CONSTRUCTORS_CHECK
void main()
{
	setlocale(LC_ALL, "Russian");
#ifdef CONSTRUCTORS_CHECK
	Fraction A;// Default
	A.print();
	Fraction B = 3;
	B.print();// constructor c 1 параметром
	Fraction C(3, 4);
	C.print();
	Fraction D(2, 3, 4);
	D.print();

	Fraction E = D;// CopyConstructor
	E.print();

	Fraction F;// Default constructor
	F = E;// operator= (CopyAssignment)
	F.print();
#endif

};
