/*********************************
 * @Author: wang
 * @LastEditTime: 2022-03-08 14:33:17
 * @FilePath: \w1\test.cpp
 * @Description:
 *********************************/
#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

int main()
{
    string str("some string");
    // range for 语句
    for (auto &c : str)
    {
        c = toupper(c);
    }
    cout << str << endl;
    return 0;
}