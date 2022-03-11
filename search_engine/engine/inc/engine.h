#ifndef ENGINE_H
#define ENGINE_H

#include <iostream>
#include "words_list.h"

using namespace std;

class Engine
{
    public:
        Engine();
        Engine(const int nb_thread);
        ~Engine();

        void SEARCH_ENGINE__Search(string pattern, vector<string>* ret);
        string SEARCH_ENGINE__GetSearchPattern();
        int SEARCH_ENGINE__GetNbThreads();
    
    protected:
        // Methods
        virtual void SEARCH_ENGINE__SearchAlgorithm(vector<string>* ret) = 0;
        //virtual void SEARCH_ENGINE__StopEngine() = 0;
        void SEARCH_ENGINE__SetSearchPattern(const string pattern);
        void SEARCH_ENGINE__SetNbThreads(const int nb_threads);

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

class BasicEngine : public Engine
{
    public:
        BasicEngine();
        BasicEngine(const int nb_thread);
        ~BasicEngine();
    
    protected:
        // Methods
        void SEARCH_ENGINE__SearchAlgorithm(vector<string>*);
        //void SEARCH_ENGINE__StopEngine();
};
#endif