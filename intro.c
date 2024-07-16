/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intro.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchavez <rchavez@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 18:53:36 by rchavez@stu       #+#    #+#             */
/*   Updated: 2024/07/16 12:49:39 by rchavez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	img1(void)
{
	printf("\033[2J\033[H\n");
	printf(" ██ ███   ██  ██  ██  ██       █████    ██████   █████   ██ ███ ");
	printf("  ██  ██  █████  ██▀███    ██████ \n ██   ██  ██  ██  ██  ██    ");
	printf("  ██   ██  ██       ██   ██  ██   ██  ██  ██  █   ▀  ██   ██  ██");
	printf("      \n ██  ██   ██▀▀██  ██  ██      ██   ██    ██▄    ██   ██ ");
	printf(" ██  ██   ██▀▀██  ███    ██  ▄█     ██▄   \n ██▄█      █  ██  ██");
	printf("  ██      ██   ██       ██  ██   ██  ██▄█      █  ██   █  ▄  ██▀");
	printf("▀█▄        ██ \n ██        █  ██  ██  ██████   ████    ██████   ");
	printf(" ████    ██        █  ██   ████  ██   ██  ██████  \n            ");
	printf("                                                                ");
	printf("                    \n                                          ");
	printf("                                                        \n      ");
	printf("                                                                ");
	printf("                            \n                                  ");
	printf("                                                              \n");
}

void	img2(void)
{
	printf("\033[2J\033[H\n");
	printf(" ██▓███   ██  ██  ██▓ ██▓      █████    ██████   █████   ██▓███ ");
	printf("  ██  ██ ▓█████  ██▀███    ██████ \n▓██   ██ ▓██  ██ ▓██ ▓██    ");
	printf("  ██   ██  ██       ██   ██ ▓██   ██ ▓██  ██ ▓█   ▀ ▓██   ██  ██");
	printf("      \n▓██  ██▓  ██▀▀██  ██  ██      ██   ██   ▓██▄    ██   ██ ");
	printf("▓██  ██▓  ██▀▀██  ███   ▓██  ▄█    ▓██▄   \n ██▄█▓    ▓█  ██  ██");
	printf("  ██      ██   ██       ██  ██   ██  ██▄█▓    ▓█  ██  ▓█  ▄  ██▀");
	printf("▀█▄        ██ \n ██       ▓█  ██▓ ██  ██████   ████▓   ██████   ");
	printf(" ████▓   ██       ▓█  ██▓  ████  ██▓  ██  ██████  \n ▓          ");
	printf("      ▓      ▓               ▓               ▓                  ");
	printf("     ▓   ▓    ▓     \n                                          ");
	printf("                                                        \n      ");
	printf("                                                                ");
	printf("                            \n                                  ");
	printf("                                                              \n");
}

void	img3(void)
{
	printf("\033[2J\033[H\n");
	printf(" ██▓███   ██  ██  ██▓ ██▓     ▒█████    ██████  ▒█████   ██▓███ ");
	printf("  ██  ██ ▓█████  ██▀███    ██████ \n▓██   ██▒▓██  ██▒▓██▒▓██▒   ");
	printf(" ▒██▒  ██▒▒██    ▒ ▒██▒  ██▒▓██   ██▒▓██  ██▒▓█   ▀ ▓██ ▒ ██▒▒██");
	printf("    ▒ \n▓██  ██▓▒▒██▀▀██ ▒██▒▒██     ▒██   ██▒  ▓██▄   ▒██   ██▒");
	printf("▓██  ██▓▒▒██▀▀██ ▒███   ▓██  ▄█ ▒  ▓██▄   \n▒██▄█▓▒ ▒ ▓█  ██  ██");
	printf(" ▒██     ▒██   ██   ▒   ██▒▒██   ██ ▒██▄█▓▒ ▒ ▓█  ██ ▒▓█  ▄ ▒██▀");
	printf("▀█▄    ▒   ██▒\n▒██▒      ▓█▒ ██▓ ██  ██████▒  ████▓▒ ▒██████▒▒ ");
	printf(" ████▓▒ ▒██▒      ▓█▒ ██▓ ▒████▒ ██▓ ▒██▒▒██████▒▒\n▒▓▒       ▒ ");
	printf("  ▒ ▒ ▓    ▒ ▓     ▒ ▒ ▒  ▒ ▒▓▒ ▒    ▒ ▒ ▒  ▒▓▒       ▒   ▒ ▒   ");
	printf("    ▒▓  ▒▓ ▒ ▒▓▒ ▒  \n ▒        ▒  ▒    ▒      ▒       ▒ ▒     ▒");
	printf("         ▒ ▒   ▒        ▒  ▒             ▒   ▒    ▒     \n      ");
	printf("            ▒                ▒                 ▒                ");
	printf("                            \n                                  ");
	printf("                                                              \n");
}

void	img4(void)
{
	printf("\033[2J\033[H\n");
	printf(" ██▓███   ██░ ██  ██▓ ██▓     ▒█████    ██████  ▒█████   ██▓███ ");
	printf("  ██░ ██ ▓█████  ██▀███    ██████ \n▓██░  ██▒▓██░ ██▒▓██▒▓██▒   ");
	printf(" ▒██▒  ██▒▒██    ▒ ▒██▒  ██▒▓██░  ██▒▓██░ ██▒▓█   ▀ ▓██ ▒ ██▒▒██");
	printf("    ▒ \n▓██░ ██▓▒▒██▀▀██░▒██▒▒██░    ▒██░  ██▒░ ▓██▄   ▒██░  ██▒");
	printf("▓██░ ██▓▒▒██▀▀██░▒███   ▓██ ░▄█ ▒░ ▓██▄   \n▒██▄█▓▒ ▒░▓█ ░██ ░██");
	printf("░▒██░    ▒██   ██░  ▒   ██▒▒██   ██░▒██▄█▓▒ ▒░▓█ ░██ ▒▓█  ▄ ▒██▀");
	printf("▀█▄    ▒   ██▒\n▒██▒ ░  ░░▓█▒░██▓░██░░██████▒░ ████▓▒░▒██████▒▒░");
	printf(" ████▓▒░▒██▒ ░  ░░▓█▒░██▓░▒████▒░██▓ ▒██▒▒██████▒▒\n▒▓▒░ ░  ░ ▒ ");
	printf("░░▒░▒░▓  ░ ▒░▓  ░░ ▒░▒░▒░ ▒ ▒▓▒ ▒ ░░ ▒░▒░▒░ ▒▓▒░ ░  ░ ▒ ░░▒░▒░░ ");
	printf(" ░░ ▒▓ ░▒▓░▒ ▒▓▒ ▒ ░\n░▒ ░      ▒ ░▒░ ░ ▒ ░░ ░ ▒  ░  ░ ▒ ▒░ ░ ░▒");
	printf("  ░ ░  ░ ▒ ▒░ ░▒ ░      ▒ ░▒░ ░ ░ ░  ░  ░▒ ░ ▒░░ ░▒  ░ ░\n      ");
	printf("           ░        ░ ░   ░    ░         ░       ░              ");
	printf("                             \n                        ░        ");
	printf("                                                              \n");
}

void	img5(void)
{
	printf("\033[2J\033[H\n");
	printf(" ██▓███   ██░ ██  ██▓ ██▓     ▒█████    ██████  ▒█████   ██▓███ ");
	printf("  ██░ ██ ▓█████  ██▀███    ██████ \n▓██░  ██▒▓██░ ██▒▓██▒▓██▒   ");
	printf(" ▒██▒  ██▒▒██    ▒ ▒██▒  ██▒▓██░  ██▒▓██░ ██▒▓█   ▀ ▓██ ▒ ██▒▒██");
	printf("    ▒ \n▓██░ ██▓▒▒██▀▀██░▒██▒▒██░    ▒██░  ██▒░ ▓██▄   ▒██░  ██▒");
	printf("▓██░ ██▓▒▒██▀▀██░▒███   ▓██ ░▄█ ▒░ ▓██▄   \n▒██▄█▓▒ ▒░▓█ ░██ ░██");
	printf("░▒██░    ▒██   ██░  ▒   ██▒▒██   ██░▒██▄█▓▒ ▒░▓█ ░██ ▒▓█  ▄ ▒██▀");
	printf("▀█▄    ▒   ██▒\n▒██▒ ░  ░░▓█▒░██▓░██░░██████▒░ ████▓▒░▒██████▒▒░");
	printf(" ████▓▒░▒██▒ ░  ░░▓█▒░██▓░▒████▒░██▓ ▒██▒▒██████▒▒\n▒▓▒░ ░  ░ ▒ ");
	printf("░░▒░▒░▓  ░ ▒░▓  ░░ ▒░▒░▒░ ▒ ▒▓▒ ▒ ░░ ▒░▒░▒░ ▒▓▒░ ░  ░ ▒ ░░▒░▒░░ ");
	printf(" ░░ ▒▓ ░▒▓░▒ ▒▓▒ ▒ ░\n░▒ ░      ▒ ░▒░ ░ ▒ ░░ ░ ▒  ░  ░ ▒ ▒░ ░ ░▒");
	printf("  ░ ░  ░ ▒ ▒░ ░▒ ░      ▒ ░▒░ ░ ░ ░  ░  ░▒ ░ ▒░░ ░▒  ░ ░\n░░    ");
	printf("    ░  ░░ ░ ▒ ░  ░ ░   ░ ░ ░ ▒  ░  ░  ░  ░ ░ ░ ▒  ░░        ░  ░");
	printf("░ ░   ░     ░░   ░ ░  ░  ░  \n          ░  ░  ░ ░      ░  ░    ░");
	printf(" ░        ░      ░ ░            ░  ░  ░   ░  ░   ░           ░\n");
	printf("\033[40G\033[31mA Project by \033]8;;https://github.com/rodalcha");
	printf("m\archavez\033]8;;\a\033[0m\n\n\033[39G");
	printf("\033[39GClick Here: → \033]8;;https://github.com/rodalcham/Philo");
	printf("sophers42/blob/master/README.md\aReadMe\033]8;;\a ←\n\n");
}
