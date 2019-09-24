#include <iostream>
#include <string>

using namespace std;

//	�� ���� ��� �����ε��� �Լ��� using�ϴ� ���, 
//	��� �����ε��� �Լ��� �����Ѵٴ� �ǹ��̱� ������ ���ǰ� �ʿ���

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

int main()
{
	Test t1{ "hello" };
	TestEx t2{ 10 };
	TestEx t3{ "world!" };	// Test�� �����ڸ� using�����ν� ������ OK
}