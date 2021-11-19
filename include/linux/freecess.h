#ifndef KFRECESS_H
#define KFRECESS_H

#include <linux/sched.h>

#define KERNEL_ID_NETLINK      0x12341234
#define UID_MIN_VALUE          10000
#define MSG_NOOP               0
#define LOOPBACK_MSG           1
#define KFREEMSG_CALLBACK      2
#define MSG_TO_USER            3
#define MSG_TYPE_END           4

#define MOD_NOOP               0
#define MOD_BINDER             1
#define MOD_SIG                2
#define MOD_END                3 

struct kfreecess_msg_data
{
	int type;
	int mod;
	int src_portid;
	int dst_portid;
	int caller_pid;
	int target_uid;
	int flag;
};

int sig_report(struct task_struct *caller, struct task_struct *p);
int binder_report(struct task_struct *caller, struct task_struct *p, int flag);
#endif