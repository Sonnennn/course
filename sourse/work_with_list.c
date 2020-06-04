
#include "../header/struct.h"
#include "../header/output.h"
#include "../header/work_with_list.h"
#include "../header/work_with_data_and_memory.h"
Node *select_by_id(Head *head, int n) { // поиск нужного узла по номеру
    Node *node;
    int k;

    node = head->first;
    k = head->cnt;
    if (n > k) n = k;
    if (n == 0) n = 1;
    if ((n > 0) && (n <= k)) {// проходим по списку пока не дойдем до нужного номера
        while ((node->id) != n)
            node = node->next;
    } else node = NULL;
    return node;// возвращаем указатель на этот узел
}

void delete_selected(Head *head, Node *current_node) {// удаление определенного узла
    Node *temp;
    int flag;
    if (current_node==head->first){
        current_node->next->prev=NULL;
        head->first=current_node->next;
    temp = head->first;
    while (temp != NULL)// обновляем номера узлов
    {
        temp->id--;
        temp = temp->next;
    }
    } else if (current_node==head->last){
        current_node->prev->next=NULL;
        head->last=current_node->prev;
    } else {
        current_node->next->prev=current_node->prev;
    current_node->prev->next=current_node->next;
    temp=current_node->next;
        while (temp != NULL)// обновляем номера узлов
        {
            temp->id--;
            temp = temp->next;
        }

    }

    free(current_node->name);// очищаем память под узел
    free(current_node->type);
    free(current_node);
    head->cnt--;
}

void insert_after(Head *head, Node *new_node, Node *current_node) {// вставка узла после текущего
    Node *node_temp;
        if(current_node==head->last){
            current_node->next=new_node;
            new_node->prev=current_node;
            new_node->next=NULL;

        } else
        {
            new_node->next=current_node->next;
            new_node->prev=current_node;
            current_node->next=new_node;
        }
        new_node->id = current_node->id + 1;
        node_temp = new_node;
        while (node_temp !=NULL) {// проходим по списку увеличивая номера узлов
            node_temp->id++;
            node_temp = node_temp->next;


        }
        head->cnt++;


}


void insert_before(Head *head, Node *new_node, Node *current_node) {// вставка узла перед определенным элементом
    Node *node_temp;
    // обновляем указатели на следующий и предыдущий узлов рядом
        if (current_node == head->first)// если это новый первый элемент обновляем голову списка
        {
            head->first = new_node;
            new_node->next=current_node;
            new_node->prev=NULL;
            current_node->prev=new_node;
        }else
            {
            current_node->prev->next=new_node;
            new_node->prev=current_node->prev;
            new_node->next=current_node;
            current_node->prev=new_node;
            }

        new_node->id = current_node->id;
        node_temp = new_node->next;
        while (node_temp!= NULL) {// проходим по списку увеличивая номера узлов
            node_temp->id++;
            node_temp=node_temp->next;



        }

        head->cnt++;


}

void copy_node(Head *head, Node *new_node, int k) {// копирование данных из одного узла в другой
    Node *temp = NULL;
    if (k > head->cnt) {// если это вставка на последнее место
        temp = select_by_id(head, k);// ищем узел который стоит на нужном месте
        insert_after(head, new_node, temp);// вставляем после него
    } else {// иначе вставляем перед искомым
        temp = select_by_id(head, k);
        insert_before(head, new_node, temp);
    }
    head->cnt++;

}


void sort_by_ascending(Head *head,int field){
    Node*swap1=NULL,*swap2=NULL;
    if (field==1){
        sort_by_field(head, weight, swap1, swap2, >)
    }
    if (field==2){
        sort_by_field(head, calories, swap1, swap2, >)
    }
    if (field==3){
        sort_by_field(head, micro[0], swap1, swap2, >)
    }
    if (field==4){
        sort_by_field(head, micro[1], swap1, swap2, >)
    }
    if (field==5){
        sort_by_field(head, micro[2], swap1, swap2, >)
    }
}
void sort_by_descending(Head *head,int field){
    Node*swap1=NULL,*swap2=NULL;
    if (field==1){
        sort_by_field(head, weight, swap1, swap2, <)
    }
    if (field==2){
        sort_by_field(head, calories, swap1, swap2, <)
    }
    if (field==3){
        sort_by_field(head, micro[0], swap1, swap2, <)
    }
    if (field==4){
        sort_by_field(head, micro[1], swap1, swap2, <)
    }
    if (field==5){
        sort_by_field(head, micro[2], swap1, swap2, <)
    }
}

