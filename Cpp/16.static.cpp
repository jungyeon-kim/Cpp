#include <iostream>

using namespace std;

// ���� static�� ���°�?: ����Ÿ���� ���� ��ü�� ���� �����ϰ� ���� �� (�ַ� Singleton)

class Test
{
private:
	static int data;	// �� ������
public:
	int getData() const { return data; }
	void setData(int rhs) { data = rhs; }
};

int Test::data{};		// �ܺο��� �ʱ�ȭ�� ���־����
						// but, �������(const)�� Ŭ���� ���ο��� �ʱ�ȭ ����

int main()
{
	Test t[10]{};

	t[0].setData(10);

	for (const auto& i : t)	// data�� static���� ������� �� t[0]�� 10�� ��
		cout << i.getData() << endl;
}