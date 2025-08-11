/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgalmich <vgalmich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 15:28:16 by vgalmich          #+#    #+#             */
/*   Updated: 2025/08/11 18:48:13 by vgalmich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// Faire une fonction qui indique si un point donne est a l'interieur d'un triangle
// Barycentric Subdivision Point Test
// retourner True uniquement si le point est a l'interieur du triangle

// calculer l'aire du triangle complet -> A
// calculer l4qire des trois triangles formes par point et deu sommets du triangle
// si le point est a l4interieur A1 + A2 + A3 == A
// aucune des aires ne doit etre nulle sinon il est sur un bord ou au sommet
// sinon hors du triangle ou sur un bord

// fonction pour calculer l'aire du triangle forme par trois points
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