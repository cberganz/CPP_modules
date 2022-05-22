/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 01:07:39 by cberganz          #+#    #+#             */
/*   Updated: 2022/05/22 01:43:39 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <time.h>
#include <cstdlib>
#include "Brain.hpp"

std::string possibleIdeas[8] = {
	"I'm hungry",
	"I want to drink",
	"I want to go out",
	"I want to sleep",
	"I need to pee",
	"I wanna procreate",
	"I want a hug",
	"I wanna play"
};

Brain::Brain( void )
{
	std::srand( ( unsigned int )time( NULL ) );
	for( int i = 0 ; i < 100 ; i++ )
		this->_ideas[i] = possibleIdeas[rand() % 8];
	std::cout << "Brain default constructor called !" << std::endl;
}

Brain::Brain( Brain const &instance )
{
    if (this != &instance)
	    *this = instance;
	std::cout << "Brain copy constructor called !" << std::endl;
}

Brain::~Brain( void )
{
	std::cout << "Brain destructor called !" << std::endl;
}

void Brain::operator=( Brain const &other )
{
	for( int i = 0 ; i < 100 ; i++ )
		this->_ideas[i] = other._ideas[i];
}
