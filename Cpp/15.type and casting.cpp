#include <iostream>

using namespace std;

/*
	typedef:	� Ÿ�Կ� ���� ������ �����.
	using:		typedef�� ����ѱ��. (���� ���Ͽ� �߰� ����� ����)
*/

/*
	static_cast<>():		�⺻ ����ȯ, ��Ӱ��� ����ȯ(up, down ����) -> �ٿ�ĳ������ ������ ����ϹǷ� ����
							�����Ͽ��� ����
	dynamic_cast<>():		��Ӱ��� ����ȯ (�⺻������ up�� ����)
							-> �ٿ�ĳ���� ���ɿ��θ� �Ǵ��Ϸ��� RTTI�� �ʿ��ѵ�,
							   �̴� �����Լ����̺� ��������⶧��. ����, �����Լ��� ������ Ŭ������ �ٿ�ĳ���õ� ����
							��Ÿ�ӿ��� ���� -> ĳ������ �������� ������ nullptr��ȯ(�����Ϳ� ����) or ���ܹ߻�(������ ����)
	const_cast<>():			constƯ���� ���ش�.
	reinterpret_cast<>():	���谡 ������� ����ȯ (���� ���谡 ���� Ÿ������ ĳ������ �����ϱ⶧���� ����)

	��	Reflection:	��Ÿ�ӿ� �ǽð����� ��ü�� ������ �����´�.		(���� c++�� ���� ���)
					RTTI ���� �� ���� ����� ����					(��Ÿ�ӿ� �Լ� ���� ��)
		RTTI:		Run Time Type Information -> �����Լ����̺� ����
					c++������ Reflection ����ȣȯ ���			(dynamic_cast�� ��ǥ�� ��)
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
	virtual ~TestEx() override {}

	void commonFunc() { cout << "TestEx::commonFunc" << endl; }
	virtual void virtualFunc() override { cout << "TestEx::virtualFunc" << endl; }
};

int main()
{
	// typedef float Myfloat;	// ����õ
	using Myfloat = float;		// ��õ

	// �Ϲ����� ĳ����
	Myfloat data{ 3.14f };
	cout << static_cast<int>(data) << endl;
	cout << data << endl;

	// ��Ӱ��� ĳ����
	Test* obj1{ new TestEx{} };						// up casting
													// Test�� �Ҵ��ϸ�, TestEx�� �������� �����Ƿ� �Ʒ����� �ٿ�ĳ���� �Ұ�
													// �� ��츦 static_cast�� ĳ�����ϸ� ����������, 
													// ���������� ���� �ڽ��� ����� ������ �����ϱ� ������ ����
	TestEx* obj2{ dynamic_cast<TestEx*>(obj1) };	// down casting
	obj1->commonFunc();
	obj2->commonFunc();
	dynamic_cast<Test*>(obj2)->commonFunc();		// up casting (���������� ĳ�����ϹǷ� commonFunc�� ��ȭO)
	obj1->virtualFunc();
	obj2->virtualFunc();
	dynamic_cast<Test*>(obj2)->virtualFunc();		// up casting (���������� ĳ�����ϹǷ� virtualFunc�� ��ȭX)
}