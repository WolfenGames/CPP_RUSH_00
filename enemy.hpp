/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tramants <tramants@student.wethinkcode.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 13:37:29 by jwolf             #+#    #+#             */
/*   Updated: 2019/06/10 14:22:21 by tramants         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_HPP
# define ENEMY_HPP

#include "Entity.hpp"

class Enemy: public Entity
{
	public:
		Enemy();
		~Enemy();
		void	renderEnemy(WINDOW *main, const char *sprite);
		void	updateMovement(int max_x, int max_y);
	private:
};

#endif