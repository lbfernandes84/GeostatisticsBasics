#include "../include/EntitiesWrapper.h"

Point* EntitiesPoint_Create(double x, double y, double z)
{
	auto* p = new Point();
	p->x = x;
	p->y = y;
	p->z = z;
	return p;
}

SampleSet* EntitiesSampleSet_Create()
{
	return new SampleSet();
}

void EntitiesSampleSet_AddSample(SampleSet* pSampleSet, Point* pPoint)
{
	if (pSampleSet && pPoint)
	{
		pSampleSet->AddSample(*pPoint);
	}
}

SampleValues* EntitiesSampleValues_Create(int size)
{
	return new SampleValues(size);
}

void EntitiesSampleValues_Setvalue(SampleValues* pSampleValues,int index, double value)
{
	if (pSampleValues)
	{
		pSampleValues->SetValue(index, value);
	}
}
