#include <stdio.h>
#include <stdlib.h>

//得られた結果を格納する
struct result
{
	int notes;//ノーツ数
	float density;//秒間密度
	float renda;//連打秒数
};

//BPM:bの場合に1小節ごとの間隔を返す（単位：ミリ秒）
float BPM_dec(int b)
{
	return (float)60*1000*4/b;
}

//データの計算
//変数名はB-2とほぼ一緒
struct result calc_data(int BPM,int measure,char score[][100])
{
	int i,j;
	float music_time;
	float interbal;
	int cnt,renda_cnt;
	int flag=0;
	struct result rr = {0,0.00f,0.00f};
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
					rr.notes++;
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
			rr.renda += (float)interbal/cnt*renda_cnt/1000;//連打時間の算出
		}
	}
	rr.density = (float)rr.notes/music_time;//譜面密度の算出
	return rr;
}

int main(int argc,char *argv[])
{
	int i,j,k;
	int BPM;
	FILE *infp;//ファイルポインタ（入力ファイル）
	FILE *outfp;//ファイルポインタ（出力ファイル）
	struct result r = {0,0.00f,0.00f}; //結果を格納する構造体の初期化
	int measure=0;
	char score[300][100];
	char buf[500];//ファイルの1行を読み込む
	if(argc!=2)//引数がなかったら
	{
		printf("notes:B-3.exe \"FILE NAME\"");
		exit(1);
	}
	if((infp = fopen(argv[1],"r"))==NULL)//ファイル名がなかったら
	{
		printf("ERROR:No exist %s",argv[1]);
		exit(1);
	}
	fgets(buf,500,infp);//1行目の読み取り（BPM）
	buf[strlen(buf)-1]='\0';//終端文字への変換
	BPM = atoi(buf);
	i=0;
	k=0;
	while((fgets(buf,500,infp))!=NULL)//ファイルを1行ずつ読み込み
	{
		j=0;
		if(buf[0]=='#')//行頭が#なら読み飛ばす
		{
			//printf("continue");
			continue;
		}
		for(j=0;j<strlen(buf);j++)
		{
			if(buf[j]==',')//小節区切りなら
			{
				score[i][k]='\0';
				i++;
				k=0;
			}else{
				score[i][k]=buf[j];
				k++;
			}
			//printf("loop%d",j);
		}
	}
	fclose(infp);//開けたら閉める！
	//ファイルの読み込みここまで
	measure = i;
	r = calc_data(BPM,measure,score);//ファイルから得られた譜面から各種データを計算

	//ファイル出力
	if((outfp = fopen("temp.txt","w")) == NULL)
	{
		fprintf(stderr,"ERROR:output Failed");
		exit(1);
	}
	fprintf(outfp,"%d\n%.2f\n%.2f\n",r.notes,r.renda,r.density);
	fclose(outfp);
	return 0;
}
