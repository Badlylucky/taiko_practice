#include <stdio.h>

//BPM:bの場合に1小節ごとの間隔を返す（単位：ミリ秒）
float BPM_dec(int b)
{
	return (float)60*1000*4/b; 
}

int main()
{
	int bpm,notes,measure;
	float interbal;
	float ave_dense;
	scanf("%d %d",&notes,&measure);
	scanf("%d",&bpm);
	interbal = (float)BPM_dec(bpm)/1000;
	ave_dense = (float)notes / (interbal*measure);
	printf("%.2f\n",ave_dense);
	return 0;
}