# include<stdio.h>
# include<conio.h>
# include<cstdlib>
main() {
	FILE *fp;
	char ch;
	if((fp=fopen("C:\\Users\\76494\\Desktop\\poc.txt","r"))==NULL) {
		printf("\nCannot open file strike any key exit!");
		//���û�����ĳ���ַ�ʱ�������Զ���ȡ�����谴�س�
		getch();
		//��ֹ�����ִ�С�����exit_code ���ݸ�����ֵ��ͨ����ֵ��ʾ��������������ֵ��ʾӦ���󷵻ء�
		exit(1);
	}
	//fgetc()������������stream(��)�е���һ���ַ�,��������ļ�β���߷�������ʱ����EOF.  
	ch=fgetc(fp);
	
	while(ch!=EOF) {
		//putchar()������chд��STDOUT(��׼���)
		putchar(ch);
		ch=fgetc(fp);
	}
	//����fclose()�رո������ļ���, �ͷ��ѹ������������л�����. fclose()ִ�гɹ�ʱ����0,���򷵻�EOF.  
	fclose(fp);
}
