#include "tests.h"
#include "print.h"
#include "bit_service.h"
#include <iostream>


int main( int argc, char *argv[] )
{
	bool test_result = false;

	printf( "set_bit tests\n" );

	test_result = TEST1();
	test_result_print( "TEST1", test_result );

	test_result = TEST2();
	test_result_print( "TEST2", test_result );

	test_result = TEST3();
	test_result_print( "TEST3", test_result );

	test_result = TEST4();
	test_result_print( "TEST4", test_result );

	printf("\n");
	printf( "clear_bit tests\n" );

	test_result = TEST5();
	test_result_print( "TEST1", test_result );

	test_result = TEST6();
	test_result_print( "TEST2", test_result );

	test_result = TEST7();
	test_result_print( "TEST3", test_result );

	test_result = TEST8();
	test_result_print( "TEST4", test_result );


	printf("\n");
	printf( "is_bit_set tests\n" );

	test_result = TEST9();
	test_result_print( "TEST1", test_result );

	test_result = TEST10();
	test_result_print( "TEST2", test_result );

	test_result = TEST11();
	test_result_print( "TEST3", test_result );

	test_result = TEST12();
	test_result_print( "TEST4", test_result );

	printf("\n");
	printf( "is_bit_clear tests\n" );

	test_result = TEST13();
	test_result_print( "TEST1", test_result );

	test_result = TEST14();
	test_result_print( "TEST2", test_result );

	test_result = TEST15();
	test_result_print( "TEST3", test_result );

	test_result = TEST16();
	test_result_print( "TEST4", test_result );

	printf("\n");
	printf( "get_bit_clear_num tests\n" );

	test_result = TEST17();
	test_result_print( "TEST1", test_result );

	test_result = TEST18();
	test_result_print( "TEST2", test_result );

	test_result = TEST19();
	test_result_print( "TEST3", test_result );

	test_result = TEST20();
	test_result_print( "TEST4", test_result );

	printf("\n");
	printf( "get_bit_set_num tests\n" );

	test_result = TEST21();
	test_result_print( "TEST1", test_result );

	test_result = TEST22();
	test_result_print( "TEST2", test_result );

	test_result = TEST23();
	test_result_print( "TEST3", test_result );

	test_result = TEST24();
	test_result_print( "TEST4", test_result );

	return 0;
}

template<typename TYPE>
bool EXPECT_EQ( TYPE expected, TYPE actual )
{
	return expected == actual;
}

//----------------------------set_bit tests----------------------------

bool TEST1()
{
	// входные данные
	uint8_t value = 0x3;
	uint8_t bit_index = 1;

	// ожидаемые выходные данные
	int expected_data = 0x3;

	// выходные данные
	int result_data = set_bit( value, bit_index );

	// сравнение ожидаемых выходных данных с выходными данными
	bool test_result = EXPECT_EQ( expected_data, result_data );
	return test_result;
}

bool TEST2()
{
	// входные данные
	uint16_t value = 0x3;
	uint8_t bit_index = 9;

	// ожидаемые выходные данные
	int expected_data = 0x103; //259

	// выходные данные
	int result_data = set_bit( value, bit_index );

	// сравнение ожидаемых выходных данных с выходными данными
	bool test_result = EXPECT_EQ( expected_data, result_data );
	return test_result;
}

bool TEST3()
{
	// входные данные
	uint32_t value = 0x3;
	uint8_t bit_index = 17;

	// ожидаемые выходные данные
	int expected_data = 0x10003; //65539

	// выходные данные
	int result_data = set_bit( value, bit_index );

	// сравнение ожидаемых выходных данных с выходными данными
	bool test_result = EXPECT_EQ( expected_data, result_data );
	return test_result;
}

bool TEST4()
{
	// входные данные
	uint64_t value = 0x0;
	uint8_t bit_index = 33;

	// ожидаемые выходные данные
	uint64_t expected_data = 0x100000000; //4294967296

	// выходные данные
	uint64_t result_data = set_bit( value, bit_index );

	// сравнение ожидаемых выходных данных с выходными данными
	bool test_result = EXPECT_EQ( expected_data, result_data );
	return test_result;
}

