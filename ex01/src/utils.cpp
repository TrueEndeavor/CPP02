/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lannur-s <lannur-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 14:04:00 by lannur-s          #+#    #+#             */
/*   Updated: 2024/06/21 14:13:14 by lannur-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cstring>

void printFloatBinary(float f)
{
	unsigned int float_bits;
	std::memcpy(&float_bits, &f, sizeof(float));

	std::cout << "Float value in Binary       : ";
	for (int i = sizeof(float) * 8 - 1; i >= 0; --i)
	{
		std::cout << ((float_bits >> i) & 1);
	}
	std::cout << std::endl;
}
