#include "words_list.h"

static int asciiSort(const void* word_a, const void* word_b);

/**
 * @brief WordsList::WordsList
 * Constructor
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
    const int w_size = WORDS_LIST__ComputeWordsListSize();

    /* Store number of words in  _words_list_size attribute */
    WORDS_LIST__SetWordsListSize(w_size);

    //WORD_LIST__DisplayWordsList();
}

void WordsList::WORDS_LIST__Init(vector<string>* words_vector)
{
    USR_FCT__GetRandomWords(words_vector);

    //USR_FCT__DisplayAllWords(&words_vector);
}

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
        //words_vector->pop_back();
        --it;
        words_vector->erase(it + 1);
    }
}

void WordsList::WORDS_LIST__SortWordsList()
{
    for (map<char,vector<string> >::iterator it_map=this->_words_list.begin(); it_map!=this->_words_list.end(); ++it_map) {
        qsort(&(it_map->second[0]), it_map->second.size(), sizeof(string), asciiSort);
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

vector<string>* WordsList::WORDS_LIST__GetListFromKey(char key)
{
    return &(this->_words_list[key]);
}

WordsList::~WordsList()
{
    
}

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