#include "engine.h"

int main()
{
    BasicEngine search_engine;
    vector<string> ret;
    search_engine.SEARCH_ENGINE__Search("ABAB", &ret);

    USR_FCT__DisplayAllWords(&ret);
	return 0;
}
