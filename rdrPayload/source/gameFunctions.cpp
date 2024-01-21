#include "../include/offsets.h" 
#include "../include/gameFunctions.h"

int (*snprintf_hook)(char* s, size_t n, const char* format, ...) = (void*)SNPRINTF; // snprintf offset is 0x5DCC10
_QWORD getEnttiyAddress(int Entity) {
	_DWORD v4;
	_DWORD v5;
	_DWORD v6;
	v4 = (unsigned int)(Entity >> 8);
	_QWORD v8 = *(_QWORD*)(GET_ENTITY_ADDR);
	v5 = *(_QWORD*)(v8 + 8) + (unsigned int)(*(_DWORD*)(v8 + 28) * v4);
	v6 = *(_QWORD*)(v5 + 8);
	return v6;
}