#include "tools.h"

extern void TOOLS__MARK_INIT(TOOLS__T_MARK *time_table)
{
    time_table->start_date = clock();
    time_table->end_date = 0; 
}

extern void TOOLS__MARK_END(TOOLS__T_MARK *time_table)
{
    time_table->end_date = clock(); 
}

extern void TOOLS__ComputeSearchTime(TOOLS__T_MARK *time_table, double *time_var)
{
    *time_var = (double) 1000*(time_table->end_date - time_table->start_date)/CLOCKS_PER_SEC;
}