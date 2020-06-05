
#include "../header/struct.h"
#include "../header/work_with_data_and_memory.h"
#include "../header/output.h"

Head *read_from_file() {// создание списка данных из файла
    Head *head = NULL;
    Node *node = NULL, *node_temp = NULL;
    int maxlen = 128;
    int slen, i, str, sep_count = 0;
    char **s2 = NULL;
    char file_name[maxlen];
    char s1[maxlen];
    char sep = ';';
    char chr;
    char end[5] = ".txt";
    char *file_name_result;
    FILE *file = NULL;
    printf("Enter file name: ");// считываем имя файла
    fgets(file_name, maxlen, stdin);
    file_name[strlen(file_name) - 1] = '\0';
    file_name_result = strcat(file_name, end);
    file = fopen(file_name_result, "r");
    if (file != NULL) {
        str = 0, sep_count = 0;
        printf("\n");
        while ((chr = fgetc(file)) != '\n') {
            if (chr == sep) sep_count++;
        }

        if (sep_count == 6) {
            rewind(file);
            while ((fgets(s1, maxlen, file)) != NULL) str++;
            rewind(file);// считаем количество строк в файле
            // читаем данные из файла и заполняем структуру
            head = make_head();
            for (i = 1; i < str + 1; i++) {
                fgets(s1, maxlen, file); // берем одну строку
                slen = strlen(s1);
                s2 = simple_split(s1, slen, sep); // разбиваем ее на части
                node = create_node(s2, i);// создаем элемент списка
                if (i == 1) {// если это первый элемент, то указатель на него помещаем в Head
                    head->first = node;
                    head->cnt = i;
                }
                if (i > 1) {
                    node_temp->next = node;// указатель на новый элемент
                    node->prev = node_temp;
                }
                node_temp = node;// запоминаем указатель на прошлый элемент

            }
            head->last = node;// заносим последний элемент в Head
            head->last->next = NULL;
            head->first->prev = NULL;
            head->cnt = head->last->id;// номер последнего элемента - кол-во элементов
            fclose(file);
        } else printf("wrong type file");
    } else puts("File not found!");
    return (head);
}

void save_file(Head *head) {// запись списка в файл
    Node *temp = NULL;
    int maxlen = 128;
    FILE *out_file = NULL;
    char out_file_name[maxlen];
    char *file_name;
    char end[5] = ".txt";
    printf("\n");
    fflush(stdin);
    printf("Which file you wanna save result to: ");// считываем имя файла
    fgets(out_file_name, maxlen, stdin);
    printf("\n");
    out_file_name[strlen(out_file_name) - 1] = '\0';
    file_name = strcat(out_file_name, end);
    out_file = fopen(file_name, "w");// открываем файл для записи
    temp = head->first;
    while (temp != NULL) {// пока не конеч списка заносим данные с узлов
        fprintf(out_file, "%s;%s;%d;%.2f;%.2f;%.2f;%.2f\n", temp->name, temp->type, temp->weight, temp->calories,
                temp->micro[0], temp->micro[1], temp->micro[2]);
        temp = temp->next;
    }
    fclose(out_file);

}