/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 15:18:13 by cberganz          #+#    #+#             */
/*   Updated: 2022/05/15 11:49:26 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>
# include <string>

class	Fixed {

public:
	int					getRawBits(void) const;
	void				setRawBits(int const raw);
	float				toFloat(void) const;
	int					toInt(void) const;
	static Fixed		&min(Fixed &fixed1, Fixed &fixed2);
	static Fixed		&min(Fixed const &fixed1, Fixed const &fixed2) const;
	static Fixed		&max(Fixed &fixed1, Fixed &fixed2);
	static Fixed		&max(Fixed const &fixed1, Fixed const &fixed2) const;

	Fixed();
	Fixed(const int n);
	Fixed(const float n);
	Fixed(const Fixed &fixed);
	~Fixed();

	bool	operator>(Fixed const &fixed) const;
	bool	operator<(Fixed const &fixed) const;
	bool	operator>=(Fixed const &fixed) const;
	bool	operator<=(Fixed const &fixed) const;
	bool	operator==(Fixed const &fixed) const;
	bool	operator!=(Fixed const &fixed) const;

	Fixed	&operator=(Fixed const &fixed);
	Fixed	operator+(Fixed const &fixed) const;
	Fixed	operator-(Fixed const &fixed) const;
	Fixed	operator*(Fixed const &fixed) const;
	Fixed	operator/(Fixed const &fixed) const;

	Fixed	operator++(int);
	Fixed	&operator++();
	Fixed	operator--(int);
	Fixed	&operator--();

private:
	int					_fixedPointValue;
	static const int	_fractionalBits = 8;
};

std::ostream	&operator<<(std::ostream &flux, Fixed const& fixed);

#endif
