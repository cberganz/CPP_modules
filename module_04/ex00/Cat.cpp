/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 17:38:49 by cberganz          #+#    #+#             */
/*   Updated: 2022/05/21 22:15:13 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Cat.hpp"

Cat::Cat( void ) : Animal("Cat")
{
    std::cout << "Cat default constructor called !" << std::endl;
}

Cat::Cat( Cat const &instance ) : Animal(instance)
{
	std::cout << "Cat copy constructor called !" << std::endl;
}

Cat::~Cat( void )
{
    std::cout << "Cat destructor called !" << std::endl;
}

Cat	&Cat::operator=( Cat const &other)
{
	if (this != &other)
		this->_type = other.getType();
	return ( *this );
}

void Cat::makeSound( void ) const
{
	std::cout << "Meow !" << std::endl;
}
