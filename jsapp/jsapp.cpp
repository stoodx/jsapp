// jsapp.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>

extern "C" {
#include "duktape.h"
}

int _tmain(int argc, _TCHAR* argv[])
{
	duk_context* ctx = duk_create_heap_default();
	if(!ctx)
	{
		std::cout << "Fail duk_create_heap_default()" << std::endl; 
		return 1;
	}

	duk_destroy_heap(ctx);
	std::system("pause");
	return 0;
}

