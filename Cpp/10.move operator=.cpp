#include <iostream>
#include <memory>

using namespace std;

/*
	클래스가 동적할당 메모리를 가진다?
	-> 반드시 소멸자, 복사생성자, 대입연산자를 재정의 해주어야한다!

	이동시맨틱(이동생성자 or 이동대입연산자)을 명시해주었다?
	-> 복사생성자 or 대입연산자를 명시해주어야한다!
 */

/*
	대입연산자가 자신을 반환하는 이유 ->
	A = B = C;와 같은 경우 B = C의 연산이후 반환값이 없다면 A에 대입할 수가 없다.
*/

class Test
{
private:
	//int* data{};
	unique_ptr<int> data{};
public:
	Test() 
	{ 
		cout << "Test()" << endl;
		//data = new int{ 10 };
		data = make_unique<int>(10);
	}
	~Test()
	{
		cout << "~Test()" << endl;
		//if (data)
		//{
		//	delete data;
		//	data = nullptr;
		//}
	}

	Test& operator=(const Test &rhs)		// 대입연산자
	{
		cout << "Test& operator=(const Test& rhs)" << endl;
		//if (data && this != &rhs) delete data;	// 할당된 값 해제 (메모리 릭 방지, 자신 대입 예외처리)
		//data = new int{ *rhs.data };
		data = make_unique<int>(*rhs.data);
		return *this;
	}
	Test& operator=(Test &&rhs) noexcept	// 이동대입연산자
	{
		cout << "Test& operator=(Test&& rhs)" << endl;
		//if (data && this != &rhs) delete data;
		data = std::move(rhs.data);
		//rhs.data = nullptr;	// 안해주면 delete가 일어남 (중복오류)
		return *this;
	}

	int getDataValue() const { return *data; }						// return by value (복사도 가능 -> *data는 value이기 때문)
	const unique_ptr<int>& getDataAddress() const { return data; }	// return by reference	(unique_ptr은 복사가 불가능)
	void setData(int nParam) { *data = nParam; }				// data의 주소값은 안바뀌고 값만 바뀜

};

int main()
{
	Test a{};	// 기본생성자 호출
	Test b{};	// 기본생성자 호출
	
	cout << "b: " << b.getDataAddress() << endl;
	
	Test c{}; // 기본생성자 호출

	b = a;	// b.operator=(a);	// 대입연산자 호출
	c = std::move(b);			// 이동대입연산자 호출

	cout << "a: " << a.getDataAddress() << " b: " << b.getDataAddress() << " c: " << c.getDataAddress() << endl;
}