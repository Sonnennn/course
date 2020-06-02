#include <stdio.h>
#include "header/work_with_data_and_memory.h"
#include "header/work_with_file.h"
#include "header/menu.h"

int main() {
    Head* head=NULL;
    head=read_from_file();
    if (head!=NULL)
    {
        Menu(head);
        Free_Node(head);
    }
    return 0;
}