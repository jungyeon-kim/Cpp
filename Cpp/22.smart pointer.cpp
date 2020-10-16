#include <iostream>
#include <memory>

using namespace std;

/*
	unique_ptr: 자원을 독점 -> 복사가 불가능 (이동시맨틱이나 참조자(&)로 가능)
	shared_ptr: 자원을 공유 -> reference count가 0이되면 객체가 자동으로 소멸
				reference count는 atomic하게 동작한다.
	weak_ptr:	자원을 공유 -> 참조만 할뿐 shared_ptr의 reference counting에 관여되지 않는다.
				shared_ptr에 의존적이기 때문에 직접적으로 포인터에 접근할 수 없다. -> 자체적 생성, 대입 불가능

	reset():	현재 메모리를 해제하고 다른 메모리를 할당한다. (인자가 없을시 해제만 동작)
	release():	메모리는 유지하되 자원의 소유권을 없애고 일반 포인터를 반환한다. (unique_ptr에만 존재)
				release()로 반환한 포인터는 반드시 사용자가 delete 해주어야 한다.
	lock():		자신이 속해있는 shared_ptr을 반환 (weak_ptr에만 존재)
*/

int main()
{
	unique_ptr<int> up{ make_unique<int>(10) };
	shared_ptr<int> sp{ make_shared<int>(10) };
	weak_ptr<int> wp{ make_shared<int>(10) };
	
	//auto p{ up };				// Error
	auto p{ up.release() };		// OK

	//sp = wp;					// Error
	wp = sp;					// OK
	auto q{ wp.lock() };

	cout << p << " " << up << " " << sp << " " << q << endl;
}