//----------------------------clear_bit tests----------------------------

bool TEST5()
{
	// входные данные
	uint8_t value = 0x3;
	uint8_t bit_index = 1;

	// ожидаемые выходные данные
	int expected_data = 0x2;

	// выходные данные
	int result_data = clear_bit( value, bit_index );

	// сравнение ожидаемых выходных данных с выходными данными
	bool test_result = EXPECT_EQ( expected_data, result_data );
	return test_result;
}

bool TEST6()
{
	// входные данные
	uint16_t value = 0x103; //259
	uint8_t bit_index = 9;

	// ожидаемые выходные данные
	int expected_data = 0x3;

	// выходные данные
	int result_data = clear_bit( value, bit_index );

	// сравнение ожидаемых выходных данных с выходными данными
	bool test_result = EXPECT_EQ( expected_data, result_data );
	return test_result;
}

bool TEST7()
{
	// входные данные
	uint32_t value = 0x10003; //65539
	uint8_t bit_index = 17;

	// ожидаемые выходные данные
	int expected_data = 0x3;

	// выходные данные
	int result_data = clear_bit( value, bit_index );

	// сравнение ожидаемых выходных данных с выходными данными
	bool test_result = EXPECT_EQ( expected_data, result_data );
	return test_result;
}

bool TEST8()
{
	// входные данные
	uint64_t value = 0x100000000; //4294967296
	uint8_t bit_index = 33;

	// ожидаемые выходные данные
	uint64_t expected_data = 0x0;

	// выходные данные
	uint64_t result_data = clear_bit( value, bit_index );

	// сравнение ожидаемых выходных данных с выходными данными
	bool test_result = EXPECT_EQ( expected_data, result_data );
	return test_result;
}

//----------------------------is_bit_set tests----------------------------

bool TEST9()
{
	// входные данные
	uint8_t value = 0x3;
	unsigned bit_index = 1;

	// ожидаемые выходные данные
	int expected_data = 0x1;

	// выходные данные
	int result_data = is_bit_set( value, bit_index );

	// сравнение ожидаемых выходных данных с выходными данными
	bool test_result = EXPECT_EQ( expected_data, result_data );
	return test_result;
}

bool TEST10()
{
	// входные данные
	uint16_t value = 0x103; //259
	unsigned bit_index = 9;

	// ожидаемые выходные данные
	int expected_data = 0x1;

	// выходные данные
	int result_data = is_bit_set( value, bit_index );

	// сравнение ожидаемых выходных данных с выходными данными
	bool test_result = EXPECT_EQ( expected_data, result_data );
	return test_result;
}

bool TEST11()
{
	// входные данные
	uint32_t value = 0x10003; //65539
	unsigned bit_index = 17;

	// ожидаемые выходные данные
	int expected_data = 0x1;

	// выходные данные
	int result_data = is_bit_set( value, bit_index );

	// сравнение ожидаемых выходных данных с выходными данными
	bool test_result = EXPECT_EQ( expected_data, result_data );
	return test_result;
}

bool TEST12()
{
	// входные данные
	uint64_t value = 0x3;
	unsigned bit_index = 4;

	// ожидаемые выходные данные
	int expected_data = 0x0;

	// выходные данные
	int result_data = is_bit_set( value, bit_index );

	// сравнение ожидаемых выходных данных с выходными данными
	bool test_result = EXPECT_EQ( expected_data, result_data );
	return test_result;
}

//----------------------------is_bit_clear tests----------------------------

bool TEST13()
{
	// входные данные
	uint8_t value = 0x3;
	unsigned bit_index = 1;

	// ожидаемые выходные данные
	int expected_data = 0x0;

	// выходные данные
	int result_data = is_bit_clear( value, bit_index );

	// сравнение ожидаемых выходных данных с выходными данными
	bool test_result = EXPECT_EQ( expected_data, result_data );
	return test_result;
}

