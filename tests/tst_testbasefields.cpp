#include <QtTest>

// add necessary includes here
#include "../src/database/orm/field/basefield.h"

class TestBaseFields : public QObject
{
    Q_OBJECT

public:
    TestBaseFields();
    ~TestBaseFields();

private slots:
    void test_create_basefield();
    void test_create();
    void test_primary_key();
};

TestBaseFields::TestBaseFields()
{

}

TestBaseFields::~TestBaseFields()
{

}

void TestBaseFields::test_create_basefield()
{
    QStringList valid_type;
    QVERIFY_EXCEPTION_THROWN(BaseField::setValidTypes(valid_type), FieldException);

    valid_type << "INTEGER" << "TEXT";
    BaseField::setValidTypes(valid_type);
    QVERIFY_EXCEPTION_THROWN(BaseField("test", "test"), FieldException);
}

void TestBaseFields::test_create()
{
    QStringList valid_type;
    valid_type << "INTEGER" << "TEXT";
    BaseField field1("test", "integer");
    QCOMPARE("test INTEGER", field1.create());

    BaseField field2("test", "text");
    QCOMPARE("test TEXT", field2.create());

    BaseField field3("test", "integer", false, true);
    QCOMPARE("test INTEGER NOT NULL", field3.create());

    BaseField field4("test", "text", false, true);
    QCOMPARE("test TEXT NOT NULL", field4.create());

    BaseField field5("test", "integer", false, false, true);
    QCOMPARE("test INTEGER UNIQUE", field5.create());

    BaseField field6("test", "text", false, false, true);
    QCOMPARE("test TEXT UNIQUE", field6.create());

    BaseField field7("test", "integer", false, true, true);
    QCOMPARE("test INTEGER NOT NULL UNIQUE", field7.create());

    BaseField field8("test", "text", false, true, true);
    QCOMPARE("test TEXT NOT NULL UNIQUE", field8.create());
}

void TestBaseFields::test_primary_key()
{
    QStringList valid_type;
    valid_type << "INTEGER" << "TEXT";
    BaseField field1("test", "integer");
    QVERIFY(!field1.is_key());

    BaseField field2("test", "integer", true);
    QVERIFY(field2.is_key());
}

#include "tst_testbasefields.moc"
