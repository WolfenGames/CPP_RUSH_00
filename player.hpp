/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <jwolf@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 13:37:29 by jwolf             #+#    #+#             */
/*   Updated: 2019/06/09 15:58:08 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_HPP
# define PLAYER_HPP

#include "Entity.hpp"

class Player: public Entity
{
	public:
		Player();
		~Player();
		void getPlayerInput(WINDOW *);
        void shoot();
	private:
        Entity **bullets;
};

#endif