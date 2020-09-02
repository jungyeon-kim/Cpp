#include <iostream>

using namespace std;

/*
	typedef:	� Ÿ�Կ� ���� ������ �����.
	using:		typedef�� ����ѱ��. (���� ���Ͽ� �߰� ����� ����)
*/

/*
	static_cast<>():		�⺻ ����ȯ, ��Ӱ��� ����ȯ(up, down ����)
							�����Ͽ��� ����
	dynamic_cast<>():		��Ӱ��� ����ȯ(up�� ����) -> �����Լ��� ������ Ŭ������ down�� ����
							��Ÿ�ӿ��� ���� -> static_cast()���� �������� (ĳ������ �������� ������ ������ �߻�)
	const_cast<>():			constƯ���� ���ش�.
	reinterpret_cast<>():	���谡 ������� ����ȯ (���� ���谡 ���� Ÿ������ ĳ������ �����ϱ⶧���� �����ϴ�.)

	��	Reflection:	��Ÿ�ӿ� �ǽð����� ��ü�� ������ �����´�.		(���� c++�� ���� ���)
					RTTI ���� �� ���� ����� ����					(��Ÿ�ӿ� �Լ� ���� ��)
		RTTI:		c++������ Reflection ����ȣȯ ���			(dynamic_cast�� ��ǥ�� ��)
					Reflection�� �ٸ��� RTTI �ɼ��� ON / OFF ����	(��Ÿ������ ������ ������� ����)
*/

class Test
{
public:
	Test() {}
	~Test() {}

	virtual void testFunc() { cout << "Test" << endl; }
};

class TestEx : public Test
{
public:
	TestEx() {}
	~TestEx() {}

	virtual void testFunc() override { cout << "TestEx" << endl; }
};

int main()
{
	// typedef float Myfloat;	// ����õ
	using Myfloat = float;		// ��õ

	// �Ϲ����� ĳ����
	Myfloat data{ 3.14 };
	cout << static_cast<int>(data) << endl;
	cout << data << endl;

	// ��Ӱ��� ĳ����
	Test* obj1{};
	TestEx* obj2{ dynamic_cast<TestEx*>(obj1) };	// down casting
}