/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charles <charles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 14:23:27 by cberganz          #+#    #+#             */
/*   Updated: 2022/05/26 03:43:42 by charles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#define BLK "\e[1;90m"
#define RED "\e[1;91m"
#define GRN "\e[1;92m"
#define YEL "\e[1;93m"
#define BLU "\e[1;94m"
#define MAG "\e[1;95m"
#define CYN "\e[1;96m"
#define WHT "\e[1;97m"
#define RESET "\e[0m"

int main(void)
{
	std::cout << std::endl << CYN << " -> CONSTRUCTION TESTS ON BUREAUCRATS :" << RESET << std::endl;
	Bureaucrat stupidGuy1;
	Bureaucrat *stupidGuy2 = new Bureaucrat( "stupidGuy2", 75 );
	Bureaucrat stupidGuy3( "stupidGuy3", 1 );
	std::cout << stupidGuy1 << std::endl << *stupidGuy2 << std::endl << stupidGuy3 << std::endl;

	std::cout << std::endl << MAG << " -> CONSTRUCTION TESTS ON SHRUBBERY FORM :" << RESET << std::endl;
	ShrubberyCreationForm shrubberyForStupidGuy1;
	ShrubberyCreationForm *shrubberyForStupidGuy2 = new ShrubberyCreationForm( std::string( "S2" ).append( "_stupidGuy2" ) );
	ShrubberyCreationForm shrubberyForStupidGuy3( std::string( "S3" ).append( "_stupidGuy3" ) );
	std::cout << shrubberyForStupidGuy1 << *shrubberyForStupidGuy2 << shrubberyForStupidGuy3;

	std::cout << std::endl << BLU << " -> CONSTRUCTION TESTS ON ROBOTOMY FORM :" << RESET << std::endl;
	RobotomyRequestForm robotomyRequestForStupidGuy1;
	RobotomyRequestForm *robotomyRequestForStupidGuy2 = new RobotomyRequestForm( "target1" );
	RobotomyRequestForm robotomyRequestForStupidGuy3( "target2" );
	std::cout << robotomyRequestForStupidGuy1 << *robotomyRequestForStupidGuy2 << robotomyRequestForStupidGuy3;

	std::cout << std::endl << YEL << " -> CONSTRUCTION TESTS ON PRESIDENTIAL PARDON FORM :" << RESET << std::endl;
	PresidentialPardonForm pardonForStupidGuy1;
	PresidentialPardonForm *pardonForStupidGuy2 = new PresidentialPardonForm( "target1" );
	PresidentialPardonForm pardonForStupidGuy3( "target2" );
	std::cout << pardonForStupidGuy1 << *pardonForStupidGuy2 << pardonForStupidGuy3;

	std::cout << std::endl << CYN << " -> DEEP COPY TESTS FOR BUREAUCRATS :" << RESET << std::endl;
	Bureaucrat *stupidGuy2Clone = new Bureaucrat( *stupidGuy2 );
	std::cout << *stupidGuy2 << std::endl;
	delete stupidGuy2Clone;
	std::cout << *stupidGuy2 << std::endl;

	std::cout << std::endl << MAG << " -> DEEP COPY TESTS FOR SHRUBBERY FORM :" << RESET << std::endl;
	ShrubberyCreationForm *shrubberyForStupidGuy2Clone = new ShrubberyCreationForm( *shrubberyForStupidGuy2 );
	std::cout << *shrubberyForStupidGuy2;
	delete shrubberyForStupidGuy2Clone;
	std::cout << *shrubberyForStupidGuy2;

	std::cout << std::endl << BLU << " -> DEEP COPY TESTS FOR ROBOTOMY FORM :" << RESET << std::endl;
	RobotomyRequestForm *robotomyRequestForStupidGuy2Clone = new RobotomyRequestForm( *robotomyRequestForStupidGuy2 );
	std::cout << *robotomyRequestForStupidGuy2;
	delete robotomyRequestForStupidGuy2Clone;
	std::cout << *robotomyRequestForStupidGuy2;
	
	std::cout << std::endl << YEL << " -> DEEP COPY TESTS FOR PRESIDENTIAL PARDON FORM :" << RESET << std::endl;
	PresidentialPardonForm *pardonForStupidGuy2Clone = new PresidentialPardonForm( *pardonForStupidGuy2 );
	std::cout << *pardonForStupidGuy2;
	delete pardonForStupidGuy2Clone;
	std::cout << *pardonForStupidGuy2;
	
	std::cout << std::endl << CYN << " -> TOO HIGH / LOW GRADE CREATION FOR BUREAUCRATS :" << RESET << std::endl;
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

	std::cout << std::endl << MAG << " -> TRYING TO SIGN SHRUBBERY FROM BUREAUCRATS :" << RESET << std::endl;
	shrubberyForStupidGuy2Clone = new ShrubberyCreationForm( *shrubberyForStupidGuy2 );
	std::cout << *shrubberyForStupidGuy2;
	try
	{
		stupidGuy1.signForm(*shrubberyForStupidGuy2);
	}
	catch( const std::exception &e )
	{
		try
		{
			stupidGuy2->signForm(*shrubberyForStupidGuy2);
			std::cout << *shrubberyForStupidGuy2;
		}
		catch( const std::exception &e )
		{
			// Do nothing
		}
	}

	std::cout << std::endl << MAG << " -> TRYING TO SIGN SHRUBBERY FROM FORM :" << RESET << std::endl;
	std::cout << *shrubberyForStupidGuy2Clone;
	try
	{
		shrubberyForStupidGuy2Clone->beSigned(stupidGuy1);
		std::cout << stupidGuy1 << " signs " << shrubberyForStupidGuy2Clone->getName() << std::endl << *shrubberyForStupidGuy2Clone;
	}
	catch( const std::exception &e )
	{
		std::cerr << stupidGuy1 << " cannot sign " << shrubberyForStupidGuy2Clone->getName() << " : " << e.what() << std::endl;
		try
		{
			shrubberyForStupidGuy2Clone->beSigned(*stupidGuy2);
			std::cout << *stupidGuy2 << " signs " << shrubberyForStupidGuy2Clone->getName() << std::endl << *shrubberyForStupidGuy2Clone;
		}
		catch( const std::exception &e )
		{
			std::cerr << *stupidGuy2 << " cannot sign " << shrubberyForStupidGuy2Clone->getName() << " : " << e.what() << std::endl;
		}
	}

	std::cout << std::endl << BLU << " -> TRYING TO SIGN ROBOTOMY FROM BUREAUCRATS :" << RESET << std::endl;
	robotomyRequestForStupidGuy2Clone = new RobotomyRequestForm( *robotomyRequestForStupidGuy2 );
	std::cout << *robotomyRequestForStupidGuy2;
	try
	{
		stupidGuy1.signForm(*robotomyRequestForStupidGuy2);
	}
	catch( const std::exception &e )
	{
		try
		{
			stupidGuy3.signForm(*robotomyRequestForStupidGuy2);
			std::cout << *robotomyRequestForStupidGuy2;
		}
		catch( const std::exception &e )
		{
			// Do nothing
		}
	}

	std::cout << std::endl << BLU << " -> TRYING TO SIGN ROBOTOMY FROM FORM :" << RESET << std::endl;
	std::cout << *robotomyRequestForStupidGuy2Clone;
	try
	{
		robotomyRequestForStupidGuy2Clone->beSigned(stupidGuy1);
		std::cout << stupidGuy1 << " signs " << robotomyRequestForStupidGuy2Clone->getName() << std::endl << *robotomyRequestForStupidGuy2Clone;
	}
	catch( const std::exception &e )
	{
		std::cerr << stupidGuy1 << " cannot sign " << robotomyRequestForStupidGuy2Clone->getName() << " : " << e.what() << std::endl;
		try
		{
			robotomyRequestForStupidGuy2Clone->beSigned(stupidGuy3);
			std::cout << *stupidGuy2 << " signs " << robotomyRequestForStupidGuy2Clone->getName() << std::endl << *robotomyRequestForStupidGuy2Clone;
		}
		catch( const std::exception &e )
		{
			std::cerr << *stupidGuy2 << " cannot sign " << robotomyRequestForStupidGuy2Clone->getName() << " : " << e.what() << std::endl;
		}
	}

	std::cout << std::endl << YEL << " -> TRYING TO SIGN PRESIDENTIAL PARDON FROM BUREAUCRATS :" << RESET << std::endl;
	pardonForStupidGuy2Clone = new PresidentialPardonForm( *pardonForStupidGuy2 );
	std::cout << *pardonForStupidGuy2;
	try
	{
		stupidGuy1.signForm(*pardonForStupidGuy2);
	}
	catch( const std::exception &e )
	{
		try
		{
			stupidGuy3.signForm(*pardonForStupidGuy2);
			std::cout << *pardonForStupidGuy2;
		}
		catch( const std::exception &e )
		{
			// Do nothing
		}
	}

	std::cout << std::endl << YEL << " -> TRYING TO SIGN PRESIDENTIAL PARDON FROM FORM :" << RESET << std::endl;
	std::cout << *pardonForStupidGuy2Clone;
	try
	{
		pardonForStupidGuy2Clone->beSigned(stupidGuy1);
		std::cout << stupidGuy1 << " signs " << pardonForStupidGuy2Clone->getName() << std::endl << *pardonForStupidGuy2Clone;
	}
	catch( const std::exception &e )
	{
		std::cerr << stupidGuy1 << " cannot sign " << pardonForStupidGuy2Clone->getName() << " : " << e.what() << std::endl;
		try
		{
			pardonForStupidGuy2Clone->beSigned(stupidGuy3);
			std::cout << *stupidGuy2 << " signs " << pardonForStupidGuy2Clone->getName() << std::endl << *pardonForStupidGuy2Clone;
		}
		catch( const std::exception &e )
		{
			std::cerr << *stupidGuy2 << " cannot sign " << pardonForStupidGuy2Clone->getName() << " : " << e.what() << std::endl;
		}
	}

	std::cout << std::endl << MAG << " -> TRYING TO EXECUTE SHRUBBERY FROM FORM :" << RESET << std::endl;
	try
	{
		shrubberyForStupidGuy2->execute( stupidGuy1 );
	}
	catch( const std::exception &e )
	{
		std::cerr << stupidGuy1 << " cannot execute " << shrubberyForStupidGuy2->getTarget() <<  " : " << e.what() << '\n';
		try
		{
			shrubberyForStupidGuy2->execute( stupidGuy3 );
		}
		catch( const std::exception &e )
		{
			std::cerr << stupidGuy3 << " cannot execute " << shrubberyForStupidGuy2->getTarget() <<  " : " << e.what() << '\n';
		}
		
	}
	
	std::cout << std::endl << MAG << " -> TRYING TO EXECUTE SHRUBBERY FROM BUREAUCRAT :" << RESET << std::endl;
	stupidGuy3.signForm(shrubberyForStupidGuy3);
	try
	{
		stupidGuy1.executeForm(shrubberyForStupidGuy3);
	}
	catch( const std::exception &e )
	{
		try
		{
			stupidGuy3.executeForm(shrubberyForStupidGuy3);
		}
		catch( const std::exception &e )
		{
			// Do nothing
		}
	}

	std::cout << std::endl << BLU << " -> TRYING TO EXECUTE ROBOTOMY FROM FORM :" << RESET << std::endl;
	stupidGuy3.signForm(*robotomyRequestForStupidGuy2);
	try
	{
		robotomyRequestForStupidGuy2->execute( stupidGuy1 );
	}
	catch( const std::exception &e )
	{
		std::cerr << stupidGuy1 << " cannot execute " << robotomyRequestForStupidGuy2->getTarget() <<  " : " << e.what() << '\n';
		try
		{
			robotomyRequestForStupidGuy2->execute( stupidGuy3 );
		}
		catch( const std::exception &e )
		{
			std::cerr << stupidGuy3 << " cannot execute " << robotomyRequestForStupidGuy2->getTarget() <<  " : " << e.what() << '\n';
		}
		
	}
	
	std::cout << std::endl << BLU << " -> TRYING TO EXECUTE ROBOTOMY FROM BUREAUCRAT :" << RESET << std::endl;
	stupidGuy3.signForm(robotomyRequestForStupidGuy3);
	try
	{
		stupidGuy1.executeForm(robotomyRequestForStupidGuy3);
	}
	catch( const std::exception &e )
	{
		try
		{
			stupidGuy3.executeForm(robotomyRequestForStupidGuy3);
		}
		catch( const std::exception &e )
		{
			// Do nothing
		}
	}

	std::cout << std::endl << YEL << " -> TRYING TO EXECUTE PRESIDENTIAL PARDON FROM FORM :" << RESET << std::endl;
	stupidGuy3.signForm(*pardonForStupidGuy2);
	try
	{
		pardonForStupidGuy2->execute( stupidGuy1 );
	}
	catch( const std::exception &e )
	{
		std::cerr << stupidGuy1 << " cannot execute " << pardonForStupidGuy2->getTarget() <<  " : " << e.what() << '\n';
		try
		{
			pardonForStupidGuy2->execute( stupidGuy3 );
		}
		catch( const std::exception &e )
		{
			std::cerr << stupidGuy3 << " cannot execute " << pardonForStupidGuy2->getTarget() <<  " : " << e.what() << '\n';
		}
		
	}
	
	std::cout << std::endl << YEL << " -> TRYING TO EXECUTE PRESIDENTIAL PARDON FROM BUREAUCRAT :" << RESET << std::endl;
	stupidGuy3.signForm(pardonForStupidGuy3);
	try
	{
		stupidGuy1.executeForm(pardonForStupidGuy3);
	}
	catch( const std::exception &e )
	{
		try
		{
			stupidGuy3.executeForm(pardonForStupidGuy3);
		}
		catch( const std::exception &e )
		{
			// Do nothing
		}
	}

	std::cout << std::endl << MAG << " -> TRYING TO EXECUTE UNSIGNED SHRUBBERY FORM :" << RESET << std::endl;
	ShrubberyCreationForm *test = new ShrubberyCreationForm( "test" );
	try
	{
		stupidGuy3.executeForm( *test );
	}
	catch( const std::exception &e )
	{
		// Do nothing
	}
	delete test;

	std::cout << std::endl << BLU << " -> TRYING TO EXECUTE UNSIGNED ROBOTOMY FORM :" << RESET << std::endl;
	RobotomyRequestForm *test2 = new RobotomyRequestForm( "test" );
	try
	{
		stupidGuy3.executeForm( *test2 );
	}
	catch( const std::exception &e )
	{
		// Do nothing
	}
	delete test2;

	std::cout << std::endl << YEL << " -> TRYING TO EXECUTE UNSIGNED PRESIDENTIAL PARDON FORM :" << RESET << std::endl;
	PresidentialPardonForm *test3= new PresidentialPardonForm( "test" );
	try
	{
		stupidGuy3.executeForm( *test3 );
	}
	catch( const std::exception &e )
	{
		// Do nothing
	}
	delete test3;

	std::cout << std::endl << MAG << " -> TRYING TO EXECUTE UNVALID PATH NAME FOR SHRUBBERY :" << RESET << std::endl;
	test = new ShrubberyCreationForm( "Invalid/path" );
	stupidGuy3.signForm(*test);
	try
	{
		stupidGuy3.executeForm(*test);
	}
	catch( const std::exception &e )
	{
		// Do nothing
	}
	delete test;

	std::cout << std::endl << CYN << " -> INCREMENT / DECREMENT BUREAUCRATS :" << RESET << std::endl;
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

	std::cout << std::endl << GRN << " -> TESTS ON INTERN :" << RESET << std::endl;
	Intern intern1;
	try
	{
		intern1.makeForm( "Robotomy request", "some stupid guy" );
	}
	catch(const std::exception& e)
	{
		std::cerr << "Intern cannot generate Robotomy request form : " << e.what() << ".\n";
	}
	try
	{
		intern1.makeForm( "Kill the bureaucracy", "some stupid guy" );
	}
	catch(const std::exception& e)
	{
		std::cerr << "Intern cannot generate Kill the bureaucracy form : " << e.what() << ".\n";
	}

	std::cout << std::endl;

	delete stupidGuy2;
	delete shrubberyForStupidGuy2;
	delete shrubberyForStupidGuy2Clone;
	delete robotomyRequestForStupidGuy2;
	delete robotomyRequestForStupidGuy2Clone;
	delete pardonForStupidGuy2;
	delete pardonForStupidGuy2Clone;

	return (0);
}
