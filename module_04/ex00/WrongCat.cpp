/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 17:38:49 by cberganz          #+#    #+#             */
/*   Updated: 2022/05/22 01:57:18 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "WrongCat.hpp"

WrongCat::WrongCat( void ) : WrongAnimal("Cat")
{
    std::cout << "WrongCat default constructor called !" << std::endl;
}

WrongCat::WrongCat( WrongCat const &instance ) : WrongAnimal(instance)
{
	*this = instance;
	std::cout << "WrongCat copy constructor called !" << std::endl;
}

WrongCat::~WrongCat( void )
{
    std::cout << "WrongCat destructor called !" << std::endl;
}

WrongCat	&WrongCat::operator=( WrongCat const &other)
{
	if (this != &other)
		this->_type = other.getType();
	return ( *this );
}

void WrongCat::makeSound( void ) const
{
	std::cout << "Meow !" << std::endl;
}
