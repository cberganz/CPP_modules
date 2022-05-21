/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 17:38:46 by cberganz          #+#    #+#             */
/*   Updated: 2022/05/22 00:59:43 by cberganz         ###   ########.fr       */
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
	    std::string     getType( void ) const;

    protected:
        std::string _type;
        Animal( std::string typeName );

};

#endif
