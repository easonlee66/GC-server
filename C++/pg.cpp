/*
	Name:
	Copyright:Easonlee
	Author:Easonlee
	Date:
	Description:
*/
#include <cstdio>
#include <conio.h>
using namespace std;
int main(int argc, char *argv[]){
	puts("���밴1��������2");
	int s=getch()-'0';
	if(s==1){
		puts("�ļ�������XX.ini��");
		char s[100];
		scanf("%s",s);
		sprintf(s,"%s\\%s",argv[1],s);
		freopen(s,"r",stdin);
	}
	return 0;
}
