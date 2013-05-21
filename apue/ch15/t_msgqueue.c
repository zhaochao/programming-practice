#include "apue.h"
#include <sys/ipc.h>
#include <sys/msg.h>

#define MAX_TEXT 512

struct my_msg_st {
    long my_msg_type;
    char my_msg_text[MAX_TEXT];
};

int main(void)
{
    int msgid;
    int i;

    for (i = 0; i < 5; i++) {
        if ((msgid = msgget((key_t)1234, 0600 | IPC_CREAT)) < 0)
            err_sys("msgget error");

        printf("newly created message queue's ID is: %d\n", msgid);
        
        printf("now delete it...\n");
        if (msgctl(msgid, IPC_RMID, NULL) == -1)
            err_sys("msgctl delete message queue error");
    }

    for (i = 0; i < 5; i++) {
        if ((msgid = msgget(IPC_PRIVATE, 0600 | IPC_PRIVATE)) < 0)
            err_sys("msgget error");

        printf("newly created message queue's ID is: %d\n", msgid);

        struct my_msg_st temp_msg;
        temp_msg.my_msg_type = 1;
        strcpy(temp_msg.my_msg_text, "test");

        if ((msgsnd(msgid, (void *)&temp_msg, MAX_TEXT, 0)) == -1)
            err_sys("msgsnd error");
        printf("a message sent to the message queue.\n");
    }

    exit(0);
}
