/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   templates.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 00:51:17 by cberganz          #+#    #+#             */
/*   Updated: 2022/06/06 00:52:16 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEMPLATES_HPP
# define TEMPLATES_HPP

template <typename T>
void swap(T &t1, T &t2)
{
	T tmp = t1;
	t1 = t2;
	t2 = tmp;
}

template <typename T>
const T	&min(const T &t1, const T &t2)
{
	return (t1 < t2 ? t1 : t2);
}

template <typename T>
const T	&max(const T &t1, const T &t2)
{
	return (t1 > t2 ? t1 : t2);
}

#endif