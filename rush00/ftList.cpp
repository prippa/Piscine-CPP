/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftList.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akokoshk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 14:28:24 by akokoshk          #+#    #+#             */
/*   Updated: 2018/06/09 19:43:51 by akokoshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftList.hpp"
#include <iostream>

ftList::ftList()
{
	_start = _end = NULL;
	_objNum = 0;
}

ftList::ftList(void *obj)
{
	_start = _end = NULL;
	_objNum = 0;
	addObj(obj);
}

ftList& ftList::operator=(ftList const &src)
{
	clearList();

	unsigned int num = src.getObjNum();
	for(unsigned int i = 0; i < num; i++)
		addObj(src.getObj(i));

	return (*this);
}

ftList::ftList(ftList const & src)
{
	*this = src;
}

ftList::~ftList()
{
	clearList();
}

unsigned int ftList::addObj(void *obj)
{
	if (obj == NULL || getObjIdx(obj) > 0)
		return (_objNum);

	_objNum++;
	try
	{
		t_obj *newObj = new t_obj;
		newObj->obj = obj;
		newObj->prev = _end;
		newObj->next = NULL;
		if (_end == NULL)
			_start = newObj;
		else
			_end->next = newObj;
		_end = newObj;
	}
	catch (std::bad_alloc&)
	{
		return (_objNum - 1);
	}

	return (_objNum);
}

void* ftList::getObj(unsigned int idx) const
{
	if (_start != NULL && idx < _objNum)
	{
		t_obj *cur = _start;
		for(unsigned int i = 0; (i < idx && cur != NULL); i++)
			cur = cur->next;
		return (cur->obj);
	}
	return (NULL);
}

unsigned int ftList::getObjNum() const
{
	return (_objNum);
}

unsigned int ftList::getObjIdx(void *obj) const
{
	t_obj *cur = _start;
	unsigned int i = 0;
	while (cur != NULL)
	{
		i++;
		if (cur->obj == obj)
			return (i);
		cur = cur->next;
	}
	return (0);
}

void ftList::rmObjFromList(unsigned int idx)
{
	if (_start != NULL && idx < _objNum)
	{
		t_obj *cur = _start;
		for(unsigned int i = 0; (i < idx && cur != NULL); i++)
			cur = cur->next;
		if (cur != NULL)
		{
			if (cur == _start)
				_start = _start->next;
			if (cur == _end)
				_end = _end->prev;
			if (cur->prev != NULL)
				cur->prev->next = cur->next;
			if (cur->next != NULL)
				cur->next->prev = cur->prev;
			cur->obj = NULL;
			delete(cur);
		}
		_objNum--;
	}
}

void ftList::rmObj(unsigned int idx, void (*rmThisObj)(void *))
{
	if (_start != NULL && idx < _objNum)
	{
		t_obj *cur = _start;
		for(unsigned int i = 0; (i < idx && cur != NULL); i++)
			cur = cur->next;
		if (cur != NULL)
		{
			if (cur == _start)
				_start = _start->next;
			if (cur == _end)
				_end = _end->prev;
			if (cur->prev != NULL)
				cur->prev->next = cur->next;
			if (cur->next != NULL)
				cur->next->prev = cur->prev;
			rmThisObj(cur->obj);
			cur->obj = NULL;
			delete(cur);
		}
		_objNum--;
	}
}

void ftList::clearList()
{
	t_obj *cur;
	for(unsigned int i = 0; (i < _objNum && _start != NULL); i++)
	{
		cur = _start->next;
		delete (_start);
		_start = cur;
	}
	_end = NULL;
	_objNum = 0;
}
