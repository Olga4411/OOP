#define _CRT_SECURE_NO_WARNINGS//for strok
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
//#define TYPE_CONVERSIONS_HOME_WORK
//#define COMPARISON_OPERATORS
//#define OUTPUT_CHECK
#define INPUT_CHECK

class Fraction;// Class Declaration
Fraction operator*(Fraction left, Fraction right);

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
	explicit Fraction(int integer)
	{
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
		cout << "1argConstructor:" << this << endl;
	}
	Fraction(int numerator, int denominator)
	{
		this->integer = 0;
		this->numerator = numerator;
		this->set_denominator(denominator);
		cout << "Constructor:\t" << this << endl;
	}

	Fraction(int integer, int numerator, int denominator)
	{
		this->integer = integer;
		this->numerator = numerator;
		this->set_denominator(denominator);
		cout << "Constructor:\t" << this << endl;

	}
	Fraction(const Fraction& other)// принимает константную ссылку
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
		this->numerator = other.numerator;
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
		// Возвращает результат операции по сссылке, поскольку результат сохраняется в this
		//следовательно this является результатом
		//this-указатель на объект, для которого вызывается метод
		//Для того, чтобы  вызвать метод, объект должен быть  уже создан
		// то есть объект появляется раньше, чем для него вызывается метод
		// и после того как метод отработал с объектом для которого он вызвался (this)
		//ничего не происходит, он никуда не девается и не удаляется, так как объекты 
		//может удалять только деструктор
		//Поскольку этот объект никуда не девается после отработки метода,мы можем вернуть его по ссылке
		// (by reference), чтобы не создавать копию этого объекта
	}

	//Increment/Decrement

	Fraction& operator++()// префикс
	{
		integer++;
		return*this;
	}
	Fraction operator++(int)//постфикс
	{
		Fraction old = *this;//сохраняем старое значение
		integer++;
		return old;// CopyConstructor
	}
	Fraction& operator--()// Дикремент
	{
		integer--;
		return *this;
	}
	Fraction operator--(int)	//Дикремент
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
	explicit operator double()const
	{
		return integer + (double)numerator / denominator;
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

	Fraction& to_improrer()// умножение дробей
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
	Fraction inverted()// обращает дробь
	{
		to_improrer();
		//int buffer = numerator;
		//numerator = denominator;
		//denominator = buffer;
		//return*this;
		return Fraction(denominator, numerator);
	}
	Fraction& reduce()
	{
		int more, less, rest;
		if (numerator > denominator)
		{
			more = numerator;
			less = denominator;
		}
		else
		{
			less = numerator;
			more = denominator;
		}
		do
		{
			rest = more & less;
			more = less;
			less = rest;
		} while (rest);
			int GCD = more;// GCD- Greatest Common Divisor
		numerator /= GCD;
		denominator /= GCD;
		return *this;
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
	return Fraction// временный безымянный объект
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
	// Result- это локальный объект, он объявлен в функции operator*
	//и существует только в этой функции и по завершении этой функции
	//result будет удален из памяти, и ессли вернуть ссылку на этот локальный объект, то на месте вызова
	//мы получим мусор
	// поэтому возвращаем объект по значению, чтобы скопировать его на место вызова
	return Fraction// Здесь явно вызываем конструктор, который создает временный безымянный объект с нужным нам результатом
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

bool operator==(const Fraction& left, const Fraction& right)
{
	/*left.to_improrer();
	right.to_improrer();
	if (left.get_numerator * right.get_denominator == right.get_numerator * left.get_denominator());
	return true;
	else
		return false;*/
	return (double)left == (double)right;
}
bool operator!=(const Fraction& left, const Fraction& right)
{
	return !(left == right);
}
bool operator>(const Fraction& left, const Fraction& right)
{
	return (double)left > (double)right;
}
bool operator<(const Fraction& left, const Fraction& right)
{
	return (double)left < (double)right;
}
bool operator>=(const Fraction& left, const Fraction& right)
{
	// return left>right|| left==right;
	return !(left < right);// больше или равно-это не меньше
}
bool operator<=(const Fraction& left, const Fraction& right)
{
	return !(left > right);// больше или равно-это не меньше
}
ostream& operator<<(ostream& os, const Fraction& obj)
{
	if (obj.get_integer())os << obj.get_integer();
	if (obj.get_integer() && obj.get_numerator())os << "(";
	if (obj.get_numerator())os << obj.get_numerator() << "/" << obj.get_denominator();
	if (obj.get_integer() && obj.get_numerator())os << ")";
	if (obj.get_integer() == 0 && obj.get_numerator() == 0) os << 0;
    return os;
}
istream& operator>>(istream& is, Fraction& obj)
{
	/*int integer, numerator, denominator;
	is >> integer >> numerator >> denominator;
	obj.set_integer(integer);
	obj.set_numerator(numerator);
	obj.set_denominator(denominator);*/
	const int n = 32;
	char buffer[n] = {};
	char delimiters[] = "(/) +";
	char* number[5] = {};
	cin.getline(buffer, n);
	//char* pch = strtok(buffer, delimiters);
	int i = 0;
	//while (pch)
	//{
	//	//cout << pch << "\t";
	//	pch = strtok(NULL, delimiters);
 //       number[i++] = pch;
	//	//atoi- converts ANSI/ASCII
	//}
	for (char* pch = strtok(buffer, delimiters); pch; pch = strtok(NULL, delimiters), i++)
	{
		number[i] = pch;
	}

	//for (int i = 0; i < 3; i++) cout << number[i] << "\t"; cout << endl;
	//cout << buffer << endl;
	switch (i)
	{
	case 1: obj.set_integer(atoi(number[0])); break;
	case 2:obj.set_numerator(atoi(number[0]));
		obj.set_denominator(atoi(number[1]));
		break;
	case 3:
		obj.set_integer(atoi(number[0]));
		obj.set_numerator(atoi(number[1]));
		obj.set_denominator(atoi(number[2]));
		break;
	default: cout << "Error:" << endl;

	}
	return is;
}
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
	A *= B;// неявный вызов оператора implicit
	A.operator*=(B);//явный вызов explicit operator call
	A.MultiplyAndAssign(B);
	A.print();

	A* B;// неявный	 вызов оператора
	operator*(A, B);// явный вызов оператора
#endif



#ifdef OPTIMISATION_CHECK
	Fraction A(2, 3, 4);
	Fraction B(3, 4, 5);
	Fraction C = A * B;
	C.print();
#endif // OPTIMISATION_CHECK

#ifdef TYPE_CONVERSIONS
	//int a = 2;// no conversion Нет преобразований
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
	
#ifdef TYPE_CONVERSIONS_HOME_WORK
	// Task 1
	Fraction A(2, 3, 4);
	double a = A;
	cout << a << endl;

	//	//Task 2
	double b = 3.14;
	Fraction B = b;
	B.print();

#endif // TYPE_CONVERSIONS_HOME_WORK

#ifdef COMPARISON_OPERATORS
	Fraction A(1, 2);
	Fraction B(5, 10);
	cout << (A == B) << endl;
	cout << (A != B) << endl;
	cout << (A > B) << endl;
	cout << (A >= B) << endl;
#endif

#ifdef OUTPUT_CHECK
	printf("Hello Fraction\n");
	Fraction A;
	cout << A << endl;
	Fraction B (5);
	cout << B << endl;
	Fraction C(1, 2);
	cout << C << endl;
	Fraction D(2, 3, 4);
	cout << D << endl;

#endif
#ifdef INPUT_CHECK
	Fraction A;
	cout << "Введите простую дробь:";
	cin >> A;
	cout << "Вы ввели: " << A << endl;
	cout << "Сокращенная дробь: " << A.reduce() << endl;
#endif
};
