/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 15:23:35 by cberganz          #+#    #+#             */
/*   Updated: 2022/05/15 11:49:59 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	this->_fixedPointValue = 0;
}

Fixed::~Fixed()
{
}

Fixed::Fixed(const Fixed &src)
{
	*this = src;
}

Fixed::Fixed(const int n)
{
	this->_fixedPointValue = n << this->_fractionalBits;
}

Fixed::Fixed(const float n)
{
	this->_fixedPointValue = roundf(n * (1 << this->_fractionalBits));
}

bool	Fixed::operator>(const Fixed &fixed) const
{
	return (this->_fixedPointValue > fixed._fixedPointValue);
}

bool	Fixed::operator<(const Fixed &fixed) const
{
	return (this->_fixedPointValue < fixed._fixedPointValue);
}

bool	Fixed::operator>=(const Fixed &fixed) const
{
	return (this->_fixedPointValue >= fixed._fixedPointValue);
}

bool	Fixed::operator<=(const Fixed &fixed) const
{
	return (this->_fixedPointValue <= fixed._fixedPointValue);
}

bool	Fixed::operator==(const Fixed &fixed) const
{
	return (this->_fixedPointValue == fixed._fixedPointValue);
}

bool	Fixed::operator!=(const Fixed &fixed) const
{
	return (this->_fixedPointValue != fixed._fixedPointValue);
}

Fixed	&Fixed::operator=(const Fixed &fixed)
{
	if (this != &fixed)
		this->_fixedPointValue = fixed.getRawBits();
	return (*this);
}

Fixed	Fixed::operator+(const Fixed &fixed) const
{
	return ( Fixed( this->toFloat() + fixed.toFloat() ) );
}

Fixed	Fixed::operator-(const Fixed &fixed) const
{
	return ( Fixed( this->toFloat() - fixed.toFloat() ) );
}

Fixed	Fixed::operator*(const Fixed &fixed) const
{
	return ( Fixed( this->toFloat() * fixed.toFloat() ) );
}

Fixed	Fixed::operator/(const Fixed &fixed) const
{
	return ( Fixed( this->toFloat() / fixed.toFloat() ) );
}

Fixed	Fixed::operator++(int)
{
	Fixed	tmp(*this);
	++this->_fixedPointValue;
	return (tmp);
}

Fixed	&Fixed::operator++()
{
	this->_fixedPointValue++;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	tmp(*this);
	--this->_fixedPointValue;
	return (tmp);
}

Fixed	&Fixed::operator--()
{
	this->_fixedPointValue--;
	return (*this);
}

std::ostream	&operator<<(std::ostream &flux, Fixed const &fixed)
{
    flux << fixed.toFloat();
    return flux;
}

int		Fixed::getRawBits(void) const
{
	return (this->_fixedPointValue);
}

void	Fixed::setRawBits(int const newValue)
{
	this->_fixedPointValue = newValue;
}

float	Fixed::toFloat(void) const
{
	return ((float)this->_fixedPointValue / (1 << Fixed::_fractionalBits));
}

int		Fixed::toInt(void) const
{
	return (this->_fixedPointValue >> Fixed::_fractionalBits);
}

Fixed	&Fixed::min(Fixed &fixed1, Fixed &fixed2)
{
	return (fixed1.toFloat() < fixed2.toFloat() ? fixed1 : fixed2);
}

Fixed	&Fixed::min(Fixed const &fixed1, Fixed const &fixed2) const
{
	return (fixed1.toFloat() < fixed2.toFloat() ? fixed1 : fixed2);
}

Fixed	&Fixed::max(Fixed &fixed1, Fixed &fixed2)
{
	return (fixed1.toFloat() > fixed2.toFloat() ? fixed1 : fixed2);
}

Fixed	&Fixed::max(Fixed const &fixed1, Fixed const &fixed2) const
{
	return (fixed1.toFloat() > fixed2.toFloat() ? fixed1 : fixed2);
}
