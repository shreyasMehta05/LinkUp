# 📚 **LinkUp : Linking the Social World with Doubly Linked Lists**  
### 🌐 **SOCIAL MEDIA PLATFORM**

**👤 Name:** Shreyas Mehta  
**🆔 Roll No:** 2023101059  
**🧑‍🤝‍🧑 Group:** 2  

---
- This project was part of the **Data Structures & Algorithms** course at **IIIT Hyderabad**.

## 📑 **Table of Contents**
- [📖 Introduction](#📖-introduction)
- [📂 Files Structure](#📂-files-structure)
- [🏗️ Structs](#🏗️-structs)
  - [📦 Platform Struct](#📦-platform-struct)
  - [📜 Post Struct](#📜-post-struct)
  - [💬 Comment Struct](#💬-comment-struct)
  - [🔗 Reply Struct](#🔗-reply-struct)
- [🔠 Macros](#🔠-macros)
- [🌐 Global Variables](#🌐-global-variables)
- [🛠️ User Commands](#🛠️-user-commands)
  - [1️⃣ create_platform](#1️⃣-create_platform)
  - [2️⃣ add_post username caption](#2️⃣-add_post-username-caption)
  - [3️⃣ delete_post number](#3️⃣-delete_post-number)
  - [4️⃣ current_post](#4️⃣-current_post)
  - [5️⃣ previous_post](#5️⃣-previous_post)
  - [6️⃣ next_post](#6️⃣-next_post)
  - [7️⃣ view_post number](#7️⃣-view_post-number)
  - [8️⃣ add_comment](#8️⃣-add_comment)
  - [9️⃣ delete_comment](#9️⃣-delete_comment)
  - [🔟 view_all_comments](#🔟-view_all_comments)
  - [🔢 add_reply](#🔢-add_reply)
  - [🗑️ delete_reply](#🗑️-delete_reply)
  - [🚪 exit](#🚪-exit)
- [💻 Code Structure & Data Structure Implementations](#💻-code-structure--data-structure-implementations)
  - [🤔 Motivation for Doubly Linked List](#🤔-motivation-for-doubly-linked-list)
- [🔧 Inbuilt Functions](#🔧-inbuilt-functions)
- [🔍 Example Usage](#🔍-example-usage)
- [📜 Print Functions](#📜-print-functions)
- [📌 Assumptions](#📌-assumptions)

---

## 📖 **Introduction**
This project simulates a simple **social media platform** with functionalities for managing posts, comments, and replies. It is implemented in **C**, leveraging **doubly linked lists** for efficient traversal and manipulation of data.

---

## 📂 **Files Structure**

| File         | Description                               |
|--------------|-------------------------------------------|
| **main.c**   | Handles user interaction and main logic.  |
| **platform.h/c** | Implements platform structure and core functionalities. |
| **post.h/c** | Manages post-related operations.          |
| **comment.h/c** | Handles comment-related operations.     |
| **reply.h/c** | Manages reply-related operations.        |

---

## 🏗️ **Structs**

### 📦 **Platform Struct**
```c
typedef struct Platform {
    postList* postHead;       // Head of the doubly linked list of posts
    Post* lastViewedPost;     // Pointer to the last viewed post
} Platform;
```

### 📜 **Post Struct**
```c
typedef struct postElement {
    char Username[BUFFER];    // Username of the post author
    char Caption[BUFFER];     // Caption of the post
    commentList* commentHead; // Pointer to the list of comments
} postElement;

typedef struct Post {
    postElement* data;        // Post data
    struct Post* next;        // Next post
    struct Post* prev;        // Previous post
} Post;
```

### 💬 **Comment Struct**
```c
typedef struct commentElement {
    char Username[BUFFER];    // Username of the comment author
    char Content[BUFFER];     // Content of the comment
    replyList* replyHead;     // Pointer to the list of replies
} commentElement;

typedef struct Comment {
    commentElement* data;     // Comment data
    struct Comment* next;     // Next comment
    struct Comment* prev;     // Previous comment
} Comment;
```

### 🔗 **Reply Struct**
```c
typedef struct replyElement {
    char Username[BUFFER];    // Username of the reply author
    char Content[BUFFER];     // Content of the reply
} replyElement;

typedef struct Reply {
    replyElement* data;       // Reply data
    struct Reply* next;       // Next reply
    struct Reply* prev;       // Previous reply
} Reply;
```

---

## 🔠 **Macros**
```c
#define BUFFER 100
```
- **Purpose:** Defines the maximum length of strings (e.g., usernames, captions, content).  
- **Usage:** Modify this value to adjust the buffer size as needed.

---

## 🌐 **Global Variables**
```c
Platform* platform;               // Pointer to the platform instance
static bool __COUNT_VIEW_POST__ = false; // Tracks last viewed post
static bool __PLATFORM_INIT__ = false;  // Ensures platform is initialized only once
```

---

## 🛠️ **User Commands**

### 1️⃣ **create_platform**
- **Description:** Initializes the platform.  
- **Usage:**  
  ```bash
  create_platform
  ```
- ⚠️ **Note:** This should be called only once at the start.

---

### 2️⃣ **add_post username caption**
- **Description:** Adds a new post to the platform.  
- **Usage:**  
  ```bash
  add_post @username #caption
  ```
- **Example:**  
  ```bash
  add_post @Shreyas "Hello, world!"
  ```

---

### 3️⃣ **delete_post number**
- **Description:** Deletes the nth recent post.  
- **Usage:**  
  ```bash
  delete_post #number
  ```

---

### 4️⃣ **current_post**
- **Description:** Views the `lastViewedPost`.  
- **Usage:**  
  ```bash
  current_post
  ```

---

### 5️⃣ **previous_post**
- **Description:** Views the next added post relative to the `lastViewedPost`.  
- **Usage:**  
  ```bash
  previous_post
  ```

---

### 6️⃣ **next_post**
- **Description:** Views the previously added post relative to the `lastViewedPost`.  
- **Usage:**  
  ```bash
  next_post
  ```

---

### 7️⃣ **view_post number**
- **Description:** Views details of the nth recent post.  
- **Usage:**  
  ```bash
  view_post #number
  ```

---

### 8️⃣ **add_comment**
- **Description:** Adds a comment to the `lastViewedPost`.  
- **Usage:**  
  ```bash
  add_comment @username #content
  ```

---

### 9️⃣ **delete_comment**
- **Description:** Deletes the nth recent comment on the `lastViewedPost`.  
- **Usage:**  
  ```bash
  delete_comment #number
  ```

---

### 🔟 **view_all_comments**
- **Description:** Views all comments (and replies) on the `lastViewedPost`.  
- **Usage:**  
  ```bash
  view_all_comments
  ```

---

### 🔢 **add_reply**
- **Description:** Adds a reply to the nth comment on the `lastViewedPost`.  
- **Usage:**  
  ```bash
  add_reply @username #content #comment_number
  ```

---

### 🗑️ **delete_reply**
- **Description:** Deletes the nth reply of the mth comment on the `lastViewedPost`.  
- **Usage:**  
  ```bash
  delete_reply #comment_number #reply_number
  ```

---

### 🚪 **exit**
- **Description:** Exits the program and frees all allocated memory.  
- **Usage:**  
  ```bash
  exit
  ```

---

## 💻 **Code Structure & Data Structure Implementations**
The platform uses **doubly linked lists** for managing posts, comments, and replies. This structure allows for:  
1. **Efficient traversal** in both directions.  
2. **Constant-time insertion** and deletion at either end.  

---

### 🤔 **Motivation for Doubly Linked List**
- Allows **bidirectional traversal**, crucial for navigating posts (e.g., next, previous).  
- Simplifies implementation of features like deleting specific posts, comments, or replies.

---

## 🔧 **Inbuilt Functions**
```c
postList* createpostList();    // Initializes post list
void deletePostList(postList* l); // Frees memory of post list

commentList* createcommentList(); // Initializes comment list
void deleteCommentList(commentList* l); // Frees memory of comment list

replyList* createreplyList();    // Initializes reply list
void deleteReplyList(replyList* r); // Frees memory of reply list

void input_string(char* str);   // Reads a sentence input from the user
```

---

## 📜 **Print Functions**
```c
void printReply(replyList* r);    // Prints replies
void printPost(Post* p);          // Prints posts
void printComment(Comment* c);    // Prints comments and replies


```

---

## 📌 **Assumptions**
1. **`create_platform`** is always the first command and is called only once.  
2. Maximum string length (for usernames, captions, content) is **100 characters** (modifiable via `BUFFER` macro).  
3. If a post is deleted, the `lastViewedPost` points to the most recent post.  
4. Usernames are single words without spaces.  

--- 

## 🛠️ **Build Instructions**  

### **Requirements**  
Ensure you have the following installed on your system:  
- A C compiler (e.g., `gcc`)  
- `make` utility (for running the Makefile)  

---

### **Steps to Build the Project on Windows**  

1. **Navigate to the Project Directory**  
   Open your terminal (Command Prompt or PowerShell) and navigate to the root folder of this project, which contains the `Makefile`.  

2. **Run the Build Command**  
   Execute the following command:  
   ```bash
   make
   ```  
   This will compile all the source files located in the `code/` directory and produce an executable named `myprogram.exe`.  

3. **Run the Program**  
   After a successful build, run the program using:  
   ```bash
   ./myprogram.exe
   ```  

4. **Clean the Build**  
   To remove the compiled executable and object files, run:  
   ```bash
   make clean
   ```  
   This will delete all `.o` files and the `myprogram.exe` executable.  

---

### **File Structure**  

- **Source Files Directory**: `code/`  
  Contains all the `.c` source files.  
- **Makefile**: Handles the build process for compiling and linking the project.  

---

💡 **Note:** If you're using an OS other than Windows, replace `del /Q` in the `clean` rule of the `Makefile` with `rm -f` for compatibility.

---

🎉 **Enjoy exploring your very own social media platform!**
---