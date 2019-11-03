#include <iostream>

using namespace std;

/*
	템플릿:	제네릭 프로그램(재사용 가능한 코드를 만드는 것)의 가장 기본적인 도구
			사용하지않는다면 인스턴스화되지 않는다.

	주의점)
	※	무분별한 템플릿의 남용은 위험을 초래한다.
		오류 내용이 상대적으로 추상적이어서 디버깅이 힘들어질뿐더러,
		대부분 컴파일 동작에 코드가 생성되기 때문에 컴파일 시간이 길어진다.
		크기가 클수록(템플릿 클래스같은), 찍어내는 종류가 많을 수록 더더욱 메모리를 차지하게되고,
		그만큼 실행파일의 크기가 커진다. (캐시 적중율이 낮아진다.)
	※	파일분할시 일반적인 경우 컴파일시 소스파일에 대한 obj파일을 생성하고
		링커는 이 obj파일을 이용하여 헤더와 소스를 연결시킨다.
		하지만, 템플릿의 경우 아직 사용하지않은 상태라면 코드를 인스턴스화 시키지 않기때문에,
		컴파일 과정에서 obj파일에 템플릿에 대한 구현을 하지 않게되고 템플릿의 인스턴스화보다 
		링킹작업이 먼저 일어나기 때문에 링커는 obj파일에서 해당 내용을 찾을 수 없어 오류가 발생한다.
		때문에 템플릿은 헤더파일에 선언과 정의가 모두 존재해야한다.
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
