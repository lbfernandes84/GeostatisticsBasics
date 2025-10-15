#pragma once

#ifdef DLLWRAPPER_EXPORTS
	#define DLLWRAPPER_API __declspec(dllexport)
#else
	#define DLLWRAPPER_API __declspec(dllimport)
#endif