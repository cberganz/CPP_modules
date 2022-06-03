/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 06:46:27 by cberganz          #+#    #+#             */
/*   Updated: 2022/06/03 07:11:29 by cberganz         ###   ########.fr       */
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
	Base *ret = NULL;
	srand(time(0));
	if (rand() % 3 == 0)
		return new A;
	else if (rand() % 3 == 1)
		return new B;
	else if (rand() % 3 == 2)
		return new C;
	return (ret);	
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p) != NULL)
		std::cout << "It's a class A !\n";
	else if (dynamic_cast<B*>(p) != NULL)
		std::cout << "It's a class B !\n";
	else if (dynamic_cast<C*>(p) != NULL)
		std::cout << "It's a class C!\n";
	else
		std::cout << "Type not recognized !\n";
}

void identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "it's a class A !\n";
	}
	catch(...)
	{
		try
		{
			(void)dynamic_cast<B&>(p);
			std::cout << "it's a class B !\n";
		}
		catch(...)
		{
			try
			{
				(void)dynamic_cast<C&>(p);
				std::cout << "It's a class C !\n";
			}
			catch(const std::exception &e)
			{
				std::cerr << e.what() << '\n';
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