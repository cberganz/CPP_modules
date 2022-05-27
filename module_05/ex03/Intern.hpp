/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charles <charles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 00:58:54 by cberganz          #+#    #+#             */
/*   Updated: 2022/05/26 03:43:44 by charles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include <iostream>
#include "Form.hpp"

#define MAX_MODELS 3

class Intern
{

    public:
    	Intern( void );
    	Intern( Intern const & );
    	Intern &operator=( Intern const & );
    	~Intern();

        void    makeClassification( void );
		int		getClassifiedIndex( std::string const &name );
    	Form    *makeForm(std::string const &formName, std::string const &target);

    	class UnclassifiedFormException : public std::exception
    	{
    	    public:
    	    	const char *what() const throw()
    	    	{
    	    		return ("Unclassified form");
    	    	}
    	};

    private:
        std::string     classifiedModelsNames[MAX_MODELS];

};

#endif
