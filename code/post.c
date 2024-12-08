#include"post.h"
Post* createPost(char* username,char* caption){
    Post* p= (Post*) malloc(sizeof(Post));
    if(p==NULL){
        return NULL;
    }
    p->data=(postElement*)malloc(sizeof(postElement));
    p->data->commentHead=createcommentList();
    strcpy(p->data->Username,username);
    strcpy(p->data->Caption,caption);
    p->next=NULL;
    p->prev=NULL;
    return p;
}
postList* createpostList(){
    postList* l=(postList*) malloc(sizeof(postList));
    if(l==NULL){
        return false;
    }
    l->head=(Post*)malloc(sizeof(Post));
    l->tail=(Post*)malloc(sizeof(Post));
    if(l->head==NULL||l->tail==NULL){
        return NULL;
    }
    l->head->data=NULL;
    l->head->prev=NULL;
    l->head->next=l->tail;
    l->tail->data=NULL;
    l->tail->prev=l->head;
    l->tail->next=NULL;
    return l;
}
void deletePostList(postList* l){
    if(l==NULL){
        return;
    }
    Post* temp=l->head;
    while(temp!=l->tail){
        Post* temp1=temp;
        temp=temp->next;

        if(temp1->data!=NULL && temp1->data->commentHead!=NULL){
            deleteCommentList(temp1->data->commentHead);
        }

        if(temp1->data!=NULL)
            free(temp1->data);
        free(temp1);
    }
    free(l->tail);
    free(l);
}
