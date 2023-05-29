#include "NSSE.h"

// メインルーチン
int main()
{
	int i;
	struct timespec startTime, endTime;
	NSSE *se;

	// 時間計測スタート
	clock_gettime(CLOCK_REALTIME, &startTime);

	// 乱数のタネの設定
	srand((unsigned int)time(NULL));

	// 解探索
	se = new NSSE();
	se->solve();

	// 処理時間計算
	clock_gettime(CLOCK_REALTIME, &endTime);

	printf("time = ");
    if (endTime.tv_nsec < startTime.tv_nsec) {
      printf("%5ld.%09ld", endTime.tv_sec - startTime.tv_sec - 1,
             endTime.tv_nsec + (long int)1.0e+9 - startTime.tv_nsec);
    } else {
      printf("%5ld.%09ld", endTime.tv_sec - startTime.tv_sec,
             endTime.tv_nsec - startTime.tv_nsec);
    }
    printf("(sec)\n");

	// 後処理
	delete se;

	return 0;
}
