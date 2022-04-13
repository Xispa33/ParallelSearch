#include "gtest/gtest.h"
#include "gmock/gmock.h"

/* include the prototype of mock function */
#include "example.h"

using namespace ::testing;

class MockA : public ClassA {
public:
    MOCK_METHOD1(getCode, int(int value));
};

TEST(ClassATest, Test1)
{
    MockA mockA;
    EXPECT_CALL(mockA, getCode(2)).WillOnce(Return(2));
    EXPECT_EQ(mockA.getName("key"), "XYZ");
}



