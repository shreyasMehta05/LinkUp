#include "platform.h"
#define BUFFER 100

void printReply(replyList* r);
void printPost(Post* p){
    if(p==NULL||p->data==NULL){
        printf("No Post is available\n");
        return;
    }
    printf("%s\t%s\n",p->data->Username,p->data->Caption);
}
void printComment(Comment* C){
    if(C==NULL){
        printf("No comments Available\n");
        return;
    }
    printf("-> %s\t%s\n",C->data->Username,C->data->Content);
    printReply(C->data->replyHead);
}
void printReply(replyList* r){
    if(r==NULL|| r->head->next==r->tail){
        return;
    }
    Reply* temp=r->head->next;
    while(temp!=r->tail){
        printf("---> %s %s\n",temp->data->Username,temp->data->Content);
        temp=temp->next;
    }
}
void input_string(char* str){
    char c;
    int i=0;
    while((c=getchar())!='\n'){
        str[i++]=c;
    }
    str[i]='\0';
    return;
}

int main(){

    printf("##################################################################################\n");
    printf("Welcome!\n");
    printf("----------------------------------------------------------------------------------\n");
    while(true){
        printf(" Command Lists:\n");
        printf("  1. create_platform\n");
        printf("  2. add_post @username #caption\n");
        printf("  3. delete_post #number\n");
        printf("  4. current_post\n");
        printf("  5. previous_post\n");
        printf("  6. next_post\n");
        printf("  7. view_post #number\n");
        printf("  8. add_comment @username #content\n");
        printf("  9. delete_comment #number\n");
        printf("  10. view_all_comments\n");
        printf("  11. add_reply @username #reply $number\n");
        printf("  12. delete_reply #comment_no. #reply_no.\n");
        printf("  13. exit\n");
        printf("----------------------------------------------------------------------------\n");
        
        char opr[BUFFER];
        scanf("%s",opr);
        if(!strcmp(opr,"create_platform")){
            createPlatform();
            printf("---------------------------------------------------------------------------\n\n");
            printf("Platform Created Successfully!\n");
        }
        else if(!strcmp(opr,"add_post")){
            char user[BUFFER];
            scanf("%s",user);
            char caption[BUFFER];
            input_string(caption);
            // scanf("%s",caption);
            printf("###############################################################################\n\n");
            if(addPost(user,caption)){
                printf("Post Added Successfully!\n");
              }
              else{
                
                printf("Post Not Added\n");
            }
        }
        else if(!strcmp(opr,"delete_post")){
            int n;
            scanf("%d",&n);
            printf("---------------------------------------------------------------------------\n\n");
            if(deletePost(n)){
                printf("Post Deleted Successfully!\n");
            }
            else{
                printf("Post Not Deleted\n");
            }

        }
        else if(!strcmp(opr,"current_post")){
            printf("---------------------------------------------------------------------------\n\n");
            printPost(currPost());
        }
        else if(!strcmp(opr,"previous_post")){
            printf ("---------------------------------------------------------------------------\n");
            printPost(prevPost());
        }
        else if(!strcmp(opr,"next_post")){
            printf("---------------------------------------------------------------------------\n\n");
            printPost(nextPost());
        }
        else if(!strcmp(opr,"view_post")){
            int n;
            scanf("%d",&n);
            printf("---------------------------------------------------------------------------\n\n");
            printPost(viewPost(n));
        }
        else if(!strcmp(opr,"add_comment")){
            char user[BUFFER],content[BUFFER];
            scanf("%s",user);
            // scanf("%s",content);
            input_string(content);
            printf("---------------------------------------------------------------------------\n\n");
            if(addComment(user,content)){
                printf("Comment Added Successfully!\n");
            }
            else{
                printf("Comment Not Added\n");
            }
        }
        else if(!strcmp(opr,"delete_comment")){
            int n;
            scanf("%d",&n);
            printf("---------------------------------------------------------------------------\n\n");
            if(deleteComment(n)){
                printf("Comment Deleted Successfully!\n");
            }
            else{
                printf("Comment Not Deleted\n");
            }
        }
        else if(!strcmp(opr,"view_all_comments")){

            Comment* C=viewComments();
            printf("---------------------------------------------------------------------------\n\n");
            if(C==NULL){   
                printf("No Comments!\n") ;       
            }
            else{
                while(C->data!=NULL){
                    printComment(C);
                    C=C->next;
                }    
            }
            
        }
        else if(!strcmp(opr,"add_reply")){
            char user[BUFFER],content[BUFFER];
            int n=0;
            scanf("%s",user);
            // scanf("%s",content);
            // scanf("%d",&n);
            input_string(content);
            int x=strlen(content)-1;
            int i=1;
            while(content[x]!=' '){
                n=n+(content[x]-'0')*i;
                x--;
                i=i*10;
            }
            content[x]='\0';
            // printf("%d",n);
            printf("---------------------------------------------------------------------------\n\n");
            if(addReply(user,content,n)){
                printf("Reply Added Successfully!\n");
            }
            else{
                printf("Reply Not Added\n");
            
            }
        }
        else if(!strcmp(opr,"delete_reply")){
            int n,m;
            scanf("%d %d",&n,&m);
            printf("---------------------------------------------------------------------------\n\n");
            if(deleteReply(n,m)){
                printf("Reply Deleted Successfully!\n");
            }
            else{
                printf("Reply Not Deleted\n");
            }
        }
        else if(strcmp("exit",opr)==0){
            printf("Exitted Succesfully!\n");
            printf("----------------------------------------------------------------------\n\n");
            destroyPlatform();
            exit(0);
        }
        else{
            printf("----------------------------------------------------------------------\n\n");
            printf(" Enter a valid command!\n");
        }
        printf("\n----------------------------------------------------------------------\n");
    }
    printf("#############################################################################\n\n");
    return 0;
}