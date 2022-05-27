/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charles <charles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 01:06:39 by cberganz          #+#    #+#             */
/*   Updated: 2022/05/26 03:25:57 by charles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include <iomanip>
#include "Form.hpp"

class PresidentialPardonForm : public Form {

	public:
		PresidentialPardonForm( void );
		PresidentialPardonForm( std::string target );
		PresidentialPardonForm( std::string target, std::string name );
		PresidentialPardonForm( const PresidentialPardonForm &instance );
		~PresidentialPardonForm( void );

		PresidentialPardonForm	&operator=( const PresidentialPardonForm &other );

		void	execute( const Bureaucrat &executor ) const;

};

#endif
