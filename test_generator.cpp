#include <iostream>
#include <fstream>
using namespace std;

void changeOutputStream(int testNumber)
{
    char inputFileName[20] = "input/inputXX.txt";
    inputFileName[11] = testNumber/10 + '0';
    inputFileName[12] = testNumber%10 + '0';
    freopen(inputFileName, "w", stdout);

}

void generateTestData()
{
    // Test specific code
    cout<<"Test"<<endl;
}

void createInfoFile(int testsCount)
{
    ofstream infoFile("input/info.txt");
    infoFile<<testsCount<<endl;
    infoFile.close();
}

void generateTest(int testNumber)
{
    changeOutputStream(testNumber);
    generateTestData();
}

void generateTests(int testsCount)
{
    createInfoFile(testsCount);
    for(int i=0;i<testsCount;++i)
    {
        generateTest(i);
    }
}

void createFolders()
{
    system("mkdir input");
    system("mkdir output");
}

int main()
{
    createFolders();
    generateTests(10);
}
