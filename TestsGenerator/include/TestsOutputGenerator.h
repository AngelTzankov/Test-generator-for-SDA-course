#ifndef TESTSOUTPUTGENERATOR_H
#define TESTSOUTPUTGENERATOR_H
#include <iostream>
#include <fstream>


struct TestsInfo {
    int testsCount;
};

class TestsOutputGenerator
{
public:
    TestsOutputGenerator();
    virtual ~TestsOutputGenerator();
    void run() const;
protected:

private:
    TestsInfo testInfo;
    void changeStreams(int testNumber) const;
    void generateAnswer() const;
    TestsInfo extractTestsInfo() const;
    void generateTestAnswers(TestsInfo testInfo) const;
    void createTestsArchive() const;
};

#endif // TESTSOUTPUTGENERATOR_H
