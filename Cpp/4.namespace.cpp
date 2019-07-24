#include <iostream>

namespace test	// 변수, 함수등의 이름중복을 방지 (여러 사람이 한 프로젝트를 진행할 때)
{
	int val{};	// test에 소속된 변수
}

int val{};	// 무소속 변수

// 사용시 소속(test::)을 붙여주지 않아도 됨.
// 이코드에서 사용시 test소속 변수와 무소속 변수간 모호성 발생
// using namespace test;

int main()
{
	test::val = 10;	// test:: -> test에 소속되었단 의미
	::val = 5;	// :: -> 무소속이란 의미
	std::cout << test::val << " " << ::val;
}