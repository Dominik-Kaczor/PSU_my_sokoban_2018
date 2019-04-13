/*
** EPITECH PROJECT, 2018
** unit_test
** File description:
** test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/my.h"
#include "../include/sokoban.h"

int test_main(int ac, char **av);

void redirect_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(test_main, resturn_of_h)
{
    int ac = 2;
    char *av[] = {"", "-h"};
    int dest = test_main(ac, av);

    cr_assert_eq(dest, 0);
}

Test(test_main, error_return)
{
    int ac = 2;
    char *av[] = {"", "-hz"};
    int dest = test_main(ac, av);

    cr_assert_eq(dest, 84);
}
