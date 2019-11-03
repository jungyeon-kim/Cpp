#include <iostream>

using namespace std;

/*
	멤버를 private에 놓고 get, set 메서드를 사용하는 이유:

	객체의 무결성 때문. weight라는 멤버가 있을 때, weight는 0보다 작을 수 없지만,
	외부에서 멤버에 직접적으로 접근할 경우 음의 값을 대입해 객체의 무결성을 깰 수 있다.
	getter:	 return by value나 return by const reference로 멤버의 복사본이나 수정불가한 원본을 반환한다.
	setter:	 weight에 대한 음의 값 대입에 대하여 예외처리를 해준다.
	
*/

class Test
{
private:
	int val{};
public:
	Test() : val{ 10 } {}
	~Test() = default;

	void print() const		// this: r-value(수정 불가)
	{
		cout << val << endl;
		cout << this << endl;
		cout << &val << endl;
		cout << this->val << endl;
	}

	int getVal() const { return val; }
	const Test& getTest() const { return *this; };
	void setVal(int param) { val = param; }
};

int main()
{
	Test t{};

	t.setVal(t.getVal() + 1);
	t.print();
}