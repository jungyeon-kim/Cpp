#include <iostream>

using namespace std;

/*
	템플릿:	제네릭 프로그램(재사용 가능한 코드를 만드는 것)의 가장 기본적인 도구
			사용하지않는다면 인스턴스화되지 않는다.
	
	※	파일분할시 일반적인 경우 컴파일시 소스파일에 대한 obj파일을 생성하고 
		링커는 이 obj파일을 이용하여 헤더와 소스를 연결시킨다.
		하지만, 템플릿의 경우 아직 사용하지않은 상태라면 인스턴스화 시키지 않기때문에,
		컴파일 과정에서 소스파일에 대한 obj파일을 생성하지 않게되고 링커는 obj파일을 찾을 수 없어 오류가 발생한다.
		때문에 템플릿은 헤더파일에 선언과 정의가 모두 존재해야한다.
		
*/

// version 1
class Test
{
public:
	template <typename T>
	void print(T val)
	{
		cout << " " << val;
	}
};

// version 2
template <typename T>
class Test2
{
public:
	void print(T val)
	{
		cout << " " << val;
	}
};

int main()
{
	Test test{};

	test.print(5);
	test.print(5.5);

	Test2 <int> test2_1{};
	Test2 <float> test2_2{};

	test2_1.print(5);
	test2_2.print(5.5);
}