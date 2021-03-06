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
	// ?????????????? ????????????
	uint8_t value = 0x3;
	uint8_t bit_index = 1;

	// ?????????????????? ???????????????? ????????????
	int expected_data = 0x3;

	// ???????????????? ????????????
	int result_data = set_bit( value, bit_index );

	// ?????????????????? ?????????????????? ???????????????? ???????????? ?? ?????????????????? ??????????????
	bool test_result = EXPECT_EQ( expected_data, result_data );
	return test_result;
}

bool TEST2()
{
	// ?????????????? ????????????
	uint16_t value = 0x3;
	uint8_t bit_index = 9;

	// ?????????????????? ???????????????? ????????????
	int expected_data = 0x103; //259

	// ???????????????? ????????????
	int result_data = set_bit( value, bit_index );

	// ?????????????????? ?????????????????? ???????????????? ???????????? ?? ?????????????????? ??????????????
	bool test_result = EXPECT_EQ( expected_data, result_data );
	return test_result;
}

bool TEST3()
{
	// ?????????????? ????????????
	uint32_t value = 0x3;
	uint8_t bit_index = 17;

	// ?????????????????? ???????????????? ????????????
	int expected_data = 0x10003; //65539

	// ???????????????? ????????????
	int result_data = set_bit( value, bit_index );

	// ?????????????????? ?????????????????? ???????????????? ???????????? ?? ?????????????????? ??????????????
	bool test_result = EXPECT_EQ( expected_data, result_data );
	return test_result;
}

bool TEST4()
{
	// ?????????????? ????????????
	uint64_t value = 0x0;
	uint8_t bit_index = 33;

	// ?????????????????? ???????????????? ????????????
	uint64_t expected_data = 0x100000000; //4294967296

	// ???????????????? ????????????
	uint64_t result_data = set_bit( value, bit_index );

	// ?????????????????? ?????????????????? ???????????????? ???????????? ?? ?????????????????? ??????????????
	bool test_result = EXPECT_EQ( expected_data, result_data );
	return test_result;
}

//----------------------------clear_bit tests----------------------------

bool TEST5()
{
	// ?????????????? ????????????
	uint8_t value = 0x3;
	uint8_t bit_index = 1;

	// ?????????????????? ???????????????? ????????????
	int expected_data = 0x2;

	// ???????????????? ????????????
	int result_data = clear_bit( value, bit_index );

	// ?????????????????? ?????????????????? ???????????????? ???????????? ?? ?????????????????? ??????????????
	bool test_result = EXPECT_EQ( expected_data, result_data );
	return test_result;
}

bool TEST6()
{
	// ?????????????? ????????????
	uint16_t value = 0x103; //259
	uint8_t bit_index = 9;

	// ?????????????????? ???????????????? ????????????
	int expected_data = 0x3;

	// ???????????????? ????????????
	int result_data = clear_bit( value, bit_index );

	// ?????????????????? ?????????????????? ???????????????? ???????????? ?? ?????????????????? ??????????????
	bool test_result = EXPECT_EQ( expected_data, result_data );
	return test_result;
}

bool TEST7()
{
	// ?????????????? ????????????
	uint32_t value = 0x10003; //65539
	uint8_t bit_index = 17;

	// ?????????????????? ???????????????? ????????????
	int expected_data = 0x3;

	// ???????????????? ????????????
	int result_data = clear_bit( value, bit_index );

	// ?????????????????? ?????????????????? ???????????????? ???????????? ?? ?????????????????? ??????????????
	bool test_result = EXPECT_EQ( expected_data, result_data );
	return test_result;
}

bool TEST8()
{
	// ?????????????? ????????????
	uint64_t value = 0x100000000; //4294967296
	uint8_t bit_index = 33;

	// ?????????????????? ???????????????? ????????????
	uint64_t expected_data = 0x0;

	// ???????????????? ????????????
	uint64_t result_data = clear_bit( value, bit_index );

	// ?????????????????? ?????????????????? ???????????????? ???????????? ?? ?????????????????? ??????????????
	bool test_result = EXPECT_EQ( expected_data, result_data );
	return test_result;
}

