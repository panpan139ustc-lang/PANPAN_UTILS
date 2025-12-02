#pragma once
#include <stdio.h>
#include <iostream>

void* operator new(std::size_t size, const char* file, int line);
void* operator new[](std::size_t size, const char* file, int line);
void* operator new(std::size_t size);
void* operator new(std::size_t size);
void operator delete(void* ptr)noexcept;
void operator delete[](void* ptr)noexcept;

#define DEBUG_NEW new(__FILE__, __LINE__)

//#define new new(__FILE__, __LINE__);

int checkLeaks();

extern bool new_autocheck_flag;
extern bool new_verbose_flag;