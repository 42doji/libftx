#include "libft.h"
#include <fcntl.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    int     fd;
    char    *line;

    if (argc != 2)
    {
        printf("사용법: %s <파일 경로>\n", argv[0]);
        return (1);
    }
    fd = open(argv[1], O_RDONLY);
    if (fd < 0)
    {
        perror("파일 열기 실패");
        return (1);
    }
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
