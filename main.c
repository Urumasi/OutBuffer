#include <stdio.h>
#include "outbuff.h"

int main(void){
	b_printf("Hello, %s!\n%d\n", "world", 42);
	b_printf("foo\n");

	b_flush();
	return 0;
}