#ifndef TESTSDATAGENERATOR_H
#define TESTSDATAGENERATOR_H
#include <iostream>
#include <fstream>

class TestsDataGenerator
{
public:
    TestsDataGenerator();
    virtual ~TestsDataGenerator();
    void run() const;

protected:

private:
    void changeOutputStream(int testNumber) const;
    void generateTestData() const;
    void createInfoFile(int testsCount) const;
    void generateTest(int testNumber) const;
    void generateTests(int testsCount) const;
    void createFolders() const;
};

#endif // TESTSDATAGENERATOR_H
