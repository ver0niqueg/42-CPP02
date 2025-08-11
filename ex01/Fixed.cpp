/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgalmich <vgalmich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 13:13:29 by vgalmich          #+#    #+#             */
/*   Updated: 2025/08/11 18:47:46 by vgalmich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : _rawBits(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	this->_rawBits = copy.getRawBits();
}

Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->_rawBits = other.getRawBits();
	return (*this);
}

Fixed::Fixed(const int intValue)
{
	std::cout << "Int constructor called" << std::endl;
	_rawBits = intValue << _fractionalBits; // decale l'entier vers la gauche de fractionalbits
}

Fixed::Fixed(const float floatValue)
{
	std::cout << "Float construction called" << std::endl;
	this->_rawBits = roundf(floatValue * (1 << _fractionalBits));
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

float Fixed::toFloat(void) const
{
	return (this->_rawBits / float(1 << _fractionalBits));
}

int Fixed::toInt(void) const
{
	return (this->_rawBits >>  _fractionalBits);
}

int Fixed::getRawBits(void) const
{
	return (this->_rawBits);
}

void Fixed::setRawBits(int const raw)
{
	this->_rawBits = raw;
}

std::ostream &operator<<(std::ostream &o, const Fixed &value)
{
	o << value.toFloat(); // on affiche la valeur en float
	return o; // on retourne le flux pour pouvoir chainer les <<
}

