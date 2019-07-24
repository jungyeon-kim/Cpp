#include <iostream>

using namespace std;

void test(int a = 4, int b = 0)
{
	cout << "a: " << a << " b: " << b << endl;
}

int main()
{
	test();	// 함수 원형을 보면 내용물을 정확히 알 수 없다.
}			// 모호성 발생. (사용 추천 x)