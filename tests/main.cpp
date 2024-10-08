#include <QtTest>

#include "tst_testtools.cpp"
#include "tst_testbasefields.cpp"
#include "tst_testbasemodels.cpp"


int main(int argc, char** argv)
{
   int status = 0;
   auto ASSERT_TEST = [&status, argc, argv](QObject* obj) {
     status |= QTest::qExec(obj, argc, argv);
     delete obj;
   };

   ASSERT_TEST(new TestTools());
   ASSERT_TEST(new TestBaseFields());
   ASSERT_TEST(new TestBaseModels());

   return status;
}
