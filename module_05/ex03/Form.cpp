/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charles <charles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 22:45:13 by cberganz          #+#    #+#             */
/*   Updated: 2022/05/26 02:01:27 by charles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

Form::Form( void ) : m_name( "DefaultForm" ), m_target( "defaulttarget" ), m_signed( false ), m_gradeToSign( 1 ), m_gradeToExecute( 150 ) 
{
	std::cout << "Form default constructor called for " << *this;
}

Form::Form( std::string name, std::string target, int gradeToSign, int gradeToexecute ) : m_name( name ), m_target( target ), m_signed( false ), m_gradeToSign( gradeToSign ), m_gradeToExecute( gradeToexecute )
{
	if ( this->m_gradeToSign < 1 or this->m_gradeToExecute < 1 )
        throw Form::GradeTooHighException();
	else if ( this->m_gradeToSign > 150 or this->m_gradeToExecute > 150 )
        throw Form::GradeTooLowException();
    else
	    std::cout << "Form constructor called for " << *this;
}

Form::Form( Form const &instance ) : m_name( instance.getName() ), m_gradeToSign( instance.getGradeToSign() ), m_gradeToExecute( instance.getGradeToExecute() )
{
	*this = instance;
	std::cout << "Form copy constructor called for " << *this;
}

Form::~Form( void )
{
	std::cout << "Form destructor called for " << *this;
}

Form	&Form::operator=( const Form &other )
{
	m_signed = other.isSigned();
	return ( *this );
}

const std::string	&Form::getName( void ) const
{
	return ( this->m_name );
}

const int   &Form::getGradeToSign( void ) const
{
	return ( this->m_gradeToSign );
}

const int   &Form::getGradeToExecute( void ) const
{
	return ( this->m_gradeToExecute );
}

const std::string	&Form::getTarget( void ) const
{
	return ( this->m_target );
}

const bool  &Form::isSigned( void ) const
{
	return ( this->m_signed );
}

void    Form::beSigned( const Bureaucrat &bureaucrat )
{
	if ( bureaucrat.getGrade() > this->m_gradeToSign )
		throw Form::GradeTooLowException();
	this->m_signed = true;
}

void	Form::execute( const Bureaucrat &executor ) const
{
	if ( this->m_signed == false )
		throw Form::UnsignedException();
	if ( executor.getGrade() > this->m_gradeToExecute )
		throw Form::GradeTooLowException();
}

std::ostream &operator<<( std::ostream &outFile, const Form &instance )
{
	outFile	<< instance.getName() << " - Grade to sign: " << instance.getGradeToSign()
			<< ". Grade to execute: " << instance.getGradeToExecute()
			<< ". Is signed: " << ( instance.isSigned() ? "Yes." : "No." ) << std::endl;
	return ( outFile );
}
