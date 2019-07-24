#include <iostream>

using namespace std;

// 비추천
/*
	friend	-	외부 클래스, 함수에게 자신의 내부 데이터 사용을 허락함
*/

class A
{
private:
	int aData{ 10 };
public:
	friend class B;	// B에게 나의 내부데이터 사용을 허락하겠다.
	A() {}
	~A() {}

	friend void testFunc(A a);	// testFunc에게 나의 내부데이터 사용을 허락하겠다.
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