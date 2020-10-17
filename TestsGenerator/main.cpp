#include "TestsDataGenerator.h"
#include "TestsOutputGenerator.h"
using namespace std;
int main()
{
    TestsDataGenerator testsDataGenerator;
    testsDataGenerator.run();
    TestsOutputGenerator testsOutputGenerator;
    testsOutputGenerator.run();
}
