#include <iostream>
#include <memory>

using namespace std;

/*
	C++���� Ŭ������ ����ü�� ����ϴ�. �ٸ�, ����ü�� �⺻ ���������ڰ� public. Ŭ������ private.
	������: ��ü(class)�� ������ �� ȣ��
	�Ҹ���: ��ü(class)�� ����� �� ȣ��
	������ �ʱ�ȭ ����Ʈ:		������ ȣ��� ���ÿ� ��������� �ʱ�ȭ�ȴ�.
							�⺻Ÿ���� ���̰� ������, Ŭ���� ������ ���������� ������ ���Ǻ� �ʱ�ȭ���� ȿ�����̴�.
							A ������ & B ������ & B ���Կ����� or A ������ & B ��������� ȣ������
							������ �ʱ�ȭ ����Ʈ�� �ƴ�, ��� ������ ���� ������ �ʱ�ȭ �ȴ�.
*/

/*
	��ü ������ ��õǾ��ִ� �����ڰ� ���ٸ� ����Ʈ �����ڰ� �Ҹ���.
	��õǾ� �ִ� �����ڰ� �ϳ��� �ִٸ� ����Ʈ �����ڴ� �Ҹ��� �ʴ´�.
*/

class B
{
public:
	B() { cout << "B()" << endl; }
	B(const B& rhs) { cout << "B(const B& rhs)" << endl; }
	~B() { cout << "~B()" << endl; }

	B& operator=(const B& rhs) { cout << "B& operator=(const B& rhs)" << endl; return *this; }
};

class A
{
private:
	B b{};
public:
	A() { cout << "A()" << endl; }
	//A(const B& rhs) : b{ rhs } { cout << "A(const B& rhs)" << endl; }	// ������ �ʱ�ȭ ����Ʈ
	A(const B& rhs) { b = rhs; cout << "A(const B& rhs)" << endl; }
	~A() { cout << "~A()" << endl; }
};

int main()
{
	A a{ B{} }; // ������ ȣ��
}	// <- ���������� �Ҹ����, LIFO (�Ҹ��� ȣ��)
	// �Ҹ��ڰ� A B B ���̾ƴ� B A B�� �Ҹ� -> 44������ B{}�� �ӽð�ü�̹Ƿ� 44���� �� �Ҹ��ϱ⶧��