
#include "../header/struct.h"
#include "../header/menu.h"
#include "../header/work_with_list.h"
#include "../header/work_with_data_and_memory.h"
#include "../header/output.h"
#include "../header/work_with_file.h"

void Menu(Head *head) {// вывод меню действий
    int flag = 0;
    char *flag_temp = NULL;
    void (*kind[9])(Head *);// массив указателей на функцию для удобства
    kind[0] = Menu_add;
    kind[1] = Menu_edit;
    kind[2] = Menu_delete;
    kind[3] = Menu_copy;
    kind[4] = Menu_swap;
    kind[5] = Menu_sort;
    kind[6] = Menu_search;
    kind[7] = save_file;
    kind[8] = Menu_end;
    clear();
    do {// вывод возможных действий
        if (head->cnt != 0) {
            printf("\n");
            Print_Node(head);
            printf("What do you wanna do?\n");
            printf("1 - add card \n");
            printf("2 - edit card \n");
            printf("3 - delete card\n");
            printf("4 - copy card\n");
            printf("5 - swap card\n");
            printf("6 - sort list\n");
            printf("7 - search by field\n");
            printf("8 - save result\n");
            printf("9 - back\n");
            while (flag < 1 || flag > 9) {
                flag_temp = safe_scan_int();
                flag = strtol(flag_temp, NULL, 10);
                free(flag_temp);
                if (flag < 1 || flag > 9) printf("wrong choice");
            }


            kind[flag - 1](head);
            if (flag != 9) flag = 0;
            clear();
        } else {
            printf("\nList is empty\n");
            flag = 9;
        }
    } while (flag != 9);

}

void Menu_copy(Head *head) {// меню операции копирования
    Node *node, *new_node;
    char **node_dates;
    int paste = 0;
    int copy = 0;
    char *copy_temp = NULL, *paste_temp = NULL;

    while ((copy > head->cnt) || (copy < 1)) {
        printf("which card id you wanna to copy:");
        copy_temp = safe_scan_int();
        copy = strtol(copy_temp, NULL, 10);
        free(copy_temp);// считываем номер узла который нужно скопировать
        if (copy > head->cnt || copy < 1) {
            printf("wrong card id, try again\n");
        }
    }
    printf("\n");
    node = select_by_id(head, copy);// ищем этот узел
    node_dates = scan_date(node);
    new_node = create_node(node_dates, 1);

    while ((paste > head->cnt + 1) || (paste < 1)) {
        printf("which card id you want to paste:");
        paste_temp = safe_scan_int();
        paste = strtol(paste_temp, NULL, 10);
        free(paste_temp);// считываем номер узла перед которым нужно вставить
        if (paste > head->cnt + 1 || paste < 1) {
            printf("wrong card id , try again\n");
        }
    }
    printf("%d", head->cnt);
    printf("\n");
    copy_node(head, new_node, paste);// выполняем копирование и вставку
}


void Menu_add(Head *head) {// меню для операции добавление после
    Node *new_node, *node;
    char **str_array;
    int id = 0;
    char *id_temp = NULL;
    clear();
    Print_Node(head);
    printf("which card id you wanna put to:");
    while ((id > head->cnt + 1) || (id < 1)) {
        id_temp = safe_scan_int();
        id = strtol(id_temp, NULL, 10);
        free(id_temp);// считываем номер узла после которого нужно добавить
        if (id > head->cnt + 1 || id < 1) {
            printf("wrong card, try again\n");
            printf("which card id you wanna put to:");
        }
    }
    printf("\n");
    str_array = scan_node();// вводим информации для узла
    new_node = create_node(str_array, 1);// создаем узел
    node = select_by_id(head, id);// ищем указатель по номеру
    insert_before(head, new_node, node);// вставляем после найденного узла новый


}

void Menu_delete(Head *head) {// меню для операции удаления
    Node *node;
    int id = 0;
    char *id_temp = NULL;
    printf("which card you wanna delete:");
    while ((id > head->cnt) || (id < 1)) {
        id_temp = safe_scan_int();
        id = strtol(id_temp, NULL, 10);
        free(id_temp);// считываем номер узла который нужно удалить
        if (id > head->cnt || id < 1) {
            printf("wrong card , try again\n");
            printf("which card you wanna delete:");
        }
    }
    printf("\n");
    node = select_by_id(head, id);// ищем на него указатель
    delete_selected(head, node);// удаляем из списка


}


