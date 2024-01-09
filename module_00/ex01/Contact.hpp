/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: learodri@student.42.fr <learodri>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 12:04:32 by learodri@st       #+#    #+#             */
/*   Updated: 2024/01/04 14:41:44 by learodri@st      ###   ########.fr       */
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

std::string  p_first(void);
std::string  p_last(void);
std::string  p_nick(void);
std::string  p_dark(void);
std::string  p_number(void);

};

# endif