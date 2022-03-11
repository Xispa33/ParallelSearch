#include "engine.h"

/**
 * @brief WordsList::WordsList
 * Constructor
 */
Engine::Engine(): _words_list(), _pattern_to_search(""), _last_search_results(), _nb_found_results(0), _nb_threads(1)
{
    //int _search_durations[];
}

Engine::Engine(const int nb_thread): _words_list(), _pattern_to_search(""), _last_search_results(), _nb_found_results(0), _nb_threads(nb_thread)
{
    //int _search_durations[];
}

BasicEngine::BasicEngine()
{
    //using Engine::Engine;
    //int _search_durations[];
}


BasicEngine::BasicEngine(const int nb_thread) : Engine(nb_thread)
{
    //int _search_durations[];
}

Engine::~Engine() { }

BasicEngine::~BasicEngine() { }

string Engine::SEARCH_ENGINE__GetSearchPattern()
{
    return this->_pattern_to_search;
}

void Engine::SEARCH_ENGINE__SetSearchPattern(const string pattern)
{
    this->_pattern_to_search = pattern;
}

int Engine::SEARCH_ENGINE__GetNbThreads()
{
    return this->_nb_threads;
}

void Engine::SEARCH_ENGINE__SetNbThreads(const int nb_threads)
{
    this->_nb_threads = nb_threads;
}

void Engine::SEARCH_ENGINE__Search(string pattern, vector<string>* ret)
{
    if (pattern != "") {
        SEARCH_ENGINE__SetSearchPattern(pattern);

        SEARCH_ENGINE__SearchAlgorithm(ret);
    } 
}

void BasicEngine::SEARCH_ENGINE__SearchAlgorithm(vector<string>* ret)
{
    vector<string> potential_words;
    string::iterator it_tmp;
    char first_letter = SEARCH_ENGINE__GetSearchPattern()[0];
    int i = 0;
    string curr_word;

    potential_words = *(this->_words_list.WORDS_LIST__GetListFromKey(first_letter));

    for (vector<string>::iterator it_word = potential_words.begin(); it_word != potential_words.end(); ++it_word) {
           i = 0;
           curr_word = *it_word;
           for (string::iterator it_pattern_letter = this->_pattern_to_search.begin(); it_pattern_letter != this->_pattern_to_search.end(); ++it_pattern_letter) {
               if (*it_pattern_letter != curr_word[i]) {
                it_tmp = it_pattern_letter;
                break;
               }
                i++;
                if (i == this->_pattern_to_search.size()) {
                    ret->push_back(*it_word);
                    i--;
                    break;
                }
            }
            if (curr_word[i] != *it_tmp) {
                if ((int) curr_word[i] > (int) *it_tmp) {
                    return;
                } 
            }
    }
    //USR_FCT__DisplayAllWords(&(ret));
    return;
}

