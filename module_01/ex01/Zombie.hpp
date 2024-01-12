/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: learodri@student.42.fr <learodri>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:59:44 by learodri          #+#    #+#             */
/*   Updated: 2024/01/12 11:19:42 by learodri@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
#include <string>

class Zombie
{
    private:
        std::string _name;
        
    
    public:
        Zombie(void);
        ~Zombie();
        void    announce(void);
        void    setName(std::string name);
};

Zombie* zombieHorde( int N, std::string name );

#endif
