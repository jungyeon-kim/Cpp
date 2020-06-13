#include <iostream>

using namespace std;

/*
	함수객체:	함수호출연산자를 가진 클래스 (functor라고도 칭함)
*/

class Test	// 함수객체
{
private:
	int data{};
public:
	Test() = default;
	~Test() = default;

	int operator+(const Test& rhs) const
	{
		return data + rhs.data;
	}
	int operator()(int param)
	{
		return param * param;
	}
	int operator()(const Test& param)
	{
		return param.data * param.data;
	}
	bool operator<(const Test& rhs) const
	{
		return data < rhs.data;
	}
	// iostream에서 클래스 private멤버에 접근할 수 있도록 friend 선언
	// 실제로 operator<<, operator>>는 friend이기에 클래스 멤버가 아니라 전역함수!
	friend ostream& operator<<(ostream& os, const Test& rhs)
	{
		os << rhs.data;
		return os;
	}
	friend istream& operator>>(istream& is, Test& rhs)
	{
		is >> rhs.data;
		return is;
	}
};

int main()
{
	Test a{};
	Test b{};

	cin >> a >> b;

	cout << a << ", " << b << endl;		// ex) cout << a; -> operator<<(cout, a);
	cout << a + b << endl;
	cout << a(3) << ", " << a(b) << endl;
}