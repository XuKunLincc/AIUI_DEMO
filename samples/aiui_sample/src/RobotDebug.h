#ifndef __ROBOT_DEBUG__
#define __ROBOT_DEBUG__

#include <stdio.h>

#if DEBUG == 0
#define robot_debug(...)
#else
#define robot_debug(...) printf(__VAR_ARGS__)
#endif

#endif