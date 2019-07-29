#include <iostream>

using namespace std;

//	언제 static을 쓰는가?: 같은타입의 여러 객체가 값을 공유하고 싶을 때 (주로 Singleton)

/*
	클래스 내부 static의 주요특징)
	1. 클래스 안에서 선언되었지만 클래스의 멤버는 아니다.
	2. 접근지정자의 영향을 받는다 (private면 외부에서 액세스 불가)
	3. 모든 객체가 공유해 사용 가능하다.
	4. 프로그램이 실행되면 바로 메모리에 저장되고 이 과정은 해당 객체가 생성되기 이전이기 때문에,
	   외부에서 정의를 해주어야 하며, 자동으로 초기화를 해주지 않기 때문에 초기화도 해주어야 한다.
	   예외적으로 const나 constexpr 키워드가 붙으면 내부에서 초기화가 가능하다.
*/

class Test
{
private:
	static int data;				// 내부에서 초기화 불가능 (빈껍데기)
public:
	static constexpr int MAX{ 10 };	// 내부에서 초기화 가능
public:
	int getData() const { return data; }
	void setData(int rhs) { data = rhs; }
};

int Test::data{};

int main()
{
	Test t[Test::MAX]{};

	t[0].setData(1);

	for (const auto& i : t)	// data를 static으로 선언안할 시 t[0]만 값이 바뀜
		cout << i.getData() << endl;
}