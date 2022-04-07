/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 15:18:13 by cberganz          #+#    #+#             */
/*   Updated: 2022/04/06 16:27:58 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>
# include <string>

class	Fixed {

public:
	Fixed();
	Fixed(const Fixed &fixed);
	Fixed(const int n);
	Fixed(const float n);
	~Fixed();
	Fixed	&operator=(const Fixed &fixed);
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat(void) const;
	int		toInt(void) const;

private:
	int					_fixedPointValue;
	static const int	_fractionalBits = 8;
};

std::ostream	&operator<<(std::ostream &flux, Fixed const& fixed);

#endif
