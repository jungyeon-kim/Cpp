#include <iostream>

using namespace std;

// version 1
class Test
{
public:
	template <typename T>
	void print(T val)
	{
		cout << " " << val;
	}
};

// version 2
template <typename T>
class Test2
{
public:
	void print(T val)
	{
		cout << " " << val;
	}
};

int main()
{
	Test test{};

	test.print(5);
	test.print(5.5);

	Test2 <int> test2_1{};
	Test2 <float> test2_2{};

	test2_1.print(5);
	test2_2.print(5.5);
}