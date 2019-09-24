#include <iostream>

using namespace std;

/*
	매크로 함수 (비추천)
	전처리기에 의하여 치환되는 방식이기 때문에, 디버거에서 제대로 보이지않는다.
	#define add(a, b) (a + b)
*/

/*
	인라인 함수 (추천)
	vs속성 인라인함수 사용안함시 선언 -> 사용시에는 안해줘도 무방
	파일을 분할하여 inline 선언시 헤더에 정의까지 해주어야함. 그렇지 않으면 컴파일러가 인식불가
	inline 선언을 하여도 컴파일러가 효율적이지 못하다 판단하면 inline화가 안될 수도 있다. (상대적으로 작은 크기를 인라이닝함)
*/

inline int add(int a, int b)
{
	return a + b;
}

int main()
{
	cout << add(3, 4);
}