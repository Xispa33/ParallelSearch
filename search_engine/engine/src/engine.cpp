/**
 * @file engine.cpp
 */

#include "engine.h"

TOOLS__T_MARK time_table;

/**
 * @brief Engine object constructor
 */
Engine::Engine(): _words_list(), _pattern_to_search(""), _last_search_results(), _nb_found_results(0), _nb_threads(1)
{
    /**
     * 1st element of _search_durations is the time taken to sort the words list
     * 2nd element is initialized to 0
    */
    _search_durations[0] = _words_list.WORDS_LIST__GetSortDuration();
    _search_durations[1] = (double) 0;
}

/**
 * @brief Engine object constructor
 */
Engine::Engine(const int nb_thread): _words_list(), _pattern_to_search(""), _last_search_results(), _nb_found_results(0), _nb_threads(nb_thread)
{
    /**
     * 1st element of _search_durations is the time taken to sort the words list
     * 2nd element is initialized to 0
    */
    _search_durations[0] = _words_list.WORDS_LIST__GetSortDuration();
    _search_durations[1] = (double) 0;
}

/**
 * @brief BasicEngine object constructor
 */
BasicEngine::BasicEngine()
{
}

/**
 * @brief BasicEngine object constructor
 */
BasicEngine::BasicEngine(const int nb_thread) : Engine(nb_thread) 
{
}

/**
 * @brief Engine object destructor
 */
Engine::~Engine() { }

/**
 * @brief BasicEngine object destructor
 */
BasicEngine::~BasicEngine() { }

/**
 * @brief SEARCH_ENGINE__GetSearchPattern function
 * 
 * This function returns _pattern_to_search attribute
 * 
 * @return current search pattern
 */
string Engine::SEARCH_ENGINE__GetSearchPattern()
{
    return this->_pattern_to_search;
}

/**
 * @brief SEARCH_ENGINE__SetSearchPattern function
 * 
 * This function sets the _pattern_to_search attribute
 * 
 * @param pattern pattern to search
 */
void Engine::SEARCH_ENGINE__SetSearchPattern(const string pattern)
{
    this->_pattern_to_search = pattern;
}

/**
 * @brief SEARCH_ENGINE__GetNbThreads function
 * 
 * This function return the _nb_threads attribute
 * 
 * @return number of threads
 */
int Engine::SEARCH_ENGINE__GetNbThreads()
{
    return this->_nb_threads;
}

/**
 * @brief SEARCH_ENGINE__SetNbThreads function
 * This function sets the _nb_threads attribute
 * 
 * @param nb_threads number of threads
 */
void Engine::SEARCH_ENGINE__SetNbThreads(const int nb_threads)
{
    this->_nb_threads = nb_threads;
}

/**
 * @brief SEARCH_ENGINE__Search function
 * 
 * This function triggers a search. pattern is searched among the list of words
 * and the results are stored in ret. The duration of the search is also computed.
 * 
 * @param pattern pattern to search
 * @param ret pointer on a vector<string> holding the search's results
 * 
 * @return ret
 */
void Engine::SEARCH_ENGINE__Search(string pattern, vector<string>* ret)
{

    if (pattern != "") {
        SEARCH_ENGINE__SetSearchPattern(pattern);

        /* Mark the beggining of the search */
        TOOLS__MARK_INIT(&time_table);

        SEARCH_ENGINE__SearchAlgorithm(ret);

        /* Mark the end of the search */
        TOOLS__MARK_END(&time_table);

        /* Compute the search's duration */
        TOOLS__ComputeSearchTime(&time_table, &(this->_search_durations[TOOLS__NB_DURATIONS-1]));

        this->_last_search_results = *ret;
        this->_nb_found_results = sizeof(ret);
    }
}

/**
 * @brief SEARCH_ENGINE__DisplaySearchResults function
 * 
 * This function display the search results: the words found
 * and the duration of the search.
 * 
 */
void Engine::SEARCH_ENGINE__DisplaySearchResults()
{
    SEARCH_ENGINE__DisplayWordsFound();

    SEARCH_ENGINE__DisplaySearchDuration();
}

/**
 * @brief SEARCH_ENGINE__DisplayWordsFound function
 * 
 * This function display the words found during the search
 * 
 */
void Engine::SEARCH_ENGINE__DisplayWordsFound()
{
    USR_FCT__DisplayAllWords(&(this->_last_search_results));
}

/**
 * @brief SEARCH_ENGINE__DisplaySearchDuration function
 * 
 * This function display the time elapsed during the search.
 * The time taken to preprocess the data is by default excluded but
 * can be included using INC_LIST_SORT flag.
 * 
 */
void Engine::SEARCH_ENGINE__DisplaySearchDuration()
{
    /* */
    #ifdef INC_LIST_SORT
    cout << "\n\n ******" << " PREPROCESS TIME = " << this->_search_durations[0] << " ****** \n\n" << endl;
    cout << "\n\n ******" << " TOTAL TIME SEARCH = " << this->_search_durations[1] + this->_search_durations[1] << " ****** \n\n" << endl;
    #else
    cout << "\n\n ******" << " TIME ELAPSED DURING SEARCH = " << this->_search_durations[1] << " ms ****** \n\n" << endl;
    #endif
}

/**
 * @brief SEARCH_ENGINE__SearchAlgorithm function
 * 
 * This function implements the search algorithm.
 * 
 * @param ret pointer on a vector<string> holding the search's results
 * 
 * @return ret
 */
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

