#ifndef TOOLS_H
#define TOOLS_H

#include <iostream>
#include <time.h>

#define TOOLS__NB_DURATIONS (2)

typedef struct _TOOLS__T_MARK {
    clock_t start_date;
    clock_t end_date;
} TOOLS__T_MARK;

extern void TOOLS__MARK_INIT(TOOLS__T_MARK *time_table);
extern void TOOLS__MARK_END(TOOLS__T_MARK *time_table);
extern void TOOLS__ComputeSearchTime(TOOLS__T_MARK *time_table, double *time_var);

#endif