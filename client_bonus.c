/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiharel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 14:53:24 by wiharel           #+#    #+#             */
/*   Updated: 2022/07/25 14:53:28 by wiharel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static void	ft_send_msg(pid_t pid, char c_msg)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if ((c_msg >> i) % 2 == 0)
			kill(pid, SIGUSR1);
		else if ((c_msg >> i) % 2 == 1)
			kill(pid, SIGUSR2);
		i--;
		usleep(1000);
	}
}

static void	handler(int signum)
{
	if (signum == SIGUSR1)
		return ;
	if (signum == SIGUSR2)
	{
		ft_printf("Message sent!\n");
		exit(0);
	}
}

int	main(int argc, char **argv)
{
	int		i;
	pid_t	pid;

	i = 0;
	if (argc != 3 || ft_strlen(argv[1]) > 7)
	{
		ft_printf("input no valid\n");
		return (0);
	}
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	pid = ft_atoi(argv[1]);
	if (pid <= 0 || pid == 1 || pid > 4194304)
	{
		ft_printf("The PID is incorrect\n");
		return (0);
	}
	while (argv[2][i])
		ft_send_msg(pid, argv[2][i++]);
	ft_send_msg(pid, argv[2][i]);
	if (argv[2][i] == '\0')
		sleep(1);
	return (0);
}
