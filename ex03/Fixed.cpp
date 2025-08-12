/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgalmich <vgalmich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 15:27:08 by vgalmich          #+#    #+#             */
/*   Updated: 2025/08/13 00:57:31 by vgalmich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : _rawBits(0)
{
}

Fixed::Fixed(const Fixed &copy)
{
	this->_rawBits = copy.getRawBits();
}

Fixed &Fixed::operator=(const Fixed &other)
{
		this->_rawBits = other.getRawBits();
	return (*this);
}

Fixed::Fixed(const int intValue)
{
	_rawBits = intValue << _fractionalBits;
}

Fixed::Fixed(const float floatValue)
{
	this->_rawBits = roundf(floatValue * (1 << _fractionalBits));
}

float Fixed::toFloat(void) const
{
	return (this->_rawBits / float(1 << _fractionalBits));
}

int Fixed::toInt(void) const
{
	return (this->_rawBits >>  _fractionalBits);
}

// operateurs de comparaisons
bool Fixed::operator>(const Fixed &other) const
{
	return this->_rawBits > other._rawBits;
}

bool Fixed::operator<(const Fixed &other) const
{
	return this->_rawBits < other._rawBits;    
}

bool Fixed::operator>=(const Fixed &other) const
{
	return this->_rawBits >= other._rawBits;    
}

bool Fixed::operator<=(const Fixed &other) const
{
	return this->_rawBits <= other._rawBits; 
}

bool Fixed::operator==(const Fixed &other) const
{
	return this->_rawBits == other._rawBits;
}

bool Fixed::operator!=(const Fixed &other) const
{
	return this->_rawBits != other._rawBits;
}

// operateurs arithmetiques
Fixed Fixed::operator+(const Fixed &other) const
{
	Fixed result;
	result.setRawBits(this->_rawBits + other._rawBits);
	return result;
}

Fixed Fixed::operator-(const Fixed &other) const
{
	Fixed result;
	result.setRawBits(this->_rawBits - other._rawBits);
	return result;
}

Fixed Fixed::operator*(const Fixed &other) const
{
	Fixed result;
	result.setRawBits((long long)(this->_rawBits * other._rawBits) >> _fractionalBits);
	return result;
}

Fixed Fixed::operator/(const Fixed &other) const
{
	Fixed result;
	result.setRawBits((this->_rawBits << _fractionalBits) / other._rawBits);
	return result;
}

Fixed &Fixed::operator++(void)
{
	this->_rawBits++;
	return (*this);   
}

Fixed Fixed::operator++(int)
{
	Fixed temp(*this);
	this->_rawBits++;
	return(temp);
}

Fixed &Fixed::operator--(void)
{
	this->_rawBits--;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed temp(*this);
	this->_rawBits--;
	return(temp);
}

Fixed::~Fixed()
{
}

int Fixed::getRawBits(void) const
{
	return (this->_rawBits);
}

void Fixed::setRawBits(int const raw)
{
	this->_rawBits = raw;
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
}

const Fixed &Fixed::min(Fixed const &a, Fixed const &b)
{
	return ((a < b) ? a : b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return (a);
	return (b);
}

const Fixed &Fixed::max(Fixed const &a, Fixed const &b)
{
	return ((a > b) ? a : b);
}

std::ostream &operator<<(std::ostream &o, const Fixed &value)
{
	o << value.toFloat();
	return o;
}