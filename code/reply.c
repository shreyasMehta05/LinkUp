#include"reply.h"
Reply* createReply(char* username,char* content){
    Reply* R=(Reply*) malloc(sizeof(Reply));
    if(R==NULL){
        return NULL;
    }
    R->data=(replyElement*) malloc(sizeof(replyElement));
    
    strcpy(R->data->Username,username);
    strcpy(R->data->Content,content);
    R->next=NULL;
    R->prev=NULL;
    return R;
}
replyList* createreplyList(){
    replyList* r=(replyList*) malloc(sizeof(replyList));
    if(r==NULL){
        return NULL;
    }
    r->head=((Reply*)malloc(sizeof(Reply)));
    r->tail=(Reply*)malloc(sizeof(Reply));
    if(r->head==NULL||r->tail==NULL){
        if(r->head!=NULL) free(r->head);
        if(r->tail!=NULL) free(r->tail);
        free(r);
        return NULL;
    }
    r->head->data=NULL;
    r->tail->data=NULL;
    r->head->prev=NULL;
    r->tail->next=NULL;
    r->head->next=r->tail;
    r->tail->prev=r->head;
    return r;
}
void deleteReplyList(replyList* r){
    if(r==NULL){
        return;
    }
    Reply* temp=r->head;
    while(temp!=r->tail){
        Reply* temp1=temp;
        temp=temp->next;
        if(temp1->data!=NULL)
        free(temp1->data);
        free(temp1);
    }
    free(r->tail);
    free(r);
}