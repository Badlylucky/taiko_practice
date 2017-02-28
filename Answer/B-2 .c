#include <stdio.h>

//BPM:bの場合に1小節ごとの間隔を返す（単位：ミリ秒）
float BPM_dec(int b)
{
	return (float)60*1000*4/b;
}

int main()
{
	int i,j;
	int BPM;
	float interbal=0;
	float music_time=0;//演奏時間
	float density=0;//秒間密度
	float renda=0;//連打秒数
	int measure=0;
	int notes=0;//総ノーツ数
	int cnt=0;//1小節ごとの0などの間隔数のカウント
	int renda_cnt=0;//連打カウント
	int flag=0;//連打状態かどうかのフラグ
	char score[100][200];
	scanf("%d",&BPM);
	scanf("%d",&measure);
	for(i=0;i<measure;i++)
	{
		scanf("%s",&score[i]);
	}
	interbal = BPM_dec(BPM);
	music_time = (float)interbal * measure /1000; //演奏時間の算出
	for(i=0;i<measure;i++)
	{
		j=0;
		cnt=0;
		renda_cnt=0;
		while(score[i][j]!='\0')//1小説の読み込み開始
		{
			if(flag==0)//連打状態でない場合
			{
				if(score[i][j]=='0')
				{
					cnt++;
				}else if(score[i][j]<'5' && score[i][j]>'0'){
					cnt++;
					notes++;
				}else if(score[i][j]>='5' && score[i][j]<'8'){
					cnt++;
					renda_cnt++;
					flag=1;
				}
			}else{//連打状態の場合
				if(score[i][j]=='8')//連打終了記号なら
				{
					cnt++;
					flag=0;
				}else{
					if(score[i][j]>='0' && score[i][j]<'9')
					{
						cnt++;
						renda_cnt++;
					}
				}
			}
			j++;
		}//1小節の読み込み終了
		if(renda_cnt>0)
		{
			renda += (float)interbal/cnt*renda_cnt/1000;//連打時間の算出
		}
	}
	density = (float)notes/music_time;//譜面密度の算出

	printf("%d\n%.2f\n%.2f\n",notes,density,renda);
	return 0;
}