#include "TestsDataGenerator.h"

using namespace std;

TestsDataGenerator::TestsDataGenerator()
{
    //ctor
}

TestsDataGenerator::~TestsDataGenerator()
{
    //dtor
}

void TestsDataGenerator::changeOutputStream(int testNumber) const
{
    char inputFileName[20] = "input/inputXX.txt";
    inputFileName[11] = testNumber/10 + '0';
    inputFileName[12] = testNumber%10 + '0';
    freopen(inputFileName, "w", stdout);

}

void TestsDataGenerator::generateTestData() const
{
    // Test specific code
    cout<<"Test"<<endl;
}

void TestsDataGenerator::createInfoFile(int testsCount) const
{
    ofstream infoFile("input/info.txt");
    infoFile<<testsCount<<endl;
    infoFile.close();
}

void TestsDataGenerator::generateTest(int testNumber) const
{
    changeOutputStream(testNumber);
    generateTestData();
}

void TestsDataGenerator::generateTests(int testsCount) const
{
    createInfoFile(testsCount);
    for(int i=0;i<testsCount;++i)
    {
        generateTest(i);
    }
}

void TestsDataGenerator::createFolders() const
{
    system("mkdir input");
    system("mkdir output");
}

void TestsDataGenerator::run() const
{
    createFolders();

    generateTests(10);
}
