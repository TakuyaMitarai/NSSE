#include "NSSE.h"

// メインルーチン
int main()
{
	int i;
	float comptime;
	clock_t start;
	NSSE *se;

	// 時間計測スタート
	start = clock();

	// 乱数のタネの設定
	srand((unsigned int)time(NULL));

	// 解探索
	se = new NSSE();
	se->solve();

	// 処理時間計算
	comptime = (float)(clock() - start) / CLOCKS_PER_SEC;

	printf("処理時間：%f秒\n", comptime);

	// 後処理
	delete se;

	return 0;
}
