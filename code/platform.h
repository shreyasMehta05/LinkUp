#ifndef __PLATFORM__H__
#define __PLATFORM__H__
#include"post.h"


// Platform* platform;
typedef struct Platform{
    postList* postHead;
    Post* lastViewedPost;
}Platform;

Platform* createPlatform();
bool addPost(char* username,char* caption);
bool deletePost(int n);
Post* viewPost(int n);
Post* currPost();
Post* nextPost();
Post* prevPost();
bool addComment(char* username,char* content);
bool deleteComment(int n);
Comment* viewComments();
bool addReply(char* username,char* content,int n);
bool deleteReply(int n,int m);
void destroyPlatform();
#endif