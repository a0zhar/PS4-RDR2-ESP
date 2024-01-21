#include "../include/lib.h"
#include <cstdarg>
u64(*syscall)(int num, ...) = (void *)SyscallAddress;
#define hookFunction(module, name) syscall(591, module, #name, &name);

void *(*malloc)(size_t size);
void(*free)(void *ptr);
void *(*calloc)(size_t num, size_t size);
void *(*realloc)(void *ptr, size_t size);
void *(*memset)(void *destination, int value, size_t num);
void *(*memcpy)(void *destination, const void *source, size_t num);
int(*memcmp)(const void *s1, const void *s2, size_t n);
char *(*strcpy)(char *destination, const char *source);
char *(*strncpy)(char *destination, const char *source, size_t num);
char *(*strcat)(char *dest, const char *src);
char *(*strncat)(char *dest, const char *src, size_t n);
size_t(*strlen)(const char *s);
int(*strcmp)(const char *s1, const char *s2);
int(*strncmp)(const char *s1, const char *s2, size_t n);
int(*sprintf)(char *str, const char *format, ...);
int(*sscanf)(const char *str, const char *format, ...);
char *(*strchr)(const char *s, int c);
char *(*strrchr)(const char *s, int c);
char *(*strstr)(char *str1, char *str2);
int(*atoi)(const char *str);
double(*atof)(const char *str);

//MATH
int(*abs)(int);
double(*cos)(double x);
double(*sin)(double x);
double(*tan)(double x);
double(*atan2)(double y, double x);
double(*atan)(double x);
double(*sqrt)(double x);


void resolveLibs() {
	int libcHandle;
	syscall(594, "libSceLibcInternal.sprx", 0, &libcHandle, 0);

	hookFunction(libcHandle, malloc);
	hookFunction(libcHandle, free);
	hookFunction(libcHandle, calloc);
	hookFunction(libcHandle, realloc);
	hookFunction(libcHandle, memset);
	hookFunction(libcHandle, memcpy);
	hookFunction(libcHandle, memcmp);
	hookFunction(libcHandle, strcpy);
	hookFunction(libcHandle, strncpy);
	hookFunction(libcHandle, strcat);
	hookFunction(libcHandle, strncat);
	hookFunction(libcHandle, strlen);
	hookFunction(libcHandle, strcmp);
	hookFunction(libcHandle, strncmp);
	hookFunction(libcHandle, sprintf);
	hookFunction(libcHandle, sscanf);
	hookFunction(libcHandle, strchr);
	hookFunction(libcHandle, strrchr);
	hookFunction(libcHandle, strstr);
	hookFunction(libcHandle, atoi);
	hookFunction(libcHandle, atof);

	// MATH RELATED 
	//hookFunction(libcHandle, abs);
	//hookFunction(libcHandle, cos);
	//hookFunction(libcHandle, sin);
	//hookFunction(libcHandle, tan);
	//hookFunction(libcHandle, atan2);
	//hookFunction(libcHandle, atan);
	//hookFunction(libcHandle, sqrt);

}

void initLibs() {
	do {
		resolveLibs();
	} while (malloc == nullptr);
}