/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 17:38:54 by cberganz          #+#    #+#             */
/*   Updated: 2022/05/22 02:02:56 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Dog.hpp"

Dog::Dog( void ) : Animal( "Dog" )
{
	this->_brain = new Brain;
    std::cout << "Dog default constructor called !" << std::endl;
}

Dog::Dog( Dog const &instance ) : Animal( instance )
{
	*this = instance;
	std::cout << "Dog copy constructor called !" << std::endl;
}

Dog::~Dog( void )
{
	delete this->_brain;
    std::cout << "Dog destructor called !" << std::endl;
}

Dog	&Dog::operator=( Dog const &other)
{
	if ( this != &other )
	{
		this->_type = other.getType();
		this->_brain = new Brain( *other.getBrain() );
	}
	return ( *this );
}

void Dog::makeSound( void ) const
{
	std::cout << "Ouaf !" << std::endl;
}

Brain	*Dog::getBrain( void ) const
{
	return ( this->_brain );
}

void Dog::getIdea( int index )
{
	std::cout << this->_brain->_ideas[index] << std::endl;
}
