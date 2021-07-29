//
//  main.c
//  Integer_Storage_Program_by_Linked_List
//
//  Created by 세광 on 2021/07/29.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int number;
    struct node *link;
} NODE;

int Get_Total(NODE *ptr_head);
void Print_All(NODE *ptr_head);

NODE *Search_Node(NODE *ptr_head, int pos);
NODE *Search_Last(NODE *ptr_head);
NODE *Search_Prev(NODE *ptr_head, int pos);

NODE *Append_Node(NODE *ptr_head, NODE *ptr_new);
NODE *Insert_Node(NODE *ptr_head, NODE *ptr_prev, NODE *ptr_new);
NODE *Delete_Node(NODE *ptr_head, NODE *ptr_prev, NODE *ptr_curr);
NODE *Reverse_Node(NODE *ptr_head);

int main() {
    NODE *ptr_head = NULL;
    NODE *ptr_new = NULL;
    
    ptr_new = (NODE *)malloc(sizeof(NODE));
    ptr_new->number = 10;
    ptr_new->link = NULL;
    ptr_head = Append_Node(ptr_head, ptr_new);
    
    ptr_new = (NODE *)malloc(sizeof(NODE));
    ptr_new->number = 20;
    ptr_new->link = NULL;
    ptr_head = Append_Node(ptr_head, ptr_new);
    
    ptr_new = (NODE *)malloc(sizeof(NODE));
    ptr_new->number = 30;
    ptr_new->link = NULL;
    ptr_head = Append_Node(ptr_head, ptr_new);
    
    ptr_new = (NODE *)malloc(sizeof(NODE));
    ptr_new->number = 40;
    ptr_new->link = NULL;
    ptr_head = Append_Node(ptr_head, ptr_new);
    
    ptr_new = (NODE *)malloc(sizeof(NODE));
    ptr_new->number = 50;
    ptr_new->link = NULL;
    ptr_head = Insert_Node(ptr_head, Search_Prev(ptr_head, 3), ptr_new);
    // 삭제 함수, 검색 함수들을 사용
    // ptr_head = Delete_Node(ptr_head, Search_Prev(ptr_head, 4), Search_Node(ptr_head, 4));
    
    Print_All(ptr_head);
    printf("\n[역순 정렬]\n");
    Reverse_Node(ptr_head);
    return 0;
}

int Get_Total(NODE *ptr_head) {
    int total = 0;
    NODE *ptr_curr = ptr_head;
    while (ptr_curr != NULL) {
        total++;
        ptr_curr = ptr_curr->link;
    }
    return total;
}

void Print_All(NODE *ptr_head) {
    int num = 1;
    NODE *ptr_curr = ptr_head;
    printf("----------------------------------\n");
    printf("번호\t 주소\t 데이터 필드\t 링크 필드\n");
    printf("----------------------------------\n");
    while (ptr_curr != NULL) {
        printf("  %d\t%x\t   %d\t\t  %x\n", num++, ptr_curr, ptr_curr->number, ptr_curr->link);
        ptr_curr = ptr_curr->link;
    }
    printf("----------------------------------\n");
    printf("총 %d개\n", Get_Total(ptr_head));
    printf("----------------------------------\n");
}

NODE *Search_Node(NODE *ptr_head, int pos) {
    NODE *ptr_curr = ptr_head;
    if (pos > 0 && pos <= Get_Total(ptr_head)) {
        for (int i = 1; i < pos; i++) {
            ptr_curr = ptr_curr->link;
        }
    }
    return ptr_curr;
}

NODE *Search_Last(NODE *ptr_head) {
    NODE *ptr_last = ptr_head;
    if (ptr_head == NULL) {
        ptr_last = ptr_head;
    } else {
        while (ptr_last->link != NULL) {
            ptr_last = ptr_last->link;
        }
    }
    return ptr_last;
}

NODE *Search_Prev(NODE *ptr_head, int pos) {
    NODE *ptr_prev = ptr_head;
    if (pos <= 1) {
        ptr_prev = NULL;
    } else if (pos > 1 && pos <= Get_Total(ptr_head)) {
        for (int i = 1; i < pos - 1; i++) {
            ptr_prev = ptr_prev->link;
        }
    } else {
        ptr_prev = Search_Last(ptr_head);
    }
    return ptr_prev;
}

NODE *Append_Node(NODE *ptr_head, NODE *ptr_new) {
    NODE *ptr_last = NULL;
    if (ptr_head == NULL) {
        ptr_head = ptr_new;
    } else {
        ptr_last = Search_Last(ptr_head);
        ptr_last->link = ptr_new;
    }
    return ptr_head;
}

NODE *Insert_Node(NODE *ptr_head, NODE *ptr_prev, NODE *ptr_new) {
    if (ptr_prev == NULL) {
        ptr_new->link = ptr_head;
        ptr_head = ptr_new;
    } else {
        ptr_new->link = ptr_prev->link;
        ptr_prev->link = ptr_new;
    }
    return ptr_head;
}

NODE *Delete_Node(NODE *ptr_head, NODE *ptr_prev, NODE *ptr_curr) {
    if (ptr_prev == NULL) {
        ptr_head = ptr_curr->link;
    } else {
        ptr_prev->link = ptr_curr->link;
    }
    free(ptr_curr);
    return ptr_head;
}

NODE *Reverse_Node(NODE *ptr_head) {
    NODE *ptr_prev, *ptr_curr, *ptr_next;
    ptr_prev = NULL;
    ptr_next = NULL;
    ptr_curr = ptr_head;
    if (ptr_head == NULL) {
        puts("** 노드가 비어 있습니다 **");
        getchar();
        exit(1);
    }
    while (ptr_curr != NULL) {
        ptr_next = ptr_curr->link;
        ptr_curr->link = ptr_prev;
        ptr_prev = ptr_curr;
        ptr_curr = ptr_next;
    }
    ptr_head = ptr_prev;
    Print_All(ptr_head);
    return ptr_head;
}
