/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 14:23:27 by cberganz          #+#    #+#             */
/*   Updated: 2022/05/23 21:14:33 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include "Bureaucrat.hpp"

int main(void)
{
	std::cout << std::endl << " -> CONSTRUCTION TESTS :" << std::endl;
	Bureaucrat stupidGuy1;
	Bureaucrat *stupidGuy2 = new Bureaucrat( "stupidGuy2", 75 );
	Bureaucrat stupidGuy3( "stupidGuy3", 1 );
	std::cout << stupidGuy1 << std::endl << *stupidGuy2 << std::endl << stupidGuy3 << std::endl;

	std::cout << std::endl << " -> DEEP COPY TESTS :" << std::endl;
	Bureaucrat *stupidGuy2Clone = new Bureaucrat( *stupidGuy2 );
	std::cout << *stupidGuy2Clone << std::endl;
	delete stupidGuy2;
	std::cout << *stupidGuy2Clone << std::endl;
	delete stupidGuy2Clone;
	
	std::cout << std::endl << " -> TOO HIGH / LOW GRADE CREATION :" << std::endl;
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

	std::cout << std::endl << " -> INCREMENT / DECREMENT :" << std::endl;
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

	return (0);
}