
#include "../header/struct.h"

void print_header() { // вывод разметки таблицы
    printf("| %2s|%15s | %9s | %6s| %9s | %4s | %4s | %4s |\n", "Id", "Section", "Product", "Weight(g)", "Calories",
           "Protein",
           " Fat ", "Carbohydrates");
    printf("+---+----------------+-----------+----------+-----------+---------+-------+---------------+\n");
}

void struct_out(Node *node) { // вывод полей структуры
    printf("| %2d|%15s | %9s |%9d | %9.2f | %7.2f | %5.2f | %13.2f |\n",
           node->id, node->name, node->type, node->weight, node->calories, node->micro[0],
           node->micro[1],
           node->micro[2]);
}


void Print_Node(Head *head) {// вывод списка
    print_header();
    Node *node = NULL;
    node = head->first;
    while (node != NULL) {// проход по списку с головы выводя каждый узел
        struct_out(node);
        node = node->next;
    }
    printf("\n");
}

void Print_help() {
    printf("\nIn the main menu you can choose: \n"
           "Open already generated list from file\n"
           "Create new list\n");
    printf("\n The program allows you to work with a list of data\n using the following steps:\n"
           "Add a new card , you will be prompted to enter the data of this card\n"
           "Edit the card fields you want\n"
           "Remove an unnecessary card from the list\n"
           "Copy some card and paste in the right place\n"
           "Swap two cards\n"
           "Sort list by selected attribute\n"
           "Find the cards you need using the search by fields, \n"
           "the result of the search is a new list with which you can do all the same actions\n"
           "Save the result of work to a file with the name you entered\n");

}

void Print_search(char **str) {
    printf("Searching dates:\n");
    if (str[0] != NULL) {
        printf("Section: %s\n", str[0]);
    }
    if (str[1] != NULL) {
        printf("Product: %s\n", str[1]);
    }
    if (str[2] != NULL && str[3] != NULL) {
        printf("Weight: [%s..%s]\n", str[3], str[2]);
    }
    if (str[4] != NULL && str[5] != NULL) {
        printf("Calories: [%s..%s]\n", str[5], str[4]);
    }
    if (str[6] != NULL && str[7] != NULL) {
        printf("Protein: [%s..%s]\n", str[7], str[6]);
    }
    if (str[8] != NULL && str[9] != NULL) {
        printf("Fat: [%s..%s]\n", str[9], str[8]);
    }
    if (str[10] != NULL && str[11] != NULL) {
        printf("Carbohydrates: [%s..%s]\n", str[11], str[10]);
    }


}