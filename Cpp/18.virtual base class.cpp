#include <iostream>

/*
	���̾Ƹ�� ����:	A�� B�� C�� ��ӹް� B�� C�� D�� ��ӹ޾��� �� �߻��Ѵ�.
						D���� A�� �Լ��� ȣ���Ϸ��� ��, B�� C�� ��������κ��� ���� ������ 
						�� �� ���� ��ȣ���� �߻��� �������� �� ����.

	�ذ�å:				A�� virtual�� ��ӹ����� �����Ϸ��� A�� �ϳ��� �Ǵ��ϱ� ������
						��ȣ���� ���� �� �ִ�.
*/
					
using namespace std;

class A
{
public: 
	void testFunc() { cout << "A::testFunc()" << endl; }
};

class B : public virtual A {};

class C : public virtual A {};

class D : public B, public C {};

int main()
{
	D d{};

	d.testFunc();
}