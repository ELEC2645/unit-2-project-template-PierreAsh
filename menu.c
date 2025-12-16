#include "menu.h"
#include "calc.h"
#include "utils.h"

void print_main_menu(void)
{
    printf("\n----------- Main menu -----------\n");
    printf("\n"
           "\t\t\t\t\t\t\n"
           "\t1. Addition\t\t\n"
           "\t2. Subtraction\t\t\n"
           "\t3. Multiplication\t\t\n"
           "\t4. Division\t\t\n"
           "\t5. Power\t\t\n"
           "\t6. Square Root\t\t\n"
           "\t7. Modulo\t\t\n"
           "\t8. Factorial\t\t\n"
           "\t9. Logarithm\t\t\n"
           "\t10. Percentage\t\t\n"
           "\t11. Sine\t\t\n"
           "\t12. Cosine\t\t\n"
           "\t13. Tangent\t\t\n"
           "\t14. Inverse Sine\t\t\n"
           "\t15. Inverse Cosine\t\t\n"
           "\t16. Inverse Tangent\t\t\n"
           "\t17. Exit\t\t\t\t\n"
           "\t\t\t\t\t\t\n");
    printf("---------------------------------------------\n");
}

int get_user_input(void){
    int choice;
    for (;;) {
        printf("\nselect menu: ");
        if (scanf("%d", &choice) != 1) {
            flush_input_buffer();
            printf("Invalid input. Enter a number between 1 and 17.\n");
            continue;
        }
        flush_input_buffer();

        if (choice < 1 || choice > 17) {
            printf("Invalid menu item. Enter a number between 1 and 17.\n");
            continue;
        }

        return choice;
    }
}

void select_menu_item(int choice){
    switch(choice) {
        case 1: addition(); break;
        case 2: subtraction(); break;
        case 3: multiplication(); break;
        case 4: division(); break;
        case 5: power(); break;
        case 6: square_root(); break;
        case 7: modulo(); break;
        case 8: factorial(); break;
        case 9: logarithm(); break;
        case 10: percentage(); break;
        case 11: sine(); break;
        case 12: cosine(); break;
        case 13: tangent(); break;
        case 14: inverse_sine(); break;
        case 15: inverse_cosine(); break;
        case 16: inverse_tangent(); break;
        case 17: printf("Exiting program...\n"); exit(0);
        default: printf("Invalid selection. Exiting...\n"); exit(1);
    }
}

void go_back_to_main(void) {
    char input;

    do {
        printf("\nEnter 'b' or 'B' to go back to main menu: ");
        if(scanf("%c", &input) != 1) {
            flush_input_buffer();
        }
        else {
            flush_input_buffer();
        }
    } while (input != 'b' && input != 'B');

    main_menu();  
}