bool TEST14()
{
	// входные данные
	uint16_t value = 0x103; //259
	unsigned bit_index = 9;

	// ожидаемые выходные данные
	int expected_data = 0x0;

	// выходные данные
	int result_data = is_bit_clear( value, bit_index );

	// сравнение ожидаемых выходных данных с выходными данными
	bool test_result = EXPECT_EQ( expected_data, result_data );
	return test_result;
}

bool TEST15()
{
	// входные данные
	uint32_t value = 0x10003; //65539
	unsigned bit_index = 17;

	// ожидаемые выходные данные
	int expected_data = 0x0;

	// выходные данные
	int result_data = is_bit_clear( value, bit_index );

	// сравнение ожидаемых выходных данных с выходными данными
	bool test_result = EXPECT_EQ( expected_data, result_data );
	return test_result;
}

bool TEST16()
{
	// входные данные
	uint64_t value = 0x3;
	unsigned bit_index = 4;

	// ожидаемые выходные данные
	int expected_data = 0x1;

	// выходные данные
	int result_data = is_bit_clear( value, bit_index );

	// сравнение ожидаемых выходных данных с выходными данными
	bool test_result = EXPECT_EQ( expected_data, result_data );
	return test_result;
}

//----------------------------get_bit_clear_num tests----------------------------

bool TEST17()
{
	// входные данные
	uint8_t value = 0x3;

	// ожидаемые выходные данные
	int expected_data = 0x6;

	// выходные данные
	int result_data = get_bit_clear_num( value );

	// сравнение ожидаемых выходных данных с выходными данными
	bool test_result = EXPECT_EQ( expected_data, result_data );
	return test_result;
}

bool TEST18()
{
	// входные данные
	uint16_t value = 0x7;

	// ожидаемые выходные данные
	int expected_data = 0xD; //13

	// выходные данные
	int result_data = get_bit_clear_num( value );

	// сравнение ожидаемых выходных данных с выходными данными
	bool test_result = EXPECT_EQ( expected_data, result_data );
	return test_result;
}

bool TEST19()
{
	// входные данные
	uint32_t value = 0x7;

	// ожидаемые выходные данные
	int expected_data = 0x1D; //29

	// выходные данные
	int result_data = get_bit_clear_num( value );

	// сравнение ожидаемых выходных данных с выходными данными
	bool test_result = EXPECT_EQ( expected_data, result_data );
	return test_result;
}

bool TEST20()
{
	// входные данные
	uint64_t value = 0x7;

	// ожидаемые выходные данные
	int expected_data = 0x3D; //61

	// выходные данные
	int result_data = get_bit_clear_num( value );

	// сравнение ожидаемых выходных данных с выходными данными
	bool test_result = EXPECT_EQ( expected_data, result_data );
	return test_result;
}

//----------------------------get_bit_set_num tests----------------------------

bool TEST21()
{
	// входные данные
	uint8_t value = 0x3;

	// ожидаемые выходные данные
	int expected_data = 0x2;

	// выходные данные
	int result_data = get_bit_set_num( value );

	// сравнение ожидаемых выходных данных с выходными данными
	bool test_result = EXPECT_EQ( expected_data, result_data );
	return test_result;
}


bool TEST22()
{
	// входные данные
	uint16_t value = 0x7;

	// ожидаемые выходные данные
	int expected_data = 0x3;

	// выходные данные
	int result_data = get_bit_set_num( value );

	// сравнение ожидаемых выходных данных с выходными данными
	bool test_result = EXPECT_EQ( expected_data, result_data );
	return test_result;
}



bool TEST23()
{
	// входные данные
	uint32_t value = 0x7;

	// ожидаемые выходные данные
	int expected_data = 0x3;

	// выходные данные
	int result_data = get_bit_set_num( value );

	// сравнение ожидаемых выходных данных с выходными данными
	bool test_result = EXPECT_EQ( expected_data, result_data );
	return test_result;
}



bool TEST24()
{
	// входные данные
	uint64_t value = 0x7;

	// ожидаемые выходные данные
	int expected_data = 0x3;

	// выходные данные
	int result_data = get_bit_set_num( value );

	// сравнение ожидаемых выходных данных с выходными данными
	bool test_result = EXPECT_EQ( expected_data, result_data );
	return test_result;
}
