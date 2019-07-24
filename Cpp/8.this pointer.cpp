#include <iostream>

using namespace std;

// this: r-value(수정 불가)

class Test
{
private:
	int val{};
public:
	Test() : val{ 1 } {}
	~Test() {}

	void print() const
	{
		cout << this << endl;
		cout << &val << endl;
		cout << this->val << endl;
	}
};

int main()
{
	Test test{};

	test.print();
}