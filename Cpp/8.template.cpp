#include <iostream>

using namespace std;

/*
	���ø�:	���׸� ���α׷�(���� ������ �ڵ带 ����� ��)�� ���� �⺻���� ����
			��������ʴ´ٸ� �ڵ尡 �ν��Ͻ�ȭ���� �ʴ´�.
			�ݴ�� �������� ���Ǵ� �κ��� ������ �ν��Ͻ�ȭ�ȴ�.

	������)
	��	���к��� ���ø��� ������ ������ �ʷ��Ѵ�.
		���� ������ ��������� �߻����̾ ������� ��������Ӵ���,
		��κ� ������ ���ۿ� �ڵ尡 �ν��Ͻ�ȭ�Ǳ� ������ ������ �ð��� �������.
		ũ�Ⱑ Ŭ����(���ø� Ŭ��������), ���� ������ ���� ���� ������ �޸𸮸� �����ϰԵǰ�,
		�׸�ŭ ���������� ũ�Ⱑ Ŀ����. (ĳ�� �������� �������� ������ ��Ÿ���� �������� �������� �ִ�.)
	��	����� ���ǰ� �Ѱ��� �� �־���Ѵ�.
		�������� ���Ǵ� �κ��� ������ �ڵ尡 �ν��Ͻ�ȭ �Ǿ�� �ϴµ�, �� �� ���¸� �˰� �־���ϱ� �����̴�.
*/

template <typename T>
class Test
{
public:
	template <typename E>
	void print(E val);
};

// ����� �Ʒ� �� ���ø� �Ű������� ���� �Ἥ�� �ȵǰ� ������ ����.
template <typename T>
template <typename E>
void Test<T>::print(E val)
{
	cout << val << endl;
}

// ���ø� Ư��ȭ
template<>
class Test<const char*>		// const char* Ÿ�Կ� ���ؼ��� print()�� �Ű������� string���� ����.
{
public:
	void print(string str);
};

void Test<const char*>::print(string str)
{
	cout << str << endl;
}

// ���ø� ����
template <typename T>
constexpr T pi{ 3.141592 };

int main()
{
	Test<int> t1{};
	Test<float> t2{};
	Test<const char*> t3{};

	cout.precision(1024);
	t1.print(pi<float>);	// ���ø� �Ű����� E�� �߰��������ν� ��Һ�ȯ�� �Ͼ�� ����
	t2.print(pi<double>);	// ���� ����
	t3.print("hello");	// string�� ���� �ڷ��� �Ұ�
}
