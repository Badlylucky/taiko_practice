#define WIN32_LEAN_AND_MEAN
#pragma comment (lib,"user32.lib")
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include <tchar.h>

//BPM:bの場合に1文字ごとの間隔を返す（単位：ミリ秒）
float BPM_dec(int b, int c)
{
	return (float)60*1000*4/b/c;
}

//データの計算
//変数名はB-2とほぼ一緒
void play(float interbal[],int measure,char score[][100])
{
	int i,j;
	int cnt,renda_cnt;
	float c_begin,c_end;
	int flag=0;
	for(i=0;i<measure;i++)
	{
		j=0;
		cnt=0;
		renda_cnt=0;
		c_begin=GetTickCount();
		c_end=c_begin+interbal[i];
		while(score[i][j]!='\0')//1小説の読み込み開始
		{
			if(j!=0)
			{
				c_begin=GetTickCount();
				c_end=c_begin+interbal[i];
			}
			if(flag==0)//連打状態でない場合
			{
				if(score[i][j]=='0')
				{
				}else if(score[i][j]<'5' && score[i][j]>'0'){
					switch(score[i][j])
					{
						case '1':
						case '3':
							//printf("d\n");
							//SendKeys("F");
							keybd_event('F',0,0,0);
							keybd_event('F',0,KEYEVENTF_KEYUP,0);
							break;
						case '2':
						case '4':
							//printf("k\n");
							keybd_event('D',0,0,0);
							keybd_event('D',0,KEYEVENTF_KEYUP,0);
							break;
						default:
							break;
					}
				}else if(score[i][j]>='5' && score[i][j]<'8'){
					//printf("r\n");
					keybd_event('F',0,0,0);
					keybd_event('F',0,KEYEVENTF_KEYUP,0);
					flag=1;
				}
			}else{//連打状態の場合
				if(score[i][j]=='8')//連打終了記号なら
				{
					flag=0;
				}else{
					if(score[i][j]>='0' && score[i][j]<'9')
					{
						//printf("r\n");
						keybd_event('F',0,0,0);
						keybd_event('F',0,KEYEVENTF_KEYUP,0);
					}
				}
			}
			j++;
			while((float)(GetTickCount())<c_end)
			{
				//wait
			}
		}//1小節の読み込み終了
	}
	return;
}

int main(int argc,char *argv[])
{
	int i,j,k;
	int BPM;
	char BPM_ch[5];
	FILE *infp;//ファイルポインタ（入力ファイル）
	FILE *outfp;//ファイルポインタ（出力ファイル）
	int measure=0;
	float interbal[300];//小節ごとの間隔
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
			if(strstr(buf,"#BPMCHANGE")!=NULL)
			{
				for(j=11;j<strlen(buf);j++)
				{
					BPM_ch[j-11]=buf[j];
				}
				BPM = atoi(BPM_ch);//BPMの算出
			}
			continue;
		}
		for(j=0;j<strlen(buf);j++)
		{
			if(buf[j]==',')//小節区切りなら
			{
				score[i][k]='\0';
				interbal[i] = BPM_dec(BPM,strlen(score[i]));
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
	play(interbal,measure,score);//ファイルから得られた譜面からタイミングを計算
	return 0;
}
