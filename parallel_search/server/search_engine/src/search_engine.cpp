#include "search_engine.h"

/**
 * @brief WordsList::WordsList
 * Constructor
 */
SearchEngine::SearchEngine(): _words_list(), _pattern_to_search(""), _last_search_results(), _nb_found_results(0), _nb_threads(1)
{
    //int _search_durations[];
}

SearchEngine::SearchEngine(const int nb_thread): _words_list(), _pattern_to_search(""), _last_search_results(), _nb_found_results(0), _nb_threads(nb_thread)
{
    //int _search_durations[];
}

BasicSearchEngine::BasicSearchEngine()
{
    //using SearchEngine::SearchEngine;
    //int _search_durations[];
}


BasicSearchEngine::BasicSearchEngine(const int nb_thread) : SearchEngine(nb_thread)
{
    //int _search_durations[];
}

SearchEngine::~SearchEngine() { }

BasicSearchEngine::~BasicSearchEngine() { }

string SearchEngine::SEARCH_ENGINE__GetSearchPattern()
{
    return this->_pattern_to_search;
}

void SearchEngine::SEARCH_ENGINE__SetSearchPattern(string pattern)
{
    this->_pattern_to_search = pattern;
}

void SearchEngine::SEARCH_ENGINE__Search(string pattern)
{
    if (pattern != "") {
        SEARCH_ENGINE__SetSearchPattern(pattern);

        SEARCH_ENGINE__SearchAlgorithm();
    } 
}

void BasicSearchEngine::SEARCH_ENGINE__SearchAlgorithm()
{
    char first_letter = SEARCH_ENGINE__GetSearchPattern()[0];
    int found_flag = 0;
    vector<string> potential_words, out;

    potential_words = *(this->_words_list.WORDS_LIST__GetListFromKey(first_letter));

    /*
    for (vector<string>::iterator it_vector = potential_words.begin(); it_vector != potential_words.end(); ++it_vector) {
        for (string::iterator it_string = it_vector->begin(); it_string != it_vector->end(); ++it_string) {
           for (string::iterator it_pattern = this->_pattern_to_search.begin(); it_pattern != this->_pattern_to_search.end(); ++it_pattern) {
               if ((int) *it_pattern != (int) *it_string) { 
                break; 
               } 
               //else if ((int) *it_pattern > (int) *it_string) { continue; }
               if (it_string == it_pattern && it_pattern == this->_pattern_to_search.end() - 1)
               { 
                   out.push_back(*it_vector);
                } else {
                   found_flag = 1;
                   break;
               }
            }
            break;
        }
    }
    */
    this->_last_search_results = *(this->_words_list.WORDS_LIST__GetListFromKey(first_letter));
    USR_FCT__DisplayAllWords(&(this->_last_search_results));
    //USR_FCT__DisplayAllWords(&out);
    //this->_last_search_results = out;
}