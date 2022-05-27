/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charles <charles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 01:06:28 by cberganz          #+#    #+#             */
/*   Updated: 2022/05/26 03:26:04 by charles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <cstdlib>
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm( void ) : Form( "PresidentialPardonForm", "defaultTarget", 25, 5 )
{
    std::cout << "Presidential pardon default constructor called for " << this->getTarget() << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm( std::string target ) : Form( "PresidentialPardonForm", target, 25, 5 )
{
    std::cout << "Presidential pardon constructor called for " << this->getTarget() << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm( std::string target, std::string name ) : Form( name, target, 25, 5 )
{
    std::cout << "Presidential pardon constructor called for " << this->getTarget() << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm &instance ) : Form(instance)
{
	std::cout << "Presidential pardon constructor called for " << *this;
}

PresidentialPardonForm &PresidentialPardonForm::operator=( PresidentialPardonForm const &other )
{
	Form::operator=( other );
	return ( *this );
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

void PresidentialPardonForm::execute( const Bureaucrat &executor ) const
{
    try
    {
	    this->Form::execute( executor );
        std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
    }
    catch ( const std::exception &e )
    {
        throw ;
    }
}
