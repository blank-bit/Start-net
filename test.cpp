/*********************************
 * @Author: wang
 * @LastEditTime: 2022-03-02 15:53:14
 * @FilePath: \练习\test.cpp
 * @Description:
 *********************************/
#include <iostream>
#include <windows.h>
using namespace std;

DWORD WINAPI Fun(LPVOID lpParamter)
{
    for (int i = 0; i < 10; i++)
        cout << "A Thread Fun Display!" << endl;
    return 0L;
}

int main()
{
    HANDLE hThread = CreateThread(NULL, 0, Fun, NULL, 0, NULL);
    CloseHandle(hThread);
    for (int i = 0; i < 10; i++)
        cout << "Main Thread Display!" << endl;
    return 0;
}