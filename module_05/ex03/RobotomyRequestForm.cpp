/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charles <charles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 20:55:19 by charles           #+#    #+#             */
/*   Updated: 2022/05/26 03:25:50 by charles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <cstdlib>
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm( void ) : Form( "RobotomyRequestForm", "defaultTarget", 72, 45 )
{
    std::cout << "Robotomy request default constructor called for " << this->getTarget() << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm( std::string target ) : Form( "RobotomyRequestForm", target, 72, 45 )
{
    std::cout << "Robotomy request constructor called for " << this->getTarget() << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm( std::string target, std::string name ) : Form( name, target, 72, 45 )
{
    std::cout << "Robotomy request constructor called for " << this->getTarget() << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm &instance ) : Form(instance)
{
	std::cout << "Robotomy request copy constructor called for " << *this;
}

RobotomyRequestForm &RobotomyRequestForm::operator=( RobotomyRequestForm const &other )
{
	Form::operator=( other );
	return ( *this );
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

void RobotomyRequestForm::execute( const Bureaucrat &executor ) const
{
    try
    {
	    this->Form::execute( executor );
        std::srand ( time(NULL) );
        if ( std::rand() % 2 == 1 )
            std::cout << "Bzeee, bzeeeeeeeee... Bureaucrat " << executor.getName() << " has successfully robotomized " << this->getTarget() << '.' << std::endl;
        else
            std::cout << "Bzeee, bzeeeeeeeee... Bureaucrat " << executor.getName() << " has failed to robotomize " << this->getTarget() << '.' << std::endl;
    }
    catch ( const std::exception &e )
    {
        throw ;
    }
}
