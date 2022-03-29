/**
 * @file engine.cpp
 */

#include "engine.h"
//#include <algorithm>

void task1(int& a, int& b);

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
BasicEngine::BasicEngine() : Engine(1)
{
}

/**
 * @brief BasicEngine object constructor
 */
/*BasicEngine::BasicEngine(const int nb_thread) : Engine(1) 
{
}*/

/**
 * @brief EngineWithThreads object constructor
 */
EngineWithThreads::EngineWithThreads(const int nb_thread) 
{
    this->_nb_threads = nb_thread;
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
 * @brief EngineWithThreads object destructor
 */
EngineWithThreads::~EngineWithThreads() { }

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
    cout << " ******" << " PREPROCESS TIME = " << this->_search_durations[0] << " ms ******" << endl;
    cout << " ******" << " TIME ELAPSED DURING SEARCH = " << this->_search_durations[1] << " ms ******" << endl;
    cout << " ******" << " TOTAL TIME ELAPSED DURING SEARCH = " << this->_search_durations[0] + this->_search_durations[1] << " ms ****** \n\n" << endl;
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
 *      
 */
void BasicEngine::SEARCH_ENGINE__SearchAlgorithm(vector<string>* ret)
{
    char first_letter, current_letter;
    int i = 1;
    string pattern;
    
    pattern = SEARCH_ENGINE__GetSearchPattern();
    first_letter = pattern[0];

    if (pattern.size() == 1) {
        *ret = *(this->_words_list.WORDS_LIST__GetListFromKey(first_letter));
        return; 
    } else {
        vector<string> potential_words;

        potential_words = *(this->_words_list.WORDS_LIST__GetListFromKey(first_letter));

        for (vector<string>::iterator it_word = potential_words.begin(); it_word != potential_words.end(); ++it_word) {
           i = 1;
           for (string::iterator it_pattern_letter = (this->_pattern_to_search.begin()+1); it_pattern_letter != this->_pattern_to_search.end(); ++it_pattern_letter) {
               current_letter = *it_pattern_letter;
               if (*it_pattern_letter != (*it_word)[i]) {
                break;
               }
                i++;
                if (i == this->_pattern_to_search.size()) {
                    ret->push_back(*it_word);
                    i--;
                    break;
                }
            }

            if ((int) (*it_word)[i] > (int) current_letter) {
                return;
            } 
        }
        //USR_FCT__DisplayAllWords(&(ret));
        return;
    } 
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
void EngineWithThreads::SEARCH_ENGINE__Search(string pattern, vector<string>* ret)
{

    if (pattern != "") {
        SEARCH_ENGINE__SetSearchPattern(pattern);

        SEARCH_ENGINE__SearchAlgorithm(ret);

        /* Compute the search's duration */
        TOOLS__ComputeSearchTime(&time_table, &(this->_search_durations[TOOLS__NB_DURATIONS-1]));

        //this->_last_search_results = *ret;
        //this->_nb_found_results = sizeof(ret);
    }
}

/**
 * @brief SEARCH_ENGINE__SearchAlgorithm function
 * 
 * This function implements the search algorithm.
 * 
 * @param ret pointer on a vector<string> holding the search's results
 * 
 * @return ret
 *      
 */
void EngineWithThreads::SEARCH_ENGINE__SearchAlgorithm(vector<string>* ret)
{
    char first_letter, current_letter;
    int i = 1;
    string pattern;
    
    pattern = SEARCH_ENGINE__GetSearchPattern();
    first_letter = pattern[0];

    if (pattern.size() == 1) {
        *ret = *(this->_words_list.WORDS_LIST__GetListFromKey(first_letter));
        return; 
    } else {
        vector<string> potential_words;

        potential_words = *(this->_words_list.WORDS_LIST__GetListFromKey(first_letter));

        SEARCH_ENGINE__RunThreadedSearch(&potential_words);
    }
    //USR_FCT__DisplayAllWords(&(ret));
    //cout << "LENGTH SIZE = " << ret->size() << endl;
    return;
}

void EngineWithThreads::SEARCH_ENGINE__RestrictedSearch(vector<string>& ret, vector<string>& potential_words)
{
    char current_letter;
    int i = 1;

    for (vector<string>::iterator it_word = potential_words.begin(); it_word != potential_words.end(); ++it_word) {
        i = 1;
        for (string::iterator it_pattern_letter = (this->_pattern_to_search.begin()+1); it_pattern_letter != this->_pattern_to_search.end(); ++it_pattern_letter) {
            current_letter = *it_pattern_letter;
            if (*it_pattern_letter != (*it_word)[i]) {
            break;
            }
            i++;
            if (i == this->_pattern_to_search.size()) {
                ret.push_back(*it_word);
                i--;
                break;
            }
        }

        if ((int) (*it_word)[i] > (int) current_letter) {
            return;
        } 
    }
    //USR_FCT__DisplayAllWords(&(ret));
    return;
}

void EngineWithThreads::SEARCH_ENGINE__RunThreadedSearch(vector<string>* potential_words)
{
    int size = (int) (potential_words->size());
    vector<string> potential_words_1(potential_words->begin(), potential_words->begin() + (int) (size/2));
    vector<string> potential_words_2(potential_words->begin() + (int) (size/2), potential_words->end());
    vector<string> ret_1, ret_2;
    
    /* Mark the beggining of the search */
    TOOLS__MARK_INIT(&time_table);

    thread th1(&EngineWithThreads::SEARCH_ENGINE__RestrictedSearch, this, ref(ret_1), ref(potential_words_1));
    thread th2(&EngineWithThreads::SEARCH_ENGINE__RestrictedSearch, this, ref(ret_2), ref(potential_words_2));

    th1.join();
    th2.join();

    /* Mark the end of the search */
    TOOLS__MARK_END(&time_table);

    //MODIFY HERE
    this->_last_search_results = ret_2;
    this->_nb_found_results = sizeof(ret_2);
}

