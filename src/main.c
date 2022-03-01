/*
** EPITECH PROJECT, 2021
** myworld
** File description:
** main.c
*/

#include "../include/my.h"
#include "../include/struct.h"
#include "../include/myworld.h"

bool str_isnum(char *str)
{
    for (int i = 0; str[i] != '\0'; ++i) {
        if (!isnum(str[i]))
            return (false);
    }
    return (true);
}

void help(void)
{
    char *filepath = "assets/help.txt";
    struct stat stat_buff;
    int s = stat(filepath, &stat_buff);
    char *buff = malloc(sizeof(char) * stat_buff.st_size);
    int fd = open(filepath, O_RDONLY);
    int r = read(fd, buff, stat_buff.st_size);

    buff[stat_buff.st_size - 1] = '\0';
    my_putstr(buff);
    my_putchar('\n');
    close(fd);
}

int main(int ac, char **av)
{
    if (ac == 1)
        return (84);
    else if (ac == 2) {
        if (!my_strcmp("-h", av[1]))
            help();
        else
            my_world(true, (sfVector2i){0, 0}, av[1]);
    } else
        if (str_isnum(av[1]) && str_isnum(av[2]))
            my_world(false, (sfVector2i){my_atoi(av[1]), my_atoi(av[2])}, "");
        else
            return (84);
    return (0);
}