void swap_node(Head *head,Node* first,Node *second){
    Node* temp=NULL;
    int id;
    int div;
    if (first->id>second->id){
        div=first->id-second->id;
    }else{
                div=second->id-first->id;
}
if (div>1){
    if (first ==head->first&&second ==head->last){
        first->next->prev=second;
        second->next=first->next;
        first->next=NULL;
        first->prev=second->prev;
        second->prev->next=first;
        second->prev=NULL;
        head->first=second;
        head->last=first;

    } else {if(first==head->last&&second==head->first){
        second->next->prev=first;
        first->next=second->next;
        second->next=NULL;
        second->prev=first->prev;
        first->prev->next=second;
        first->prev=NULL;
        head->first=first;
        head->last=second;
    }}
    if(first==head->first&&second!=head->last){
        first->next->prev=second;
        second->next->prev=first;
        second->prev->next=first;
        first->prev=second->prev;
        second->prev=NULL;
        temp=second->next;
        second->next=first->next;
        first->next=temp;
        head->first=second;

    }else{
    if(second==head->first&&first!=head->last){
        second->next->prev=first;
        first->next->prev=second;
        first->prev->next=second;
        second->prev=first->prev;
        first->prev=NULL;
        temp=first->next;
        first->next=second->next;
        second->next=temp;
        head->first=first;

    }}
    if(first==head->last&&second!=head->first){
        first->prev->next=second;
        second->next->prev=first;
        second->prev->next=first;
        first->next=second->next;
        second->next=NULL;
        temp=second->prev;
        second->prev=first->prev;
        first->prev=temp;
        head->last=second;

    }else{
    if(second==head->last&&first!=head->first){
        second->prev->next=first;
        first->next->prev=second;
        first->prev->next=second;
        second->next=first->next;
        first->next=NULL;
        temp=first->prev;
        first->prev=second->prev;
        second->prev=temp;
        head->last=first;

    }}
    if (first!=head->last&&first!=head->first&&second!=head->last&&second!=head->first){
        first->next->prev=second;
        first->prev->next=second;
        second->next->prev=first;
        second->prev->next=first;
        temp=first->next;
        first->next=second->next;
        second->next=temp;
        temp=first->prev;
        first->prev=second->prev;
        second->prev=temp;



    }}else {
    if (first ==head->first){
        first->next=second->next;
        second->next->prev=first;
        first->prev=second;
        second->prev=NULL;
        second->next=first;
        head->first=second;

    } else if(second==head->first){
        second->next=first->next;
        first->next->prev=second;
        second->prev=first;
        first->prev=NULL;
        first->next=second;
        head->first=first;
    }
    if(first==head->last){
        second->prev->next=first;
        first->prev=second->prev;
        first->next=second;
        second->prev=first;
        second->next=NULL;
        head->last=second;
    } else if(second==head->last){
        first->prev->next=second;
        second->prev=first->prev;
        second->next=first;
        first->prev=second;
        first->next=NULL;
        head->last=first;
    }
    if (second!=head->last&&second!=head->first&&first!=head->first&&first!=head->last){
        first->prev->next=second;
        second->next->prev=first;
        first->next=second->next;
        second->next=first;
        second->prev=first->prev;
        first->prev=second;
    }




}
    id=first->id;
    first->id=second->id;
    second->id=id;


}
Head *search_by_string(Head *head,int flag,char* string){
    Head* new_head=NULL;
    Node* temp=NULL;
    Node* temp_prev=NULL;
    Node* new_node=NULL;
    char** node_dates=NULL;
    int count=0;
    if (flag==1){
        new_head=make_head();
        temp=head->first;
        while(temp!=NULL){
            if (strstr(temp->name,string)!=NULL){
                count++;
                node_dates=scan_date(temp);
                new_node = create_node(node_dates, count);
                if (count==1){
                    new_head->first=new_node;
                    new_node->prev=NULL;
                    new_head->cnt=count;
                }
                if( count>1){
                    temp_prev->next=new_node;
                    new_node->prev=temp_prev;

                }
                temp_prev=new_node;

            }
            temp=temp->next;
        }
        new_head->last=temp_prev;
        new_head->last->next=NULL;
        new_head->cnt=count;
    }
    if(flag==2){
        temp=head->first;
        while(temp!=NULL){
            if (strstr(string,temp->name)==NULL){
                delete_selected(head,temp);
            }
            temp=temp->next;
        }

    }
    printf("%d",new_head->cnt);
    if (new_head->cnt==0)
    {
        free(new_head);
        new_head=NULL;
    }

    return(new_head);
}