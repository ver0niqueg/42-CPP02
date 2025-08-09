/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgalmich <vgalmich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 20:29:40 by vgalmich          #+#    #+#             */
/*   Updated: 2025/08/09 20:29:40 by vgalmich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// constructeur par defaut -> initialisation a 0
Fixed::Fixed(void) : _rawBits(0)
{
    std::cout << "Default constructor called" << std::endl;
}

// constructeur de copie -> initialisation de l'objet en utilisant un autre objet de meme classe
Fixed::Fixed(const Fixed &copy)
{
    std::cout << "Copy constructor called" << std::endl;
    this->_rawBits = copy.getRawBits();
}

// operateur d'affectation -> prends un objet deja existant et lui attribu les valeurs d'un autre objet
Fixed &Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    // evite l'auto affectation
    if (this != &other)
        this->_rawBits = other.getRawBits();
    // retourne une ref vers l'objet courant
    return (*this);
}

// destructeur
Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

// getter pour la valeur du nombre a virgule fixe (sans la convertir)
int Fixed::getRawBits(void) const
{
    std::cout << "getRawBit member function called" << std::endl;
    return (this->_rawBits);
}

// initialise la valeur du nombre a virgule fixe a celle celui pass en parametre
void Fixed::setRawBits(int const raw)
{
    this->_rawBits = raw;
}

