#include <iostream>

using namespace std;

/*
	typedef:	어떤 타입에 대한 별명을 만든다.
	using:		typedef와 같은기능. (17번에서 더 많은 기능을 설명한다.)
*/

/*
	static_cast<>():		기본 형변환, 상속관계 형변환(up, down 가능)
							컴파일에서 연산
	dynamic_cast<>():		상속관계 형변환(up만 가능) -> 가상함수를 가지는 클래스는 down도 가능
							런타임에서 연산 -> static_cast()보다 안정성↑ (캐스팅이 적합하지 않으면 에러를 발생)
	const_cast<>():			const특성을 없앤다.
	reinterpret_cast<>():	관계가 상관없는 형변환 (전혀 관계가 없는 타입으로 캐스팅이 가능하기때문에 위험하다.)

	※	다운캐스팅은 꼭 필요한 경우에만 사용하고 static_cast보다 dynamic_cast를 권장한다.
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
	// typedef float Myfloat;	// 비추천
	using Myfloat = float;		// 추천

	// 일반적인 캐스팅
	Myfloat data{ 3.14 };
	cout << static_cast<int>(data) << endl;
	cout << data << endl;

	// 상속관계 캐스팅
	Test *obj1{};
	TestEx *obj2{ dynamic_cast<TestEx*>(obj1) };	// down casting
}