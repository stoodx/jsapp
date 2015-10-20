// jsapp.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>

extern "C" {
#include "duktape.h"
}

int _tmain(int argc, _TCHAR* argv[])
{
	int nRes = 0;
	duk_context* ctx = duk_create_heap_default();
	if(!ctx)
	{
		std::cout << "Fail duk_create_heap_default()" << std::endl; 
		return 1;
	}
	if (duk_peval_file(ctx, ".\\Files\\SyncData.js") == 0)
	{
		//reg
		duk_push_global_object(ctx);
		duk_get_prop_string(ctx, -1, "getSyncData");
		duk_eval_string(ctx, "getSyncData();");
		duk_pop(ctx);
	}
	else
	{
		std::cout << "Fail duk_peval_file()" << std::endl;
		nRes = 1;
	}

	duk_destroy_heap(ctx);
	std::system("pause");
	return nRes;
}

