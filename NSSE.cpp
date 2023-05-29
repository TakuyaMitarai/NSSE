#include "NSSE.h"

// コンストラクタ
NSSE::NSSE()
{
	int i, j;

	// 部分解初期化
	ppop = new PartialPopulation();
	WholeIndividual::ppop = ppop;

	// 全体解初期化
	wpop = new WholePopulation();

	//パレートランキングと混雑距離による評価
	wpop->evaluation();
	ppop->evaluation();
}

// デストラクタ
NSSE::~NSSE()
{
	int i;
	
	delete ppop;
	delete wpop;
}

// 探索
void NSSE::solve(void)
{
	int gen, i, j, k, cnt;
	vector<double> x, y;

	//wpop->reference();
	for(gen = 1; gen <=	GENERATION_MAX; gen++) {
		//cout << "第" << gen << "世代" << endl;

		//交叉する部分解個体の選択
		std::sort(WholePopulation::refpop.begin(), WholePopulation::refpop.end());
		WholePopulation::refpop.erase(std::unique(WholePopulation::refpop.begin(), WholePopulation::refpop.end()), WholePopulation::refpop.end());
		vector<PartialIndividual*> poptmp = ppop->pop;
		for(i = 0; i < WholePopulation::refpop.size(); i++) {
			for(j = 0; j < poptmp.size(); j++) {
				if(WholePopulation::refpop[i] == poptmp[j]) {
					poptmp.erase(poptmp.begin() + j);
					break;
				}
			}
		}
		//cout << poptmp.size() << endl;
		//#pragma omp parallel sections
		{
			//#pragma omp section
			{
				//部分解世代交代
				ppop->newGeneration(poptmp);
			}
			WholePopulation::refpop.clear();

			//#pragma omp section
			{
				//全体解世代交代
				wpop->newWholeGeneration();
			}
		}
		// 部分解適応度初期化
		ppop->evalinit();

		//パレートランキングと混雑距離による評価
		wpop->evaluation();
		
		//部分解の評価
		ppop->evaluation();
	}
	wpop->printfitness();
	//wpop->printsolution();
	wpop->reference();
}
