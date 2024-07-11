/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchavez <rchavez@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 19:34:19 by rchavez@stu       #+#    #+#             */
/*   Updated: 2024/07/11 10:31:45 by rchavez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_params(long params[5])
{
	printf("               ╭────────╮ ╭─────────────╮ ╭─────────────╮ ╭─────");
	printf("──────────╮ ╭─────────────────╮\n./philosophers │ number │ │ tim");
	printf("e to die │ │ time to eat │ │ time to sleep │ │ number of meals │");
	printf("\n               ╰────────╯ ╰─────────────╯ ╰─────────────╯ ╰───");
	printf("────────────╯ ╰─────────────────╯\n");
	printf("\033[20G\033[1m\033[31m%li", params[0]);
	printf("\033[33G\033[1m\033[31m%li", params[1]);
	printf("\033[49G\033[1m\033[31m%li", params[2]);
	printf("\033[66G\033[1m\033[31m%li", params[3]);
	printf("\033[85G\033[1m\033[31m%li\n\033[0m", params[4]);
	msleep(500);
}

void	usage2(void)
{
	printf("               ╔════════╗ ╔═════════════╗ ╔═════════════╗ ╔═════");
	printf("══════════╗ ╔═════════════════╗\n./philosophers ║ number ║ ║ tim");
	printf("e to die ║ ║ time to eat ║ ║ time to sleep ║ ║ number of meals ║");
	printf("\n               ╚════════╝ ╚═════════════╝ ╚═════════════╝ ╚═══");
	printf("════════════╝ ╚═════════════════╝\n               ┊        ┊ ┊  ");
	printf("           ┊ ┊             ┊ ┊               ┊ ┊    <optional>  ");
	printf(" ┊\n               ┊        ┊ ┊             ┊ ┊             ┊ ┊ ");
	printf("              ┊ ┊                 ┊\n      MIN      ┊    1   ┊ ┊");
	printf(" eat + sleep ┊ ┊      1      ┊ ┊       1       ┊ ┊        1     ");
	printf("   ┊\n               ┊        ┊ ┊             ┊ ┊             ┊ ");
	printf("┊               ┊ ┊                 ┊\n               ┊        ┊");
	printf(" ┊             ┊ ┊             ┊ ┊               ┊ ┊            ");
	printf("     ┊\n      MAX      ┊   200  ┊ ┊             ┊ ┊             ");
	printf("┊ ┊               ┊ ┊                 ┊\n               ┊       ");
	printf(" ┊ ┊             ┊ ┊             ┊ ┊               ┊ ┊          ");
	printf("       ┊\n               ┊        ┊ ┊             ┊ ┊           ");
	printf("  ┊ ┊               ┊ ┊                 ┊\n               ╘═════");
	printf("═══╛ ╘═════════════╛ ╘═════════════╛ ╘═══════════════╛ ╘════════");
	printf("═════════╛\n");
}

int	usage(void)
{
	printf("\n\033[39G\033[1m ___________________\033[0m");
	printf("\n\033[39G\033[1m/                   \\\033[0m");
	printf("\n\033[39G\033[1m|   YOU'RE FIRED!   |\033[0m");
	printf("\n\033[39G\033[1m\\___________________/\033[0m\n\n\n");
	printf("\033[26G\033[3mSeems like you killed all of your philosophers...");
	printf("\033[0m\n\n\033[28GTry setting some ground rules for \033[1m");
	printf("\033[31mNEXT TIME:\033[0m\n\n");
	usage2();
	return (0);
}
