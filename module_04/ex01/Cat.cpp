/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 17:38:49 by cberganz          #+#    #+#             */
/*   Updated: 2022/05/22 02:02:21 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Cat.hpp"

Cat::Cat( void ) : Animal( "Cat" )
{
	this->_brain = new Brain;
    std::cout << "Cat default constructor called !" << std::endl;
}

Cat::Cat( Cat const &instance ) : Animal( instance )
{
	*this = instance;
	std::cout << "Cat copy constructor called !" << std::endl;
}

Cat::~Cat( void )
{
	delete this->_brain;
    std::cout << "Cat destructor called !" << std::endl;
}

Cat	&Cat::operator=( Cat const &other)
{
	if ( this != &other )
	{
		this->_type = other.getType();
		this->_brain = new Brain( *other.getBrain() );
	}
	return ( *this );
}

void Cat::makeSound( void ) const
{
	std::cout << "Meow !" << std::endl;
}

Brain	*Cat::getBrain( void ) const
{
	return ( this->_brain );
}

void Cat::getIdea( int index )
{
	std::cout << this->_brain->_ideas[index] << std::endl;
}
