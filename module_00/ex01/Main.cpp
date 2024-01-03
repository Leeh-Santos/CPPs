/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: learodri <learodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 11:55:33 by learodri@st       #+#    #+#             */
/*   Updated: 2024/01/03 21:49:24 by learodri         ###   ########.fr       */
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
		if (in == "ADD")
		{
            phonebook.add();
			//system("clear");
			continue;
		}
		if (in == "EXIT")
			exit(1);
		else
		{
			std::cout << " wrong option, try it again" << std::endl;
			sleep(1);
			system("clear");
			std::cin.clear();
			continue;
		}
		std::cin.clear();
	}
	
}
 