#pragma once
#ifndef WORK_WITH_LIST_H
#define WORK_WITH_LIST_H


#define sort_by_field(head, field, swap1, swap2, sign) for (int i=1;i<=head->cnt-1;i++){\
            for (int j=1;j<=head->cnt-1;j++){\
                swap1 = select_by_id(head,j);\
                swap2 = select_by_id(head,j+1);\
                if(swap1->field sign swap2->field){\
                    swap_node(head,swap1,swap2);\
                }\
            }\
        }

#include "struct.h"

Node *select_by_id(Head *head, int n);

void delete_selected(Head *head, Node *current_node);

void insert_after(Head *head, Node *new_node, Node *current_node);

void insert_before(Head *head, Node *new_node, Node *current_node);

void copy_node(Head *head, Node *new_node, int k);
void sort_by_descending(Head *head,int field);

void swap_node(Head* head, Node* first, Node* second);
void sort_by_ascending(Head *head,int field);

#endif
