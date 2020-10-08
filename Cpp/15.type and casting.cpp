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
							��Ÿ�ӿ��� ���� -> static_cast()���� �������� (ĳ������ �������� ������ null��ȯ or ���ܹ߻�)
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
	virtual ~Test() {}

	void commonFunc() { cout << "Test::commonFunc" << endl; }
	virtual void virtualFunc() { cout << "Test::virtualFunc" << endl; }
};

class TestEx : public Test
{
public:
	TestEx() {}
	virtual ~TestEx() {}

	void commonFunc() { cout << "TestEx::commonFunc" << endl; }
	virtual void virtualFunc() override { cout << "TestEx::virtualFunc" << endl; }
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
	Test* obj1{ new TestEx{} };						// Test�� �Ҵ��ϸ�, TestEx�� �������� �����Ƿ� �Ʒ����� �ٿ�ĳ���� �Ұ�
	TestEx* obj2{ dynamic_cast<TestEx*>(obj1) };	// down casting
	obj1->commonFunc();
	obj2->commonFunc();
	dynamic_cast<Test*>(obj2)->commonFunc();		// up casting (�������� ĳ�����ϹǷ� commonFunc�� ��ȭO)
	obj1->virtualFunc();
	obj2->virtualFunc();
	dynamic_cast<Test*>(obj2)->virtualFunc();		// up casting (�������� ĳ�����ϹǷ� virtualFunc�� ��ȭX)
}