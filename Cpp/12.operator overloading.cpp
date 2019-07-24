#include <iostream>

using namespace std;

class Test
{
private:
	int data{};
public:
	Test() {}
	Test(int nParam) : data{ nParam } {}

	friend ostream& operator<<(ostream& os, const Test& rhs)	// 출력 연산자
	{
		os << rhs.data;
		return os;
	}
	friend istream& operator>>(istream& is, Test& rhs)	// 입력 연산자
	{
		is >> rhs.data;
		return is;
	}
};

template <typename T>			// type은 Test
void change(T &left, T &right)	// call by reference
{
	T tmp{ left };
	left = right;
	right = tmp;
}

int main()
{
	Test a{};
	Test b{};

	cin >> a >> b;

	change(a, b);

	cout << a << ", " << b << endl;	// ex) cout << a; -> operator<<(cout, a);
}