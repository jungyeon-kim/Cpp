#include <iostream>
#include <thread>
#include <mutex>
#include <vector>

using namespace std;

/*
	프로세스:	실행중인 프로그램
	스레드:		프로그램 실행의 흐름

	Heterogeneous:	작업을 쪼개 용도별로 스레드에 맡기는 스타일 (클라이언트에서 주로 사용)
	Homogenous:		작업을 쪼개 구분없이 스레드에 맡기는 스타일 (서버에서 주로 사용)

	※ 스레드 각각에 고유한 스택이 존재 (데이터, 코드, 힙은 공유)
	※ 스레드가 많다고 좋은 것이 아님. 코어의 개수에 맞추는게 일반적 (코어보다 많은 스레드 생성시 문맥전환에 대한 오버헤드 발생)
*/

/*
	문제점)
	DataRace:	같은 메모리를 여러 스레드에서 읽고 쓰는 경우 (반드시 하나 이상의 쓰기 동작이 있어야함. 그래야 문제가 발생하기에)
				-> mutex(상호배제)로 해결
*/

/*
	thread)
	join():		해당 스레드가 종료될 때까지 기다린다. (아직 스레드가 실행중인데 프로그램이 종료되면 안되기 때문)
	detach():	해당 스레드 객체에 연결된 스레드를 떼어낸다. (스레드는 계속 실행되지만 제어할 수 없음, join()불가능)
	joinable():	해당 스레드를 join()으로 기다릴 수 있는 상태인지 bool값을 반환한다. (detach된 상태라면 false 반환)

	mutex)
	lock():		어떤 자원을 다른 스레드에서 사용중이면 대기. 사용중이 아니면 자신의 스레드에서 사용중 표시 (성능저하)
	unLock():	사용중 표시를 지움

	※ mutex 객체는 전역변수여야함 (같은 자원을 사용하는 스레드마다 mutex도 같은 객체여야하기 때문)
*/

// join()과 detach()에 대한 실습코드
void printID(int myID)
{
	cout << "My Thread ID: " << myID << endl;
}

void solution1()
{
	vector<thread> v{};

	for (int i = 0; i < 10; ++i) v.emplace_back(printID, i);
	for (auto& thread : v) thread.join();

	v.clear();
	cout << "---------------------------------" << endl;

	for (int i = 0; i < 10; ++i)
	{
		v.emplace_back(printID, i);
		v[i].detach();
	}
	for (auto& thread : v)
		if (thread.joinable())	// join()을 호출할 수 있는지 확인
			thread.join();		// detach되면 join()이 호출되지 않기 때문에 스레드 실행도중 프로그램이 종료된다.
}

// 상호배제, 임계영역에 대한 실습코드
int sum{};	// 스레드 공유자원
mutex m{};	// mutex 객체

void add()
{
	int localSum{};

	// 부하를 유발하는 lock을 사용하지않고 연산하기 위해 로컬변수를 사용
	for (int i = 0; i < 1000000; ++i) ++localSum;

	m.lock();			// lock을 걸어주지않으면 DataRace에 의해 sum은 예상과 다른 값이 됨
	sum += localSum;	// 로컬변수의 결과를 전역변수(공유자원)에 더해줄때만 lock을 사용
	m.unlock();
}

void solution2()
{
	vector<thread> v{};

	for (int i = 0; i < 10; ++i) v.emplace_back(add);
	for (auto& thread : v) thread.join();

	cout << sum << endl;
}

int main()
{
	//solution1();
	solution2();
}