#include <stdio.h>
#include "print.h"

void test_result_print( const char *test_name, bool test_result )
{
	printf( "%s", test_result_to_str( test_name, test_result ).c_str() );
}

string test_result_to_str( const char *test_name, bool test_result )
{
	const char *result_str = test_result ? "PASSED" : "ERROR (NOT PASSED)";

	char tmp_str[256];
	sprintf( tmp_str, "%s: %s\n", test_name, result_str );

	return tmp_str;
}
