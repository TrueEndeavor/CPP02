/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed_comparisons.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lannur-s <lannur-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 16:01:13 by lannur-s          #+#    #+#             */
/*   Updated: 2024/06/21 16:01:13 by lannur-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <bitset>

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
