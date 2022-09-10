#include <string>
#include <iostream>
#include "test.h"

void TestFailed(std::string msg)
{
    using namespace std;

    cout << "Test Failed (" << line << "): " << msg << endl;
}