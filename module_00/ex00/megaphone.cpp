/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex00.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: learodri@student.42.fr <learodri>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 12:07:01 by learodri@st       #+#    #+#             */
/*   Updated: 2023/12/26 15:23:48 by learodri@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string.h>

int main(int argc, char *argv[])
{
    int i = 1;
    if (argc == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    while(i < argc)
    {
        std:: string str = argv[i];
        for(int k = 0; k < (int)str.length(); k++)
            std::cout << (char)toupper(str[k]);
        std::cout << " ";     
        i++;
    }
}