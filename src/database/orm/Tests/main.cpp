#include <QtTest>

#include "tst_testfields.cpp"
#include "tst_testmodels.cpp"


int main(int argc, char** argv)
{
   int status = 0;
   auto ASSERT_TEST = [&status, argc, argv](QObject* obj) {
     status |= QTest::qExec(obj, argc, argv);
     delete obj;
   };

   ASSERT_TEST(new TestFields());
   ASSERT_TEST(new TestModels());

   return status;
}
