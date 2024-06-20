/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lannur-s <lannur-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 16:32:24 by lannur-s          #+#    #+#             */
/*   Updated: 2024/05/09 16:32:24 by lannur-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <bitset>

const int	Fixed::fractionalBits = 8;

/*****************************************************************************/
Fixed::Fixed() : value( 0 ) { }

Fixed::Fixed( const int intVal ) : value ( intVal * (1 << fractionalBits) ) { }

Fixed::Fixed( const float floatVal ) : value (  roundf(floatVal * (1 << fractionalBits) ) ) { }
		
Fixed::~Fixed() { }

Fixed::Fixed( const Fixed& other ) { *this = other; }

Fixed&	Fixed::operator=( const Fixed& other )
{
	if (this != &other)
		this->value = other.getRawBits();
	return (*this);
}

/*****************************************************************************/
int	Fixed::getRawBits( void ) const { return (this->value); }

void	Fixed::setRawBits( int const raw ) { this->value = raw; }

float	Fixed::toFloat( void ) const
{
	float floatPart =  (float)value / (1 << fractionalBits);
	return (floatPart);
}

int		Fixed::toInt( void ) const
{
	int integerPart = ( value / (1 << fractionalBits) );
	return (integerPart);
}

/*****************************************************************************/
// 4 arithmetic operators: +, -, *, and /
Fixed	Fixed::operator+( const Fixed &other ) const 
{
	Fixed temp;
	
	temp.setRawBits (this->getRawBits() + other.getRawBits());
	return (temp);
}

Fixed	Fixed::operator-( const Fixed &other ) const 
{
	Fixed temp;
	
	temp.setRawBits (this->getRawBits() - other.getRawBits());
	return (temp);
}

Fixed	Fixed::operator*( const Fixed &other ) const 
{
	Fixed temp;
	
	temp.setRawBits( this->getRawBits() * other.getRawBits() / (1 << fractionalBits) );
	return (temp);
}

Fixed	Fixed::operator/( const Fixed &other ) const 
{
	Fixed temp;
	
	temp.setRawBits( this->getRawBits() * other.getRawBits() * (1 << fractionalBits) );
	return (temp);
}

/*****************************************************************************/
// 4 increment/decrement operators: ++i, --i, i++, i--
Fixed &Fixed::operator++()
{
	this->value += 1;
	return *this;
}

Fixed &Fixed::operator--()
{
	this->value --;
	return *this;
}

Fixed	Fixed::operator++( int )
{
	//Fixed	tmp(*this);
	return (++(*this));
	//return tmp;
}

Fixed	Fixed::operator--( int )
{
	Fixed	tmp(*this);
	--(*this);
	return tmp;
}

/*****************************************************************************/
// 6 comparison operators: >, <, >=, <=, == and !=
bool	Fixed::operator>( const Fixed &other ) const { return ( this->value > other.value ); }

bool	Fixed::operator<( const Fixed &other ) const { return ( this->value < other.value ); }

bool	Fixed::operator>=( const Fixed &other ) const { return ( this->value >= other.value ); }

bool	Fixed::operator<=( const Fixed &other ) const { return ( this->value <= other.value ); }

bool	Fixed::operator==( const Fixed &other ) const { return ( this->value == other.value ); }

bool	Fixed::operator!=( const Fixed &other ) const { return ( this->value != other.value ); }

// Helper functions for the comparisons
Fixed const &Fixed::min(Fixed const &a, Fixed const &b) { return a < b ? a : b; }

Fixed const &Fixed::max(Fixed const &a, Fixed const &b) { return a > b ? a : b; }

Fixed const &min(Fixed const &a, Fixed const &b) { return Fixed::min(a, b); }

Fixed const &max(Fixed const &a, Fixed const &b) { return Fixed::max(a, b); }

/*****************************************************************************/
// Operator overloaded function
std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
	os<<fixed.toFloat();
	return (os);
}
