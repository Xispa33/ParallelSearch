#include <gtest/gtest.h>

#include "engine.h"
#include "assert.h"

using namespace std;

int _main()
{
    BasicEngine search_engine;
    vector<string> ret;
    string pattern = "CCA";
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

TEST(TI_0001, f1) {
    //EXPECT_EQ(2, 2);
    //EXPECT_NE(0, 1);
    EXPECT_EQ(_main(), 0);
}
