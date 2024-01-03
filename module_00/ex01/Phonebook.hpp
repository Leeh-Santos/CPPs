/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: learodri <learodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 12:04:30 by learodri@st       #+#    #+#             */
/*   Updated: 2024/01/03 21:29:04 by learodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PHONEBOOK_HPP

# define PHONEBOOK_HPP
# include <iostream>
# include <string>
# include "Contact.hpp"
#include <cstdlib>
#include <iomanip>
#include <unistd.h>

class Phonebook
{
private:
    int i;
    Contact contact[8];
public:
    Phonebook(int nb);
    ~Phonebook();
    void    add(void);
    
};

#endif