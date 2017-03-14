#include "float.h"

char *doubleToRawString(double x) {
	const size_t bytesInDouble = 8;

	union {
		double value;
		unsigned char bytes[bytesInDouble];
	} u;

	u.value = x;

	char *buffer = (char *)malloc(sizeof(char) * (bytesInDouble * 2 + 1));
	unsigned char *input = u.bytes;
	char *output = buffer;

	for(int i = 0; i < bytesInDouble; ++i) {
		sprintf(output, "%02hhX", *input);

		++input;
		output += 2;
	}
	return buffer;
}

int main(void)
{
	double x = 0.123;
	printf("%s\n", doubleToRawString(x));
	printf("%a\n", x);
}