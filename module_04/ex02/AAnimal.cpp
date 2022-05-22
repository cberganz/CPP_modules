/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 17:38:34 by cberganz          #+#    #+#             */
/*   Updated: 2022/05/22 13:09:36 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AAnimal.hpp"

AAnimal::AAnimal( void ) : _type( "default" )
{
    std::cout << "AAnimal default constructor called !" << std::endl;
}

AAnimal::AAnimal( std::string type ) : _type(type)
{
    std::cout << "AAnimal constructor called for a " << this->_type << " !" << std::endl;
}

AAnimal::AAnimal( AAnimal const &other )
{
	*this = other;
    std::cout << "AAnimal copy constructor called for a " << this->_type << " !" << std::endl;
}

AAnimal::~AAnimal( void )
{
    std::cout << "AAnimal destructor called for a " << this->_type << " !" << std::endl;
}

AAnimal  &AAnimal::operator=( AAnimal const &instance )
{
	if (this != &instance)
		this->_type = instance.getType();
	return ( *this );
}

std::string AAnimal::getType( void ) const
{
	return ( this->_type );
}

void    AAnimal::makeSound( void ) const
{
	std::cout << "No sound..." << std::endl;
}

void    AAnimal::getIdea( int index )
{
	(void)index;
	std::cout << "This animal has no idea..." << std::endl;
}