//----------------------------is_bit_set tests----------------------------

bool TEST9()
{
	// ?????????????? ????????????
	uint8_t value = 0x3;
	unsigned bit_index = 1;

	// ?????????????????? ???????????????? ????????????
	int expected_data = 0x1;

	// ???????????????? ????????????
	int result_data = is_bit_set( value, bit_index );

	// ?????????????????? ?????????????????? ???????????????? ???????????? ?? ?????????????????? ??????????????
	bool test_result = EXPECT_EQ( expected_data, result_data );
	return test_result;
}

bool TEST10()
{
	// ?????????????? ????????????
	uint16_t value = 0x103; //259
	unsigned bit_index = 9;

	// ?????????????????? ???????????????? ????????????
	int expected_data = 0x1;

	// ???????????????? ????????????
	int result_data = is_bit_set( value, bit_index );

	// ?????????????????? ?????????????????? ???????????????? ???????????? ?? ?????????????????? ??????????????
	bool test_result = EXPECT_EQ( expected_data, result_data );
	return test_result;
}

bool TEST11()
{
	// ?????????????? ????????????
	uint32_t value = 0x10003; //65539
	unsigned bit_index = 17;

	// ?????????????????? ???????????????? ????????????
	int expected_data = 0x1;

	// ???????????????? ????????????
	int result_data = is_bit_set( value, bit_index );

	// ?????????????????? ?????????????????? ???????????????? ???????????? ?? ?????????????????? ??????????????
	bool test_result = EXPECT_EQ( expected_data, result_data );
	return test_result;
}

bool TEST12()
{
	// ?????????????? ????????????
	uint64_t value = 0x3;
	unsigned bit_index = 4;

	// ?????????????????? ???????????????? ????????????
	int expected_data = 0x0;

	// ???????????????? ????????????
	int result_data = is_bit_set( value, bit_index );

	// ?????????????????? ?????????????????? ???????????????? ???????????? ?? ?????????????????? ??????????????
	bool test_result = EXPECT_EQ( expected_data, result_data );
	return test_result;
}

//----------------------------is_bit_clear tests----------------------------

bool TEST13()
{
	// ?????????????? ????????????
	uint8_t value = 0x3;
	unsigned bit_index = 1;

	// ?????????????????? ???????????????? ????????????
	int expected_data = 0x0;

	// ???????????????? ????????????
	int result_data = is_bit_clear( value, bit_index );

	// ?????????????????? ?????????????????? ???????????????? ???????????? ?? ?????????????????? ??????????????
	bool test_result = EXPECT_EQ( expected_data, result_data );
	return test_result;
}

bool TEST14()
{
	// ?????????????? ????????????
	uint16_t value = 0x103; //259
	unsigned bit_index = 9;

	// ?????????????????? ???????????????? ????????????
	int expected_data = 0x0;

	// ???????????????? ????????????
	int result_data = is_bit_clear( value, bit_index );

	// ?????????????????? ?????????????????? ???????????????? ???????????? ?? ?????????????????? ??????????????
	bool test_result = EXPECT_EQ( expected_data, result_data );
	return test_result;
}

bool TEST15()
{
	// ?????????????? ????????????
	uint32_t value = 0x10003; //65539
	unsigned bit_index = 17;

	// ?????????????????? ???????????????? ????????????
	int expected_data = 0x0;

	// ???????????????? ????????????
	int result_data = is_bit_clear( value, bit_index );

	// ?????????????????? ?????????????????? ???????????????? ???????????? ?? ?????????????????? ??????????????
	bool test_result = EXPECT_EQ( expected_data, result_data );
	return test_result;
}

bool TEST16()
{
	// ?????????????? ????????????
	uint64_t value = 0x3;
	unsigned bit_index = 4;

	// ?????????????????? ???????????????? ????????????
	int expected_data = 0x1;

	// ???????????????? ????????????
	int result_data = is_bit_clear( value, bit_index );

	// ?????????????????? ?????????????????? ???????????????? ???????????? ?? ?????????????????? ??????????????
	bool test_result = EXPECT_EQ( expected_data, result_data );
	return test_result;
}

