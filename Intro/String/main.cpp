#include "String.h"
void main()
{
	setlocale(LC_ALL, "Russian");

#ifdef CONSTRUCTORS_CHECK
	int a = 2;
	int b = 3;
	a = b;
	//String str=5;// implicit conversion from int to String
	//������� �������������� �����
	String str(5);//explicit constructor ����� ������� ������ ��� � ������ ������� ���������� ���������
	str.print();
	String str1 = "Hello";
	str1 = str1;
	str1.print();

	String str2 = str1;
	str2.print();

	String str3;
	str3 = str2;
	str3.print();
}
#endif // CONSTRUCTORS_CHECK

String str1 = "Hello";
cout << str1 << endl;
String str2 = "World";
cout << str2 << endl;
//cout << "\n--------------------------------------\n";
//String str3 = str1 +" "+ str2;
//cout << "\n----------------------------------------\n";
//cout << str3 << endl;
//cout << str1 + str2 << endl;
str1 += str2;
cout << str1 << endl;
}

