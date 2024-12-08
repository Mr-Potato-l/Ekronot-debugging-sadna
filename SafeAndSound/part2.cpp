#include "part2.h"
#include <iostream>
#include <stdexcept>

char* safe_string_copy(char* dest, unsigned int destsize, char* src)
{
	unsigned int srcsize = (unsigned int)strlen(src);
	if (srcsize + 1 > destsize)
		throw std::overflow_error("possible buffer overflow");

	char* ret = dest;
	while ((*dest++ = *src++));
	return ret;
}


#define BUF_SIZE 20
void part2()
{
	char password[] = "secret";
	char dest[BUF_SIZE];
	char src[] = "hello world!";

	try 
	{
		safe_string_copy(dest, BUF_SIZE, src);

		std::cout << "Source: " << src << std::endl;
		std::cout << "Destination: " << dest << std::endl;
	}
	catch (const std::overflow_error& e) 
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
}
