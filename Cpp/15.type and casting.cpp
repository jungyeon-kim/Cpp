#include <iostream>

using namespace std;

/*
	typedef:	어떤 타입에 대한 별명을 만든다.
	using:		typedef와 비슷한기능. (다음 파일에 추가 기능을 설명)
*/

/*
	static_cast<>():		기본 형변환, 상속관계 형변환(up, down 가능)
							컴파일에서 연산
	dynamic_cast<>():		상속관계 형변환(up만 가능) -> 가상함수를 가지는 클래스는 down도 가능
							런타임에서 연산 -> static_cast()보다 안정성↑ (캐스팅이 적합하지 않으면 에러를 발생)
	const_cast<>():			const특성을 없앤다.
	reinterpret_cast<>():	관계가 상관없는 형변환 (전혀 관계가 없는 타입으로 캐스팅이 가능하기때문에 위험하다.)

	※	Reflection:	런타임에 실시간으로 객체의 정보를 가져온다.		(현재 c++에 없는 기능)
					RTTI 보다 더 많은 기능을 제공					(런타임에 함수 생성 등)
		RTTI:		c++에서의 Reflection 하위호환 기능			(dynamic_cast가 대표적 예)
					Reflection과 다르게 RTTI 옵션을 ON / OFF 가능	(메타데이터 생성의 오버헤드 때문)
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
	Test* obj1{};
	TestEx* obj2{ dynamic_cast<TestEx*>(obj1) };	// down casting
}