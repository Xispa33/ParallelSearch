#include <gtest/gtest.h>
#include "usr_fct.h"

// ****** This test tests usr_fct overloaded functions. 
// Overloading is done in current usr_functions directory ******
using namespace std;

TEST(TU_0002, USR_FCT__GetRandomWords) {
    /* EXPECT_EQ checks the equality between 2 values. If not, moves on to the next one */
    vector<string> words_list;
    USR_FCT__GetRandomWords(&words_list);

    EXPECT_EQ(words_list.size(), 26);

}