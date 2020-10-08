#include <iostream>

using namespace std;

/*
	상속	-	1. 코드를 재사용하는 방법
			2. 규모 확장 / 개선
			3. is-a 관계	(남자는 사람이다 o)
						(사람은 머리를 가지고있다 x)

	※ 자식에서 부모멤버 초기화 금지 -> 멤버변수는 웬만하면 private
*/

/*
	가상함수			-	객체의 마지막 오버라이딩된 함수 호출
	순수가상함수		-	정의 없이 선언만 있는 가상함수
						부모에 순수가상함수가 있으면 자식에 무조건 오버라이딩되어야함
						순수가상함수가 존재하는 클래스(추상클래스, 인터페이스)는 객체를 생성할 수 없음
	가상함수테이블	-	하나 이상의 가상함수가 존재하는 클래스에서는 가상함수테이블을 생성해 오버라이딩된
						함수의 포인터를 찾아 올바른 버전의 함수가 실행되도록 한다.

	※	일반함수는 접근형식, 가상함수는 실형식을 따른다.
	※	부모에만 virtual 키워드가 있어도 잘 동작되지만, 확실히하기위해 자식에도 virtual 키워드를 선언하고,
		override 키워드까지 선언해주는게 좋다.
	※	static 함수는 클래스 멤버가 아니기때문에 오버라이딩할 수 없다. (= 가상함수가 될 수 없다.)
	※	부모에 오버로딩된 함수가 하나라도 자식에 재정의 되어있다면,
		자식에 재정의되지않은 부모의 오버로딩된 함수는 "접근형식이 자식인" 객체에서 접근할 수 없다.
		(부모로 업캐스팅하거나, 접근형식이 부모라면 가능하다.)
*/

/*
	virtual		-	해당 함수를 "가상화"시킨다.
	override	-	해당 함수가 오버라이딩된 것이 아니라면 오류를 발생시킴
	final		-	1. 가상함수 재정의 방지
					2. 상속 불가능한 클래스 지정
*/

// 부모클래스
class Test	// final
{
public:
	Test() { cout << "Test()" << endl; }
	Test(int val) { cout << "Test(int val)" << endl; }
	// 실형식의 소멸자가 불리는 것을 보장
	virtual ~Test() { cout << "~Test()" << endl; }

	//virtual void virtualFunc() = 0;	// 순수가상함수
	virtual void virtualFunc() { cout << "Test::virtualFunc()" << endl; }
};

// 자식클래스
class TestEx : public Test	// 99%는 public으로 상속
{
public:
	// 부모가 Test(int val)를 호출하도록 명시적 선언
	TestEx() : Test(1) { cout << "TestEx()" << endl; }
	virtual ~TestEx() override { cout << "~TestEx()" << endl; }

	virtual void virtualFunc() override { cout << "TestEx::virtualFunc()" << endl; }
};

int main()
{
	//↓접근형식	↓실형식
	Test* obj{ new TestEx };
	obj->virtualFunc();
	delete obj;
}