#include <QtTest>
#include <../server/functions.cpp>
#include <../server/database_u.h>
// add necessary includes here

class testik : public QObject
{
    Q_OBJECT

public:
    testik();
    ~testik();

private slots:
    void test_case1();
    void test_case2();
    void test_case3();

};

testik::testik()
{

}

testik::~testik()
{

}

void testik::test_case1()
{
    QVERIFY(Database_u::GetInstance()->GetTaskTemplate("test") == QString("tasktemplate"));
}
void testik::test_case2()
{
    std::set<std::pair<int, int>> Task;
    Task.insert(std::make_pair(1,4));
    Task.insert(std::make_pair(2,4));
    Task.insert(std::make_pair(3,1));
    Task.insert(std::make_pair(3,2));
    int vertexes = 4;
    QVERIFY(GetTask2Answer(vertexes,Task)=="1010010100111100");
}
void testik::test_case3()
{
    std::set<std::pair<int, int>> Task;
    Task.insert(std::make_pair(1,4));
    Task.insert(std::make_pair(3,4));
    Task.insert(std::make_pair(5,1));
    Task.insert(std::make_pair(5,2));
    Task.insert(std::make_pair(5,3));
    int vertexes = 5;
    QVERIFY(GetTask3Answer(vertexes,Task)=="0001100001000111010011100");
}
QTEST_APPLESS_MAIN(testik)

#include "tst_testik.moc"
