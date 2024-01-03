/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: learodri@student.42.fr <learodri>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 11:55:33 by learodri@st       #+#    #+#             */
/*   Updated: 2024/01/03 15:28:00 by learodri@st      ###   ########.fr       */
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
            phonebook.add();
		else
			continue;
	}
	
}