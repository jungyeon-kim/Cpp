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
	function<void()> callBack{};
	high_resolution_clock::time_point wakeUpTime{};

	constexpr bool operator>(const Event& rhs) const
	{
		return wakeUpTime > rhs.wakeUpTime;
	}
};

// Event ����ü�� ������ �켱���� ť �ڷᱸ�� -> WakeUpTime�� �������� �켱������ ����
priority_queue<Event, vector<Event>, greater<Event>> timerQueue;

// Ÿ�̸� ť�� �̺�Ʈ �߰�
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

			//��ϵ� �Լ� ȣ��
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