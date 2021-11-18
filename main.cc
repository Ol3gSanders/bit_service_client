#include <stdio.h>
#include <inttypes.h>
#include <iostream>
#include "bit_service.h"


int main()
{
	std::cout << "set_bit: " << unsigned( set_bit( 3, 1 ) ) << std::endl;
	std::cout << "clear_bit: " << unsigned( clear_bit( 3, 1 ) ) << std::endl;
	std::cout << "is_bit_set: " << std::boolalpha << ( is_bit_set( 3, 1 ) ) << std::endl;
	std::cout << "is_bit_clear: " << std::boolalpha << ( is_bit_clear( 3, 1 ) ) << std::endl;
	std::cout << "get_bit_clear_num: " << unsigned( get_bit_clear_num( 3 ) ) << std::endl;
	std::cout << "get_bit_set_num: " << unsigned( get_bit_set_num( 3 ) ) << std::endl;
	return 0;
}
