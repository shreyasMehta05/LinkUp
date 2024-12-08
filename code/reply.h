#ifndef __REPLY__H__
#define __REPLY__H__
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#define BUFFER 100
typedef struct replyElement{
    char Username[BUFFER];
    char Content[BUFFER];
}replyElement;

typedef struct Reply{
    replyElement* data;    
    struct Reply* next;
    struct Reply* prev;
}Reply;
typedef struct replyList{
    Reply* head; 
    Reply* tail;
} replyList;

Reply* createReply(char* username,char* content);
replyList* createreplyList();
void deleteReplyList(replyList* r);
#endif