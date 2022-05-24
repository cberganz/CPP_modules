/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 14:23:15 by cberganz          #+#    #+#             */
/*   Updated: 2022/05/24 01:44:57 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat( void ) : m_name( "defaultName" ), m_grade( 150 )
{
	std::cout << "Default constructor called for Bureaucrat. Grade has been set to 150 !" << std::endl;
}

Bureaucrat::Bureaucrat( std::string name, int grade ) : m_name( name ), m_grade( grade )
{
	if ( this->m_grade < 1 )
        throw Bureaucrat::GradeTooHighException();
    else if ( this->m_grade > 150 )
        throw Bureaucrat::GradeTooLowException();
    else
	    std::cout << "Constructor called for Bureaucrat " << this->m_name << " with a grade of " << this->m_grade << " !" << std::endl;
}

Bureaucrat::Bureaucrat( const Bureaucrat &instance ) : m_name(instance.getName())
{
	*this = instance;
	std::cout << "Copy constructor called for Bureaucrat " << this->m_name << " !" << std::endl;
}

Bureaucrat::~Bureaucrat( void )
{
	std::cout << "Destructor called for Bureaucrat " << this->m_name << " !" << std::endl;
}

Bureaucrat	&Bureaucrat::operator=( const Bureaucrat &other )
{
	this->m_grade = other.getGrade();
	return ( *this );
}

const std::string   &Bureaucrat::getName( void ) const
{
    return ( this->m_name );
}

const int   &Bureaucrat::getGrade( void ) const
{
    return ( this->m_grade );
}

void    Bureaucrat::incrementGrade( void )
{
    if ( this->m_grade <= 1 )
        throw Bureaucrat::GradeTooHighException();
    this->m_grade--;
}

void    Bureaucrat::decrementGrade( void )
{
    if ( this->m_grade >= 150 )
        throw Bureaucrat::GradeTooLowException();
    this->m_grade++;
}

void    Bureaucrat::signForm( Form &form )
{
	try
	{
		form.beSigned( *this );
	}
	catch( const std::exception &e )
	{
		std::cerr << *this << " cannot sign " << form.getName() << " : " << e.what() << std::endl;
		throw;
	}
	std::cout << *this << " signs " << form.getName() << std::endl;
}

std::ostream &operator<<( std::ostream &outFile, const Bureaucrat &instance )
{
	outFile << instance.getName() << ", bureaucrat grade " << instance.getGrade();
	return (outFile);
}
