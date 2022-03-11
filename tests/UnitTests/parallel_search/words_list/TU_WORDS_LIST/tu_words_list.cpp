#include <gtest/gtest.h>
#include "words_list.h"

TEST(TESTS_WORDS_LIST_GENERATION, WORDS_LIST_TU_1) {
    /* EXPECT_EQ checks the equality between 2 values. If not, moves on to the next one */
    //EXPECT_EQ(ADVANCED_MATH__Factoriel(4U),24);
    const int nb_char = 4;
    WordsList word_list(nb_char);
    int list_size = word_list.WORDS_LIST__GetWordsListSize();
    int computed_size = (int) pow ((double) WORDS_LIST__C_NB_CHAR_ALPHABET, (double) nb_char);
    
    EXPECT_EQ(list_size, computed_size);
}

TEST(example,soustraction) {
    //EXPECT_EQ(ADVANCED_MATH__PGCD(12, 6),6);
}