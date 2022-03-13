/**
 * @file tools.cpp
 */

#include "tools.h"

/**
 * @brief TOOLS__MARK_INIT function
 * 
 * This function initializes a time table that will hold a start and an end date.
 * clock() returns the number of ticks consummed by the running application.
 * 
 * @param time_table time table
 * 
 * @return time_table with start date value updated 
 */
extern void TOOLS__MARK_INIT(TOOLS__T_MARK *time_table)
{
    time_table->start_date = clock();
    time_table->end_date = 0; 
}

/**
 * @brief TOOLS__MARK_END function
 * 
 * This function updates the end date value of a time table.
 * clock() returns the number of ticks consummed by the running application.
 * 
 * @param time_table time table
 * 
 * @return time_table with end date value updated 
 */
extern void TOOLS__MARK_END(TOOLS__T_MARK *time_table)
{
    time_table->end_date = clock(); 
}

/**
 * @brief TOOLS__ComputeSearchTime function
 * 
 * This function returns the time elapsed (in ms) between the start date and the 
 * end date of time_table.
 * 
 * @param time_table time table
 * 
 * @return time_table with end date value updated 
 */
extern void TOOLS__ComputeSearchTime(TOOLS__T_MARK *time_table, double *time_var)
{
    *time_var = (double) 1000*(time_table->end_date - time_table->start_date)/CLOCKS_PER_SEC;
}