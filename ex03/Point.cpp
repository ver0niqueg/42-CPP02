/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgalmich <vgalmich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 15:28:07 by vgalmich          #+#    #+#             */
/*   Updated: 2025/08/11 17:32:50 by vgalmich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// constructeur par defaut
Point::Point() : _x(0), _y(0)
{
}

// constructeur 
Point::Point(float const x, float const y) : _x(x), _y(y)
{
}

// constructeur de copie
Point::Point(Point const &copy) : _x(copy.getX()), _y(copy.getY())
{
}

// operateur d'affectation
Point &Point::operator=(const Point &other)
{
    (void)other;
    return (*this);
}

// detructeur
Point::~Point()
{
}

Fixed Point::getX(void) const
{
    return (this->_x);
}

Fixed Point::getY(void) const
{
    return (this->_y);
}

