/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: learodri@student.42.fr <learodri>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 12:04:30 by learodri@st       #+#    #+#             */
/*   Updated: 2024/01/03 16:19:26 by learodri@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PHONEBOOK_HPP

# define PHONEBOOK_HPP
# include <iostream>
# include <string>
# include "Contact.hpp"

class Phonebook
{
private:
    //int i;
    Contact contact[8];
public:
    int i;
    Phonebook(int nb);
    ~Phonebook();
    void    add(void);
    
};



#endif