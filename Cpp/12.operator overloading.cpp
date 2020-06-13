#include <iostream>

using namespace std;

/*
	�Լ���ü:	�Լ�ȣ�⿬���ڸ� ���� Ŭ���� (functor��� Ī��)
*/

class Test	// �Լ���ü
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
	// iostream���� Ŭ���� private����� ������ �� �ֵ��� friend ����
	// ������ operator<<, operator>>�� friend�̱⿡ Ŭ���� ����� �ƴ϶� �����Լ�!
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