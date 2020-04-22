#include <iostream>
#include <memory>

using namespace std;

/*
	Ŭ������ �����Ҵ� �޸𸮸� ������?
	-> �ݵ�� �Ҹ���, ���������, ���Կ����ڸ� ������ ���־���Ѵ�!

	�̵��ø�ƽ(�̵������� or �̵����Կ�����)�� ������־���?
	-> ��������� or ���Կ����ڸ� ������־���Ѵ�!
 */

/*
	���Կ����ڰ� �ڽ��� ��ȯ�ϴ� ���� ->
	A = B = C;�� ���� ��� B = C�� �������� ��ȯ���� ���ٸ� A�� ������ ���� ����.
*/

class Test
{
private:
	//int* data{};
	unique_ptr<int> data{};
public:
	Test() 
	{ 
		cout << "Test()" << endl;
		//data = new int{ 10 };
		data = make_unique<int>(10);
	}
	~Test()
	{
		cout << "~Test()" << endl;
		//if (data)
		//{
		//	delete data;
		//	data = nullptr;
		//}
	}

	Test& operator=(const Test &rhs)		// ���Կ�����
	{
		cout << "Test& operator=(const Test& rhs)" << endl;
		//if (data && this != &rhs) delete data;	// �Ҵ�� �� ���� (�޸� �� ����, �ڽ� ���� ����ó��)
		//data = new int{ *rhs.data };
		data = make_unique<int>(*rhs.data);
		return *this;
	}
	Test& operator=(Test &&rhs) noexcept	// �̵����Կ�����
	{
		cout << "Test& operator=(Test&& rhs)" << endl;
		//if (data && this != &rhs) delete data;
		data = std::move(rhs.data);
		//rhs.data = nullptr;	// �����ָ� delete�� �Ͼ (�ߺ�����)
		return *this;
	}

	int getDataValue() const { return *data; }						// return by value (���絵 ���� -> *data�� value�̱� ����)
	const unique_ptr<int>& getDataAddress() const { return data; }	// return by reference	(unique_ptr�� ���簡 �Ұ���)
	void setData(int nParam) { *data = nParam; }				// data�� �ּҰ��� �ȹٲ�� ���� �ٲ�

};

int main()
{
	Test a{};	// �⺻������ ȣ��
	Test b{};	// �⺻������ ȣ��
	
	cout << "b: " << b.getDataAddress() << endl;
	
	Test c{}; // �⺻������ ȣ��

	b = a;	// b.operator=(a);	// ���Կ����� ȣ��
	c = std::move(b);			// �̵����Կ����� ȣ��

	cout << "a: " << a.getDataAddress() << " b: " << b.getDataAddress() << " c: " << c.getDataAddress() << endl;
}