#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

//#define INCREMENT_CHECK
//#define ARIFMETICAL_OPERATORS_CHECK
//#define COMPAUND_ASSIGNMENTS_CHECK
//#define OPTIMIZASION_CHECK
//#define TYPE_CONVERSIONS
#define TYPE_CONVERSIONS_HOME_WORK

class Fraction;// Class Declaration
Fraction operator*(Fraction left, Fraction right);

class Fraction
{
	int integer;//����� �����
	int numerator;//���������
	int denominator;//�����������
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
		if (denominator == 0)denominator = 1;// ���������� ������
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
	 explicit Fraction(int integer)
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
	Fraction (const Fraction& other)// ��������� ����������� ������
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
	Fraction& operator = (const Fraction& other)// �������� ������������
	{
		this->integer = other.integer;
	this-> numerator = other.numerator;
	this->denominator = other.denominator;
	cout << "CopyAssignment:\t" << this << endl;
	return *this;
	}
	Fraction& operator*=(const Fraction& other)
	{
		/*int a = 2;
		int b = 3;
		a *= b;
		a = a * b;
		*/
		return *this = *this * other;
	}
	Fraction& MultiplyAndAssign(const Fraction& other)
	{
		/*int a = 2;
		int b = 3;
		a *= b;
		a = a * b;
		*/
		return *this = *this * other;
		// ���������� ��������� �������� �� �������, ��������� ��������� ����������� � this
		//������������� this �������� �����������
		//this-��������� �� ������, ��� �������� ���������� �����
		//��� ����, �����  ������� �����, ������ ������ ����  ��� ������
		// �� ���� ������ ���������� ������, ��� ��� ���� ���������� �����
		// � ����� ���� ��� ����� ��������� � �������� ��� �������� �� �������� (this)
		//������ �� ����������, �� ������ �� �������� � �� ���������, ��� ��� ������� 
		//����� ������� ������ ����������
		//��������� ���� ������ ������ �� �������� ����� ��������� ������,�� ����� ������� ��� �� ������
		// (by reference), ����� �� ��������� ����� ����� �������
	}

	//Increment/Decrement

	Fraction& operator++()// �������
	{
		integer++;
		return*this;
	}
	Fraction operator++(int)//��������
	{
		Fraction old = *this;//��������� ������ ��������
		integer++;
		return old;// CopyConstructor
	}
	Fraction& operator--()// ���������
	{
		integer--;
		return *this;
	}
	Fraction operator--(int)	//���������
	{
		Fraction old = *this;
		integer--;
		return old;
	}

