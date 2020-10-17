#include <iostream>
#include <fstream>
using namespace std;

struct TestsInfo {
    int testsCount;
};

void changeStreams(int testNumber)
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

void generateAnswer()
{
    //Problem specific code
    cout<<"TEST"<<endl;
}

TestsInfo extractTestsInfo()
{
    TestsInfo readTestsInfo;
    ifstream testsInfoFile("input/info.txt");
    testsInfoFile>>readTestsInfo.testsCount;
    cout<<readTestsInfo.testsCount;
    testsInfoFile.close();
    return readTestsInfo;
}

void generateTestAnswers(TestsInfo testInfo)
{
    for(int i=0;i<testInfo.testsCount;++i)
    {
        changeStreams(i);
        generateAnswer();
    }
    fclose(stdin);
    fclose(stdout);
}

void createTestsArchive()
{
    system("7z d HackerrankTestsArchive.zip * -r");
    system("7z a HackerrankTestsArchive.zip input");
    system("7z a HackerrankTestsArchive.zip output");
}

int main()
{
    TestsInfo testsInfo;
    testsInfo = extractTestsInfo();
    generateTestAnswers(testsInfo);
    createTestsArchive();
}
