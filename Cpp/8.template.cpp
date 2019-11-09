#include <iostream>

using namespace std;

/*
	템플릿:	제네릭 프로그램(재사용 가능한 코드를 만드는 것)의 가장 기본적인 도구
			사용하지않는다면 코드가 인스턴스화되지 않는다.
			반대로 컴파일중 사용되는 부분을 만나면 인스턴스화된다.

	주의점)
	※	무분별한 템플릿의 남용은 위험을 초래한다.
		오류 내용이 상대적으로 추상적이어서 디버깅이 힘들어질뿐더러,
		대부분 컴파일 동작에 코드가 인스턴스화되기 때문에 컴파일 시간이 길어진다.
		크기가 클수록(템플릿 클래스같은), 찍어내는 종류가 많을 수록 더더욱 메모리를 차지하게되고,
		그만큼 실행파일의 크기가 커진다. (캐시 적중율이 낮아지기 때문에 런타임은 빠를수도 느릴수도 있다.)
	※	선언과 정의가 한곳에 들어가 있어야한다.
		컴파일중 사용되는 부분을 만나면 코드가 인스턴스화 되어야 하는데, 이 때 형태를 알고 있어야하기 때문이다.
*/

template <typename T>
class Test
{
public:
	template <typename E>
	void print(E val);
};

// 절대로 아래 두 템플릿 매개변수를 같이 써서는 안되고 쓸수도 없다.
template <typename T>
template <typename E>
void Test<T>::print(E val)
{
	cout << val << endl;
}

// 템플릿 특수화
template<>
class Test<const char*>		// const char* 타입에 한해서는 print()의 매개변수로 string형만 쓴다.
{
public:
	void print(string str);
};

void Test<const char*>::print(string str)
{
	cout << str << endl;
}

// 템플릿 변수
template <typename T>
constexpr T pi{ 3.141592 };

int main()
{
	Test<int> t1{};
	Test<float> t2{};
	Test<const char*> t3{};

	cout.precision(1024);
	t1.print(pi<float>);	// 템플릿 매개변수 E를 추가해줌으로써 축소변환이 일어나지 않음
	t2.print(pi<double>);	// 위와 동일
	t3.print("hello");	// string형 외의 자료형 불가
}
