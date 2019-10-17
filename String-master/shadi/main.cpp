#include<iostream>
using namespace std;

/*
TODO:
Перегрузить оператор +.
*/

//#define CONSTRUCTORS_CHECK

class String
{
	int size;	//Размер строки
	char* str;	//Адрес строки в динамической памяти
public:
	int get_size() const
	{
		return size;
	}
	char* get_str()
	{
		return str;
	}
	const char* get_str() const
	{
		return str;
	}

	//			Constructors:
	String(int size = 80)
	{
		this->size = size;
		this->str = new char[size] {};
		cout << "DefConstructor:\t" << this << endl;
	}
	String(const char str[])
	{
		this->size = strlen(str) + 1;
		this->str = new char[size] {};
		for (int i = 0; str[i]; i++)this->str[i] = str[i];
		cout << "Constructor:\t" << this << endl;
	}
	String(const String& other)
	{
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)this->str[i] = other.str[i];
		cout << "CopyConstructor:" << this << endl;
	}

	String(String&& other)
	{
		this->size = other.size;
		this->str = other.str;
		other.str = nullptr;
		cout << "MoveConstructor:" << this << endl;
	}
	~String()
	{
		delete[] this->str;
		cout << "Destructor:\t" << this << endl;
	}

	//			Operators:
	String& operator=(const String& other)
	{
		if (this == &other)return *this;
		delete[] this->str;
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)this->str[i] = other.str[i];
		cout << "CopyAssignment: " << this << endl;
		return *this;
	}
	String& operator=(String&& other)
	{
		delete[] this->str;
		this->size = other.size;
		this->str = other.str;
		other.str = nullptr;
		cout << "MoveAssignment: " << this << endl;
		return *this;
	}

	//			Methods:

	void print()
	{
		cout << "size:\t" << size << endl;
		cout << "str:\t" << str << endl;
	}

};
ostream& operator<<(ostream& os, const String& obj)
{
	return os << obj.get_str();
}

String operator+(const String& left, const String& right)
{
	String temp = left.get_size() + right.get_size() - 1;
	for (int i = 0; left.get_str()[i]; i++)
	{
		temp.get_str()[i] = left.get_str()[i];
	}
	for (int i = 0; right.get_str()[i]; i++)
	{
		temp.get_str()[i + left.get_size() - 1] = right.get_str()[i];
	}
	return temp;
}
String operator+=(String& left, const String& right)
{
	return (left = left + right);
}


void main()
{
	setlocale(LC_ALL, "");
#ifdef CONSTRUCTORS_CHECK
	cout << typeid(typeid("Hello").name()).name() << endl;
	String str0;	//Default constructor
	str0.print();
	String str1 = "Hello";	//Single argument constructor
	cout << str1 << endl;
	String str2 = str1;	//Copy Constructor
	cout << str2 << endl;
	str0 = str1;	//Copy assignment
	cout << str0 << endl;
	cout << "\n---------------------------------\n";
	str2 = str2;
	cout << str2 << endl;
	cout << "\n---------------------------------\n";
#endif // CONSTRUCTORS_CHECK

	String str1 = "Hello";
	String str2 = "World";

	//cout << (str1 += str2) << endl;
	//str1 += str2;
	cout << "\n---------------------------------\n";
	String str3 = str1 + " " + str2;
	cout << str3 << endl;
	cout << "\n---------------------------------\n";
	str3 = str1 + " " + str2;
	cout << "\n---------------------------------\n";
	cout << str3 << endl;
	cout << "\n---------------------------------\n";

}