#include "PartialIndividual.h"

// コンストラクタ
PartialIndividual::PartialIndividual()
{
	int i;
	
	for(i = 0; i < PCHROM_LEN; i++) {
		//chrom[i] =  (double)(rand() % 60000) / 1000 - 30;
		//chrom[i] =  (double)(rand() % 80000) / 10000 - 4;
		chrom[i] =  (double)(rand() % 100000) / 10000 - 5; //ZDT4・ KUR
		//chrom[i] =  (double)(rand() % 100000) / 100000; //Discontinuous Pareto-optimal front
		//chrom[i] =  rand() % 2; //多目的部分だまし問題
	}
	fitness = DBL_MAX;
}

// デストラクタ
PartialIndividual::~PartialIndividual()
{

}

// 次世代
void PartialIndividual::newGeneration()
{
	mutate();
}

// 二点交叉
void PartialIndividual::newGeneration(PartialIndividual* p1, PartialIndividual* p2, int index1, int index2)
{
	int i, min, max;

	if(index1 < index2) {
		min = index1;
		max = index2;
	} else {
		min = index2;
		max = index1;
	}
	for(i = 0; i < min; i++)
		chrom[i] = p1->chrom[i];
	for( ; i < max; i++)
		chrom[i] = p2->chrom[i];
	for( ; i < PCHROM_LEN; i++)
		chrom[i] = p1->chrom[i];
	mutate();
}

// 突然変異
void PartialIndividual::mutate()
{
	int i;

	for(i = 0; i < PCHROM_LEN; i++) {
		if(rand() < MUTATE_PROBI){
			//chrom[i] =  (double)(rand() % 60000) / 1000 - 30;
			//chrom[i] =  (double)(rand() % 80000) / 10000 - 4;
			chrom[i] =  (double)(rand() % 100000) / 10000 - 5; //ZDT4・KUR
			//chrom[i] =  (double)(rand() % 100000) / 100000; //Discontinuous Pareto-optimal front
			//chrom[i] =  rand() % 2; //多目的部分だまし問題
		}
	}
}
