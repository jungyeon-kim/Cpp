#include <iostream>

using namespace std;

void test(int a = 4, int b = 0)
{
	cout << "a: " << a << " b: " << b << endl;
}

int main()
{
	test();	// �Լ� ������ ���� ���빰�� ��Ȯ�� �� �� ����.
}			// ��ȣ�� �߻�. (��� ��õ x)