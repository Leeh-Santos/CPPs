/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: learodri@student.42.fr <learodri>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 12:04:30 by learodri@st       #+#    #+#             */
/*   Updated: 2024/01/09 16:24:01 by learodri@st      ###   ########.fr       */
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
    int ilock;
    int flag;
    Contact contact[8];
public:
    Phonebook(int nb);
    ~Phonebook();
    void    add(void);
    void    search(void);    
    
};

#endif