void Menu_edit(Head *head) {
    Node *node;
    int id = 0;
    int flag = 0;
    int temp_int;
    double temp_double;
    char *flag_temp = NULL;
    char *id_temp = NULL;
    char *str = NULL;

    printf("which card you wanna edit:");
    while ((id > head->cnt) || (id < 1)) {
        id_temp = safe_scan_int();
        id = strtol(id_temp, NULL, 10);
        free(id_temp);
        if (id > head->cnt || id < 1) {
            printf("wrong card id , try again\n");
            printf("which card you wanna edit:");
        }
    }
    printf("\n");
    node = select_by_id(head, id);// ищем на него указатель
    do {
        system("clear");
        print_header();
        struct_out(node);
        printf("\n");
        printf("What do you wanna edit:\n");
        printf("1 - section\n");
        printf("2 - product\n");
        printf("3 - weight\n");
        printf("4 - calories\n");
        printf("5 - protein\n");
        printf("6 - fat\n");
        printf("7 - carbohydrates\n");
        printf("8 - back\n");
        flag_temp = safe_scan_int();
        flag = strtol(flag_temp, NULL, 10);
        free(flag_temp);
        if (flag == 1) {
            do {
                printf("New section:");
                str = safe_scan_string();
                printf("\n");
            } while (str == NULL);
            free(node->name);
            node->name = str;
        }
        if (flag == 2) {
            do {
                printf("New product:");
                str = safe_scan_string();
                printf("\n");
            } while (str == NULL);
            free(node->type);
            node->type = str;
        }
        if (flag == 3) {
            do {
                printf("New weight:");
                str = safe_scan_int();
                printf("\n");
            } while (str == NULL);
            temp_int = strtol(str, NULL, 10);
            free(str);
            node->weight = temp_int;
        }
        if (flag == 4) {
            do {
                printf("New calories:");
                str = safe_scan_float();
                printf("\n");
            } while (str == NULL);
            temp_double = strtod(str, NULL);
            free(str);
            node->calories = temp_double;
        }
        if (flag == 5) {
            do {
                printf("New proteint:");
                str = safe_scan_float();
                printf("\n");
            } while (str == NULL);
            temp_double = strtod(str, NULL);
            free(str);
            node->micro[0] = temp_double;
        }
        if (flag == 6) {
            do {
                printf("New fat:");
                str = safe_scan_float();
                printf("\n");
            } while (str == NULL);
            temp_double = strtod(str, NULL);
            free(str);
            node->micro[1] = temp_double;
        }
        if (flag == 7) {
            do {
                printf("New carbohydrates:");
                str = safe_scan_float();
                printf("\n");
            } while (str == NULL);
            temp_double = strtod(str, NULL);
            free(str);
            node->micro[2] = temp_double;
        }


    } while (flag != 8);

}

void Menu_end(Head *head) {

}

void Menu_swap(Head *head) {
    Node *first_node = NULL, *second_node = NULL;
    int second = 0;
    int first = 0;
    char *first_temp = NULL, *second_temp = NULL;
    clear();
    Print_Node(head);
    if (head->cnt > 1) {
        printf("which card you wanna swap:\n");
        while ((first > head->cnt) || (first < 1)) {
            printf("First:\n");
            first_temp = safe_scan_int();
            first = strtol(first_temp, NULL, 10);
            free(first_temp);// считываем номер узла который нужно скопировать
            if (first > head->cnt || first < 1) {
                printf("wrong card , try again\n");
            }
        }
        while ((second > head->cnt) || (second < 1)) {
            printf("Second:");
            second_temp = safe_scan_int();
            second = strtol(second_temp, NULL, 10);
            free(second_temp);// считываем номер узла перед которым нужно вставить
            if (second > head->cnt || second < 1) {
                printf("wrong card id , try again\n");
            }
        }
        first_node = select_by_id(head, first);
        second_node = select_by_id(head, second);
        printf("\n");
        swap_node(head, first_node, second_node);
    } else printf("You should have 2 or more card\n");
}


