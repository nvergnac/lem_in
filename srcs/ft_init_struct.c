/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvergnac <nvergnac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 14:18:04 by nvergnac          #+#    #+#             */
/*   Updated: 2018/04/10 15:30:23 by nvergnac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		*ft_intdup(int *path_tab, int room_nb, int new_index)
{
	int	*tab;
	int i;

	i = 0;
	if (!(tab = (int*)malloc(sizeof(int) * room_nb)))
		exit(0);
	ft_bzero(tab, room_nb * sizeof(int));
	if (path_tab)
	{
		while (i < room_nb && path_tab[i] != 0)
		{
			tab[i] = path_tab[i];
			i++;
		}
		if (i < room_nb)
			tab[i] = new_index;
	}
	else
		tab[0] = new_index;
	return (tab);
}

t_path	*ft_path_init(t_info *info, t_path *path_lst, int new_index)
{
	t_path	*path;
	int		path_len;

	path_len = 0;
	if (!(path = (t_path*)malloc(sizeof(t_path))))
		exit(0);
	if (path_lst)
		path->path_index = ft_intdup(path_lst->path_index, ROOM_NB, new_index);
	else
		path->path_index = ft_intdup(0, ROOM_NB, new_index);
	while (path_len < ROOM_NB && path->path_index[path_len] != 0)
		path_len++;
	path->path_len = path_len - 1;
	path->flag = FLAG;
	path->next = 0;
	return (path);
}

t_room	*ft_room_init(int x, int y, int type, int index)
{
	t_room *room;

	if (!(room = (t_room*)malloc(sizeof(t_room))))
		exit(0);
	room->x = x;
	room->y = y;
	room->index = index;
	room->type = type;
	room->name = 0;
	room->link_room_count = 0;
	room->linked_room = 0;
	room->next = NULL;
	return (room);
}

t_link	*ft_linked_room_init(char *room_name)
{
	t_link	*new_linked_room;

	if (!(new_linked_room = (t_link*)malloc(sizeof(t_link))))
		exit(0);
	new_linked_room->name = ft_strdup(room_name);
	new_linked_room->next = NULL;
	return (new_linked_room);
}
