#include <iostream>
#include <thread>
#include <functional>
#include <chrono>
#include <queue>

using namespace std;
using namespace std::chrono;

// �Լ������Ϳ� ȣ��ð��� ������ ����ü
struct Event
{
	function<void()> CallBack{};
	high_resolution_clock::time_point WakeUpTime{};

	constexpr bool operator>(const Event& Rhs) const
	{
		return WakeUpTime > Rhs.WakeUpTime;
	}
};

// Event ����ü�� ������ �켱���� ť �ڷᱸ�� -> WakeUpTime�� �������� �켱������ ����
priority_queue<Event, vector<Event>, greater<Event>> TimerQueue;

// Ÿ�̸� ť�� �̺�Ʈ �߰�
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

			//��ϵ� �Լ� ȣ��
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