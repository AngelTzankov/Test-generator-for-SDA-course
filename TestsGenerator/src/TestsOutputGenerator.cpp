#include "TestsOutputGenerator.h"

using namespace std;

TestsOutputGenerator::TestsOutputGenerator()
{
    extractTestsInfo();
}

TestsOutputGenerator::~TestsOutputGenerator()
{
    //dtor
}

void TestsOutputGenerator::changeStreams(int testNumber) const
{
    char inputFileName[20] = "input/inputXX.txt";
    char outputFileName[20] = "output/outputXX.txt";
    inputFileName[11] = testNumber/10 + '0';
    inputFileName[12] = testNumber%10 + '0';
    outputFileName[13] = testNumber/10 + '0';
    outputFileName[14] = testNumber%10 + '0';
    freopen(inputFileName, "r", stdin);
    freopen(outputFileName, "w", stdout);
}

void TestsOutputGenerator::generateAnswer() const
{
    //Problem specific code
    cout<<"TEST"<<endl;
}


TestsInfo TestsOutputGenerator::extractTestsInfo() const
{
    TestsInfo readTestsInfo;
    ifstream testsInfoFile("input/info.txt");
    testsInfoFile>>readTestsInfo.testsCount;
    testsInfoFile.close();
    return readTestsInfo;
}

void TestsOutputGenerator::generateTestAnswers(TestsInfo testInfo) const
{
    for(int i=0;i<testInfo.testsCount;++i)
    {
        changeStreams(i);
        generateAnswer();
    }
    fclose(stdin);
    fclose(stdout);
}

void TestsOutputGenerator::createTestsArchive() const
{
    system("7z d HackerrankTestsArchive.zip * -r");
    system("7z a HackerrankTestsArchive.zip input");
    system("7z a HackerrankTestsArchive.zip output");
}

void TestsOutputGenerator::run() const
{
    TestsInfo testsInfo;
    testsInfo = extractTestsInfo();
    generateTestAnswers(testsInfo);
    createTestsArchive();
}
