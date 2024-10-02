#ifndef TESTTOOLS_H
#define TESTTOOLS_H

#include <QtTest>

// add necessary includes here
#include "../src/tools/tools.h"

class TestTools : public QObject
{
    Q_OBJECT

public:
    TestTools();
    ~TestTools();

private slots:
    void test_normilize_string();
    void test_capitalize_string();

};

TestTools::TestTools()
{

}

TestTools::~TestTools()
{

}

void TestTools::test_normilize_string()
{
    QCOMPARE("first second third", normalize(QString("   FIRST,Second   third!!!!")));
    QCOMPARE("first-second third", normalize(QString("   FIRST-Second   third!!!!")));
    QCOMPARE("первое слово дороже второго", normalize(QString("!!! ПЕрвое...СЛОВО,,,  ДоРоже !!!!! ВТОРОго.... ")));
}

void TestTools::test_capitalize_string()
{
    QCOMPARE("Test", capitalize(QString("TEST")));
    QCOMPARE("Test", capitalize(QString("test")));
    QCOMPARE("Test test", capitalize(QString("TEST TEST")));
}

#include "tst_testtools.moc"

#endif // DATABASE_H
