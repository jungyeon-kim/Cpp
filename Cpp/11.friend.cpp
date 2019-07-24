#include <iostream>

using namespace std;

// ����õ
/*
	friend	-	�ܺ� Ŭ����, �Լ����� �ڽ��� ���� ������ ����� �����
*/

class A
{
private:
	int aData{ 10 };
public:
	friend class B;	// B���� ���� ���ε����� ����� ����ϰڴ�.
	A() {}
	~A() {}

	friend void testFunc(A a);	// testFunc���� ���� ���ε����� ����� ����ϰڴ�.
};

class B
{
private:
	int bData{ 20 };
public:
	B() {}
	~B() {}

	int getaData(A obj) const { return obj.aData; }
};

void testFunc(A obj)
{
	cout << obj.aData << endl;
}

int main()
{
	A a{};
	B b{};

	cout << b.getaData(a) << endl;
}