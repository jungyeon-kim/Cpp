#include <iostream>

/*
	다이아몬드 문제:	A를 B와 C가 상속받고 B와 C를 D가 상속받았을 때 발생한다.
						D에서 A의 함수를 호출하려할 때, B와 C중 어느것으로부터 오는 것인지 
						알 수 없어 모호성이 발생해 컴파일할 수 없다.

	해결책:				A를 virtual로 상속받으면 컴파일러가 A를 하나로 판단하기 때문에
						모호성을 피할 수 있다.
*/
					
using namespace std;

class A
{
public: 
	void testFunc() { cout << "A::testFunc()" << endl; }
};

class B : public virtual A {};

class C : public virtual A {};

class D : public B, public C {};

int main()
{
	D d{};

	d.testFunc();
}