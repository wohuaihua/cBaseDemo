#include<stdio.h>

//���ʹ��main��������ĺ�������ô����ǰ����к���������
//��������
int SQ(int y);

main() {
	int i=1;
	while(i<=5) {
		printf("%d\n",SQ(i++));
	}
}

int SQ(int y) {
	return ((y)*(y));
}
