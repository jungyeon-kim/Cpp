#include <iostream>

using namespace std;

/*
	enum과 enum class
	
	enum:			네이밍 중복이 발생할 수 있다, 묵시적 형변환이 가능하다.
	enum class:		네이밍 중복이 발생할 수 없다, 묵시적 형변환이 불가능하다.
*/

enum { PLAYER };
//enum { PLAYER };					// 중복
enum class Test { PLAYER };
enum class Other { PLAYER };		// OK

int main()
{
	int val{ PLAYER };				// OK
	//int other{ Test::PLAYER };	// Error
}