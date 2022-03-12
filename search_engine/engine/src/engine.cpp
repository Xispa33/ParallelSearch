#include "engine.h"

TOOLS__T_MARK time_table;

/**
 * @brief WordsList::WordsList
 * Constructor
 */
Engine::Engine(): _words_list(), _pattern_to_search(""), _last_search_results(), _nb_found_results(0), _nb_threads(1)
{
    // Get word list duration for the 1st element
    _search_durations[0] = _words_list.WORDS_LIST__GetSortDuration();
    _search_durations[1] = (double) 0;
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

        TOOLS__MARK_INIT(&time_table);

        SEARCH_ENGINE__SearchAlgorithm(ret);

        TOOLS__MARK_END(&time_table);
    }

    TOOLS__ComputeSearchTime(&time_table, &(this->_search_durations[TOOLS__NB_DURATIONS-1]));

    //memcpy(&(this->_last_search_results), ret, sizeof(ret));
    this->_last_search_results = *ret;
    this->_nb_found_results = sizeof(ret);
}

void Engine::SEARCH_ENGINE__DisplaySearchResults()
{
    SEARCH_ENGINE__DisplayWordsFound();

    SEARCH_ENGINE__DisplaySearchDuration();
}

void Engine::SEARCH_ENGINE__DisplayWordsFound()
{
    USR_FCT__DisplayAllWords(&(this->_last_search_results));
}

void Engine::SEARCH_ENGINE__DisplaySearchDuration()
{
    #ifdef INC_LIST_SORT
    cout << "\n\n ******" << " PREPROCESS TIME = " << this->_search_durations[0] << " ****** \n\n" << endl;
    cout << "\n\n ******" << " TOTAL TIME SEARCH = " << this->_search_durations[1] + this->_search_durations[1] << " ****** \n\n" << endl;
    #else
    cout << "\n\n ******" << " TIME ELAPSED DURING SEARCH = " << this->_search_durations[1] << " ms ****** \n\n" << endl;
    #endif
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

