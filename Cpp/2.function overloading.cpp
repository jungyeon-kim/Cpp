#include <iostream>

using namespace std;

/*
	overloading	-	�Լ��� ����, �Ű������� ��ȯŸ���� �ٸ��ų�, �Ű������� �ٸ� (��ȯŸ�Ը� �ٸ� ���� �Ұ���)
	overriding	-	�Լ���, �Ű�����, ��ȯŸ�� ����, ���ǰ� �ٸ� (��Ӱ��迡�� ���) -> ������

	��	�Լ� ������ ������ �ӽð�ü�� ���۷����� �����ͷ� ��ȯ�ϴ� ���� ����
		ex) ���δٸ� �� �����Ͱ� ���� �ּҸ� ������ �� �� ����
*/

// ����õ ���
/*
int print(int a)
{
	return a;
}

double print(double a)
{
	return a;
}
*/

// ��õ���
template <typename T>
T print(T a)
{
	return a;
}

int main()
{
	cout << print(3) << " " << print(3.3) << endl;
}