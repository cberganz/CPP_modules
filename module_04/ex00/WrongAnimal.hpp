/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 17:38:46 by cberganz          #+#    #+#             */
/*   Updated: 2022/05/22 01:00:24 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>

class WrongAnimal {

    public:
        WrongAnimal( void );
	    WrongAnimal( WrongAnimal const& instance );
	    virtual ~WrongAnimal( void );
	    WrongAnimal	    &operator=( WrongAnimal const &instance );
	    void            makeSound( void ) const;
	    std::string     getType( void ) const;

    protected:
        std::string _type;
        WrongAnimal( std::string typeName );

};

#endif
