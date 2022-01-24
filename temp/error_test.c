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

#include "../fillit.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <errno.h>

int main(void)
{
	/*	Add test file name here	*/
	//char	*file_names[] = {
	//	"max.txt",
	//	"short_line.txt",
	//	"wrong_char.txt",
	//	NULL
	//};

		system("../fillit ./test_files/error_file/error_0");
		system("../fillit ./test_files/error_file/error_1");
		system("../fillit ./test_files/error_file/error_2");
		system("../fillit ./test_files/error_file/error_3");
		system("../fillit ./test_files/error_file/error_4");
		system("../fillit ./test_files/error_file/error_5");
		system("../fillit ./test_files/error_file/error_6");
		system("../fillit ./test_files/error_file/error_7");
		system("../fillit ./test_files/error_file/error_8");
		system("../fillit ./test_files/error_file/error_9");
		system("../fillit ./test_files/error_file/error_10");
		system("../fillit ./test_files/error_file/error_11");
		system("../fillit ./test_files/error_file/error_12");
		system("../fillit ./test_files/error_file/error_13");
		system("../fillit ./test_files/error_file/error_14");
		system("../fillit ./test_files/error_file/error_15");
		system("../fillit ./test_files/error_file/error_16");
		system("../fillit ./test_files/error_file/error_17");
		system("../fillit ./test_files/error_file/error_18");
		system("../fillit ./test_files/error_file/error_19");
		system("../fillit ./test_files/error_file/error_20");
		system("../fillit ./test_files/error_file/error_21");
		system("../fillit ./test_files/error_file/error_22");
		system("../fillit ./test_files/error_file/error_23");
		system("../fillit ./test_files/error_file/error_24");
		system("../fillit ./test_files/error_file/error_25");
}