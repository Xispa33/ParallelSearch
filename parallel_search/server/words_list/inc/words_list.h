#ifndef WORDS_LIST_H
#define WORDS_LIST_H

#include <string.h>
#include <math.h>

#include <iostream>
#include <map>
#include <vector>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include <usr_fct.h>     

using namespace std;

#define WORDS_LIST__C_NB_CHAR_ALPHABET (26) 

class WordsList
{
    public:
        WordsList();
        ~WordsList();

        int WORDS_LIST__GetWordsListSize();
        vector<string>* WORDS_LIST__GetListFromKey(char key);
        void WORD_LIST__DisplayWordsList();
        //vector<string>* void WORDS_LIST__GetWordsList();
        //vector<string>* WORDS_LIST__GetAllWords();
    private:
        // Methods
        void WORDS_LIST__ProcessWordsList(vector<string>* words_vector);
        int WORDS_LIST__ComputeWordsListSize();
        void WORDS_LIST__CreateWordsList(vector<string>* words_vector);
        void WORDS_LIST__SortWordsList();
        void WORDS_LIST__SetWordsListSize(const int size);
        void WORDS_LIST__Init(vector<string>* words_vector);
        //vector<string> WORDS_LIST__GetWordsFromFile(const string filepath);
        //map<char, vector<string>> WORDS_LIST__GenerateWordsList();

        // Attributes
        map<char, vector<string> > _words_list;
        int _words_list_size;
};
#endif