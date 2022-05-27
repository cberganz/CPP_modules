/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 01:07:00 by cberganz          #+#    #+#             */
/*   Updated: 2022/05/25 01:07:01 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm( void ) : Form( "ShrubberyCreationForm", "defaultTarget", 145, 137 )
{
    std::cout << "Shrubbery default constructor called for " << this->getTarget() << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm( std::string target ) : Form( "ShrubberyCreationForm", target, 145, 137 )
{
    std::cout << "Shrubbery constructor called for " << this->getTarget() << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm &instance ) : Form(instance)
{
	std::cout << "Shrubbery copy constructor called for " << *this;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=( ShrubberyCreationForm const &other )
{
	Form::operator=( other );
	return ( *this );
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

void ShrubberyCreationForm::execute( const Bureaucrat &executor ) const
{
    try
    {
	    this->Form::execute( executor );
	    std::ofstream outStream( this->getTarget().c_str() );
	    if ( outStream.is_open() == false )
	    	throw std::ofstream::failure( this->getTarget() + " : Failure while opening file " );
        outStream   << "              .     .  .      +     .      .          .\n"
                    << "     .       .      .     #       .           .\n"
                    << "        .      .         ###            .      .      .\n"
                    << "      .      .   \"#:. .:##\"##:. .:#\"  .      .\n"
                    << "          .      . \"####\"###\"####\"  .\n"
                    << "       .     \"#:.    .:#\"###\"#:.    .:#\"  .        .       .\n"
                    << "  .             \"#########\"#########\"        .        .\n"
                    << "        .    \"#:.  \"####\"###\"####\"  .:#\"   .       .\n"
                    << "     .     .  \"#######\"\"##\"##\"\"#######\"                  .\n"
                    << "                .\"##\"#####\"#####\"##\"           .      .\n"
                    << "    .   \"#:. ...  .:##\"###\"###\"##:.  ... .:#\"     .\n"
                    << "      .     \"#######\"##\"#####\"##\"#######\"      .     .\n"
                    << "    .    .     \"#####\"\"#######\"\"#####\"    .      .\n"
                    << "            .     \"      000      \"    .     .\n"
                    << "       .         .   .   000     .        .       .\n"
                    << ".. .. ..................O000O........................ ......";
	    std::cout << executor << " has executed " << this->getTarget() << std::endl;
    }
    catch ( const std::exception &e )
    {
        throw ;
    }
}
