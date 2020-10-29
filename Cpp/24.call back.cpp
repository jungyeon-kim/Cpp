#include <iostream>
#include <thread>
#include <functional>
#include <chrono>
#include <queue>

using namespace std;
using namespace std::chrono;

// 함수포인터와 호출시간을 가지는 구조체
struct Event
{
	function<void()> callBack{};
	high_resolution_clock::time_point wakeUpTime{};

	constexpr bool operator>(const Event& rhs) const
	{
		return wakeUpTime > rhs.wakeUpTime;
	}
};

// Event 구조체를 가지는 우선순위 큐 자료구조 -> WakeUpTime이 작을수록 우선순위가 높음
priority_queue<Event, vector<Event>, greater<Event>> timerQueue;

// 타이머 큐에 이벤트 추가
void addTimerQueue(function<void()> callBack, int duration)
{
	Event event{ callBack, high_resolution_clock::now() + milliseconds{ duration } };
	timerQueue.push(event);
}

void timerThread()
{
	while (true)
	{
		this_thread::sleep_for(1ms);

		while (true)
		{
			if (timerQueue.empty() || timerQueue.top().wakeUpTime > high_resolution_clock::now()) break;

			//등록된 함수 호출
			timerQueue.top().callBack();
			timerQueue.pop();
		}
	}
}

int main()
{
	addTimerQueue([]() {cout << "call" << endl; }, 1000);
	addTimerQueue([]() {cout << "call" << endl; }, 2000);
	addTimerQueue([]() {cout << "call" << endl; }, 3000);

	timerThread();
}