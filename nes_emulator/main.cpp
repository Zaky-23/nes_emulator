#include <iostream>

int main()
{
	uint8_t a = 0x80;
	a |= 0x00;

	printf("%d\n", a);

	return 0;
}