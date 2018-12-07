#include <stdio.h>
#include <stdlib.h>
#define SWAP(X) ((((X)&0x55555555)<<1)+(((X)&0xaaaaaaaa)>>1))
  //提取奇数位向左移动1位
  //提取偶数位向右移动1位
  
  /**
  	例如：11----->1011
	奇数位提取出来为0001---->向左移动1位为0010
	偶数位提取出来为1010---->向右移动1位为0101
	两个移位后的值相加为0111---->输出的值为7
	这样就完成了奇数位和偶数位交换。
  */ 
int main()
{
    int n = 111;
    char bin[32];
	itoa(111&1431655765,bin,2);//2即是代表转换为2进制
    printf("%s\n",bin);
    int ret = SWAP(n);
    printf("ret = %d\n", ret);
    system("pause");
    return 0;
}
