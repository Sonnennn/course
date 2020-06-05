

#include "../header/struct.h"
#include "../header/work_with_data_and_memory.h"

void clear() {
#if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
    system("clear");
#endif

#if defined(_WIN32) || defined(_WIN64)
    system("cls");
#endif
}

Head *make_head() {// создание головы списка
    Head *head = NULL;

    head = (Head *) malloc(sizeof(Head));
    if (head) {
        head->cnt = 0;
        head->first = NULL;
        head->last = NULL;
    }
    return head;
}

char **scan_node() { // ввод элементов нового узла списка
    char **str_array = NULL;
    str_array = (char **) malloc((8) * sizeof(char *));// выделяем память для массива строк
    printf("\nEnter your dates:\n");
    for (int i = 0; i < 7; i = i + 1) {
        fflush(stdin);
        if (i == 0) {
            printf("Section:");
            str_array[i] = safe_scan_string();
        }
        if (i == 1) {
            printf("Product:");
            str_array[i] = safe_scan_string();
        }
        if (i == 2) {
            printf("Weight:");
            str_array[i] = safe_scan_int();
        }
        if (i == 3) {
            printf("Calories:");
            str_array[i] = safe_scan_float();
        }
        if (i == 4) {
            printf("Protein:");
            str_array[i] = safe_scan_float();
        }
        if (i == 5) {
            printf("Fat:");
            str_array[i] = safe_scan_float();
        }
        if (i == 6) {
            printf("Carbohydrates:");
            str_array[i] = safe_scan_float();
        }

    }

    return
            str_array;// возвращаем указатель на массив строк
}

void Free_Node(Head *head) {// освобождение памяти под список
    Node *temp_node = NULL;
    Node *temp = NULL;
    temp_node = head->first;
    while (temp_node != NULL) {// проходим по списку и освобождаем память пока не дойдем до конца
        free(temp_node->name);
        free(temp_node->type);
        temp = temp_node->next;
        free(temp_node);
        temp_node = temp;
    }
    free(head);
}

Node *create_node(char **str, int id) // инициализация узла
{
    Node *new_node = NULL; // выделяем память под узел и заполняем его и массива строк
    new_node = (Node *) malloc(sizeof(Node));
    new_node->id = id;
    new_node->name = str[0];
    new_node->type = str[1];
    new_node->weight = strtol(str[2], NULL, 10);
    new_node->calories = strtod(str[3], NULL);
    new_node->micro[0] = strtod(str[4], NULL);
    new_node->micro[1] = strtod(str[5], NULL);
    new_node->micro[2] = strtod(str[6], NULL);
    new_node->next = NULL;
    new_node->prev = NULL;
    free(str[2]);
    free(str[3]);
    free(str[4]);
    free(str[5]);
    free(str[6]);
    free(str);
    return new_node; // возвращаем адрес узла
}

char **simple_split(char *str, int length, char sep) { // разделение строки на части
    char **str_array = NULL;
    int i, j, k, m;
    int key;
    for (j = 0, m = 0; j < length; j++) {
        if (str[j] == sep) m++;// считаем кол-во знаков разделителей
    }

    key = 0;
    str_array = (char **) malloc((m + 1) * sizeof(char *));// выделяем память под массив строк
    if (str_array != NULL) {
        for (i = 0; i <= m; i++) {
            str_array[i] = (char *) malloc(length * sizeof(char));
            if (str_array[i] != NULL) key = 1;// проходим по строке ища знак разделитель
            else {
                key = 0;
                i = m;
            }
        }
        if (key) {
            k = 0;
            m = 0;
            for (j = 0; j < length; j++) {// как только знак нашелся , заполняем соответствующее элемент массива строк
                if (str[j] != sep) str_array[m][j - k] = str[j];
                else {
                    str_array[m][j - k] = '\0';
                    k = j + 1;
                    m++;
                }
            }

        }
    }
    str_array[m][j - k] = '\0';
    return str_array;// возвращаем указатель на массив строк
}

char **scan_date(Node *node) {//создает массив строк с данными переданного узла

    int length = 100;
    char **str_array = NULL;
    str_array = (char **) malloc(7 * sizeof(char *));// выделяем память под массив строк
    if (str_array != NULL) {
        for (int i = 0; i < 7; i++) {
            str_array[i] = (char *) malloc(length * sizeof(char));// выделяет память под сами строки
        }
        strcpy(str_array[0], node->name);// заполняет сами строки данными из полей узла
        strcpy(str_array[1], node->type);
        sprintf(str_array[2], "%d", node->weight);
        sprintf(str_array[3], "%.2f", node->calories);
        sprintf(str_array[4], "%.2f", node->micro[0]);
        sprintf(str_array[5], "%.2f", node->micro[1]);
        sprintf(str_array[6], "%.2f", node->micro[2]);
    }
    return (str_array);
}

char *safe_scan_int() {
    char *str = NULL;
    int n = 0;
    int temp;
    unsigned int slen;
    do {
        str = malloc(100 * sizeof(char));
        if (str != NULL) {
            fflush(stdin);
            n = 0;
            fgets(str, 100, stdin);
            printf("\n");
            slen = strlen(str);
            for (int i = 0; i < slen - 1; i++) {
                temp = str[i];
                if (temp < '0' || temp > '9') n++;
            }
            if (n > 0) {
                printf("incorrect integer number, try again\n");
                free(str);
                printf("Your integer number");
            }
        }
    } while (n > 0);


    return (str);
}

char *safe_scan_float() {
    char *str = NULL;
    int n = 0;
    int m = 0;
    int temp;
    unsigned int slen;
    char *search = NULL;
    do {
        str = malloc(100 * sizeof(char));
        if (str != NULL) {
            fflush(stdin);
            n = 0;
            m = 0;
            fgets(str, 100, stdin);
            slen = strlen(str);
            for (unsigned int i = 0; i < slen - 1; i++) {
                temp = str[i];
                if (temp < 48 || temp > 57)n++;
                if (str[i] == '.')m++;
            }
            if (str[0] == '.')m++;
            n = n - m;
            if (n > 0 || m > 1) {
                printf("incorrect float number, try again\n");
                free(str);
                printf("Your float number:");
            }
        }
    } while (n > 0 || m > 1);
    if (m == 1) {
        search = strchr(str, '.');
        str[search - str + 3] = '\0';
    } else
        str[strlen(str) - 1] = '\0';
    return (str);
}

char *safe_scan_string() {
    char *str = NULL;
    int n = 0;
    int temp;
    unsigned int slen;

    do {
        str = malloc(100 * sizeof(char));
        if (str != NULL) {
            fflush(stdin);
            n = 0;
            fgets(str, 100, stdin);

            slen = strlen(str);
            for (unsigned int i = 0; i < slen; i++) {
                temp = str[i];
                if (temp >= 48 && temp <= 57)n++;
            }

            if (str[0] == ' ')n++;
            if (str[strlen(str) - 2] == ' ')n++;
            if (n > 0) {
                free(str);
                printf("incorrect string, try again\n");
                printf("Your string:");
            }
        }
        n = 0;
    } while (n > 0);
    str[strlen(str) - 1] = '\0';
    return (str);
}
