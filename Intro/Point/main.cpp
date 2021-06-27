#include<iostream>
using namespace std;
#define tab "\t"
#define delimiter "\n--------------------------------------\n"
//#define STRUCT_POINT
//#define DISTANCE_CHECK
//#define CONSTRUCTORS_CHECK
//#define ASSIGNMENT_CHECK
class Point
{
	double x;
	double y;
public:
	double get_x()const
	{
		return x;
	}
	double get_y()const
	{
		return y;
	}
	void set_x(double x)
	{
		this->x = x;
	}
	void set_y(double y)
	{
		this->y = y;
	}
	


	//Constructors
	// �����������-�����,������� ������� ������
	//�������� ������ ��� ������, ����� ���������������� ���� �������
	//����������� ����� �� �� ���, ��� � �����
	Point()
	{
		x = y = 0;
		cout << "DefaultConstructor:\t" << this << endl;
		//����������� �� ���������-��� �����������, ������� ����� ���� ������ ��� ����������.
		//��� ����� ���� �����������, �� ����������� ������� ���������� ��� �� ����������� � �����������
		//������ �������� �������� ����� �������� �� ���������.
		//����������� ����������� ����� ���� �������. � ��� ������ ���� � ������ ��� �� ������ ������������, �� ���������� ��� ������� ����������� �� ���������..
//����� ������� ����������� �� ��������� ������ �������� ������ ��� ������ � ��������� ��� ���������� �������.
		//��� ������������ ���������� ������� ������.
		//����������� �� ��������� ������ ��������� ���������� ������� ���������� �� ���������
		//!!!!!this-���������� ����� �������,�� �������� �� ��������� � ������
	}

	~Point()
	{
		cout << "Destructor:\t\t" << this << endl;
	}
	Point(const Point& other)
	{
		//Shalow copy -������������� ����������� �������
		this->x = other.x;
		this->y = other.y;
		cout << "CopyConstructor:\t" << this << endl;
	}

	
	//Operators
	// �������� ���������

	Point operator=(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyAssignment:\t\t" << this << endl;
		return *this;
	}

	Point(double x)// ���������� � 1 ����������
	{
		this->x = x;
		this->y = 0;
		cout << "SingleArgumentConstructor:\t" << this << endl;
	}
	Point(double x, double y)//c 2 �����������
	{
		this->x = x;
		this->y = y;
		cout << "Constructor:\t\t" << this << endl;
	}


	

	// Methods
	
	double distance(const Point& other)
	{
		//B-this
		//A-other
		//other.x += 100;
		double x_distance = this->x - other.x;
		double y_distance= this->y - other.y;
		double distance =sqrt( x_distance * x_distance + y_distance * y_distance);
		return distance;
	}
	void print()const
	{
		cout << "X=" << x << tab << "Y=" << y << endl;
	}
};

double distance(const Point& A, const Point& B)
{
	double x_distance = A.get_x() - B.get_x();
	double y_distance = A.get_y() - B.get_y();
	double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
	return distance;
}


void main()
{
	setlocale(LC_ALL, "Russian");
#ifdef DISTANCE_CHECK
	Point A;
	A.set_x(2);
	A.set_y(3);
	//cout << sizeof(A) << endl;
	cout << A.get_x() << tab << A.get_y() << endl;
	Point B;
	B.set_x(4);
	B.set_y(5);
	cout << delimiter << endl;
	cout << B.distance(A) << endl;
	cout << delimiter << endl;
	cout << A.distance(B) << endl;
	cout << delimiter << endl;
	cout << distance(A, B) << endl;
	cout << delimiter << endl;
	cout << distance(B, A) << endl;
	cout << delimiter << endl;
#endif // DISTANCE_CHECK

#ifdef STRUCT_POINT
	// �������� ������� ��������� ���������� A ���� Point
	//��������� ������ � ��������� Point
	//������� ��������� � ��������� Point
	//A.x = 2;// ������������� ����� �������, ����������
	//A.y = 3;// ����������
	//cout << A.x << tab << A.y<< endl;
	//Point* pA = &A;//��������� ��������� �� point � ����� ����� ����� A
	//cout << pA->x << tab << pA->y << endl;
	//cout << (*pA).x << tab << (*pA).y << endl;
#endif // STRUCT_POINT


#ifdef CONSTRUCTORS_CHECK

	Point A;//Default constructor- ���������� ������ ��� ����� �� ����� ������ ������� ������
	A.print();
	Point B = 3;//Single argument constructor
	B.print();
	Point C(2, 3);//Parametrized construcctor
	C.print();

	Point D = C;//CopyConstructor
	D.print();
	Point E;//DefaultConstructor
	E = C;// CopyAssignment
	E.print();
	//���������� ���������� �� ��� ������������, ��� �������
#endif

#ifdef ASSIGNMENT_CHECK

	int a, b, c;
	a = b = c = 0;
	cout << a<<tab << b<<tab << c<<tab << endl;
	Point A, B, C;
	cout << "\n-----------------------------\n";
		A = B = C = Point(4, 5);

	cout << "\n-----------------------------\n";
	A.print();
	B.print();
	C.print();
	

#endif // ASSIGNMENT_CHECK

}