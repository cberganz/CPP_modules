/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 20:44:45 by cberganz          #+#    #+#             */
/*   Updated: 2022/04/07 18:57:02 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Fixed	area(Point p1, Point p2, Point p3)
{
//	return std::abs((p1.getX().toFloat() * (p2.getY().toFloat() - p3.getY().toFloat()) + p2.getX().toFloat() * (p3.getY().toFloat() - p1.getY().toFloat()) + p3.getX().toFloat() * (p1.getY().toFloat() - p2.getY().toFloat()))/2.0);
	Fixed aire;

	Fixed p1x = p1.getX();
	Fixed p1y = p1.getY();
	Fixed p2x = p2.getX();
	Fixed p2y = p2.getY();
	Fixed p3x = p3.getX();
	Fixed p3y = p3.getY();

	aire = ((p2x - p1x)*(p3y - p1y) - (p3x - p1x)*(p2y - p1y)) / 2;
	if (aire < 0)
		aire = aire * -1;
	return (aire);
}

bool	bsp(Point const a, Point const b, Point const c, Point const point, bool drawMode)
{
	Fixed	A = area(a, b, c);
	Fixed	A1 = area(a, b, point);
	Fixed	A2 = area(a, c, point);
	Fixed	A3 = area(b, c, point);

	if (!drawMode && (A1 == 0 || A2 == 0 || A3 == 0))
		return (false);
	return (A == (A1 + A2 + A3));
}
