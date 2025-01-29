#include "libft.h"
#include <fcntl.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>

int main(void)
{
    DIR *dir;
    struct dirent *entry;
    char filepath[512];
    char *line;
    int fd;

    dir = opendir("test");
    if (dir == NULL)
    {
        perror("opendir 실패");
        return (1);
    }

    while ((entry = readdir(dir)) != NULL)
    {
        if (strstr(entry->d_name, ".txt") != NULL)
        {
            snprintf(filepath, sizeof(filepath), "test/%s", entry->d_name);
            printf("Testing file: %s\n", filepath);
            fd = open(filepath, O_RDONLY);
            if (fd == -1)
            {
                perror("파일 열기 실패");
                continue;
            }
            while ((line = get_next_line(fd)) != NULL)
            {
                printf("%s", line);
                free(line);
            }
            close(fd);
            printf("\n--- %s 종료 ---\n\n", entry->d_name);
        }
    }

    closedir(dir);
    return (0);
}
