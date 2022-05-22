/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 17:38:34 by cberganz          #+#    #+#             */
/*   Updated: 2022/05/22 01:28:23 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"

Animal::Animal( void ) : _type( "default" )
{
    std::cout << "Animal default constructor called !" << std::endl;
}

Animal::Animal( std::string type ) : _type(type)
{
    std::cout << "Animal constructor called for a " << this->_type << " !" << std::endl;
}

Animal::Animal( Animal const &other )
{
    if (this != &other)
	    *this = other;
    std::cout << "Animal copy constructor called for a " << this->_type << " !" << std::endl;
}

Animal::~Animal( void )
{
    std::cout << "Animal destructor called for a " << this->_type << " !" << std::endl;
}

Animal  &Animal::operator=( Animal const &instance )
{
	this->_type = instance.getType();
	return ( *this );
}

std::string Animal::getType( void ) const
{
	return ( this->_type );
}

void    Animal::makeSound( void ) const
{
	std::cout << "No sound..." << std::endl;
}

void    Animal::getIdea( int index )
{
	(void)index;
	std::cout << "This animal has no idea..." << std::endl;
}
