/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 18:25:24 by cberganz          #+#    #+#             */
/*   Updated: 2022/06/08 19:56:13 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>

template < typename T, class Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> {

	public:
		MutantStack() {}
		MutantStack(const MutantStack &src) : std::stack<T, Container>(src) {}
		~MutantStack() {}

		MutantStack &operator=(const MutantStack &rhs) {
			std::stack<T, Container>::operator=(rhs);
			return (*this);
		}

		typedef typename Container::iterator iterator;
		iterator begin() { return this->c.begin(); }
		iterator end() { return this->c.end(); }
		iterator rbegin() { return this->c.rbegin(); }
		iterator rend() { return this->c.rend(); }

};

#endif