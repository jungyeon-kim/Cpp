#include <iostream>

namespace test	// ����, �Լ����� �̸��ߺ��� ���� (���� ����� �� ������Ʈ�� ������ ��)
{
	int val{};	// test�� �Ҽӵ� ����
}

int val{};	// ���Ҽ� ����

// ���� �Ҽ�(test::)�� �ٿ����� �ʾƵ� ��.
// ���ڵ忡�� ���� test�Ҽ� ������ ���Ҽ� ������ ��ȣ�� �߻�
// using namespace test;

int main()
{
	test::val = 10;	// test:: -> test�� �ҼӵǾ��� �ǹ�
	::val = 5;	// :: -> ���Ҽ��̶� �ǹ�
	std::cout << test::val << " " << ::val;
}