void Menu_sort(Head *head) {
    int flag = 0;
    int kind = 0;
    char *kind_temp = NULL;
    char *flag_temp = NULL;
    clear();
    Print_Node(head);
    printf("\n");
    printf("What field should be sort:\n");
    printf("1 - weight\n");
    printf("2 - calories\n");
    printf("3 - protein\n");
    printf("4 - fat\n");
    printf("5 - carbohydrates\n");
    while ((flag > 5) || (flag < 1)) {
        printf("Enter your choice:");
        flag_temp = safe_scan_int();
        flag = strtol(flag_temp, NULL, 10);
        free(flag_temp);
        if (flag > 5 || flag < 1)
            printf("wrong choice, try again\n");
    }
    printf("Kinds of sort:\n");
    printf("1 - Descending\n");
    printf("2 - Ascending\n");
    while ((kind > 2) || (kind < 1)) {
        printf("Enter your choice:");
        kind_temp = safe_scan_int();
        kind = strtol(kind_temp, NULL, 10);
        free(kind_temp);
        if (kind > 2 || kind < 1)
            printf("wrong choice, try again\n");
    }
    if (kind == 2)
        sort_by_ascending(head, flag);
    if (kind == 1)
        sort_by_descending(head, flag);


}

void Menu_search(Head *head) {
    Head *new_head = NULL;
    int flag = 0;
    int count = 0;
    char *flag_temp = NULL;
    char *search;
    float max, min;
    char **str_search = NULL;
    str_search = (char **) malloc(12 * sizeof(char *));
    for (int i = 0; i < 12; i++) {
        str_search[i] = NULL;
    }
    do {
        clear();
        Print_Node(head);
        count = 0;
        for (int i = 0; i < 12; i++) {
            if (str_search[i] != NULL)
                count++;
        }
        if (count > 0)
            Print_search(str_search);

        printf("\n");
        printf("What field you wanna search :\n");
        printf("1 - Section\n");
        printf("2 - Product\n");
        printf("3 - Weight\n");
        printf("4 - Calories\n");
        printf("5 - Protein\n");
        printf("6 - Fat\n");
        printf("7 - Carbohydrates\n");
        printf("8 -  Start search\n");
        while ((flag > 8) || (flag < 1)) {
            printf("Enter your choice:");
            flag_temp = safe_scan_int();
            flag = strtol(flag_temp, NULL, 10);
            free(flag_temp);
            if (flag > 8 || flag < 1)
                printf("wrong choice, try again\n");
        }
        if (flag == 1) {
            printf("\nSearching Section:");
            if (str_search[0] == NULL) {
                search = safe_scan_string();
                str_search[0] = search;
            } else {
                free(str_search[0]);
                search = safe_scan_string();
                str_search[0] = search;
            }
            if (new_head == NULL) {
                new_head = search_by_string(head, 1, search, flag);
            } else new_head = search_by_string(new_head, 2, search, flag);

        }
        if (flag == 2) {
            printf("\nSearching Product:");
            if (str_search[1] == NULL) {
                search = safe_scan_string();
                str_search[1] = search;
            } else {
                free(str_search[1]);
                search = safe_scan_string();
                str_search[1] = search;
            }
            if (new_head == NULL) {
                new_head = search_by_string(head, 1, search, flag);
            } else new_head = search_by_string(new_head, 2, search, flag);
        }
        if (flag == 3) {
            printf("\nSearching Weight:\n");
            printf("Maximum range value:\n");
            if (str_search[2] == NULL) {
                search = safe_scan_float();
                str_search[2] = search;
                max = strtof(search, NULL);
            } else {
                free(str_search[2]);
                search = safe_scan_float();
                str_search[2] = search;
                max = strtof(search, NULL);
            }
            printf("Minimum range value:\n");
            if (str_search[3] == NULL) {
                search = safe_scan_float();
                str_search[3] = search;
                min = strtof(search, NULL);
            } else {
                free(str_search[3]);
                search = safe_scan_float();
                str_search[3] = search;
                min = strtof(search, NULL);
            }
            if (new_head == NULL) {
                new_head = search_by_number(head, 1, max, min, flag);
            } else new_head = search_by_number(new_head, 2, max, min, flag);
        }
        if (flag == 4) {
            printf("\nSearching Calories:\n");
            printf("Maximum range value:\n");
            if (str_search[4] == NULL) {
                search = safe_scan_float();
                str_search[4] = search;
                max = strtof(search, NULL);
            } else {
                free(str_search[4]);
                search = safe_scan_float();
                str_search[4] = search;
                max = strtof(search, NULL);
            }
            printf("Minimum range value:\n");
            if (str_search[5] == NULL) {
                search = safe_scan_float();
                str_search[5] = search;
                min = strtof(search, NULL);
            } else {
                free(str_search[5]);
                search = safe_scan_float();
                str_search[5] = search;
                min = strtof(search, NULL);
            }
            if (new_head == NULL) {
                new_head = search_by_number(head, 1, max, min, flag);
            } else new_head = search_by_number(new_head, 2, max, min, flag);
        }
        if (flag == 5) {
            printf("\nSearching Protein:\n");
            printf("Maximum range value:\n");
            if (str_search[6] == NULL) {
                search = safe_scan_float();
                str_search[6] = search;
                max = strtof(search, NULL);
            } else {
                free(str_search[6]);
                search = safe_scan_float();
                str_search[6] = search;
                max = strtof(search, NULL);
            }
            printf("Minimum range value:\n");
            if (str_search[7] == NULL) {
                search = safe_scan_float();
                str_search[7] = search;
                min = strtof(search, NULL);
            } else {
                free(str_search[7]);
                search = safe_scan_float();
                str_search[7] = search;
                min = strtof(search, NULL);
            }
            if (new_head == NULL) {
                new_head = search_by_number(head, 1, max, min, flag);
            } else new_head = search_by_number(new_head, 2, max, min, flag);
        }
        if (flag == 6) {
            printf("\nSearching Fat:\n");
            printf("Maximum range value:\n");
            if (str_search[8] == NULL) {
                search = safe_scan_float();
                str_search[8] = search;
                max = strtof(search, NULL);
            } else {
                free(str_search[8]);
                search = safe_scan_float();
                str_search[8] = search;
                max = strtof(search, NULL);
            }
            printf("Minimum range value:\n");
            if (str_search[9] == NULL) {
                search = safe_scan_float();
                str_search[9] = search;
                min = strtof(search, NULL);
            } else {
                free(str_search[9]);
                search = safe_scan_float();
                str_search[9] = search;
                min = strtof(search, NULL);
            }
            if (new_head == NULL) {
                new_head = search_by_number(head, 1, max, min, flag);
            } else new_head = search_by_number(new_head, 2, max, min, flag);
        }
        if (flag == 7) {
            printf("\nSearching Carbohydrates:\n");
            printf("Maximum range value:\n");
            if (str_search[10] == NULL) {
                search = safe_scan_float();
                str_search[10] = search;
                max = strtof(search, NULL);
            } else {
                free(str_search[10]);
                search = safe_scan_float();
                str_search[10] = search;
                max = strtof(search, NULL);
            }
            printf("Minimum range value:\n");
            if (str_search[11] == NULL) {
                search = safe_scan_float();
                str_search[11] = search;
                min = strtof(search, NULL);
            } else {
                free(str_search[11]);
                search = safe_scan_float();
                str_search[11] = search;
                min = strtof(search, NULL);
            }
            if (new_head == NULL) {
                new_head = search_by_number(head, 1, max, min, flag);
            } else new_head = search_by_number(new_head, 2, max, min, flag);
        }
        if (flag != 8) flag = 0;
    } while (flag != 8);

    for (int i = 0; i < 12; i++) {
        if (str_search[i] != NULL)
            free(str_search[i]);
    }
    free(str_search);
    if (new_head != NULL) {
        Menu(new_head);
        Free_Node(new_head);
    } else
        printf("\nNothing was found\n");
}

