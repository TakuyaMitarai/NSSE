#pragma once

#include "WholePopulation.h"

class NSSE
{
public:
	NSSE();
	~NSSE();
	void solve();

	WholePopulation* wpop;
	PartialPopulation* ppop;
};
