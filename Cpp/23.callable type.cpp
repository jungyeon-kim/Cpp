#include <iostream>
#include <functional>

using namespace std;

class Dog
{
public:
	int operator()(int param)	// ()연산자 오버로딩
	{
		cout << "int operator()(int param)" << endl;
		return param * param;
	}
};

void func() { cout << "void func()" << endl; }
void func(int i) { cout << "void func(int i)" << endl; }
void func(int i, int j) { cout << "void func(int i, int j)" << endl; }

template <typename T, typename... Param>
void callBack(function<T> func, Param... param)
{
	func(param...);
}

int main()
{
	// 호출가능타입 정리

	// 1. 일반함수
	void(*f1)() { func };
	f1();
	cout << "일반함수: " << typeid(f1).name() << endl;

	// 2. 람다
	auto f2{ []() {cout << "lambda[]()" << endl; } };
	f2();
	cout << "람다함수: " << typeid(f2).name() << endl;

	// 3. 함수객체: ()연산자를 overloading한 클래스
	Dog dog{};
	auto f3{ dog };
	f3(3);
	cout << "함수객체: " << typeid(f3).name() << endl;

	// 4. std::funtion
	function<void(int)> f4{ static_cast<void(*)(int)>(func) };
	f4(1);
	cout << "std::function: " << typeid(f4).name() << endl;

	// 5. std::bind
	auto f5{ bind(static_cast<void(*)(int, int)>(func), 1, 1) };
	f5();
	cout << "std::bind: " << typeid(f5).name() << endl;

	// 6. callback
	callBack<void(int)>(static_cast<void(*)(int)>(func), 1);
}