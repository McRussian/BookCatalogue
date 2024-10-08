#ifndef TESTBASEMODEL_H
#define TESTBASEMODEL_H

#include <QtTest>
#include <QDebug>

// add necessary includes here
#include "../src/database/orm/model/basemodel.cpp"
#include "../src/database/orm/field/basefield.h"


class TestBaseModels : public QObject
{
    Q_OBJECT

public:
    TestBaseModels() {};
    ~TestBaseModels() {};

private slots:
    void test_create_basemodel();
    void test_create_table_with_one_pk();
    void test_create_table_with_two_pk();
};

void TestBaseModels::test_create_basemodel()
{
    QList<BaseField> fields;
    QVERIFY_EXCEPTION_THROWN(BaseModel("", fields), ModelException);

    QVERIFY_EXCEPTION_THROWN(BaseModel("test test", fields), ModelException);

    QVERIFY_EXCEPTION_THROWN(BaseModel("test", fields), ModelException);
}

void TestBaseModels::test_create_table_with_one_pk()
{
    QStringList valid_type;
    valid_type << "INTEGER" << "TEXT";
    BaseField::setValidTypes(valid_type);
    BaseField field1("id", "integer", true);
    BaseField field2("test", "text", false);
    QList<BaseField> fields = {field1, field2};

    BaseModel table("test", fields);
    QCOMPARE("CREATE TABLE IF NOT EXISTS test ("
             "id INTEGER NOT NULL UNIQUE, "
             "test TEXT NOT NULL, "
             "PRIMARY KEY (id))", table.createTable());
}

void TestBaseModels::test_create_table_with_two_pk()
{
    QStringList valid_type = {"INTEGER", "TEXT"};
    BaseField::setValidTypes(valid_type);
    QList<BaseField> fields = {BaseField("id", "integer", true),
                               BaseField("parent", "integer", true),
                               BaseField("test", "text", false)};
    BaseModel table("test", fields);

    QCOMPARE("CREATE TABLE IF NOT EXISTS test ("
             "id INTEGER NOT NULL UNIQUE, "
             "parent INTEGER NOT NULL UNIQUE, "
             "test TEXT NOT NULL, "
             "PRIMARY KEY (id, parent))", table.createTable());
}

#include "tst_testbasemodels.moc"

#endif

