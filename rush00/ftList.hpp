/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftList.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akokoshk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 14:21:29 by akokoshk          #+#    #+#             */
/*   Updated: 2018/06/09 14:26:56 by akokoshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTLIST_HPP
#define FTLIST_HPP

class ftList
{
private:
	typedef struct	s_obj
	{
		struct s_obj	*prev;
		struct s_obj	*next;
		void			*obj;
	}				t_obj;

	unsigned int		_objNum;
	t_obj				*_start, *_end;

public:
	ftList();
	ftList(ftList const &);
	ftList(void *);
	~ftList();
	ftList &operator= (ftList const &);

	unsigned int addObj(void *);
	void *getObj(unsigned int idx) const;
	void rmObj(unsigned int idx, void (*rmThisObj)(void *));
	void rmObjFromList(unsigned int idx);
	unsigned int getObjIdx(void *obj) const;
	void clearList();
	
	unsigned int getObjNum() const;
};


#endif
