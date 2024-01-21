#pragma once
#ifndef _GAMEFUNC_HH
#define _GAMEFUNC_HH
#include "types.h"
extern int (*snprintf_hook)(char* s, size_t n, const char* format, ...);
_QWORD getEnttiyAddress(int Entity);

#endif