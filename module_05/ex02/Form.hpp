/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charles <charles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 21:28:04 by cberganz          #+#    #+#             */
/*   Updated: 2022/05/25 21:23:30 by charles          ###   ########.fr       */
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
        Form( std::string name, std::string target, int gradeToSign, int gradeToExecute );
        Form( const Form &instance );
        virtual ~Form( void ) = 0;

        virtual Form &operator=( const Form &other );

        const std::string   &getName( void ) const;
        const bool          &isSigned( void ) const;
        const int           &getGradeToSign( void ) const;
        const int           &getGradeToExecute( void ) const;
        const std::string   &getTarget( void ) const;
        void		        beSigned( const Bureaucrat &bureaucrat );
        void virtual        execute( const Bureaucrat &executor ) const;

    private:
        const std::string   m_name;
        const std::string   m_target;
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

        class UnsignedException : public std::exception
        {
        	public:
        	    virtual const char* what() const throw()
        	    {
        		    return ( "Form not signed." );
        		}
        };
        
};

std::ostream &operator<<( std::ostream &outFile, Form const &instance );

#endif