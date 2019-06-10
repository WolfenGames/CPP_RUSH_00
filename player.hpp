/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-beer <rde-beer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 13:37:29 by jwolf             #+#    #+#             */
/*   Updated: 2019/06/10 16:57:41 by rde-beer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_HPP
# define PLAYER_HPP

#include "Entity.hpp"
#include "Projectile.hpp"

class Player: public Entity
{
	public:
	Player();
	~Player();
	void getPlayerInput(WINDOW *);
	void shoot();
	void addBullet(VEC);
	t_list *getProjectiles();
	void killBullet(VEC);
	int	getLifes(void);

	private:
	t_list *bullets;

};

#endif