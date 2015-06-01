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
		void setFileIdentifier(int page, int value);
		int  getFileIdentifier(int page);
		void setDirty(int page, bool value);
		bool getDirty(int page);

	private:
		int pageNum;
		BitMap *memoryMap;
		int *lastModifyTime;
		int *fileIdentifier;
		bool *dirty;
};


#endif /* MACHINE_PHYMEMMANAGER_H_ */
