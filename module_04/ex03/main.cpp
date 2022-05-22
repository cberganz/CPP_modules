/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 13:14:39 by cberganz          #+#    #+#             */
/*   Updated: 2022/05/22 22:49:15 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMateriaSource.hpp"
#include "AMateria.hpp"
#include "MateriaSource.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main(void)
{
	AMateria		*aMateria, *item;
	MateriaSource	*iMateriaSource;
	MateriaSource	*iMateriaSource2;
	MateriaSource	*iMateriaSource2Cpy;
	Character		*me, *meCopy;
	ICharacter		*you;

	std::cout << std::endl << "BASIC TESTS" << std::endl;
	iMateriaSource = new MateriaSource();
	iMateriaSource->learnMateria( new Ice() );
	iMateriaSource->learnMateria( new Cure() );	
	me = new Character( "me" );
	aMateria = iMateriaSource->createMateria( "ice" );
	me->equip( aMateria );
	aMateria = iMateriaSource->createMateria( "cure" );
	me->equip( aMateria );

	std::cout << std::endl << "DEEP COPIES TESTS FOR MATERIA" << std::endl;
	iMateriaSource2 = new MateriaSource();
	iMateriaSource2->learnMateria( new Ice() );
	iMateriaSource2->learnMateria( new Cure() );
	iMateriaSource2Cpy = new MateriaSource( *iMateriaSource2 );
	std::cout << "iMateriaSource2 learningBook pointer is " << iMateriaSource2->getLearningBook() << " while its copy pointer is " << iMateriaSource2Cpy->getLearningBook() << std::endl;
	delete iMateriaSource2;

	std::cout << std::endl << "EQUIP/UNEQUIP TESTS" << std::endl;
	aMateria = iMateriaSource2Cpy->createMateria( "ice" );
	me->equip( aMateria );
	item = iMateriaSource2Cpy->createMateria( "cure" );
	me->equip( item );
	me->equip( aMateria );
	me->unequip( 3 );
	me->unequip( 3 );
	delete item;

	std::cout << std::endl << "DEEP COPY TESTS FOR CHARACTERS" << std::endl;
	you = new Character( "you" );
	meCopy = new Character( *me );
	delete me;
	meCopy->use( 0, *you );
	meCopy->use( 1, *you );
	//empty slot, do nothing:
	meCopy->use( 3, *you );

	std::cout << std::endl << "NOT EXISTING MATERIA TESTS" << std::endl;
	aMateria = iMateriaSource->createMateria( "blurp" );
	meCopy->equip( aMateria );
	meCopy->use( 3, *you );

	std::cout << std::endl;
	delete you;
	delete meCopy;
	delete iMateriaSource;
	delete iMateriaSource2Cpy;

	return ( 0 );
}