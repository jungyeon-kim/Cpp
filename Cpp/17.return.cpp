#include <iostream>

using namespace std;

/*
	return by value:		값으로 반환 -> 복사 발생
	return by reference:	참조로 반환
	return by address:		주소로 반환
*/

class Test
{
private:
	int x{}, y{}, z{};

public:
	int getX() const { return x; }					// return by value
	void setX(int param) { x = param; }

	const int& getY() const { return y; }			// return by reference
	void setY(int param) { y = param; }

	const int* getZ() const { return &z; }			// return by address
	void setZ(int param) { z = param; }
};

int main()
{
	Test t;

	t.setX(10);
	t.setY(t.getX());
	t.setZ(t.getY());

	cout << t.getX() << " " << t.getY() << " " << t.getZ() << endl;
}