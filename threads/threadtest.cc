// threadtest.cc 
//	Simple test case for the threads assignment.
//
//	Create two threads, and have them context switch
//	back and forth between themselves by calling Thread::Yield, 
//	to illustratethe inner workings of the thread system.
//
// Copyright (c) 1992-1993 The Regents of the University of California.
// All rights reserved.  See copyright.h for copyright notice and limitation 
// of liability and disclaimer of warranty provisions.

#include "copyright.h"
#include "system.h"

extern ThreadManager *threadManager;

// testnum is set in main.cc
int testnum = 2;

//----------------------------------------------------------------------
// SimpleThread
// 	Loop 5 times, yielding the CPU to another ready thread 
//	each iteration.
//
//	"which" is simply a number identifying the thread, for debugging
//	purposes.
//----------------------------------------------------------------------

void
SimpleThread(int which)
{
    int num;
    
    for (num = 0; num < 5; num++) {
    	printf("*** thread %d looped %d times\n", which, num);
        currentThread->Yield();
    }
}

//----------------------------------------------------------------------
// ThreadTest1
// 	Set up a ping-pong between two threads, by forking a thread 
//	to call SimpleThread, and then calling SimpleThread ourselves.
//----------------------------------------------------------------------

void
ThreadTest1()
{
    DEBUG('t', "Entering ThreadTest1");

//    Thread *t = new Thread("forked thread");
    Thread *t = threadManager->createThread("forked thread");

    t->Fork(SimpleThread, 1);
    SimpleThread(0);
}

//----------------------------------------------------------------------
// ThreadTest
// 	Invoke a test routine.
//----------------------------------------------------------------------

void
ThreadTest2()
{
	DEBUG('t', "Entering ThreadTest2");

	Thread *t1 = threadManager->createThread("Thread1 Low");
	t1->setPriority(PRIORITY_LOW);
	Thread *t2 = threadManager->createThread("Thread2 MID");
	t2->setPriority(PRIORITY_MID);
	Thread *t3 = threadManager->createThread("Thread3 High");
	t3->setPriority(PRIORITY_HIGH);
	Thread *t4 = threadManager->createThread("Thread4 High");
	t4->setPriority(PRIORITY_HIGH);
	Thread *t5 = threadManager->createThread("Thread5 Mid");
	t5->setPriority(PRIORITY_MID);

	t1->Fork(SimpleThread, 1);
	t2->Fork(SimpleThread, 2);
	t3->Fork(SimpleThread, 3);
	t4->Fork(SimpleThread, 4);
	t5->Fork(SimpleThread, 5);

	SimpleThread(0);
}
void
ThreadTest()
{
    switch (testnum) {
    case 1:
    	ThreadTest1();
    	break;
    case 2:
    	ThreadTest2();
    	break;
    default:
    	printf("No test specified.\n");
    	break;
    }
}

