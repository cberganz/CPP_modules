/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charles <charles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 01:06:55 by cberganz          #+#    #+#             */
/*   Updated: 2022/05/25 21:42:47 by charles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include <iomanip>
#include "Form.hpp"

class RobotomyRequestForm : public Form {

	public:
		RobotomyRequestForm( void );
		RobotomyRequestForm( std::string target );
		RobotomyRequestForm( const RobotomyRequestForm &instance );
		~RobotomyRequestForm( void );

		RobotomyRequestForm	    &operator=( const RobotomyRequestForm &other );

		void					execute( const Bureaucrat &executor ) const;

};

#endif
