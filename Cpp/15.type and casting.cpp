#include <iostream>

using namespace std;

/*
	typedef:	어떤 타입에 대한 별명을 만든다.
	using:		typedef와 비슷한기능. (다음 파일에 추가 기능을 설명)
*/

/*
	static_cast<>():		기본 형변환, 상속관계 형변환(up, down 가능) -> 다운캐스팅을 무조건 허용하므로 위험
							컴파일에서 연산
	dynamic_cast<>():		상속관계 형변환 (기본적으로 up만 가능)
							-> 다운캐스팅 가능여부를 판단하려면 RTTI가 필요한데,
							   이는 가상함수테이블에 만들어지기때문. 따라서, 가상함수를 가지는 클래스는 다운캐스팅도 가능
							런타임에서 연산 -> 캐스팅이 적합하지 않으면 nullptr반환(포인터에 대입) or 예외발생(참조에 대입)
	const_cast<>():			const특성을 없앤다.
	reinterpret_cast<>():	관계가 상관없는 형변환 (전혀 관계가 없는 타입으로 캐스팅이 가능하기때문에 위험)

	※	Reflection:	런타임에 실시간으로 객체의 정보를 가져온다.		(현재 c++에 없는 기능)
					RTTI 보다 더 많은 기능을 제공					(런타임에 함수 생성 등)
		RTTI:		Run Time Type Information -> 가상함수테이블에 존재
					c++에서의 Reflection 하위호환 기능			(dynamic_cast가 대표적 예)
					Reflection과 다르게 RTTI 옵션을 ON / OFF 가능	(메타데이터 생성의 오버헤드 때문)
*/

class Test
{
public:
	Test() {}
	virtual ~Test() {}

	void commonFunc() { cout << "Test::commonFunc" << endl; }
	virtual void virtualFunc() { cout << "Test::virtualFunc" << endl; }
};

class TestEx : public Test
{
public:
	TestEx() {}
	virtual ~TestEx() override {}

	void commonFunc() { cout << "TestEx::commonFunc" << endl; }
	virtual void virtualFunc() override { cout << "TestEx::virtualFunc" << endl; }
};

int main()
{
	// typedef float Myfloat;	// 비추천
	using Myfloat = float;		// 추천

	// 일반적인 캐스팅
	Myfloat data{ 3.14f };
	cout << static_cast<int>(data) << endl;
	cout << data << endl;

	// 상속관계 캐스팅
	Test* obj1{ new TestEx{} };						// up casting
													// Test로 할당하면, TestEx는 생성되지 않으므로 아래에서 다운캐스팅 불가
													// 위 경우를 static_cast로 캐스팅하면 가능하지만, 
													// 생성되지도 않은 자식의 멤버에 접근이 가능하기 때문에 위험
	TestEx* obj2{ dynamic_cast<TestEx*>(obj1) };	// down casting
	obj1->commonFunc();
	obj2->commonFunc();
	dynamic_cast<Test*>(obj2)->commonFunc();		// up casting (접근형식을 캐스팅하므로 commonFunc는 변화O)
	obj1->virtualFunc();
	obj2->virtualFunc();
	dynamic_cast<Test*>(obj2)->virtualFunc();		// up casting (접근형식을 캐스팅하므로 virtualFunc는 변화X)
}