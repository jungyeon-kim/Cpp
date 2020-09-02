#include <iostream>
#include <string>

using namespace std;

/*
	※ 오버로딩된 함수를 using하는 경우, 모든 오버로딩된 함수를 참조한다는 의미이기 때문에 주의가 필요함
	※ typedef는 템플릿을 사용할 수 없지만, using은 가능하다.
*/

class Test
{
public:
	Test() = default;
	Test(const string& rhs) { cout << "Test()" << endl; }
};

class TestEx : public Test
{
public:
	using Test::Test;
	TestEx(int rhs) { cout << "TestEx()" << endl; }
};

// Error
//template <typename T>
//typedef T myType;

// OK
template <typename T>
using myType = T;

int main()
{
	myType<int> var{};

	Test t1{ "hello" };
	TestEx t2{ 10 };
	TestEx t3{ "world!" };	// Test의 생성자를 using함으로써 컴파일 OK
}