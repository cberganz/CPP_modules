/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 14:23:27 by cberganz          #+#    #+#             */
/*   Updated: 2022/05/24 02:04:14 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"

int main(void)
{
	std::cout << std::endl << " -> CONSTRUCTION TESTS ON BUREAUCRATS :" << std::endl;
	Bureaucrat stupidGuy1;
	Bureaucrat *stupidGuy2 = new Bureaucrat( "stupidGuy2", 75 );
	Bureaucrat stupidGuy3( "stupidGuy3", 1 );
	std::cout << stupidGuy1 << std::endl << *stupidGuy2 << std::endl << stupidGuy3 << std::endl;

	std::cout << std::endl << " -> CONSTRUCTION TESTS ON FORMS :" << std::endl;
	Form formForStupidGuy1;
	Form *formForStupidGuy2 = new Form( "formForStupidGuy2", 75, 150 );
	Form formForStupidGuy3( "formForStupidGuy3", 1, 150 );
	std::cout << formForStupidGuy1 << *formForStupidGuy2 << formForStupidGuy3 << std::endl;

	std::cout << std::endl << " -> DEEP COPY TESTS FOR BUREAUCRATS :" << std::endl;
	Bureaucrat *stupidGuy2Clone = new Bureaucrat( *stupidGuy2 );
	std::cout << *stupidGuy2 << std::endl;
	delete stupidGuy2Clone;
	std::cout << *stupidGuy2 << std::endl;
	
	std::cout << std::endl << " -> DEEP COPY TESTS FOR FORMS :" << std::endl;
	Form *formForStupidGuy2Clone = new Form( *formForStupidGuy2 );
	std::cout << *formForStupidGuy2;
	delete formForStupidGuy2Clone;
	std::cout << *formForStupidGuy2;
	
	std::cout << std::endl << " -> TOO HIGH / LOW GRADE CREATION FOR BUREAUCRATS :" << std::endl;
	try
	{
		Bureaucrat stupidGuy4("stupidGuy4", 0);
	}
	catch ( const std::exception &e )
	{
		std::cerr << e.what() << " Please enter a grade between 1 and 150 !" << std::endl;
	}
	try
	{
		Bureaucrat stupidGuy5("stupidGuy5", 151);
	}
	catch( const std::exception &e )
	{
		std::cerr << e.what() << " Please enter a grade between 1 and 150 !" << std::endl;
	}

	std::cout << std::endl << " -> TOO HIGH / LOW GRADE CREATION FOR FORMS :" << std::endl;
	try
	{
		Form formForStupidGuy4("formForStupidGuy4", 0, 75);
	}
	catch ( const std::exception &e )
	{
		std::cerr << e.what() << " Please enter a grade to sign between 1 and 150 !" << std::endl;
	}
	try
	{
		Form formForStupidGuy4("formForStupidGuy4", 75, 0);
	}
	catch ( const std::exception &e )
	{
		std::cerr << e.what() << " Please enter a grade to execute between 1 and 150 !" << std::endl;
	}
	try
	{
		Form formForStupidGuy5("formForStupidGuy5", 151, 75);
	}
	catch( const std::exception &e )
	{
		std::cerr << e.what() << " Please enter a grade to sign between 1 and 150 !" << std::endl;
	}
	try
	{
		Form formForStupidGuy5("formForStupidGuy5", 75, 151);
	}
	catch( const std::exception &e )
	{
		std::cerr << e.what() << " Please enter a grade to execute between 1 and 150 !" << std::endl;
	}

	formForStupidGuy2Clone = new Form( *formForStupidGuy2 );

	std::cout << std::endl << " -> TRYING TO SIGN FROM BUREAUCRATS :" << std::endl;
	std::cout << *formForStupidGuy2;
	try
	{
		stupidGuy1.signForm(*formForStupidGuy2);
	}
	catch( const std::exception &e )
	{
		try
		{
			stupidGuy2->signForm(*formForStupidGuy2);
			std::cout << *formForStupidGuy2;
		}
		catch( const std::exception &e )
		{
			// Do nothing
		}
	}

	std::cout << std::endl << " -> TRYING TO SIGN FROM FORM :" << std::endl;
	std::cout << *formForStupidGuy2Clone;
	try
	{
		formForStupidGuy2Clone->beSigned(stupidGuy1);
		std::cout << stupidGuy1 << " signs " << formForStupidGuy2Clone->getName() << std::endl << *formForStupidGuy2Clone;
	}
	catch( const std::exception &e )
	{
		std::cerr << stupidGuy1 << " cannot sign " << formForStupidGuy2Clone->getName() << " : " << e.what() << std::endl;
		try
		{
			formForStupidGuy2Clone->beSigned(*stupidGuy2);
			std::cout << *stupidGuy2 << " signs " << formForStupidGuy2Clone->getName() << std::endl << *formForStupidGuy2Clone;
		}
		catch( const std::exception &e )
		{
			std::cerr << *stupidGuy2 << " cannot sign " << formForStupidGuy2Clone->getName() << " : " << e.what() << std::endl;
		}
	}

	std::cout << std::endl << " -> INCREMENT / DECREMENT BUREAUCRATS :" << std::endl;
	std::cout << stupidGuy3 << std::endl;
	try
	{
		stupidGuy3.incrementGrade();
	}
	catch( const std::exception &e )
	{
		std::cerr << e.what() << ' ' << stupidGuy3 << " cannot be upgraded !" << std::endl;
	}

	std::cout << stupidGuy1 << std::endl;
	try
	{
		stupidGuy1.decrementGrade();
	}
	catch( const std::exception &e )
	{
		std::cerr << e.what() << ' ' << stupidGuy1 << " cannot be retrograded !" << std::endl;
	}

	std::cout << std::endl;

	delete stupidGuy2;
	delete formForStupidGuy2;
	delete formForStupidGuy2Clone;

	return (0);
}