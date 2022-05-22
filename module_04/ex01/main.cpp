/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 17:38:59 by cberganz          #+#    #+#             */
/*   Updated: 2022/05/22 22:51:56 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <unistd.h>

int main( void )
{
	std::cout << std::endl << "TESTING ARRAY OF ANIMALS\n" << std::endl;
	const int	arrSize = 2;
    Animal *animals[arrSize];
	for( int i = 0 ; i < arrSize ; i++ )
	{
		usleep(500000);
		if ( i % 2 == 0 )
			animals[i] = new Cat;
		else
			animals[i] = new Dog;
	}
	for( int i = 0 ; i < arrSize ; i++ )
	{
        std::cout << std::endl;
		std::cout << animals[i]->getType() << std::endl;
		animals[i]->makeSound();
        for ( int j = 0 ; j < 100 ; j++ )
		    animals[i]->getIdea( j );
		delete animals[i];
	}

	std::cout << std::endl << "TESTING CONSTRUCTORS AND ASIGNATION\n" << std::endl;
	Dog	dog;
	Dog	dogCpy( dog );
	dog.getIdea( 10 );
	dogCpy.getIdea( 10 );
	std::cout << "Dog's Brain pointer is " << dog.getBrain() << " while dogCpy pointer is " << dogCpy.getBrain() << std::endl << std::endl;
	usleep(500000);
	Cat cat;
	Cat catCpy( cat );
	cat.getIdea( 10 );
	catCpy.getIdea( 10 );
	std::cout << "Cat's Brain pointer is " << cat.getBrain() << " while catCpy pointer is " << catCpy.getBrain() << std::endl;

	std::cout << std::endl;
    return ( 0 );
}
