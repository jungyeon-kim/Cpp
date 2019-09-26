#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/*
	ios_base::
	app:		�۾� ������ ��Ʈ���� ��ġ(������ ��ġ)�� ���� ���� ������ �ű��.
	ate:		������ ���ڸ��� ��Ʈ���� ��ġ�� ���� ���� ������ �ű��.
	binary:		���̳ʸ� ���� �����͸� ������Ѵ�. (�ݴ�� �ؽ�Ʈ ���)
	in:			�Է� ���� ������ ����.
	out:		��� ���� ������ ����.
	trunc:		������ ���� ���������ʹ� �����Ѵ�.
*/

int main()
{
	string str{"hello"};
	ifstream in{ "test.txt", ios_base::binary };
	ofstream out{ "test.txt", ios_base::app };

	in >> str;	// ���ڿ� str�� test.txt�� ���ڿ��� �Է��Ѵ�.
	out << str;	// str�� test.txt�� ����Ѵ�.
	// ��������� test.txt�� ���ڿ��� ��µɰ��̴�.
}