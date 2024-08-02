// Sleeping locks

#include "types.h"
#include "defs.h"
#include "param.h"
#include "x86.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"
#include "spinlock.h"
#include "sleeplock.h"

void
initsleeplock(struct sleeplock *lk, char *name)
{
  initlock(&lk->lk, "sleep lock");
  lk->name = name;
  lk->locked = 0;
  lk->pid = 0;
}

void
acquiresleep(struct sleeplock *lk)
{
  acquire(&lk->lk);
  while (lk->locked) {
    sleep_on_chan(&lk->sleeping, &lk->lk);
    //sleep(lk, &lk->lk);
  }
  lk->locked = 1;
  lk->pid = myproc()->pid;
  release(&lk->lk);
}

void
releasesleep(struct sleeplock *lk)
{
  acquire(&lk->lk);
  if (lk->pid != myproc()->pid) {
    release(&lk->lk);
    return;
  }
  lk->locked = 0;
  lk->pid = 0;
  wakeup_max_pid(&lk->sleeping);
  //wakeup(lk);
  release(&lk->lk);
}

int
holdingsleep(struct sleeplock *lk)
{
  int r;
  
  acquire(&lk->lk);
  r = lk->locked && (lk->pid == myproc()->pid);
  release(&lk->lk);
  return r;
}

void
bubble_up(struct heap* hp, int index)
{ 
  int parent;
  while(1) {
    if(index % 2) {
      parent = (index - 1) / 2;
    }
    else {
      parent = (index - 2) / 2;
    }
    if (parent >= 0 && hp->heap[parent]->pid < hp->heap[index]->pid){
      sawp(&hp->heap[parent], &hp->heap[index]);
      index = parent;
    }
    else {
      break;
    }
  }
}

void
bubble_down(struct heap* hp, int index)
{
  int left, right, max;
  while (1) {
    left = 2 * index + 1;
    right = 2 * index + 2;
    if (left < hp->end && hp->heap[left]->pid > hp->heap[index]->pid) {
      max = left;
    }
    else {
      max = index;
    }
    if ( right < hp->end && hp->heap[right]->pid > hp->heap[max]->pid) {
      max = right;
    }
    if (max != index) {
      sawp(&hp->heap[max], &hp->heap[index]);
      index = max;
    }
    else {
      break;
    }
  }
}

void
push_heap(struct heap *hp,struct proc* p)
{
  hp->heap[hp->end] = p;
  bubble_up(hp, hp->end);
  hp->end++;
}

struct proc*
pop_heap(struct heap *hp)
{
  if(hp->end == 0) {
    return 0;
  }
  struct proc *p;
  p = hp->heap[0];
  hp->end--;
  hp->heap[0] = hp->heap[hp->end];
  bubble_down(hp, 0);
  return p;
}

void
sawp(struct proc* *p, struct proc* *q)
{
  struct proc* temp = *p;
  *p = *q;
  *q = temp;
}