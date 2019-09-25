#include <iostream>

using namespace std;

/*
	1. 할당과 해제는 쌍을 이루어야한다.
	2. 해제시 조건문으로 값이 nullptr인지 확인한다.
	3. 해제후에는 반드시 nullptr을 대입해주어야한다.

	메모리 릭:		할당된 메모리를 해제 하지않아 누수가 생기는 것
	댕글링 포인터:	이미 해제된 메모리를 가리키는 포인터
*/

/*
	constexpr:		상수만 초기화가능 혹은 상수로 캐스팅됨, 컴파일 과정에 처리됨 (빠름)
	mutable:		const 타입의 영역에서 해당 값의 수정을 가능하게 해줌
	explicit:		묵시적 형변환 방지 (생성자와 변환연산자에 사용)
*/

class Test
{
private:
	mutable int val{};
public:
	static constexpr int MAX{ 5 };
public:
	Test() = default;
	Test(int i) : val{ i } {}
	~Test() { cout << "~Test()" << endl; }

	explicit operator int() const { return val; }	// int()변환 연산자 오버로딩 (반환형식을 기재하지 않는다.)

	void print() const
	{
		++val;	// mutable 형식이기 때문에 수정가능
		cout << val << endl;
	}
};

int main()
{
	Test t{ 10 };
	int i = static_cast<int>(t);	// int()변환 연산자가 explicit이라 명시적으로 타입캐스팅을 해주어야한다.
	int j{ t };						// 근데 얘는 왜 될까..??

	///////////////////////////////////////////////////////////////////////

	Test* test{ new Test[Test::MAX] };
	
	for (int i = 0; i < Test::MAX; ++i)
		test[i].print();

	if (test)
	{
		delete[] test;			// 해제
		test = nullptr;			// 댕글링포인터 방지
	}

	if (test)
		for (int i = 0; i < Test::MAX; ++i)
			test[i].print();
}