	//Type-cast operators:
	explicit operator int()
	{
		return integer;

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

	Fraction& to_improrer()// ��������� ������
	{
		numerator += integer * denominator;
		integer = 0;
		return*this;
	}

	Fraction& to_proper()
	{
		integer += numerator / denominator;
		numerator %= denominator;
		return*this;
	}
	Fraction inverted()// �������� �����
	{
		to_improrer();
		//int buffer = numerator;
		//numerator = denominator;
		//denominator = buffer;
		//return*this;
		return Fraction(denominator, numerator);
	}
};




Fraction operator+(Fraction left, Fraction right)
{
	left.to_improrer();
	right.to_improrer();
	//Fraction sum
	//(
	//	left.get_numerator() * right.get_denominator() + right.get_numerator() * left.get_denominator(),
	//left.get_denominator() * right.get_denominator()
	//);
		//sum.to_proper();
		//return sum;
	return Fraction// ��������� ���������� ������
	(
		left.get_numerator() * right.get_denominator() + right.get_numerator() * left.get_denominator(),
		left.get_denominator() * right.get_denominator()
	).to_proper();

}

Fraction operator*(Fraction left, Fraction right)
{
	left.to_improrer();
	right.to_improrer();
	//Fraction result;
	//result.set_numerator(left.get_numerator() * right.get_numerator());
	//result.set_denominator(left.get_denominator() * right.get_denominator());
	//Fraction result
	//(
		//left.get_numerator() * right.get_numerator(),
		//left.get_denominator() * right.get_denominator()
	//);
	//return result;
	// 
	// Result- ��� ��������� ������, �� �������� � ������� operator*
	//� ���������� ������ � ���� ������� � �� ���������� ���� �������
	//result ����� ������ �� ������, � ����� ������� ������ �� ���� ��������� ������, �� �� ����� ������
	//�� ������� �����
	// ������� ���������� ������ �� ��������, ����� ����������� ��� �� ����� ������
	return Fraction// ����� ���� �������� �����������, ������� ������� ��������� ���������� ������ � ������ ��� �����������
	(
		left.get_numerator() * right.get_numerator(),
		left.get_denominator() * right.get_denominator()
	);
}

Fraction  operator/(Fraction left, Fraction right)
{
	//left.to_improrer();
	//right.to_improrer();
	//Fraction result
	//(
	//	left.get_numerator() * right.get_denominator(),
		//left.get_denominator() * right.get_denominator()
	//);
	//return result;
	Fraction result = left * right.inverted();
	return result;
	//return left*right.inverted();
}

//#define CONSTRUCTORS_CHECK
void main()
{
	setlocale(LC_ALL, "Russian");
#ifdef CONSTRUCTORS_CHECK
	Fraction A;// Default
	A.print();
	Fraction B = 3;
	B.print();// constructor c 1 ����������
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

#ifdef ARIFMETICAL_OPERATORS_CHECK


	int a = 2;
	int b = 3;
	int c = a * b;
	int d = a / b;
	int e = a + b;

	Fraction A(2, 3, 4);
	Fraction B(3, 4, 5);
	Fraction C = A * B;
	C.print();
	Fraction D = A / B;
	D.print();

	Fraction E = A + B;
	E.print();
	//A.print();
	//A.to_improrer();
	//A.print();
	//A.to_proper();
	//A.print();

	(A + B).print();

#endif // ARIFMETICAL_OPERATORS_CHECK

#ifdef INCREMENT_CHECK

	for (double i = .25; i < 10; i++)
	{
		cout << i << "\t";
	}
	cout << endl;

	for (Fraction i(1, 4); i.get_integer() < 10; i++)
	{
		i.print();
	}
	cout << endl;
#endif

#ifdef COMPAUND_ASSIGNMENTS_CHECK

	Fraction A(2, 3, 4);
	Fraction B(3, 4, 5);
	A *= B;// ������� ����� ��������� implicit
	A.operator*=(B);//����� ����� explicit operator call
	A.MultiplyAndAssign(B);
	A.print();

	A* B;// �������	 ����� ���������
	operator*(A, B);// ����� ����� ���������
#endif



#ifdef OPTIMISATION_CHECK
	Fraction A(2, 3, 4);
	Fraction B(3, 4, 5);
	Fraction C = A * B;
	C.print();
#endif // OPTIMISATION_CHECK

#ifdef TYPE_CONVERSIONS
	//int a = 2;// no conversion ��� ��������������
//double b = 3;// from int to double (From less to more)
//int c = 4.5;// from double to int (from more to less with data loss)
//int d = b;// from double to int( from more to less no data loss)
//int e = 5.3;
//int f = a + e;
//cout << f;

//OTHER TYPES TO OUR TYPE

	int a = 2;
	Fraction A = (Fraction)5;// from int to Fraction from less to more
	A.print();
	Fraction B;
	B = (Fraction)3;
	B.print();

	//OUR OBJECTS TO OTHER TYPES
	// operator type()
	//{
	//}
	int b = (int)B;
	cout << b << endl;
#endif // TYPE_CONVERSIONS
	// Task 1
//	Fraction A(2, 3, 4);
//	double b = A;
//	cout << a << endl;
//	//Task 2
//	double b = 3.14;
//	Fraction B = b;
//	B.print();
//
//};
