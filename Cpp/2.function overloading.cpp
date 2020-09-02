#include <iostream>

using namespace std;

/*
	overloading	-	함수명 동일, 매개변수와 반환타입이 다르거나, 매개변수가 다름 (반환타입만 다른 것은 불가능)
	overriding	-	함수명, 매개변수, 반환타입 동일, 정의가 다름 (상속관계에서 사용) -> 다형성
*/

// 비추천 방식
/*
int print(int a)
{
	return a;
}

double print(double a)
{
	return a;
}
*/

// 추천방식
template <typename T>
T print(T a)
{
	return a;
}

int main()
{
	cout << print(3) << " " << print(3.3) << endl;
}