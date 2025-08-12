/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgalmich <vgalmich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 15:28:16 by vgalmich          #+#    #+#             */
/*   Updated: 2025/08/13 01:03:12 by vgalmich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

/* 
1. calculer l'aire du triangle complet -> A
2. calculer l'aire des trois triangles formes par point et deux sommets du triangle
- si le point est a l'interieur A1 + A2 + A3 == A
- aucune des aires ne doit etre nulle sinon il est sur un bord ou au sommet
- sinon hors du triangle ou sur un bord
*/

static Fixed calculateArea(Point const a, Point const b, Point const c)
{
	Fixed area = Fixed(0.5f) *
		(a.getX() * (b.getY() - c.getY())
		+ b.getX() * (c.getY() - a.getY())
		+ c.getX() * (a.getY() - b.getY()));
	return (area);
}
// fonction pour determiner si le point est strictement a l'interieur
bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed A;
	Fixed A1;
	Fixed A2;
	Fixed A3;

	A = calculateArea(a, b, c);
	A1 = calculateArea(point, b, c);
	A2 = calculateArea(a, point, c);
	A3 = calculateArea(a, b, point);
	if (A1 <= Fixed(0) || A2 <= Fixed(0) || A3 <= Fixed(0))
		return false;
	return (A == (A1 + A2 + A3));
}