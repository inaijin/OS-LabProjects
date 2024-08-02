#include "types.h"
#include "x86.h"
#include "defs.h"
#include "date.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"

int
sys_fork(void)
{
  return fork();
}

int
sys_exit(void)
{
  exit();
  return 0;  // not reached
}

int
sys_wait(void)
{
  return wait();
}

int
sys_kill(void)
{
  int pid;

  if(argint(0, &pid) < 0)
    return -1;
  return kill(pid);
}

int
sys_getpid(void)
{
  return myproc()->pid;
}

int
sys_sbrk(void)
{
  int addr;
  int n;

  if(argint(0, &n) < 0)
    return -1;
  addr = myproc()->sz;
  if(growproc(n) < 0)
    return -1;
  return addr;
}

int
sys_sleep(void)
{
  int n;
  uint ticks0;

  if(argint(0, &n) < 0)
    return -1;
  acquire(&tickslock);
  ticks0 = ticks;
  while(ticks - ticks0 < n){
    if(myproc()->killed){
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}

// return how many clock tick interrupts have occurred
// since start.
int
sys_uptime(void)
{
  uint xticks;

  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}

int
sys_get_queue_number(void)
{
  int pid;
  if(argint(0, &pid) < 0) {
    return -1;
  }
  return get_queue_number(pid);
}

int
sys_change_queue(void)
{
  int pid, queue_num;
  if(argint(0, &pid) < 0 || argint(1, &queue_num) < 0) {
    return -1;
  }
  return change_queue(pid, queue_num);
}

int
sys_print_procs_info(void)
{
  return print_procs_info();
}

int
sys_change_proc_ratio(void)
{
  int pid, R_Prty, R_Arvl, R_Exec, R_size;
  if(argint(0, &pid) < 0 || argint(1, &R_Prty) < 0 || argint(2, &R_Arvl) < 0 || argint(3, &R_Exec) < 0 || argint(4, &R_size) < 0) {
    return -1;
  }
  return change_proc_ratio(pid, R_Prty, R_Arvl, R_Exec, R_size);
}

int
sys_change_sys_ratio(void)
{
  int R_Prty, R_Arvl, R_Exec, R_size;
  if(argint(0, &R_Prty) < 0 || argint(1, &R_Arvl) < 0 || argint(2, &R_Exec) < 0 || argint(3, &R_size) < 0) {
    return -1;
  }
  return change_sys_ratio(R_Prty, R_Arvl, R_Exec, R_size);
}