/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 17:38:34 by cberganz          #+#    #+#             */
/*   Updated: 2022/05/22 01:00:19 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal( void ) : _type( "default" )
{
    std::cout << "WrongAnimal default constructor called !" << std::endl;
}

WrongAnimal::WrongAnimal( std::string type ) : _type(type)
{
    std::cout << "WrongAnimal constructor called for a " << this->_type << " !" << std::endl;
}

WrongAnimal::WrongAnimal( WrongAnimal const &other )
{
    if (this != &other)
	    *this = other;
    std::cout << "WrongAnimal copy constructor called for a " << this->_type << " !" << std::endl;
}

WrongAnimal::~WrongAnimal( void )
{
    std::cout << "WrongAnimal destructor called for a " << this->_type << " !" << std::endl;
}

WrongAnimal  &WrongAnimal::operator=( WrongAnimal const &instance )
{
	this->_type = instance.getType();
	return ( *this );
}

std::string WrongAnimal::getType( void ) const
{
	return ( this->_type );
}

void    WrongAnimal::makeSound( void ) const
{
	std::cout << "No sound..." << std::endl;
}
