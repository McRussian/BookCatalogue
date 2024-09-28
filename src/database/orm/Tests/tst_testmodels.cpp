#include <QtTest>

// add necessary includes here

class TestModels : public QObject
{
    Q_OBJECT

public:
    TestModels();
    ~TestModels();

private slots:
    void test_case1();

};

TestModels::TestModels()
{

}

TestModels::~TestModels()
{

}

void TestModels::test_case1()
{

}

#include "tst_testmodels.moc"
