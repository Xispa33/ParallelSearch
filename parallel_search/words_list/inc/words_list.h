#ifndef WORDS_LIST_H
#define WORDS_LIST_H

#include <string.h>
#include <math.h>

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>       

using namespace std;

#define WORDS_LIST__C_NB_CHAR_ALPHABET (26) 

extern void EXTERN__GetRandomWords(const int nb_char, vector<string>* words_vector);
extern void EXTERN__ShuffleWords(vector<string>* words_vector);
extern void EXTERN__DisplayAllWords(vector<string>* words_vector);
extern int EXTERN__WordsAsciiComparison(const void* word_a, const void* word_b);


class WordsList
{
    public:
        WordsList(const int nb_char);
        ~WordsList();

        int WORDS_LIST__GetWordsListSize();
        void WORD_LIST__DisplayWordsList();
        //vector<string>* void WORDS_LIST__GetWordsList();
        //vector<string>* WORDS_LIST__GetAllWords();

    private:
        // Methods
        void WORDS_LIST__ProcessWordsList(vector<string>* words_vector);
        void WORDS_LIST__CreateWordsList(vector<string>* words_vector);
        void WORDS_LIST__SortWordsList();
        void WORDS_LIST__SetWordsListSize(const int size);
        int WORDS_LIST__ComputeWordsListSize();
        //vector<string> WORDS_LIST__GetWordsFromFile(const string filepath);
        //map<char, vector<string>> WORDS_LIST__GenerateWordsList();

        // Attributes
        map<char, vector<string> > _words_list;
        int _words_list_size;
};
#endif