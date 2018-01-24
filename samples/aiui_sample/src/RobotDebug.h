#ifndef __ROBOT_DEBUG__
#define __ROBOT_DEBUG__

#include <stdio.h>

#define DEBUG 1

#if DEBUG == 0
#define robot_debug(...)
#else
#define robot_debug(...) printf(__VA_ARGS__)
#endif

#endif
