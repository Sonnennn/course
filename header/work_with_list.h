#pragma once
#ifndef WORK_WITH_LIST_H
#define WORK_WITH_LIST_H


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
