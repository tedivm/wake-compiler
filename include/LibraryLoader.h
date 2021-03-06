/**************************************************
 * Source Code for the Original Compiler for the
 * Programming Language Wake
 *
 * LibraryLoader.h
 *
 * Licensed under the MIT license
 * See LICENSE.TXT for details
 *
 * Author: Michael Fairhurst
 * Revised By:
 *
 **************************************************/

#ifndef HEADER_LIBRARY_LOADER
#define HEADER_LIBRARY_LOADER

#include "ClassSpaceSymbolTable.h"
#include "PropertySymbolTable.h"

extern "C" {
	#include "type.h"
}

class LibraryLoader {

	public:
		bool loadImport(string importname, string importpath, ClassSpaceSymbolTable& objtable);
		void loadStdLibToTable(ClassSpaceSymbolTable* table);

};

#endif
