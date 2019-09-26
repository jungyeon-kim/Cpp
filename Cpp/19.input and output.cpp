#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/*
	ios_base::
	app:		작업 시작전 스트림의 위치(수행할 위치)를 파일 제일 끝으로 옮긴다.
	ate:		파일을 열자마자 스트림의 위치를 파일 제일 끝으로 옮긴다.
	binary:		바이너리 모드로 데이터를 입출력한다. (반대는 텍스트 모드)
	in:			입력 모드로 파일을 연다.
	out:		출력 모드로 파일을 연다.
	trunc:		파일을 열고 기존데이터는 삭제한다.
*/

int main()
{
	string str{"hello"};
	ifstream in{ "test.txt", ios_base::binary };
	ofstream out{ "test.txt", ios_base::app };

	in >> str;	// 문자열 str에 test.txt의 문자열을 입력한다.
	out << str;	// str을 test.txt에 출력한다.
	// 결론적으로 test.txt의 문자열이 출력될것이다.
}