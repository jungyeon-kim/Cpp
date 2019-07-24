#include <iostream>

using namespace std;

/*
	1. �Ҵ�� ������ ���� �̷����Ѵ�.
	2. ������ ���ǹ����� ���� nullptr���� Ȯ���Ѵ�.
	3. �����Ŀ��� �ݵ�� nullptr�� �������־���Ѵ�.
*/

/*
	�޸� ��:		�Ҵ�� �޸𸮸� ���� �����ʾ� ������ ����� ��
	��۸� ������:	�̹� ������ �޸𸮸� ����Ű�� ������
*/

// constexpr:	����� �ʱ�ȭ����, ������ ������ ó����(����)
// mutable:		const Ÿ���� �������� ���� ������ �����ϰ� ����

class Test
{
private:
	mutable int val{};
public:
	static constexpr int MAX{ 5 };
public:
	Test() : val{ 1 } {}
	~Test() { cout << "~Test()" << endl; }

	void print() const
	{
		++val;	// mutable �����̱� ������ ��������
		cout << val << endl;
	}
};

int main()
{
	Test* test{ new Test[Test::MAX] };
	
	for (int i = 0; i < Test::MAX; ++i)
		test[i].print();

	if (test)
	{
		delete[] test;			// ����
		test = nullptr;			// ��۸������� ����
	}

	if(test)
		for (int i = 0; i < Test::MAX; ++i)
			test[i].print();
}