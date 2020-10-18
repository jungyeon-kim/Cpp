#include <iostream>
#include <memory>

using namespace std;

/*
	C++에서 클래스와 구조체는 비슷하다. 다만, 구조체는 기본 접근제어자가 public. 클래스는 private.
	생성자: 객체(class)가 생성될 때 호출
	소멸자: 객체(class)가 사라질 때 호출
	생성자 초기화 리스트:		생성자 호출과 동시에 멤버변수가 초기화된다.
							기본타입은 차이가 없지만, 클래스 단위로 놓고보았을때 생성자 정의부 초기화보다 효율적이다.
							부모 생성자 & 자식 생성자 & 자식 대입연산자 or 부모 생성자 & 자식 복사생성자 호출차이
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
	Test t1{ 10 }; // 생성자 호출
	unique_ptr<Test> t2{ make_unique<Test>() };	// 생성자 호출
}	// <- 지역변수의 소멸시점, LIFO (소멸자 호출)