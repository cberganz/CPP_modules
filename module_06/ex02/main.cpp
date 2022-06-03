/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 06:46:27 by cberganz          #+#    #+#             */
/*   Updated: 2022/06/04 01:09:08 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include <cstdlib>
#include <iomanip>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void)
{
	srand(time(0));
	switch (rand() % 3)
	{
		case 0:
			return new A;

		case 1:
			return new B;

		default:
			return new C;
	}	
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p) != NULL)
		std::cout << "It's a class A !\n";
	else if (dynamic_cast<B*>(p) != NULL)
		std::cout << "It's a class B !\n";
	else if (dynamic_cast<C*>(p) != NULL)
		std::cout << "It's a class C !\n";
	else
		std::cout << "Type not recognized !" << std::endl;
}

void identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "It's a class A !\n";
	}
	catch(...)
	{
		try
		{
			(void)dynamic_cast<B&>(p);
			std::cout << "It's a class B !\n";
		}
		catch(...)
		{
			try
			{
				(void)dynamic_cast<C&>(p);
				std::cout << "It's a class C !\n";
			}
			catch(...)
			{
				std::cerr << "Type not recognized !" << std::endl;
			}
		}
		
	}
	
}

int main()
{
	Base *ptr = generate();
	Base &ref = *ptr;
	identify(ptr);
	identify(ref);

	return (0);
}