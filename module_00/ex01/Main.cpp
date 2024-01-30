/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: learodri@student.42.fr <learodri>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 11:55:33 by learodri@st       #+#    #+#             */
/*   Updated: 2024/01/30 14:32:21 by learodri@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

int main(void)
{
	std::string in;
	Phonebook phonebook(0);
	
	while (1)
	{
		std::cout << "OPTIONS : ADD - SEARCH - EXIT" << std::endl;
		getline(std::cin, in);
		if (std::cin.eof())
			return 0;
		if (in == "ADD")
            phonebook.add();
        if (in == "SEARCH")
            phonebook.search();
		if (in == "EXIT")
			exit(1);
		else if (in != "EXIT" && in != "SEARCH" && in != "ADD")
		{
			std::cout << " wrong option, try it again" << std::endl;
			sleep(1);
			std::cin.clear();
			continue;
		}
		std::cin.clear();
	}
}
 