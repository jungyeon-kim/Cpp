#include <iostream>

using namespace std;

// �������(�������� ���곶��)�� �������� �����
// ������ ���� �������

// ��ũ�� �Լ� (����õ)
//#define add(a, b) (a + b)

// �ζ��� �Լ� (��õ)
// vs�Ӽ� �ζ����Լ� �����Խ� ���� -> ���ÿ��� �����൵ ����
// ������ �����Ͽ� inline ����� ����� ���Ǳ��� ���־����. �׷��� ������ �����Ϸ��� �νĺҰ�
// inline ������ �Ͽ��� �����Ϸ��� ȿ�������� ���ϴ� �Ǵ��ϸ� inlineȭ�� �ȵ� ���� �ִ�. (��������� ���� ũ�⸦ �ζ��̴���)

inline int add(int a, int b)
{
	return a + b;
}

int main()
{
	cout << add(3, 4);
}