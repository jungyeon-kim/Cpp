#include <iostream>

using namespace std;

/*
	매크로 함수 (비추천)
	전처리기에 의하여 치환되는 방식이기 때문에, 디버거에서 제대로 보이지않는다.
	#define add(a, b) (a + b)
*/

/*
	인라인 함수 (추천)
	함수의 호출을 그 함수의 본문으로 대체한다.
	선언과 정의가 한곳에 들어가 있어야한다. (컴파일 도중에 수행되기 때문에 형태를 알고있어야 하기 때문)
	inline 선언을 하여도 컴파일러가 효율적이지 못하다 판단하면 inline화가 안될 수도 있다. (상대적으로 작은 크기를 인라이닝함)
	vs속성 인라인함수 사용안함시 선언 -> 사용시에는 안해줘도 무방
*/

//	둘다 함수본체가 선언되기 때문에 호출이나 리턴등의 오버헤드가 사라져 일반함수보다 속도가 빠르다.

inline int add(int a, int b)
{
	return a + b;
}

int main()
{
	cout << add(3, 4);
}