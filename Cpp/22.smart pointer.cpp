#include <iostream>
#include <memory>

using namespace std;

/*
	unique_ptr: �ڿ��� ���� -> ���簡 �Ұ��� (�̵��ø�ƽ�̳� ������(&)�� ����)
	shared_ptr: �ڿ��� ���� -> reference count�� 0�̵Ǹ� ��ü�� �ڵ����� �Ҹ�
				reference count�� atomic�ϰ� �����Ѵ�.
	weak_ptr:	�ڿ��� ���� -> ������ �һ� shared_ptr�� reference counting�� �������� �ʴ´�.
				shared_ptr�� �������̱� ������ ���������� �����Ϳ� ������ �� ����. -> ��ü�� ����, ���� �Ұ���

	reset():	���� �޸𸮸� �����ϰ� �ٸ� �޸𸮸� �Ҵ��Ѵ�. (���ڰ� ������ ������ ����)
	release():	�޸𸮴� �����ϵ� �ڿ��� �������� ���ְ� �Ϲ� �����͸� ��ȯ�Ѵ�. (unique_ptr���� ����)
				release()�� ��ȯ�� �����ʹ� �ݵ�� ����ڰ� delete ���־�� �Ѵ�.
	lock():		�ڽ��� �����ִ� shared_ptr�� ��ȯ (weak_ptr���� ����)
*/

int main()
{
	unique_ptr<int> up{ make_unique<int>(10) };
	shared_ptr<int> sp{ make_shared<int>(10) };
	weak_ptr<int> wp{ make_shared<int>(10) };
	
	//auto p{ up };				// Error
	auto p{ up.release() };		// OK

	//sp = wp;					// Error
	wp = sp;					// OK
	auto q{ wp.lock() };

	cout << p << " " << up << " " << sp << " " << q << endl;
}