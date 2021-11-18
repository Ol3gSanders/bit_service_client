#ifndef BIT_SERVICE_H
#define BIT_SERVICE_H

#include <inttypes.h>

template<typename TYPE>
TYPE set_bit( TYPE value, uint8_t bit_index )
{
	TYPE uno = 1;
	TYPE mask = uno << ( bit_index - 1 );
	TYPE ret_val = ( ( value ) | ( mask ) );
	
	return ret_val;
}

template<typename TYPE>
TYPE clear_bit( TYPE value, uint8_t bit_index )
{
	TYPE uno = 1;
	TYPE mask = uno << ( bit_index - 1 );
	TYPE ret_val = ( value & ( ~mask ) );
	
	return ret_val;
}

template<typename TYPE>
bool is_bit_set( TYPE value, unsigned bit_index )
{
	bool bit_set = false;
	TYPE ret_val = ( ( value >> ( bit_index - 1 ) ) & 1 );
	if ( ret_val == 1 ){
		bit_set = true;
	}
		
	return bit_set;
}

template<typename TYPE>
bool is_bit_clear( TYPE value, unsigned bit_index )
{
	bool bit_clear = false;
	TYPE ret_val = ( ( value >> ( bit_index - 1 ) ) & 1 );
	if ( ret_val == 0 ){
		bit_clear = true;
	}
	
	return bit_clear;
}

template<typename TYPE>
TYPE get_bit_clear_num( TYPE value )
{
	size_t bit_clear_num = 0;
	for( size_t i = 0; i < sizeof(value) * 8; ++i, value >>= 1 ){
		if ( ( value & 1 ) == 0 ){
			bit_clear_num ++;
		}
	}
	
	return bit_clear_num;
}

template<typename TYPE>
TYPE get_bit_set_num( TYPE value )
{
	size_t bit_set_num = 0;
	for( size_t i = 0; i < sizeof(value) * 8; ++i, value >>= 1 ){
		if ( ( value & 1 ) == 1 ){
			bit_set_num ++;
		}
	}
	
	return bit_set_num;
}

#endif // BIT_SERVICE_H