//----------------------------get_bit_clear_num tests----------------------------

bool TEST17()
{
	// ?????????????? ????????????
	uint8_t value = 0x3;

	// ?????????????????? ???????????????? ????????????
	int expected_data = 0x6;

	// ???????????????? ????????????
	int result_data = get_bit_clear_num( value );

	// ?????????????????? ?????????????????? ???????????????? ???????????? ?? ?????????????????? ??????????????
	bool test_result = EXPECT_EQ( expected_data, result_data );
	return test_result;
}

bool TEST18()
{
	// ?????????????? ????????????
	uint16_t value = 0x7;

	// ?????????????????? ???????????????? ????????????
	int expected_data = 0xD; //13

	// ???????????????? ????????????
	int result_data = get_bit_clear_num( value );

	// ?????????????????? ?????????????????? ???????????????? ???????????? ?? ?????????????????? ??????????????
	bool test_result = EXPECT_EQ( expected_data, result_data );
	return test_result;
}

bool TEST19()
{
	// ?????????????? ????????????
	uint32_t value = 0x7;

	// ?????????????????? ???????????????? ????????????
	int expected_data = 0x1D; //29

	// ???????????????? ????????????
	int result_data = get_bit_clear_num( value );

	// ?????????????????? ?????????????????? ???????????????? ???????????? ?? ?????????????????? ??????????????
	bool test_result = EXPECT_EQ( expected_data, result_data );
	return test_result;
}

bool TEST20()
{
	// ?????????????? ????????????
	uint64_t value = 0x7;

	// ?????????????????? ???????????????? ????????????
	int expected_data = 0x3D; //61

	// ???????????????? ????????????
	int result_data = get_bit_clear_num( value );

	// ?????????????????? ?????????????????? ???????????????? ???????????? ?? ?????????????????? ??????????????
	bool test_result = EXPECT_EQ( expected_data, result_data );
	return test_result;
}

//----------------------------get_bit_set_num tests----------------------------

bool TEST21()
{
	// ?????????????? ????????????
	uint8_t value = 0x3;

	// ?????????????????? ???????????????? ????????????
	int expected_data = 0x2;

	// ???????????????? ????????????
	int result_data = get_bit_set_num( value );

	// ?????????????????? ?????????????????? ???????????????? ???????????? ?? ?????????????????? ??????????????
	bool test_result = EXPECT_EQ( expected_data, result_data );
	return test_result;
}


bool TEST22()
{
	// ?????????????? ????????????
	uint16_t value = 0x7;

	// ?????????????????? ???????????????? ????????????
	int expected_data = 0x3;

	// ???????????????? ????????????
	int result_data = get_bit_set_num( value );

	// ?????????????????? ?????????????????? ???????????????? ???????????? ?? ?????????????????? ??????????????
	bool test_result = EXPECT_EQ( expected_data, result_data );
	return test_result;
}



bool TEST23()
{
	// ?????????????? ????????????
	uint32_t value = 0x7;

	// ?????????????????? ???????????????? ????????????
	int expected_data = 0x3;

	// ???????????????? ????????????
	int result_data = get_bit_set_num( value );

	// ?????????????????? ?????????????????? ???????????????? ???????????? ?? ?????????????????? ??????????????
	bool test_result = EXPECT_EQ( expected_data, result_data );
	return test_result;
}



bool TEST24()
{
	// ?????????????? ????????????
	uint64_t value = 0x7;

	// ?????????????????? ???????????????? ????????????
	int expected_data = 0x3;

	// ???????????????? ????????????
	int result_data = get_bit_set_num( value );

	// ?????????????????? ?????????????????? ???????????????? ???????????? ?? ?????????????????? ??????????????
	bool test_result = EXPECT_EQ( expected_data, result_data );
	return test_result;
}
