#ifndef PRINT_H
#define PRINT_H

#include <string>
using std::string;

typedef unsigned uint32_t;

string test_result_to_str( const char *test_name, bool test_result );
string double_array_to_str( double *data, uint32_t data_num );

void test_result_print( const char *test_name, bool test_result );
void double_array_print( double *data, uint32_t data_num );

#endif /* PRINT_H_ */
