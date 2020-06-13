#include <iostream>

using namespace std;

/*
	생성자	-	1. 기본 생성자
				2. 다중 정의된 생성자
				3. 복사 생성자
						깊은복사: 값을 복사
				4. 이동 생성자
						얕은복사: 주소를 복사
						r-value 참조의 도입으로 임시객체에 한해서 얕은복사를 수행
						임시객체는 const &보다 &&이 우선순위기 때문에 이동생성자가 불림
*/

/*
	임시객체	-	1. 함수 반환이나 연산과정에서 발생
				2. 모두 r-value
				3. 연산이 끝나면 자동 소멸
				4. 임시객체를 참조할경우 참조자의 scope가
					   닫힐 때까지 임시객체도 소멸안함

	※			std::move()는 객체를 r-value로 캐스팅해주는 것 일뿐, 객체를 소멸시킬순 없다.
*/

/*
	int data = 3 + 4;
	data: l-value
	3 + 4: r-value
	7: r-value (임시객체) -> 3과 4가 + 되면서 생성되고
							 연산이 끝나면 사라짐

	int &&a = 3 + 4;	// r-value 참조
	int &b = a;			// l-value 참조
*/

/*
	이동 시맨틱은 예외를 던질 수 없다.
	벡터같은 STL 컨테이너의 경우 공간 재할당시에 이동을 하게되면 이전 공간의 데이터는 사라지기때문이다.
	따라서, 이동 시맨틱에는 noexcept 키워드가 붙어야한다.
*/

class Test
{
private:
	int* data{};
public:
	Test() 
	{ 
		cout << "Test()" << endl; 
		data = new int{ 10 };
	}
	~Test() 
	{ 
		cout << "~Test()" << endl;
		if (data)
		{
			delete data;		// data가 nullptr이라면 해제동작을 건너뜀 (다른곳에서 잘처리해준다면 예외처리 필요x)
			data = nullptr;
		}
	}
	Test(const Test &rhs)	// 복사생성자
	{
		cout << "Test(const Test& rhs)" << endl;
		// 얕은복사			// 문제점	1. lhs의 메모리해제가 일어나면 rhs는 가리키는값이 사라짐 (댕글링포인터)
		//data = rhs.data;	//			2. 소멸자에서 메모리해제 두번일어남 (오류)
		// 깊은복사
		data = new int{ *rhs.data };	// data에 rhs.data의 '값'을 할당
										// rhs.data = 주소값, *rhs.data = 값
	}
	Test(Test &&rhs) noexcept			// 이동생성자: 임시객체라는 점을 고려해 얕은복사를 하여 성능을 높이자.
	{
		cout << "Test(Test&& rhs)" << endl;
		data = rhs.data;	// 얕은복사
		rhs.data = nullptr;	// 안해주면 delete가 두번 일어남 (중복오류)
	}

	const int* getData() const { return data; }	// return by address
	void setData(int nParam) { *data = nParam; }
};

int main()
{
	Test a{};				// 기본생성자 호출

	cout << "a: " << a.getData() << endl;

	Test b{ a };			// 복사생성자 호출 ( 객체가 새롭게 생성될때만! -> b = a;는 대입연산자)
	Test c{ std::move(a) };	// 이동생성자 호출, move: r-value로 캐스팅

	cout << "a: " << a.getData() << "	b: " << b.getData() << "	c: " << c.getData() << endl;
}