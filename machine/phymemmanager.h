/*
 * phymemmanager.h
 *
 *  Created on: May 31, 2015
 *      Author: jasonwayne
 */

#ifndef MACHINE_PHYMEMMANAGER_H_
#define MACHINE_PHYMEMMANAGER_H_


#include "bitmap.h"

class PhyMemManager
{
	public:
		PhyMemManager(int num);
		~PhyMemManager();

		int FindOnePage();

	private:
		int pageNum;
		BitMap *memoryMap;
		int *lastModifyTime;
};


#endif /* MACHINE_PHYMEMMANAGER_H_ */
