/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akokoshk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 20:11:01 by akokoshk          #+#    #+#             */
/*   Updated: 2018/06/11 21:11:24 by akokoshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOL_HPP
#define TOOL_HPP

#define HIGHT 50// y - высота
#define WIDTH 150 // x - ширин
#define SCREEN_HIGHT HIGHT + 3 // y - высота
#define SCREEN_WIDTH WIDTH + 2 // x - ширин
#define FIELD_SIZE HIGHT * WIDTH;


typedef struct s_xy
{
	int x;
	int y;
}				t_xy;

typedef enum	e_type
{
	o_background,
	o_player,
	o_obstacle,
	o_enemy,
	o_boss,
	o_projectile,
}				t_type;

typedef enum	e_colrpair
{
	c_fade = 0,
	c_background = 1,
	c_player = 2,
	c_obstacle = 3,
	c_enemy = 4,
	c_boss = 5,
	c_projectile = 6,
	c_border = 7,

}				t_colrpair;

typedef enum	e_direction
{
	d_up = 0,
	d_down = 1,

}				t_direction;


typedef enum	e_key
{
	k_up = 259,
	k_down = 258,
	k_left = 260,
	k_right = 261,
	k_enter = 10,
	k_space = 32,
	k_esc = 27
}				t_key;

#endif
