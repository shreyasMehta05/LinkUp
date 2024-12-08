#include"platform.h"
Platform* platform;
static bool __COUNT_VIEW_POST__=false;
static bool __PLATFORM_INIT__=false;

Platform* createPlatform(){
    if(__PLATFORM_INIT__==true){
        return platform;
    }
    // creates an instance of the platform data type.
    platform=(Platform*) malloc(sizeof(Platform));
    if(platform==NULL){
        exit(0);
    }
    platform->postHead=createpostList();
    platform->lastViewedPost=NULL;
    __PLATFORM_INIT__=true;
    return platform;
}

bool addPost(char* username,char* caption){
    // create a post and adds it to the existing list
    Post* p=createPost(username,caption);
    if(p==NULL){ 
        return false;
    }
    platform->postHead->tail->prev->next=p;
    p->prev=platform->postHead->tail->prev;
    p->next=platform->postHead->tail;
    platform->postHead->tail->prev=p;
    if(platform->lastViewedPost==NULL||__COUNT_VIEW_POST__==false){
        platform->lastViewedPost=p;
    }
    return true;
}
bool deletePost(int n){
    // deletes the nth recent post also clears the replies and comments
    Post* curr=platform->postHead->tail;
    if(curr==platform->postHead->head->next||n<=0){
        // printf("No Post to delete\n");
        return false;
    }
    
    if(n==1){
        curr=curr->prev;
        if(curr==platform->lastViewedPost){
                platform->lastViewedPost=curr->prev;
                if(platform->lastViewedPost==platform->postHead->head){
                    platform->lastViewedPost=NULL;
                }
                __COUNT_VIEW_POST__=false;
        }
        curr->prev->next=curr->next;
        curr->next->prev=curr->prev;
        // delete all the comments and replies create some functions here
        deleteCommentList(curr->data->commentHead);
        free(curr->data);
        free(curr);
        // platform->lastViewedPost=platform->postHead->tail->prev;
        return true;
    }
    curr=curr->prev;
    while(platform->postHead->head!=curr){
        if(n==1){
            if(curr==platform->lastViewedPost){
                platform->lastViewedPost=platform->postHead->tail->prev;
                if(platform->lastViewedPost==platform->postHead->head){
                    platform->lastViewedPost=NULL;
                }
                __COUNT_VIEW_POST__=false;

            }
            curr->prev->next=curr->next;
            curr->next->prev=curr->prev;
            // delete all the comments and replies create some functions here
            deleteCommentList(curr->data->commentHead);
            free(curr->data);
            free(curr);
            return true;
        }
        curr=curr->prev;
        n--;
    }
    return false;

}
Post* viewPost(int n){
    // returns the nth recent post else return NULL
    Post* curr=platform->postHead->tail;
    if(curr==platform->postHead->head->next){
        // printf("No Post to view\n");
        return NULL;
    }
    if(n<=0){
        // printf("Invalid inex!\n");
        return NULL;
    }
    while(platform->postHead->head!=curr){
        curr=curr->prev;
        n--;
        if(n==0){
            platform->lastViewedPost=curr;
            __COUNT_VIEW_POST__=true;
            return curr;
        }
    }
    return NULL;
}
Post* currPost(){
    // returns the current post i.e the last_viewed post
    __COUNT_VIEW_POST__=true;
    return platform->lastViewedPost;
}
Post* nextPost(){
    // returns the post which was just posted before the 
    if(platform->lastViewedPost==NULL){ 
        // printf("No Post to View\n");
        return NULL;
    }
    if(platform->lastViewedPost->prev==platform->postHead->head){
        __COUNT_VIEW_POST__=true;
        return platform->lastViewedPost;
    }
    platform->lastViewedPost=platform->lastViewedPost->prev;
    __COUNT_VIEW_POST__=true;
    return platform->lastViewedPost;
}
Post* prevPost(){
    // returns the post which is generated after the current post
    if(platform->lastViewedPost==NULL) return NULL;
    if(platform->lastViewedPost->next==platform->postHead->tail){
        __COUNT_VIEW_POST__=true;
        return platform->lastViewedPost;
    }
    platform->lastViewedPost=platform->lastViewedPost->next;
    __COUNT_VIEW_POST__=true;
    return platform->lastViewedPost;
}
bool addComment(char* username,char* content){
  Comment* new= createComment(username,content);
  if(new==NULL) return false;
  if(platform->lastViewedPost==NULL){

    return false;
  }
  commentList* temp;
  if(platform->lastViewedPost->data->commentHead==NULL){
    temp=platform->lastViewedPost->data->commentHead=createcommentList();
  }
  else{
    temp=platform->lastViewedPost->data->commentHead;
  }
    temp->tail->prev->next=new;
    new->prev=temp->tail->prev;
    new->next=temp->tail;
    temp->tail->prev=new;
    return true;
  
}
bool deleteComment(int n){
    if(platform->lastViewedPost==NULL || platform->lastViewedPost->data==NULL || platform->lastViewedPost->data->commentHead==NULL){ 
        return false;
    }
    Comment* curr=platform->lastViewedPost->data->commentHead->tail;
    if(curr==platform->lastViewedPost->data->commentHead->head->next||n<=0){
        return false;
    }
    if(n==1){
        curr=curr->prev;
        curr->prev->next=curr->next;
        curr->next->prev=curr->prev;
        // delete all the  replies create some functions here
        deleteReplyList(curr->data->replyHead);
        free(curr->data);
        free(curr);
        return true;
    }
    while(platform->lastViewedPost->data->commentHead->head!=curr){
        curr=curr->prev;
        n--;
        if(n==0){
            curr->prev->next=curr->next;
            curr->next->prev=curr->prev;
            // delete all the  replies create some functions here
            deleteReplyList(curr->data->replyHead);
            free(curr->data);
            free(curr);
            return true;
        }
    }
        return false;

}
Comment* viewComments(){
    if(platform->lastViewedPost==NULL||platform->lastViewedPost->data==NULL||platform->lastViewedPost->data->commentHead==NULL) return NULL;
    Comment* c=platform->lastViewedPost->data->commentHead->head;
    return c->next; // pointer to 1st node
}
bool addReply(char* username,char* content,int n){
    Reply*new=createReply(username,content);
        if(new==NULL){
            return false;
        }
        if(platform->lastViewedPost!=NULL && platform->lastViewedPost->data!=NULL && platform->lastViewedPost->data->commentHead!=NULL){
            Comment* temp=platform->lastViewedPost->data->commentHead->tail;
            while(temp!=platform->lastViewedPost->data->commentHead->head){
                temp=temp->prev;
                n--;
                if(n==0){
                    if(temp->data->replyHead==NULL){
                        temp->data->replyHead= createreplyList();
                    }
                replyList* curr=temp->data->replyHead;
                
                curr->tail->prev->next=new;
                new->prev=curr->tail->prev;
                new->next=curr->tail;
                curr->tail->prev=new;
                return true;
                }
            }
        return false;
    }
}
bool deleteReply(int n,int m){
    if(platform->lastViewedPost==NULL || platform->lastViewedPost->data==NULL || platform->lastViewedPost->data->commentHead==NULL){ 
        return false;
    }
    Comment* temp=platform->lastViewedPost->data->commentHead->tail;
    while(temp!=platform->lastViewedPost->data->commentHead->head){
        temp=temp->prev;
        n--;
        if(n==0){
            if(temp->data->replyHead==NULL){
                return false;
            }
            Reply* temp1= temp->data->replyHead->tail;
            while(temp1!=temp->data->replyHead->head){
                temp1=temp1->prev;
                m--;
                if(m==0){
                    temp1->next->prev=temp1->prev;
                    temp1->prev->next=temp1->next;
                    free(temp1->data);
                    free(temp1);
                    return true;
                }
            }
            return false;
        }
    }
    return false;
}

void destroyPlatform(){
    // destroys the platform and frees all the memory
        if(platform==NULL){
            return;
        }
        deletePostList(platform->postHead);
        free(platform);
        
}