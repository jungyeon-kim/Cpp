#include <iostream>

using namespace std;

/*
	템플릿:	제네릭 프로그램(재사용 가능한 코드를 만드는 것)의 기본적인 도구
			사용하지않는다면 코드가 생성(템플릿 인스턴스화)되지 않는다.
			반대로 "컴파일중" 사용되는 부분을 만나면 코드가 생성된다.
			가능하다면 컴파일 타임에 연산한다. -> TMP
			정적 다형성이다. (가상 테이블을 생성하지않는다.)

	주의점을 알기 전에)
		프로그램 동작과정:	전처리 -> 컴파일 -> 링크
		전처리:				컴파일전 수행되는 작업 (include는 해당 헤더로 치환되고, define은 해당 정의로 치환됨)
		C컴파일:				코드를 어셈블리어로 번역
		어셈블컴파일:			어셈블리어를 기계어로 번역한 오브젝트파일 생성
		링크:				각각의 오브젝트 파일들을 연결시켜 실행파일을 생성
		컴파일타임:			코드, 스택, 데이터 영역의 크기 결정
		런타임:				힙 영역의 크기 결정

	주의점)
	※	무분별한 템플릿의 남용은 위험을 초래한다.
		오류 내용이 상대적으로 추상적이어서 디버깅이 힘들어질뿐더러,
		TMP같은 경우 컴파일 타임에 수많은 코드를 생성하고 연산하기 때문에 컴파일 시간이 상대적으로 더 길어진다.
	※	선언과 정의가 한곳에 들어가 있어야한다.
		컴파일중 사용되는 부분을 만나면 해당 코드가 생성되어야 하는데, 이 때 형태를 알고 있어야하기 때문이다.
*/

template <typename T>
class Test
{
public:
	template <typename E>
	void print(E val);
};

// 절대로 아래 두 템플릿 매개변수를 한 곳에 같이 써서는 안되고 쓸수도 없다.
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
	t1.print(pi<float>);	// 템플릿 매개변수 T가아닌 E를 사용함으로써 축소변환이 일어나지 않음
	t2.print(pi<double>);	// 위와 동일
	t3.print("hello");		// string형 외의 자료형 불가
}
