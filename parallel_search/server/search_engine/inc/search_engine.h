#ifndef SEARCH_ENGINE_H
#define SEARCH_ENGINE_H

#include <iostream>
#include "words_list.h"

using namespace std;

class SearchEngine
{
    public:
        SearchEngine();
        SearchEngine(const int nb_thread);
        ~SearchEngine();

        void SEARCH_ENGINE__Search(string pattern);
        string SEARCH_ENGINE__GetSearchPattern();
    
    protected:
        // Methods
        virtual void SEARCH_ENGINE__SearchAlgorithm() = 0;
        //virtual void SEARCH_ENGINE__StopEngine() = 0;
        void SEARCH_ENGINE__SetSearchPattern(string pattern);

        //void SEARCH_ENGINE__GetTotalSearchDuration();
        //void SEARCH_ENGINE__GetIthSearchDuration(int i);

        // Attributes
        WordsList _words_list;
        string _pattern_to_search;
        vector<string> _last_search_results;
        //int _search_durations[];
        int _nb_found_results;
        int _nb_threads;
};

class BasicSearchEngine : public SearchEngine
{
    public:
        BasicSearchEngine();
        BasicSearchEngine(const int nb_thread);
        ~BasicSearchEngine();
    
    protected:
        // Methods
        void SEARCH_ENGINE__SearchAlgorithm();
        //void SEARCH_ENGINE__StopEngine();
};
#endif