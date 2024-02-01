/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorder.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: learodri <learodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:59:35 by learodri          #+#    #+#             */
/*   Updated: 2024/01/10 21:00:08 by learodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name ){
    
    Zombie* t = new Zombie[N];

    for (int i = 0; i < N; i++)
    { 
      t[i].setName(name);
      t[i].announce();
    }
    return (t);
}