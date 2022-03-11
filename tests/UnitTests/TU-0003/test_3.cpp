#include <gtest/gtest.h>
#include "words_list.h"


// ****** This test tests words_list module ******

using namespace std;

TEST(TU_0003, WordsList__Constructor) {
    WordsList words_list;

    int nb_words = words_list.WORDS_LIST__GetWordsListSize();
    // 81 = 3^4
    EXPECT_EQ(nb_words, 81);

    vector<string> words_a = *(words_list.WORDS_LIST__GetListFromKey('A'));
    vector<string> words_b = *(words_list.WORDS_LIST__GetListFromKey('B'));
    vector<string> words_c = *(words_list.WORDS_LIST__GetListFromKey('C'));
    
    EXPECT_EQ(words_a.size(), 27);
    EXPECT_EQ(words_b.size(), 27);
    EXPECT_EQ(words_c.size(), 27);

    EXPECT_EQ(words_a[0], "AAAA");
    EXPECT_EQ(words_b[1], "BAAB");
    EXPECT_EQ(words_c[2], "CAAC");
}