#include <iostream>

using namespace std;

/*
	enum�� enum class
	
	enum:			���̹� �ߺ��� �߻��� �� �ִ�, ������ ����ȯ�� �����ϴ�.		(����õ)
	enum class:		���̹� �ߺ��� �߻��� �� ����, ������ ����ȯ�� �Ұ����ϴ�.	(��õ)
*/

enum { PLAYER };
//enum { PLAYER };					// �ߺ�
enum class Test { PLAYER };
enum class Other { PLAYER };		// OK

int main()
{
	int val{ PLAYER };				// OK
	//int other{ Test::PLAYER };	// Error
}