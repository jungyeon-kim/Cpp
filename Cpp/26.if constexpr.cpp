#pragma warning(disable : 4984)

#include <iostream>

using namespace std;

/*
    #if�� ��ü�� �� �ִ� if constexpr

    Ư¡: ����Ŀ� ���Ͽ� ������Ÿ�ӿ� ���ǰ˻縦 ���� �ڵ带 ������ ��󿡼� ���ܽ�Ų��.
    ����: ��ũ�ο� �ٸ��� ������Ÿ�ӿ� �����ϱ� ������ ���ø��� Ȱ���� �� �ְ�, �������� ����.

    �� C++ 17 ���� ���� ȣȯ���� ���� ��� ���. C4984
*/

#define MACRO
constexpr bool CONSTEXPR = true;

int main()
{
    // #if ����
#ifdef MACRO
    cout << "MACRO" << endl;
#endif

    // if constepxr ����
    if constexpr (CONSTEXPR)
    {
        cout << "CONSTEXPR" << endl;
    }
}
