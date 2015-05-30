/*
 * threadmanager.cc
 *
 *  Created on: May 29, 2015
 *      Author: jasonwayne
 */
#include "threadmanager.h"

void printThread(int arg) {
	Thread *thread = (Thread *)arg;
	const char* status[4] = {"Created", "Running", "Ready", "Blocked"};
	printf(" %8d | %16s | %6d | %s \n",
			thread->getThreadID(),
			thread->getName(),
			thread->getUserID(),
			status[thread->getStatus()]);
}

ThreadManager::ThreadManager() {
	threadList = new List;
}

ThreadManager::~ThreadManager() {
	delete threadList;
}

Thread *
ThreadManager::createThread(char *debugName) {
	Thread *newThread = NULL;

	int tid = generateThreadID();
	if (tid == -1) {
		return NULL;
	} else {
		newThread = new Thread(debugName, tid);
		newThread->setPriority(PRIORITY_MID);
//		threadList->SortedInsert((void *)newThread, tid);
	}
	return newThread;
}

void
ThreadManager::deleteThread(Thread *thread) {
	if (thread != NULL) {
		int tid = thread->getThreadID();
		threadMap[tid] = 0;
//		threadList->RemoveElement(thread);
		delete thread;
	}
}

// return -1 if threads reaches max count
int
ThreadManager::generateThreadID() {
	for (int i = 0; i < THREAD_MAX_COUNT; i++) {
		if (threadMap[i] == 0) {
			threadMap[i] = 1;
			return i;
		}
	}
	return -1;
}

void
ThreadManager::printThreads()
{
	printf(" ThreadID |    ThreadName    | UserID | Status \n");
	printf(" -------- | ---------------- | ------ | ------ \n");

	threadList->Mapcar((VoidFunctionPtr)printThread);


}



