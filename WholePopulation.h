#pragma once

#include "WholeIndividual.h"

class WholePopulation
{
public:
	WholePopulation();
	~WholePopulation();
	void newWholeGeneration();
	void evaluation();
	void congestion(int rank,vector<int> rank_s);
	void printsolution();
	void printfitness();
	void reference();

	WholeIndividual* pop[WPOP_SIZE*2];	// 全体解個体
	static vector<PartialIndividual*> refpop;	// 全体解個体が参照する部分解個体

private:
	void sort(int lb, int ub);
	void sortobject(int lb, int ub, vector<int> rank_s);
	void sortobject2(int lb, int ub, vector<int> rank_s);
};
