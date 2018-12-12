#include <stdio.h>
#include<io.h>
#include <string.h>
#include <stdlib.h>

int main(){
	char  buf1[]="123";
	char  buf2[]="456";	
    char * title = strcat( buf1, buf2 );
    printf( "Hello, %s\n", title );
    printf( "Hello, %s\n", buf1 );
	printf( "Hello, %s\n", buf2 );
}
