#include "words_list.h"

/**
 * @brief WordsList::WordsList
 * Constructor
 */
WordsList::WordsList(const int nb_char)
{
    vector<string> words_vector;

    EXTERN__GetRandomWords(nb_char, &words_vector);
    EXTERN__ShuffleWords(&words_vector);
    //EXTERN__DisplayAllWords(&words_vector);

    WORDS_LIST__ProcessWordsList(&words_vector);

    const int w_size = WORDS_LIST__ComputeWordsListSize();

    WORDS_LIST__SetWordsListSize(w_size);

    WORD_LIST__DisplayWordsList();
}

/*
vector<string>* WordsList::WORDS_LIST__GetWordsList()
{
    vector<string>* a;
    return a;
}*/

void WordsList::WORDS_LIST__SetWordsListSize(const int size)
{
    this->_words_list_size = (int) size;
}

int WordsList::WORDS_LIST__GetWordsListSize()
{
    return this->_words_list_size;
}

int WordsList::WORDS_LIST__ComputeWordsListSize()
{
    int size = 0;
    
    for (map<char,vector<string> >::iterator it_map=this->_words_list.begin(); it_map!=this->_words_list.end(); ++it_map) {
        size += it_map->second.size();
    }

    return size;
}

void WordsList::WORDS_LIST__ProcessWordsList(vector<string>* words_vector)
{
    WORDS_LIST__CreateWordsList(words_vector);

    WORDS_LIST__SortWordsList();

}

void WordsList::WORDS_LIST__CreateWordsList(vector<string>* words_vector)
{
    vector<string>::iterator it = words_vector->end() - 1;
    int cpt = 0;
    char first_letter = ' ';

    while (words_vector->size() > 0) {
        first_letter = (*it)[0];
        this->_words_list[first_letter].push_back(*it);
        words_vector->pop_back();
        --it;
    }
}

void WordsList::WORDS_LIST__SortWordsList()
{
    for (map<char,vector<string> >::iterator it_map=this->_words_list.begin(); it_map!=this->_words_list.end(); ++it_map) {
        qsort(&(it_map->second[0]), it_map->second.size(), sizeof(string), EXTERN__WordsAsciiComparison);
    }
}

void WordsList::WORD_LIST__DisplayWordsList()
{
    for (map<char,vector<string> >::iterator it_map=this->_words_list.begin(); it_map!=this->_words_list.end(); ++it_map) {
        cout << it_map->first << " => [ ";
        for (vector<string>::iterator it_vector=it_map->second.begin(); it_vector!=it_map->second.end(); ++it_vector) {
            cout << *it_vector;
            if (it_vector != it_map->second.end() - 1) {
               cout << ", "; 
            }
        }
        cout << "] \n\n";
    }
}

WordsList::~WordsList()
{
    
}

extern void EXTERN__GetRandomWords(const int nb_char, vector<string>* words_vector)
{
    string word(nb_char, 'A');
    for (int i = 'A'; i <= 'C'; ++i) {
        word[0] = i; 
        for (int j = 'A'; j <= 'C'; ++j) {
            word[1] = j;
            for (int k = 'A'; k <= 'C'; ++k) {
                word[2] = k; 
                for (int l = 'A'; l <= 'C'; ++l) {
                    word[3] = l; 
                    words_vector->push_back(word);
                }
            }
        }
    }
}

extern void EXTERN__DisplayAllWords(vector<string>* words_vector)
{
    vector<string>::iterator it;
    for (it = words_vector->begin(); it != words_vector->end(); ++it) {
        cout << *it << endl;
    }
}

extern void EXTERN__ShuffleWords(vector<string>* words_vector)
{
    // obtain a time-based seed
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    shuffle(words_vector->begin(), words_vector->end(), default_random_engine(seed));
}

extern int EXTERN__WordsAsciiComparison(const void* word_a, const void* word_b)
{
    int i = 0;
    string tmp_word_a = (*(string*) word_a);
    string tmp_word_b = (*(string*) word_b);
    do {
        if ((int) (tmp_word_a[i] - tmp_word_b[i]) != 0) {
            return (int) (tmp_word_a[i] - tmp_word_b[i]);
        }
        else {
            i++;
        }
    } while (tmp_word_a[i] == tmp_word_b[i]);
    
    return (int) (tmp_word_a[i] - tmp_word_b[i]);
}