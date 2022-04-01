/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MySed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 01:59:45 by cberganz          #+#    #+#             */
/*   Updated: 2022/04/01 03:13:02 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_SED_HPP
# define MY_SED_HPP

# include <iostream>
# include <string>
# include <fstream>

class MySed {

public:
	MySed(const std::string& fileName, const std::string& toReplace,
			const std::string& toInsert);
	~MySed();
	bool	sed();

private:
	std::string	_toReplace;
	std::string	_toInsert;
	std::string	_fileName;
};

#endif
