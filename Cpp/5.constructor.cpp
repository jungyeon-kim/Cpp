#include <iostream>
#include <memory>

using namespace std;

/*
	클래스 = 구조체 + 함수 + 접근제어 + 상속
	생성자: 객체(class)가 생성될 때 호출
	소멸자: 객체(class)가 사라질 때 호출
	생성자 초기화 리스트:	생성자와 멤버 변수의 초기화가 동시에 일어난다. -> 정의부에서 초기화하는 것보다 효율적
							생성자 초기화 리스트가 아닌, 멤버 변수의 선언 순서로 초기화 된다.
*/

/*
	객체 생성시 명시되어있는 생성자가 없다면 디폴트 생성자가 불린다.
	명시되어 있는 생성자가 하나라도 있다면 디폴트 생성자는 불리지 않는다.
*/

class Test
{
private:
	int val{};
public:
	Test() = default;
	Test(int n) : val{ n } {}	// 생성자 초기화 리스트
	~Test() = default;
};

int main()
{
	Test t1{}; // 생성자 호출
	unique_ptr<Test> t2{ make_unique<Test>() };	// 생성자 호출
}	// <- 지역변수의 소멸시점, LIFO (소멸자 호출)