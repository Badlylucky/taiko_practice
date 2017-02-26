#include <stdio.h>

int main()
{
	char s[100];
	int i=0;
	scanf("%s",&s);

	while(s[i]!='\0')
	{
		if(s[i]=='0')
		{
			s[i]='.';
		}else if(s[i]=='1'){
			s[i]='d';
		}else if(s[i]=='2'){
			s[i]='k';
		}else{
			s[i]=' ';
		}
		i++;
	}
	printf("%s\n",s);
	return 0;
}