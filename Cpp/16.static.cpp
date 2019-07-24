#include <iostream>

using namespace std;

// 언제 static을 쓰는가?: 같은타입의 여러 객체가 값을 공유하고 싶을 때 (주로 Singleton)

class Test
{
private:
	static int data;	// 빈 껍데기
public:
	int getData() const { return data; }
	void setData(int rhs) { data = rhs; }
};

int Test::data{};		// 외부에서 초기화를 해주어야함
						// but, 정적멤버(const)는 클래스 내부에서 초기화 가능

int main()
{
	Test t[10]{};

	t[0].setData(10);

	for (const auto& i : t)	// data를 static으로 선언안할 시 t[0]만 10이 됨
		cout << i.getData() << endl;
}