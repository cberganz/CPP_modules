/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 18:39:39 by cberganz          #+#    #+#             */
/*   Updated: 2022/05/15 13:02:55 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include <iostream>
# include "Fixed.hpp"

class	Point {

public:
	Point();
	Point(float const x, float const y);
	Point(Point const &point);
	~Point();

	Point	&operator=(Point const &point);

	Fixed	getX(void) const;
	Fixed	getY(void) const;

private:
	Fixed	const _x;
	Fixed	const _y;
};

bool	bsp(Point const a, Point const b, Point const c, Point const point);

#endif
