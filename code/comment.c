#include"comment.h"
Comment* createComment(char* username,char* content){
    Comment* C=(Comment*) malloc(sizeof(Comment));
    if(C==NULL){
        return NULL;
    }
    C->data=(commentElement*)malloc(sizeof(commentElement));
    C->data->replyHead=createreplyList();
    strcpy(C->data->Username,username);
    strcpy(C->data->Content,content);
    C->data->replyHead=NULL;
    C->next=NULL;
    C->prev=NULL;
    return C;
}
commentList* createcommentList(){
    commentList* l=(commentList*)malloc(sizeof(commentList));
    if(l==NULL){
        return NULL;
    }
    l->head=(Comment*)malloc(sizeof(Comment));
    l->tail=(Comment*)malloc(sizeof(Comment));
    if(l->head==NULL||l->tail==NULL){
        return false;
    }
    l->head->data=NULL;
    l->tail->data=NULL;
    l->head->next=l->tail;
    l->tail->prev=l->head;
    l->head->prev=NULL;
    l->tail->next=NULL;
    return l;
}
void deleteCommentList(commentList* l){
    if(l==NULL){
        return;
    }
    Comment* temp=l->head;
    while(temp!=l->tail){
        Comment* temp1=temp;
        temp=temp->next;
        if(temp1->data && temp1->data->replyHead!=NULL)
        deleteReplyList(temp1->data->replyHead);
        if(temp1->data!=NULL)
        free(temp1->data);
        free(temp1);
    }
    free(l->tail);
    free(l);
}

