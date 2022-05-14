/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MySed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 02:06:51 by cberganz          #+#    #+#             */
/*   Updated: 2022/04/01 03:11:20 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MySed.hpp"

MySed::MySed(const std::string& fileName, const std::string& toReplace,
				const std::string& toInsert)
{
	this->_fileName = fileName;
	this->_toReplace = toReplace;
	this->_toInsert = toInsert;
}

MySed::~MySed()
{
}

bool	MySed::sed(void)
{
	std::string::size_type	pos;
	std::string				line, save;

	std::ifstream fileIn(this->_fileName.c_str());
	if (!fileIn)
		return (false);
	while (std::getline(fileIn, line))
		save.append(line.append("\n"));
	while ((pos = save.find(this->_toReplace)) >= 0 and pos != std::string::npos)
	{
		save.erase(pos, this->_toReplace.length());
		save.insert(pos, this->_toInsert);
	}
	fileIn.close();

	std::ofstream fileOut(this->_fileName.append(".replace").c_str());
	if (!fileOut)
		return (false);
	fileOut << save;
	fileOut.close();

	return (true);
}
