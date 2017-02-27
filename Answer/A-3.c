#include <stdio.h>
#include <stdlib.h>

//第1引数と第2引数の文字列の内容を交換する関数
void Change(char a[],char b[])
{
	int i=0;
	char temp;
	do
	{
		temp=b[i];
		b[i]=a[i];
		a[i]=temp;
		i++;
	}while(a[i]!='\0');
	return;
}

int main()
{
	int n;
	char s[5][100];
	int i,j;
	scanf("%d",&n);
	srand(n);
	for(i=0;i<5;i++)
	{
		scanf("%s",&s[i]);
	}

	//ここからシャッフル
	for(i=0;i<5;i++)
	{
		j=rand()%(i+1);
		if(i!=j)
		{
			Change(s[i],s[j]);//チェンジの作業は煩雑になるので関数にして分離
		}
	}
	//ここまで

	for(i=0;i<5;i++)
	{
		printf("%s\n",s[i]);
	}
	return 0;
}