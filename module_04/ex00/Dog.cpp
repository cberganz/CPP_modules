/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 17:38:54 by cberganz          #+#    #+#             */
/*   Updated: 2022/05/21 22:14:51 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Dog.hpp"

Dog::Dog( void ) : Animal("Dog")
{
    std::cout << "Dog default constructor called !" << std::endl;
}

Dog::Dog( Dog const &instance ) : Animal(instance)
{
	std::cout << "Dog copy constructor called !" << std::endl;
}

Dog::~Dog( void )
{
    std::cout << "Dog destructor called !" << std::endl;
}

Dog	&Dog::operator=( Dog const &other)
{
	if (this != &other)
		this->_type = other.getType();
	return ( *this );
}

void Dog::makeSound( void ) const
{
	std::cout << "Ouaf !" << std::endl;
}
