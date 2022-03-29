/**
 * @file engine.h
 */

#ifndef ENGINE_H
#define ENGINE_H

#include <iostream>
#include <time.h>
#include <thread>

#include "words_list.h"
#include "tools.h"

using namespace std;

/**
 * Implementation of the engine class (abstract class)
 */
class Engine
{
    public:
        Engine();
        Engine(const int nb_thread);
        ~Engine();

        void SEARCH_ENGINE__Search(string pattern, vector<string>* ret);
        string SEARCH_ENGINE__GetSearchPattern();
        int SEARCH_ENGINE__GetNbThreads();
        void SEARCH_ENGINE__DisplaySearchResults();
    
    protected:
        // Methods
        virtual void SEARCH_ENGINE__SearchAlgorithm(vector<string>* ret) = 0;
        void SEARCH_ENGINE__SetSearchPattern(const string pattern);
        void SEARCH_ENGINE__SetNbThreads(const int nb_threads);
        void SEARCH_ENGINE__DisplaySearchDuration();
        void SEARCH_ENGINE__DisplayWordsFound();

        // Attributes
        WordsList _words_list;
        string _pattern_to_search;
        vector<string> _last_search_results;
        int _nb_found_results;
        int _nb_threads;
        double _search_durations[TOOLS__NB_DURATIONS];
};

/**
 * Implementation of the Basicengine class, inherits from
 * the engine class.
 */
class BasicEngine : public Engine
{
    public:
        BasicEngine();
        //BasicEngine(const int nb_thread);
        ~BasicEngine();
    
    protected:
        // Methods
        void SEARCH_ENGINE__SearchAlgorithm(vector<string>* ret);
};

/**
 * Implementation of the EngineWithThreads class, inherits from
 * the engine class.
 */
class EngineWithThreads : public BasicEngine
{
    public:
        EngineWithThreads(const int nb_thread);
        ~EngineWithThreads();

        void SEARCH_ENGINE__Search(string pattern, vector<string>* ret);
        void SEARCH_ENGINE__RestrictedSearch(vector<string>& ret, vector<string>& potential_words);

    private:
        vector<string> SEARCH_ENGINE__SplitWordsList(vector<string>* ret);
        void SEARCH_ENGINE__RunThreadedSearch(vector<string>* potential_words);
    protected:
        // Methods
        void SEARCH_ENGINE__SearchAlgorithm(vector<string>* ret);
};
#endif