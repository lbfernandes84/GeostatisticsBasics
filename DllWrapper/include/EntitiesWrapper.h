#pragma once
#include "DllWrapper_API.h"
#include "Entities/Point.h"
#include "Entities/SampleSet.h"
#include "Entities/SampleValues.h"

extern "C"
{
	//Point
	DLLWRAPPER_API Point* EntitiesPoint_Create(double x, double y, double z);

	//SampleSet
	DLLWRAPPER_API SampleSet* EntitiesSampleSet_Create();
	DLLWRAPPER_API void EntitiesSampleSet_AddSample(SampleSet* pSampleSet, Point* pPoint);

	//SampleValues
	DLLWRAPPER_API SampleValues* EntitiesSampleValues_Create(int size);
	DLLWRAPPER_API void EntitiesSampleValues_Setvalue(SampleValues* pSampleValues, int index, double value);
	
}