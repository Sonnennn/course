
#ifndef MENU_H
#define MENU_H

#include "struct.h"
#include "work_with_list.h"
void Menu_main();
void Menu(Head *head);

void Menu_copy(Head *head);

void Menu_edit(Head *head);

void Menu_add(Head *head);

void Menu_delete(Head *head);

void Menu_end(Head *head);

void Menu_sort(Head *head);

void Menu_swap(Head *head);

void Menu_search(Head *head);

Head *Menu_add_first();



#endif