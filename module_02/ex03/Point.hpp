/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 18:39:39 by cberganz          #+#    #+#             */
/*   Updated: 2022/04/07 16:13:52 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include <iostream>
# include "Fixed.hpp"

class	Point {

public:
	Point();
	Point(Fixed const &x, Fixed const &y);
	Point(Point const &point);
	~Point();

	Point	&operator=(Point const &point);

	Fixed const	&getX(void) const;
	Fixed const	&getY(void) const;

private:
	Fixed	_x; // Should be const
	Fixed	_y;
};

bool	bsp(Point const a, Point const b, Point const c, Point const point);

#endif
