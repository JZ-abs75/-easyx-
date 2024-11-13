#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<easyx.h>
#include<math.h>
#include<time.h>
#include<mmsystem.h>
#include<chrono>

#pragma comment(lib, "winmm.lib")

using namespace std;

int main()
{
	auto start_time = chrono::high_resolution_clock::now();

	initgraph(800, 600, EX_SHOWCONSOLE);

	mciSendString("open FunkyTown.mp3 alias BGM", NULL, 0, NULL);
	mciSendString("play BGM repeat", NULL, 0, NULL);

	setbkcolor(WHITE);
	cleardevice();

	setfillcolor(YELLOW);
	int left, top, right, bottom;
	while (true)
	{
		cleardevice();
		clock_t t1 = clock();
		top = 200 + 25 * sin(t1);
		bottom = 400 + 25 * sin(t1);
		clock_t t2 = clock();
		left = min(400 + 50 * sin(t2), 400 - 50 * sin(t2));
		right = max(400 + 50 * sin(t2), 400 - 50 * sin(t2));
		BeginBatchDraw();
		auto now_time = chrono::high_resolution_clock::now();
		auto duration = chrono::duration_cast<chrono::milliseconds>(now_time - start_time);
		char str[100];
		sprintf(str, "%02d:%02d:%02d", duration.count() / 1000 / 60 / 60, duration.count() / 1000 / 60 % 60, duration.count() / 1000 % 60);
		settextcolor(BLACK);
		outtextxy(10, 10, str);
		solidellipse(left, top, right, bottom);
		EndBatchDraw();
		
	}
	mciSendString("close BGM", NULL, 0, NULL);
	closegraph();

	return 0;
}
