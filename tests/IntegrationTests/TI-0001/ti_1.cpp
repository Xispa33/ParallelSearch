#include "engine.h"
#include "assert.h"

using namespace std;

int main()
{
    BasicEngine search_engine;
    vector<string> ret;
    string pattern = "CCCC";
    search_engine.SEARCH_ENGINE__Search(pattern, &ret);

    #ifndef NDEBUG
    search_engine.SEARCH_ENGINE__DisplaySearchResults();
    //assert (ret.size() == 1);
    //assert (ret[0] == pattern);
    #else
    cout << "NDEBUG should be disabled" << endl;
    #endif
	return 0;
}
