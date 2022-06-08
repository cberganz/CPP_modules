/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 02:43:41 by cberganz          #+#    #+#             */
/*   Updated: 2022/06/08 04:17:33 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <ctime>
# include <cstdlib>
# include <algorithm>
# include <iostream>

class Span {

	public:
		Span();
		Span(unsigned int N);
		Span(const Span &src);
		~Span();

		Span		&operator=(const Span &rhs);

		int			getSize() const;
		int			getNumber(unsigned int index);

		void		addNumber(int n);
		void		addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		int			shortestSpan();
		int			longestSpan();
		static void	printSpan(std::vector<int> vec);

	private:
		std::vector<int>	m_tab;
		unsigned int		m_size;


};

#endif