Head *Menu_add_first() {
    Head *head = NULL;
    clear();
    head = make_head();
    char **new_node = NULL;
    printf("Add your first card\n");
    new_node = scan_node();
    head->first = create_node(new_node, 1);
    head->cnt = 1;
    head->last = head->first;

    return (head);
}

void Menu_main() {
    clear();
    Head *head = NULL;
    Head *(*kind[2])();
    int flag = 0;
    char *flag_temp = NULL;
    kind[0] = read_from_file;
    kind[1] = Menu_add_first;
    clear();
    do {
        printf("\nWhat you wanna do?\n");
        printf("1 - read list from file\n");
        printf("2 - create new list\n");
        printf("3 - for help\n");
        printf("4 - exit\n");
        while (flag < 1 || flag > 4) {
            printf("Enter your choice\n");
            flag_temp = safe_scan_int();
            flag = strtol(flag_temp, NULL, 10);
            free(flag_temp);
            if (flag < 1 || flag > 4) printf("wrong choice");
        }
        if (flag < 3) {
            head = kind[flag - 1]();
            if (head != NULL) {
                Menu(head);
                if (head->cnt != 0)
                    Free_Node(head);
            }
        }
        if (flag == 3) {
            clear();
            Print_help();
        }
        if (flag != 4)flag = 0;
    } while (flag != 4);
    clear();
}