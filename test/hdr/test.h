#include <string>

#define TEST_FAILED(msg) line=__LINE__;TestFailed(msg)

int line;

void TestFailed(std::string msg);