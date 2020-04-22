#include <iostream>
#include <thread>
#include <mutex>
#include <vector>

using namespace std;

/*
	���μ���:	�������� ���α׷�
	������:		���α׷� ������ �帧

	Heterogeneous:	�۾��� �ɰ� �뵵���� �����忡 �ñ�� ��Ÿ�� (Ŭ���̾�Ʈ���� �ַ� ���)
	Homogenous:		�۾��� �ɰ� ���о��� �����忡 �ñ�� ��Ÿ�� (�������� �ַ� ���)

	�� ������ ������ ������ ������ ���� (������, �ڵ�, ���� ����)
	�� �����尡 ���ٰ� ���� ���� �ƴ�. �ھ��� ������ ���ߴ°� �Ϲ��� (�ھ�� ���� ������ ������ ������ȯ�� ���� ������� �߻�)
*/

/*
	������)
	DataRace:	���� �޸𸮸� ���� �����忡�� �а� ���� ��� (�ݵ�� �ϳ� �̻��� ���� ������ �־����. �׷��� ������ �߻��ϱ⿡)
				-> mutex(��ȣ����)�� �ذ�
*/

/*
	thread)
	join():		�ش� �����尡 ����� ������ ��ٸ���. (���� �����尡 �������ε� ���α׷��� ����Ǹ� �ȵǱ� ����)
	detach():	�ش� ������ ��ü�� ����� �����带 �����. (������� ��� ��������� ������ �� ����, join()�Ұ���)
	joinable():	�ش� �����带 join()���� ��ٸ� �� �ִ� �������� bool���� ��ȯ�Ѵ�. (detach�� ���¶�� false ��ȯ)

	mutex)
	lock():		� �ڿ��� �ٸ� �����忡�� ������̸� ���. ������� �ƴϸ� �ڽ��� �����忡�� ����� ǥ��
	unLock():	����� ǥ�ø� ����

	�� mutex ��ü�� �������������� (���� �ڿ��� ����ϴ� �����帶�� mutex�� ���� ��ü�����ϱ� ����)
*/

// join()�� detach()�� ���� �ǽ��ڵ�
void printID(int myID)
{
	cout << "My Thread ID: " << myID << endl;
}

void solution1()
{
	vector<thread> v{};

	for (int i = 0; i < 10; ++i) v.emplace_back(printID, i);
	for (auto& thread : v) thread.join();

	v.clear();
	cout << "---------------------------------" << endl;

	for (int i = 0; i < 10; ++i)
	{
		v.emplace_back(printID, i);
		v[i].detach();
	}
	for (auto& thread : v)
		if (thread.joinable())
			thread.join();		// detach�Ǹ� join()�� ȣ����� �ʱ� ������ ������ ���൵�� ���α׷��� ����ȴ�.
}

// ��ȣ����, �Ӱ迵���� ���� �ǽ��ڵ�
int sum{};	// ������ �����ڿ�
mutex m{};	// mutex ��ü

void add()
{
	for (int i = 0; i < 1000000; ++i)
	{
		m.lock();		// lock�� �ɾ����������� DataRace�� ���� sum�� ����� �ٸ� ���� ��
		++sum;
		m.unlock();
	}
}

void solution2()
{
	vector<thread> v{};

	for (int i = 0; i < 10; ++i) v.emplace_back(add);
	for (auto& thread : v) thread.join();

	cout << sum << endl;
}

int main()
{
	//solution1();
	solution2();
}