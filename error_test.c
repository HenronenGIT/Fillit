/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   error_test.c									   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: hmaronen <hmaronen@student.hive.fi>		+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2022/01/13 11:22:43 by hmaronen		  #+#	#+#			 */
/*   Updated: 2022/01/13 11:22:49 by hmaronen		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <errno.h>

int main(void)
{
	size_t	i;
	/*	Add test file name here	*/
	char	*file_names[] = {
		"max.txt",
		"short_line.txt",
		"wrong_char.txt",
		NULL
	};

	i = 0;
	while (file_names[i])
	{
		//system("./fillit ./test_files/short_line.txt");
		//system("./fillit ./test_files/wrong_line.txt");
		//system("./fillit max_line.txt");
		execve("./fillit ",  &file_names[i], NULL);
		i++;
	}
}