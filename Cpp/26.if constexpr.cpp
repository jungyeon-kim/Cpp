#pragma warning(disable : 4984)

#include <iostream>

using namespace std;

/*
    #if를 대체할 수 있는 if constexpr

    특징: 상수식에 대하여 컴파일타임에 조건검사를 통해 코드를 컴파일 대상에서 제외시킨다.
    장점: 매크로와 다르게 컴파일타임에 수행하기 때문에 템플릿을 활용할 수 있고, 가독성이 높다.

    ※ C++ 17 이전 버전 호환성에 대한 경고가 뜬다. C4984
*/

#define MACRO
constexpr bool CONSTEXPR = true;

int main()
{
    // #if 버전
#ifdef MACRO
    cout << "MACRO" << endl;
#endif

    // if constepxr 버전
    if constexpr (CONSTEXPR)
    {
        cout << "CONSTEXPR" << endl;
    }
}
