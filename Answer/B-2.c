#include <stdio.h>
#include <windows.h>

//BPM:bの場合に1拍ごとの間隔を返す（単位：ミリ秒）
int BPM_dec(int b)
{
	return 60*1000/b; 
}

int main()
{
	int i;
	int n,b;
	int interbal;
	double c_end,c_begin;//現在の時間
	scanf("%d",&n);
	scanf("%d",&b);
	interbal = BPM_dec(b);//1拍ごとの間隔
	for(int i=0;i<n*4;i++)
	{
		c_begin=(double)(GetTickCount());
		c_end=c_begin+interbal;
		printf("%d %d",i/4+1,i%4+1);
		while((double)(GetTickCount())<c_end)
		{
			//wait
		}
	}
	return 0;
}