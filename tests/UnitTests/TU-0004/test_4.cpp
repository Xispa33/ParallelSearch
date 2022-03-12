#include <gtest/gtest.h>
#include "engine.h"

// ****** This test tests engine module (just the construction of an engine object) ******

using namespace std;

TEST(TU_0004, WordsList__Constructor) {
    BasicEngine search_engine(5);

    int nb_threads = search_engine.SEARCH_ENGINE__GetNbThreads();

    EXPECT_EQ(nb_threads, 5);
}