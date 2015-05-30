/*
 * threadmanager.h
 *
 *  Created on: May 29, 2015
 *      Author: jasonwayne
 */

#ifndef THREADS_THREADMANAGER_H_
#define THREADS_THREADMANAGER_H_

#include "list.h"
#include "thread.h"

#define THREAD_MAX_COUNT 128

class ThreadManager {
public:
	ThreadManager();
	~ThreadManager();

	Thread *createThread(char *debugName);
	void deleteThread(Thread *thread);

	int generateThreadID();
	void printThreads();

private:
	int threadMap[THREAD_MAX_COUNT];
	List *threadList;
};





#endif /* THREADS_THREADMANAGER_H_ */
