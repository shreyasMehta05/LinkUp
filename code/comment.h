#ifndef __COMMENT__H__
#define __COMMENT__H__
#include"reply.h"
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#define BUFFER 100

typedef struct commentElement{
    char Username[BUFFER];
    char Content[BUFFER];
    replyList* replyHead;
}commentElement;
typedef struct Comment{
    commentElement* data;
    struct Comment* next;
    struct Comment* prev;
}Comment;
typedef struct commentList{
    Comment* head;
    Comment* tail;
}commentList;
Comment* createComment(char* username,char* content);
commentList* createcommentList();
void deleteCommentList(commentList* l);
#endif