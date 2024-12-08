#ifndef __POST__H__
#define __POST__H__
#include"comment.h"
#define BUFFER 100

typedef struct postElement{
    char Username[BUFFER];
    char Caption[BUFFER];
    commentList* commentHead;
}postElement;
typedef struct Post{
    postElement* data;
    struct Post* next;
    struct Post* prev;
}Post;
typedef struct postList{
    Post* head;
    Post* tail;
}postList;

Post* createPost(char* username,char* caption);
postList* createpostList();
void deletePostList(postList* l);
#endif