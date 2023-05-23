#pragma once

#include "PartialIndividual.h"

class PartialPopulation
{
public:
	PartialPopulation();
	~PartialPopulation();
	void newGeneration(vector<PartialIndividual*> poptmp);
	void evaluation();
	void evalinit();

	vector<PartialIndividual*> pop;

private:
	void sort(int lb, int ub);
};
