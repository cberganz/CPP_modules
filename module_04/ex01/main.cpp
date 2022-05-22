/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 17:38:59 by cberganz          #+#    #+#             */
/*   Updated: 2022/05/22 01:42:06 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main( void )
{
    Animal *animals[4];
	for( int i = 0 ; i < 4 ; i++ )
	{
		if ( i % 2 == 0 )
			animals[i] = new Cat;
		else
			animals[i] = new Dog;
	}
	for( int i = 0 ; i < 4 ; i++ )
	{
        std::cout << std::endl;
		animals[i]->makeSound();
        for ( int j = 0 ; j < 100 ; j++ )
		    animals[i]->getIdea( j );
		delete animals[i];
	}
    return ( 0 );
}
