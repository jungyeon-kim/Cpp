#include <iostream>

using namespace std;

/*
	1. �Ҵ�� ������ ���� �̷����Ѵ�.
	2. ������ ���ǹ����� ���� nullptr���� Ȯ���Ѵ�.
	3. �����Ŀ��� �ݵ�� nullptr�� �������־���Ѵ�.

	�޸� ��:		�Ҵ�� �޸𸮸� ���� �����ʾ� ������ ����� ��
	��۸� ������:	�̹� ������ �޸𸮸� ����Ű�� ������
*/

/*
	constexpr:		����� �ʱ�ȭ���� Ȥ�� ����� ĳ���õ�, ������ ������ ó���� (����)
	mutable:		const Ÿ���� �������� �ش� ���� ������ �����ϰ� ����
	explicit:		������ ����ȯ ���� (�����ڿ� ��ȯ�����ڿ� ���)
*/

class Test
{
private:
	mutable int val{};
public:
	static constexpr int MAX{ 5 };
public:
	Test() = default;
	Test(int i) : val{ i } {}
	~Test() { cout << "~Test()" << endl; }

	explicit operator int() const { return val; }	// int()��ȯ ������ �����ε� (��ȯ������ �������� �ʴ´�.)

	void print() const
	{
		++val;	// mutable �����̱� ������ ��������
		cout << val << endl;
	}
};

int main()
{
	Test t{ 10 };
	int i = static_cast<int>(t);	// int()��ȯ �����ڰ� explicit�̶� ��������� Ÿ��ĳ������ ���־���Ѵ�.
	int j{ t };						// �ٵ� ��� �� �ɱ�..??

	///////////////////////////////////////////////////////////////////////

	Test* test{ new Test[Test::MAX] };
	
	for (int i = 0; i < Test::MAX; ++i)
		test[i].print();

	if (test)
	{
		delete[] test;			// ����
		test = nullptr;			// ��۸������� ����
	}

	if (test)
		for (int i = 0; i < Test::MAX; ++i)
			test[i].print();
}