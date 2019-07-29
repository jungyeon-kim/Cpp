#include <iostream>

using namespace std;

//	���� static�� ���°�?: ����Ÿ���� ���� ��ü�� ���� �����ϰ� ���� �� (�ַ� Singleton)

/*
	Ŭ���� ���� static�� �ֿ�Ư¡)
	1. Ŭ���� �ȿ��� ����Ǿ����� Ŭ������ ����� �ƴϴ�.
	2. ������������ ������ �޴´� (private�� �ܺο��� �׼��� �Ұ�)
	3. ��� ��ü�� ������ ��� �����ϴ�.
	4. ���α׷��� ����Ǹ� �ٷ� �޸𸮿� ����ǰ� �� ������ �ش� ��ü�� �����Ǳ� �����̱� ������,
	   �ܺο��� ���Ǹ� ���־�� �ϸ�, �ڵ����� �ʱ�ȭ�� ������ �ʱ� ������ �ʱ�ȭ�� ���־�� �Ѵ�.
	   ���������� const�� constexpr Ű���尡 ������ ���ο��� �ʱ�ȭ�� �����ϴ�.
*/

class Test
{
private:
	static int data;				// ���ο��� �ʱ�ȭ �Ұ��� (�󲮵���)
public:
	static constexpr int MAX{ 10 };	// ���ο��� �ʱ�ȭ ����
public:
	int getData() const { return data; }
	void setData(int rhs) { data = rhs; }
};

int Test::data{};

int main()
{
	Test t[Test::MAX]{};

	t[0].setData(1);

	for (const auto& i : t)	// data�� static���� ������� �� t[0]�� ���� �ٲ�
		cout << i.getData() << endl;
}