/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed_conv.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lannur-s <lannur-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 16:00:26 by lannur-s          #+#    #+#             */
/*   Updated: 2024/06/21 16:00:26 by lannur-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "utils.hpp"
#include <bitset>

/*
	For example:
	Decimal : 12.75
	value in Q8.8: 3264 (00001100 11000000 in binary)
	Right bitwise shift: 00001100 11000000 >> 8 = 00000000 00001100
	integerPart: 12 (decimal value of 00000000 00001100)
	1 * (2^(3)) + 1 * (2^(2)) = 8 + 4 = 12
	
	Mask: (1 << 8) - 1 = 256 - 1 = 255 
	Bitwise AND: 00001100 11000000 & 00000000 11111111 (mask) = 00000000 00100000
	fractionPart: 32 (binary fraction value of 00000000 00100000)
	1 * (2^(-1)) + 1 * (2^(-2))  = 0.5 + 0.25 = 0.75
*/
std::string Fixed::toBin( void ) const
{
	int integerPart = value >> fractionalBits;
	int fractionPart = value & ((1 << fractionalBits) - 1);

	std::string integerStr = std::bitset<8>(integerPart).to_string();
	std::string fractionStr = std::bitset<8>(fractionPart).to_string();

	return integerStr + "." + fractionStr.substr(1);
}

/*
	To convert the value from Q8.8 back to a floating-point number, divide it by (1 << fractionalBits)
	3264 / (1 << 8) = 3264 / 256 = 12.75
*/
float	Fixed::toFloat( void ) const
{
	float floatPart =  ((float) value / (1 << fractionalBits));
	std::cout << "Float value (normal format) : " << floatPart << std::endl;
	printFloatBinary( value );
	std::cout << std::endl;
	std::cout << "Fixed point Q8.8 format     : " << value << std::endl;
	std::cout << "            Q8.8 (binary)   : " << toBin() << std::endl;
	return (floatPart);
}

/*
	To convert the value from Q8.8 back to a integer number, divide it by (1 << fractionalBits)
	3072 / (1 << 8) = 3072 / 256 = 12
*/
int		Fixed::toInt( void ) const
{
	int integerPart = ( value / (1 << fractionalBits) );
	std::cout << "Int value in Binary        : " << std::bitset<16>(value) << std::endl;
	std::cout << "            Decimal        : " << integerPart << std::endl;
	return (integerPart);
}
