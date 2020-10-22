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
	function<void()> CallBack{};
	high_resolution_clock::time_point WakeUpTime{};

	constexpr bool operator>(const Event& Rhs) const
	{
		return WakeUpTime > Rhs.WakeUpTime;
	}
};

// Event 구조체를 가지는 우선순위 큐 자료구조 -> WakeUpTime이 작을수록 우선순위가 높음
priority_queue<Event, vector<Event>, greater<Event>> TimerQueue;

// 타이머 큐에 이벤트 추가
void AddTimerQueue(function<void()> CallBack, int Duration)
{
	Event Event{ CallBack, high_resolution_clock::now() + milliseconds{ Duration } };
	TimerQueue.push(Event);
}

void TimerThread()
{
	while (true)
	{
		this_thread::sleep_for(1ms);

		while (true)
		{
			if (TimerQueue.empty() || TimerQueue.top().WakeUpTime > high_resolution_clock::now()) break;

			Event Event{ TimerQueue.top() };
			TimerQueue.pop();

			//등록된 함수 호출
			Event.CallBack();
		}
	}
}

int main()
{
	AddTimerQueue([]() {cout << "call" << endl; }, 1000);
	AddTimerQueue([]() {cout << "call" << endl; }, 2000);
	AddTimerQueue([]() {cout << "call" << endl; }, 3000);

	TimerThread();
}