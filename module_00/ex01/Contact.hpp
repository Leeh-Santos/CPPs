/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: learodri <learodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 12:04:32 by learodri@st       #+#    #+#             */
/*   Updated: 2024/01/03 21:21:59 by learodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP

# define CONTACT_HPP

# include <iostream>
# include <string>


class Contact
{
    
private:

std::string _first;
std::string _last;
std::string _nick;
std::string _dark;
std::string _number;
    
public:

void    first(std::string name);
void    last(std::string name);
void    nick(std::string name);
void    dark(std::string name);
void    number(std::string name);
int     spit(void);

    
};

# endif