#include <gtest/gtest.h>
#include "usr_fct.h"
//#include "words_list.h"

// ****** This test tests usr_fct provided functions ******
using namespace std;

TEST(TU_0001, USR_FCT__GetRandomWords) {
    /* EXPECT_EQ checks the equality between 2 values. If not, moves on to the next one */
    vector<string> words_list;
    USR_FCT__GetRandomWords(&words_list);
    EXPECT_EQ(words_list.size(), 81);
    EXPECT_NE(words_list[0], "AAAA");
}

TEST(TU_0001, random_test_2) {
    const int toto = 4;

    EXPECT_EQ(toto, 4);
}