/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiharel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 14:54:37 by wiharel           #+#    #+#             */
/*   Updated: 2022/07/25 14:54:38 by wiharel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	printf_str(int num, siginfo_t *info)
{
	static char	str[2147400000];
	static int	i = 0;

	(void) info;
	if (num == -1)
	{
		i = 0;
		return ;
	}
	if (num != 0)
	{
		str[i] = num;
		i++;
	}
	if (num == 0)
	{
		str[i] = num;
		ft_printf("%s\n", str);
		i = 0;
		kill(info->si_pid, SIGUSR2);
	}
}

static void	send_bit(char c, siginfo_t *info)
{
	static char	str[7];
	static int	i = 0;

	if (i < 8)
		str[i] = c;
	i++;
	if (i == 8 && c != '2')
	{
		printf_str(to_decimal(str), info);
		i = 0;
	}
	if (c == '2')
	{
		i = 0;
		return ;
	}
}

static int	ft_check_pid(int signum, siginfo_t *info, void *context)
{
	static int	pid[1];

	(void)signum;
	(void)context;
	if (pid[0] == 0)
		pid[0] = info->si_pid;
	pid[1] = info->si_pid;
	if (pid[0] != pid[1])
	{
		pid[0] = pid[1];
		return (-1);
	}
	else if (pid[0] == pid[1])
		return (1);
	return (0);
}

static void	sig_usr(int signum, siginfo_t *info, void *context)
{
	int	i;

	(void)context;
	i = 0;
	if (signum == SIGUSR1)
	{
		i = ft_check_pid(signum, info, context);
		if (i == -1)
		{
			printf_str(-1, info);
			send_bit('2', info);
		}
		send_bit('0', info);
	}
	else if (signum == SIGUSR2)
	{
		i = ft_check_pid(signum, info, context);
		if (i == -1)
		{
			printf_str(-1, info);
			send_bit('2', info);
		}
		send_bit('1', info);
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(int argc, char **argv)
{
	struct sigaction	sa_usr;

	(void)argv;
	if (argc > 1)
	{
		ft_printf("Please enter: ./server\n");
		return (1);
	}
	ft_printf("Server PID: %d\n", getpid());
	sa_usr.sa_flags = SA_SIGINFO;
	sa_usr.sa_sigaction = sig_usr;
	sigemptyset(&sa_usr.sa_mask);
	sigaddset(&sa_usr.sa_mask, SIGUSR1);
	sigaddset(&sa_usr.sa_mask, SIGUSR2);
	sigaction(SIGUSR1, &sa_usr, NULL);
	sigaction(SIGUSR2, &sa_usr, NULL);
	while (1)
	{
	}
	return (0);
}
