#include <iostream>

using namespace std;

/*
	static_cast<>()	-	기본 형변환, 상속관계 형변환(up, down)
						컴파일에서 연산
	dynamic_cast<>()	-	상속관계 형변환(up) -> 가상함수를 가지는 클래스는 down도 가능
							런타임에서 연산
							static보다 안정성↑ (캐스팅이 적합하지 않으면 에러를 발생시킴)
	const_cast<>()	-	포인터와 참조자의 const 제거
	reinterpret_cast<>()	-	관계가 상관없는 형변환
*/

/*
	※	다운캐스팅은 꼭 필요한 경우에만 사용하고 static_cast보다 dynamic_cast를 사용해야한다.
*/

class Test
{
public:
	Test() {}
	~Test() {}

	virtual void testFunc() { cout << "Test" << endl; }
};

class TestEx : public Test
{
public:
	TestEx() {}
	~TestEx() {}

	virtual void testFunc() override { cout << "TestEx" << endl; }
};

int main()
{
	// 일반적인 경우
	float data{ 3.14 };
	cout << static_cast<int>(data) << endl;
	cout << data << endl;

	// 상속관계 경우
	Test *obj1{};
	TestEx *obj2{ dynamic_cast<TestEx*>(obj1) };	// down casting
}