/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 21:28:04 by cberganz          #+#    #+#             */
/*   Updated: 2022/05/23 23:44:55 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iomanip>
# include "Bureaucrat.hpp"

class   Bureaucrat;

class   Form {

    public:
        Form( void );
        Form( std::string name, int gradeToSign, int gradeToExecute );
        Form( const Form &instance );
        ~Form( void );

        Form &operator=( const Form &other );

        const std::string   &getName( void ) const;
        const bool          &isSigned( void ) const;
        const int           &getGradeToSign( void ) const;
        const int           &getGradeToExecute( void ) const;
        void		        beSigned( Bureaucrat const &bureaucrat );

    private:
        const std::string   m_name;
        bool                m_signed;
        const int           m_gradeToSign;
        const int           m_gradeToExecute;

        class GradeTooHighException : public std::exception
        {
            public:
        	    virtual const char* what() const throw()
        	    {
        		    return ( "Grade too high." );
        	    }
        };

        class GradeTooLowException : public std::exception
        {
        	public:
        	    virtual const char* what() const throw()
        	    {
        		    return ( "Grade too low." );
        		}
        };
        
};

std::ostream &operator<<( std::ostream &outFile, Form const &instance );

#endif