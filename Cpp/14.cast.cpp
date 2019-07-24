#include <iostream>

using namespace std;

/*
	static_cast<>()	-	�⺻ ����ȯ, ��Ӱ��� ����ȯ(up, down)
						�����Ͽ��� ����
	dynamic_cast<>()	-	��Ӱ��� ����ȯ(up) -> �����Լ��� ������ Ŭ������ down�� ����
							��Ÿ�ӿ��� ����
							static���� �������� (ĳ������ �������� ������ ������ �߻���Ŵ)
	const_cast<>()	-	�����Ϳ� �������� const ����
	reinterpret_cast<>()	-	���谡 ������� ����ȯ
*/

/*
	��	�ٿ�ĳ������ �� �ʿ��� ��쿡�� ����ϰ� static_cast���� dynamic_cast�� ����ؾ��Ѵ�.
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
	// �Ϲ����� ���
	float data{ 3.14 };
	cout << static_cast<int>(data) << endl;
	cout << data << endl;

	// ��Ӱ��� ���
	Test *obj1{};
	TestEx *obj2{ dynamic_cast<TestEx*>(obj1) };	// down casting
}