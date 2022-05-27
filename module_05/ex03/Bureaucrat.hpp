/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charles <charles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 14:23:22 by cberganz          #+#    #+#             */
/*   Updated: 2022/05/26 01:04:51 by charles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iomanip>
# include "Form.hpp"

class   Form;

class   Bureaucrat {

    public:
        Bureaucrat( void );
        Bureaucrat( std::string name, int grade );
        Bureaucrat( const Bureaucrat &instance );
        ~Bureaucrat( void );

        Bureaucrat &operator=( const Bureaucrat &other );

        const std::string   &getName( void ) const;
        const int           &getGrade( void ) const;
        void                incrementGrade( void );
        void                decrementGrade( void );
        void		        signForm( Form &form );
        void                executeForm ( const Form &form ) const;

    private:
        const std::string   m_name;
        int                 m_grade;

        class GradeTooHighException : public std::exception
        {
            public:
        	    const char* what() const throw()
        	    {
        		    return ( "Grade too high." );
        	    }
        };

        class GradeTooLowException : public std::exception
        {
        	public:
        	    const char* what() const throw()
        	    {
        		    return ( "Grade too low." );
        		}
        };

};

std::ostream &operator<<( std::ostream &outFile, Bureaucrat const &instance );

#endif
