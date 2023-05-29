#include "PartialPopulation.h"

// コンストラクタ
PartialPopulation::PartialPopulation()
{
	int i;

	for(i = 0; i < PPOP_SIZE * 2; i++)
		pop.push_back(new PartialIndividual());
}

// デストラクタ
PartialPopulation::~PartialPopulation()
{
	int i;
	int size = pop.size();
	for(i = 0; i < size; i++)
		delete pop[i];
}

// 混雑度トーナメント・二点交叉による部分解個体の生成
void PartialPopulation::newGeneration(vector<PartialIndividual*> poptmp)
{
	int i, j, k, a, fit1, tmp1, tmp2, index1, index2;
	int cnt = 0;

	//#pragma omp parallel for
	for(k = 0; k < poptmp.size(); k++) {
		tmp1 = rand() % PPOP_SIZE;
		fit1 = pop[tmp1]->fitness;
		for(i = 0; i < TOURNAMENT_SIZE; i++) {
			a = rand() % PPOP_SIZE;
			if(fit1 > pop[a]->fitness) {
				fit1 = pop[a]->fitness;
				tmp1 = a;
			}
		}
		tmp2 = rand() % PPOP_SIZE;
		fit1 = pop[tmp2]->fitness;
		for(i = 0; i < TOURNAMENT_SIZE; i++) {
			a = rand() % PPOP_SIZE;
			if(fit1 > pop[a]->fitness) {
				fit1 = pop[a]->fitness;
				tmp2 = a;
			}
		}
		index1 = rand() % PCHROM_LEN;
		index2 = ((rand() % (PCHROM_LEN - 1)) + index1) % PCHROM_LEN;

		poptmp[k]->newGeneration(pop[tmp1], pop[tmp2], index1, index2);

		//突然変異
		poptmp[k]->newGeneration();
	}
}

// 適応度初期化
void PartialPopulation::evalinit()
{
	int i;
	
	for(i = 0; i < pop.size(); i++)
		pop[i]->fitness = DBL_MAX;
}

// 部分解個体の評価
void PartialPopulation::evaluation()
{
	sort(0, PPOP_SIZE * 2 - 1);
}

// クイックソート
void PartialPopulation::sort(int lb, int ub)
{
	int i, j, k;
	double pivot;
	PartialIndividual* swap;

	if(lb < ub) {
		k = (lb + ub) / 2;
		pivot = pop[k]->fitness;
		i = lb;
		j = ub;
		do {
			while(pop[i]->fitness < pivot)
				i++;
			while(pop[j]->fitness > pivot)
				j--;
			if(i <= j) {
				swap = pop[i];
				pop[i] = pop[j];
				pop[j] = swap;
				i++;
				j--;
			}
		} while(i <= j);
		sort(lb, j);
		sort(i, ub);
	}
}