#include "calc.h"
#include "menu.h"
#include "utils.h"

int main(void)
{
    main_menu();
    return 0;
}

void main_menu(void) {
    print_main_menu();
    int input = get_user_input();
    select_menu_item(input);
}