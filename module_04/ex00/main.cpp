/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 17:38:59 by cberganz          #+#    #+#             */
/*   Updated: 2022/05/22 00:58:00 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main( void )
{
    std::cout << std::endl << "BASIC TESTS :" << std::endl;
    const Animal* meta = new Animal();
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();
    std::cout << meta->getType() << std::endl;
    std::cout << dog->getType() << std::endl;
    std::cout << cat->getType() << std::endl;
    meta->makeSound();
    dog->makeSound();
    cat->makeSound();

    std::cout << std::endl << "WRONGANIMAL TESTS :" << std::endl;
    const WrongAnimal* wrongCat = new WrongCat();
    std::cout << wrongCat->getType() << std::endl;
    wrongCat->makeSound();

    std::cout << std::endl;
    delete dog;
    delete cat;
    delete meta;
    delete wrongCat;
    std::cout << std::endl;

    return ( 0 );
}
