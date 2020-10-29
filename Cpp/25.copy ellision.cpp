#include <iostream>

using namespace std;

/*
	RVO:			return 구문에서 생성한 임시객체를 복사과정없이 반환
					최적화 여부에 구애받지 않음
	NRVO:			함수내에서 생성한 임시객체를 복사과정없이 반환
					최적화 여부에 구애받음
	생성자 복사생략:	같은 타입의 임시객체에 대하여 복사생성이 일어날 경우 복사과정 생략
					최적화 여부에 구애받지 않음
*/

class T
{
public:
	T() { cout << "T()" << endl; }
	T(const T& rhs) { cout << "T(const T& rhs)" << endl; }
};

T RVO()
{
	return T{};
}

T NRVO()
{
	T t{};
	return t;
}

int main()
{
	RVO();

	cout << "------------------------------------------" << endl;

	NRVO();

	cout << "------------------------------------------" << endl;

	T t1{ T{} };

	cout << "------------------------------------------" << endl;

	T t2{ t1 };
}