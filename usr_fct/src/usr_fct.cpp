#include "usr_fct.h"

static void USR_FCT__ShuffleWords(vector<string>* words_vector);

extern void USR_FCT__GetRandomWords(vector<string>* words_vector)
{
    string word(4, 'A');
    for (int i = 'A'; i <= 'Z'; ++i) {
        word[0] = i; 
        for (int j = 'A'; j <= 'Z'; ++j) {
            word[1] = j;
            for (int k = 'A'; k <= 'Z'; ++k) {
                word[2] = k; 
                for (int l = 'A'; l <= 'Z'; ++l) {
                    word[3] = l; 
                    words_vector->push_back(word);
                }
            }
        }
    }

    /* Shuffle of the words */
    USR_FCT__ShuffleWords(words_vector);
}

extern void USR_FCT__DisplayAllWords(vector<string>* words_vector)
{
    vector<string>::iterator it;
    cout << "+++++\nWORDS FOUND: " << endl;
    cout << "[";
    for (it = words_vector->begin(); it != words_vector->end(); ++it) {
        cout << *it << " ";
    }
    cout << "]\n";
    cout << "+++++\n";
}

static void USR_FCT__ShuffleWords(vector<string>* words_vector)
{
    // obtain a time-based seed
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    shuffle(words_vector->begin(), words_vector->end(), default_random_engine(seed));
}