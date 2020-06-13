#include <iostream>

using namespace std;

/*
	������	-	1. �⺻ ������
				2. ���� ���ǵ� ������
				3. ���� ������
						��������: ���� ����
				4. �̵� ������
						��������: �ּҸ� ����
						r-value ������ �������� �ӽð�ü�� ���ؼ� �������縦 ����
						�ӽð�ü�� const &���� &&�� �켱������ ������ �̵������ڰ� �Ҹ�
*/

/*
	�ӽð�ü	-	1. �Լ� ��ȯ�̳� ����������� �߻�
				2. ��� r-value
				3. ������ ������ �ڵ� �Ҹ�
				4. �ӽð�ü�� �����Ұ�� �������� scope��
					   ���� ������ �ӽð�ü�� �Ҹ����

	��			std::move()�� ��ü�� r-value�� ĳ�������ִ� �� �ϻ�, ��ü�� �Ҹ��ų�� ����.
*/

/*
	int data = 3 + 4;
	data: l-value
	3 + 4: r-value
	7: r-value (�ӽð�ü) -> 3�� 4�� + �Ǹ鼭 �����ǰ�
							 ������ ������ �����

	int &&a = 3 + 4;	// r-value ����
	int &b = a;			// l-value ����
*/

/*
	�̵� �ø�ƽ�� ���ܸ� ���� �� ����.
	���Ͱ��� STL �����̳��� ��� ���� ���Ҵ�ÿ� �̵��� �ϰԵǸ� ���� ������ �����ʹ� ������⶧���̴�.
	����, �̵� �ø�ƽ���� noexcept Ű���尡 �پ���Ѵ�.
*/

class Test
{
private:
	int* data{};
public:
	Test() 
	{ 
		cout << "Test()" << endl; 
		data = new int{ 10 };
	}
	~Test() 
	{ 
		cout << "~Test()" << endl;
		if (data)
		{
			delete data;		// data�� nullptr�̶�� ���������� �ǳʶ� (�ٸ������� ��ó�����شٸ� ����ó�� �ʿ�x)
			data = nullptr;
		}
	}
	Test(const Test &rhs)	// ���������
	{
		cout << "Test(const Test& rhs)" << endl;
		// ��������			// ������	1. lhs�� �޸������� �Ͼ�� rhs�� ����Ű�°��� ����� (��۸�������)
		//data = rhs.data;	//			2. �Ҹ��ڿ��� �޸����� �ι��Ͼ (����)
		// ��������
		data = new int{ *rhs.data };	// data�� rhs.data�� '��'�� �Ҵ�
										// rhs.data = �ּҰ�, *rhs.data = ��
	}
	Test(Test &&rhs) noexcept			// �̵�������: �ӽð�ü��� ���� ����� �������縦 �Ͽ� ������ ������.
	{
		cout << "Test(Test&& rhs)" << endl;
		data = rhs.data;	// ��������
		rhs.data = nullptr;	// �����ָ� delete�� �ι� �Ͼ (�ߺ�����)
	}

	const int* getData() const { return data; }	// return by address
	void setData(int nParam) { *data = nParam; }
};

int main()
{
	Test a{};				// �⺻������ ȣ��

	cout << "a: " << a.getData() << endl;

	Test b{ a };			// ��������� ȣ�� ( ��ü�� ���Ӱ� �����ɶ���! -> b = a;�� ���Կ�����)
	Test c{ std::move(a) };	// �̵������� ȣ��, move: r-value�� ĳ����

	cout << "a: " << a.getData() << "	b: " << b.getData() << "	c: " << c.getData() << endl;
}