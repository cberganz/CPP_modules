/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 17:38:46 by cberganz          #+#    #+#             */
/*   Updated: 2022/05/22 01:29:03 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal {

    public:
        Animal( void );
	    Animal( Animal const& instance );
	    virtual ~Animal( void );
	    Animal	        &operator=( Animal const &instance );
	    virtual void    makeSound( void ) const;
        virtual void    getIdea( int index );
	    std::string     getType( void ) const;

    protected:
        std::string _type;
        Animal( std::string typeName );

};

#endif
