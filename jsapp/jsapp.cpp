// jsapp.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>

extern "C" {
#include "duktape.h"
}

int main(int argc, char* argv[])
{
	int nRes = 0;
	duk_context* ctx = duk_create_heap_default();
	if(!ctx)
	{
		std::cout << "Fail duk_create_heap_default()" << std::endl; 
		return 1;
	}
	if (argc < 3 || !argv[1] || !argv[2])
	{
		duk_eval_string(ctx, "print('Error: Nead a path to js file');");
		duk_eval_string(ctx, "print('Usage: jsapp.exe <path_to_js> <path_to_file>');");
	}
	else
	{
		if (duk_peval_file(ctx, argv[1]) == 0)
		{
			duk_pop(ctx);
			duk_push_global_object(ctx);
			duk_get_prop_string(ctx, -1, "main");
			duk_push_string(ctx, argv[2]);
			duk_pcall(ctx, 1);
			duk_pop(ctx);
		}
		else
		{
			std::cout << "Fail duk_peval_file()" << std::endl;
			nRes = 1;
		}
	}

	duk_destroy_heap(ctx);
	std::system("pause");
	return nRes;
}

