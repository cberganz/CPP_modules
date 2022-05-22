/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 17:38:46 by cberganz          #+#    #+#             */
/*   Updated: 2022/05/22 13:09:49 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <iostream>

class AAnimal {

    public:
        AAnimal( void );
        AAnimal( std::string typeName );
	    AAnimal( AAnimal const& instance );
	    virtual ~AAnimal( void );
	    AAnimal	        &operator=( AAnimal const &instance );
	    virtual void    makeSound( void ) const = 0;
        virtual void    getIdea( int index );
	    std::string     getType( void ) const;

    protected:
        std::string _type;

};

#endif
