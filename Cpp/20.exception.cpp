#include <iostream>

using namespace std;

int f(int l, int r)
{
	if (!r) throw exception("Divide by Zero");

	return l / r;
}

int main()
{
	try
	{
		cout << f(10, 0);
	}
	catch (const exception& e)
	{
		cout << e.what() << endl;
	}
}