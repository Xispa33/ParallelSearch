/**
 * @file words_list.cpp
 */

#include "words_list.h"

static int asciiSort(const void* word_a, const void* word_b);

/**
 * @brief WordsList object constructor
 */
WordsList::WordsList()
{
    /* vector containing all words of a list */
    vector<string> words_vector;

    /* Retrieving/generating all words of the list */
    WORDS_LIST__Init(&words_vector);

    /* Converting the vector containing all words to a map of lists */
    WORDS_LIST__ProcessWordsList(&words_vector);

    /* Compute the number of words from the map of lists 
     * It should be equal to the number of words originally created 
     * */
    int w_size = WORDS_LIST__ComputeWordsListSize();

    /* Store number of words in  _words_list_size attribute */
    WORDS_LIST__SetWordsListSize(w_size);

    //WORD_LIST__DisplayWordsList();
}

/**
 * @brief WORDS_LIST__Init function
 * 
 * This function generates a list of random words and stores them
 * in a vector container.
 * 
 * @param words_vector pointer on a vector of strings
 * 
 * @return words_vector
 */
void WordsList::WORDS_LIST__Init(vector<string>* words_vector)
{
    USR_FCT__GetRandomWords(words_vector);

    //USR_FCT__DisplayAllWords(&words_vector);
}

/**
 * @brief WORDS_LIST__SetWordsListSize function
 * 
 * This function sets the _words_list_size attribute
 * 
 * @param size total number of words in the words list
 */
void WordsList::WORDS_LIST__SetWordsListSize(const int size)
{
    this->_words_list_size = (int) size;
}

/**
 * @brief WORDS_LIST__GetWordsListSize function
 * 
 * This function returns the _words_list_size attribute
 * 
 * @return total number of words in the words list
 */
int WordsList::WORDS_LIST__GetWordsListSize()
{
    return this->_words_list_size;
}

/**
 * @brief WORDS_LIST__ComputeWordsListSize function
 * 
 * This function computes the size of the words list
 * The size of the words list is the sum of the size of 
 * each vector of the map container
 * 
 * @param size total number of words in the words list
 */
int WordsList::WORDS_LIST__ComputeWordsListSize()
{
    int size = 0;

    for (map<char,vector<string> >::iterator it_map=this->_words_list.begin(); it_map!=this->_words_list.end(); ++it_map) {
        size += it_map->second.size();
    }

    return size;
}

/**
 * @brief WORDS_LIST__ProcessWordsList function
 * 
 * This function processes the original words list.
 * A first sort places every word in a vector of a map container. Each key
 * of the map container corresponds to the first letter of each word.
 * 
 * A second sort then sorts alphabetically vector of the map container.
 * 
 * @param words_vector pointer on the original words list
 */
void WordsList::WORDS_LIST__ProcessWordsList(vector<string>* words_vector)
{
    /* Mark the beggining of the search */
    TOOLS__MARK_INIT(&(this->_sort_duration));

    /* First sort */
    WORDS_LIST__CreateWordsList(words_vector);

    /* Second sort */
    WORDS_LIST__SortWordsList();

    /* Mark the end of the search */
    TOOLS__MARK_END(&(this->_sort_duration));

}

/**
 * @brief WORDS_LIST__CreateWordsList function
 * 
 * This function initializes _words_list attribute.
 * 
 * Each key of _words_list holds a vector of strings.
 * Each key corresponds to the first letter of every word in the vector.
 * 
 * Vectors of the map container are not sorted.
 * 
 * @param words_vector pointer on the raw words_list
 * 
 */
void WordsList::WORDS_LIST__CreateWordsList(vector<string>* words_vector)
{
    vector<string>::iterator it = words_vector->end() - 1;
    int cpt = 0;
    char first_letter = ' ';

    while (words_vector->size() > 0) {
        first_letter = (*it)[0];
        this->_words_list[first_letter].push_back(*it);
        //words_vector->pop_back();
        --it;
        words_vector->erase(it + 1);
    }
}

/**
 * @brief WORDS_LIST__SortWordsList function
 * 
 * This function sorts the words list of every entry of the map
 * 
 */
void WordsList::WORDS_LIST__SortWordsList()
{
    for (map<char,vector<string> >::iterator it_map=this->_words_list.begin(); it_map!=this->_words_list.end(); ++it_map) {
        qsort(&(it_map->second[0]), it_map->second.size(), sizeof(string), asciiSort);
    }
}

/**
 * @brief WORD_LIST__DisplayWordsList function
 * 
 * This function displays the sorted words list
 * 
 */
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

/**
 * @brief WORDS_LIST__GetListFromKey function
 * 
 * This function returns a list of all the possible words
 * starting with key letter
 * 
 * @param key 
 * 
 * @return list of all the possible words
 * starting with key letter
 */
vector<string>* WordsList::WORDS_LIST__GetListFromKey(char key)
{
    return &(this->_words_list[key]);
}

/**
 * @brief WORDS_LIST__GetSortDuration function
 * 
 * This function returns the time taken to sort the word list.
 * 
 * @return computated _sort_duration attribute
 */
double WordsList::WORDS_LIST__GetSortDuration()
{
    double ret = 0.0;

    TOOLS__ComputeSearchTime(&(this->_sort_duration), &ret);

    return ret;
}

/**
 * @brief WordsList object destructor
 */
WordsList::~WordsList()
{
    
}

/**
 * @brief asciiSort function
 * 
 * This function compares two strings according to 
 * the ascii value of each of its characters. In other
 * words, words are sorted alphabetically.
 * 
 * @param word_a word to compare with word_b
 * @param word_b word to compare with word_a
 * 
 * @return if > 0, word_a > word_b
 *         if < 0, word_a < word_b
 *         else word_a = word_b
 */
int asciiSort(const void* word_a, const void* word_b)
{
    int i = 0;
    string tmp_word_a = (*(string*) word_a);
    string tmp_word_b = (*(string*) word_b);

    if (tmp_word_a.size() != tmp_word_b.size()) {
        return tmp_word_a.size() - tmp_word_b.size();
    }
    else {

        do {
            if ((int) (tmp_word_a[i] - tmp_word_b[i]) != 0) {
                break;
            }
            else {
                i++;
            }
        } while (tmp_word_a[i] == tmp_word_b[i]);
        
        return (int) (tmp_word_a[i] - tmp_word_b[i]);
    }
}