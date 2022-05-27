/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charles <charles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 00:59:34 by cberganz          #+#    #+#             */
/*   Updated: 2022/05/26 03:43:41 by charles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Intern.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern( void )
{
	this->makeClassification();
}

Intern::Intern( Intern const & ) 
{
	this->makeClassification();
}

Intern::~Intern()
{
}

Intern	&Intern::operator=( Intern const & )
{
    return ( *this );
}

void	Intern::makeClassification( void )
{
	classifiedModelsNames[0] = "Presidential pardon";
	classifiedModelsNames[1] = "Robotomy request";
	classifiedModelsNames[2] = "Shrubbery creation";
}

int		Intern::getClassifiedIndex( std::string const &name )
{
	for ( int i = 0 ; i < MAX_MODELS ; i++ ) {
		if ( this->classifiedModelsNames[i] == name )
			return ( i );
	}
	return ( -1 );
}

Form    *Intern::makeForm( std::string const &name, std::string const &target )
{

	switch ( this->getClassifiedIndex( name ) )
	{
		case 0:
			std::cout << "Intern creates a Presidential pardon form for " << target << std::endl;
			return ( new PresidentialPardonForm( target ) );

		case 1:
			std::cout << "Intern creates a Presidential pardon form for " << target << std::endl;
			return ( new RobotomyRequestForm( target ) );

		case 2:
			std::cout << "Intern creates a Presidential pardon form for " << target << std::endl;
			return ( new ShrubberyCreationForm( target ) );

		default:
			throw Intern::UnclassifiedFormException();
	}

}
