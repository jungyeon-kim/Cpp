#include <iostream>

using namespace std;

/*
	����� private�� ���� get, set �޼��带 ����ϴ� ����:

	��ü�� ���Ἲ ����. weight��� ����� ���� ��, weight�� 0���� ���� �� ������,
	�ܺο��� ����� ���������� ������ ��� ���� ���� ������ ��ü�� ���Ἲ�� �� �� �ִ�.
	getter:	 return by value�� return by const reference�� ����� ���纻�̳� �����Ұ��� ������ ��ȯ�Ѵ�.
	setter:	 weight�� ���� ���� �� ���Կ� ���Ͽ� ����ó���� ���ش�.
	
*/

class Test
{
private:
	int val{};
public:
	Test() : val{ 10 } {}
	~Test() = default;

	void print() const		// this: r-value(���� �Ұ�)
	{
		cout << val << endl;
		cout << this << endl;
		cout << &val << endl;
		cout << this->val << endl;
	}

	int getVal() const { return val; }
	const Test& getTest() const { return *this; };
	void setVal(int param) { val = param; }
};

int main()
{
	Test t{};

	t.setVal(t.getVal() + 1);
	t.print();
}