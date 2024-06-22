/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed_arithmetic.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lannur-s <lannur-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 16:01:05 by lannur-s          #+#    #+#             */
/*   Updated: 2024/06/21 16:01:05 by lannur-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <bitset>

/****************4 arithmetic operators: +, -, *, and '/'***********************/

/*
	Addition: adds the raw fixed-point values
	Example:
			 Decimal    | Q8.8
			 --------   | -------
			 12.75  (+) | 3264  (+)
			 12.75      | 3264
			 --------   | -------
			 25.5       | 6528
			 --------   | -------
	Result:  25.5         (Q8.8: 6528)
*/
Fixed	Fixed::operator+( const Fixed &other ) const 
{
	Fixed ret;
	float decResult;

	// Print values before addition
	float dec1 = toFloat();
	float dec2 = other.toFloat();
	std::cout << "--------    | -------" << std::endl;	
	std::cout << "Decimal     | Q8.8" << std::endl;
	std::cout << "--------    | -------" << std::endl;	
	std::cout << dec1 << "(+)    | " << getRawBits() << std::endl;
	std::cout << dec2 << "       | " << other.getRawBits() << std::endl;
	std::cout << "--------    | -------" << std::endl;
	
	// core logic - add the two values
	ret.setRawBits(getRawBits() + other.getRawBits());
	
	// Print results
	decResult = ret.toFloat();
	std::cout << decResult << "        | " << ret.getRawBits() << std::endl;
	std::cout << "--------    | -------" << std::endl;
	std::cout << GREEN << "Result: ";
	return ret;
}

/*
	Subtraction: subtracts the raw fixed-point values
	Example:
			 Decimal    | Q8.8
			 --------   | -------
			 12.75  (-) | 3264  (-)
			 12.75      | 3264
			 --------   | -------
			 0          | 0
			 --------   | -------
	Result:  0            (Q8.8: 0)
*/
Fixed Fixed::operator-(const Fixed &other) const 
{
	Fixed ret;

	// Print values before subtraction
	float dec1 = toFloat();
	float dec2 = other.toFloat();
	std::cout << "--------    | -------" << std::endl;
	std::cout << "Decimal     | Q8.8" << std::endl;
	std::cout << "--------    | -------" << std::endl;
	std::cout << dec1 << "(-)    | " << getRawBits() << std::endl;
	std::cout << dec2 << "       | " << other.getRawBits() << std::endl;
	std::cout << "--------    | -------" << std::endl;

	// core logic - subtract the two values
	ret.setRawBits(getRawBits() - other.getRawBits());

	// Print results
	float decResult = ret.toFloat();
	std::cout << decResult << "           | " << ret.getRawBits() << std::endl;
	std::cout << "--------    | -------" << std::endl;
	std::cout << GREEN << "Result: ";
	return ret;
}

/*
	Multiplication: multiplies the raw fixed-point values and normalizes
	Example:
			 Decimal          | Q8.8
			 ---------------- | -------
			 12.75  (x)       | 3264  (x)
			 12.75            | 3264
			 ---------------- | -------
			 162.5625         | 41600 (normalized)
			 ---------------- | -------
								Raw: 3264 * 3264 = 10649600
								Normalized: 10649600 >> 8 = 41600 
	Result : 162.562           (Q8.8: 41600)
*/
Fixed Fixed::operator*(const Fixed &other) const 
{
	Fixed ret;

	// Print values before multiplication
	float dec1 = toFloat();
	float dec2 = other.toFloat();
	std::cout << "---------------- | -------" << std::endl;
	std::cout << "Decimal          | Q8.8" << std::endl;
	std::cout << "---------------- | -------" << std::endl;
	std::cout << dec1 << " (x)        | " << getRawBits() << " (x)" << std::endl;
	std::cout << dec2 << "            | " << other.getRawBits() << std::endl;
	std::cout << "---------------- | -------" << std::endl;

	// core logic - multiply the two values
	ret.setRawBits(getRawBits() * other.getRawBits() >> fractionalBits);

	// Print results
	float decResult = ret.toFloat();
	std::cout << decResult << "          | " << ret.getRawBits() << std::endl;
	std::cout << "---------------- | -------" << std::endl;
	std::cout << GREEN << "Result: ";
	return ret;
}

/*
	Division: divides the raw fixed-point values.
	Example:
			 Decimal          | Q8.8
			 ---------------- | --------
			 12.75  (/)       | 3264 (/)
			 12.75            | 3264
			 ---------------- | --------
			 1                | 256
			 ---------------- | --------
								Raw: 3264 / 3264 = 1
								Normalized: 1 << 8 = 256
	Result: 1 (Q8.8: 256)
*/
Fixed Fixed::operator/(const Fixed &other) const 
{
	Fixed ret;

	// Print values before division
	float dec1 = toFloat();
	float dec2 = other.toFloat();
	std::cout << "---------------- | --------" << std::endl;
	std::cout << "Decimal          | Q8.8" << std::endl;
	std::cout << "---------------- | --------" << std::endl;
	std::cout << dec1 << " (/)        | " << getRawBits() << " (/)" << std::endl;
	std::cout << dec2 << "            | " << other.getRawBits() << std::endl;
	std::cout << "---------------- | --------" << std::endl;

	// core logic - divide the two values
	ret.setRawBits(getRawBits() / other.getRawBits() << fractionalBits);

	// Print results
	float decResult = ret.toFloat();
	std::cout << decResult << "                | " << ret.getRawBits() << std::endl;
	std::cout << "---------------- | --------" << std::endl;
	std::cout << GREEN << "Result: ";
	return ret;
}
