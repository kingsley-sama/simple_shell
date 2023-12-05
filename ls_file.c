#include "shell.h"
#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
/**
 * ls_file - List all files and directories.
 * @dir: directory
 *
 * Return:void.
 */
void ls_file(const char *dir)
{
	DIR *all_dir;
	struct dirent *de;

	all_dir = opendir("dir");
	if (all_dir == NULL)
	return;

	de = readdir(all_dir);

	while (de != NULL)
	{
	print_str(de->d_name);
	}

	closedir(all_dir);
}
