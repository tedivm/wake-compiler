#ifndef HEADER_OBJECT_SYM_TABLE
#define HEADER_OBJECT_SYM_TABLE

#include <utility>
#include <string>
#include <map>
#include <vector>
#include "SemanticError.h"
#include "PropertySymbolTable.h"
#include "TypeAnalyzer.h"
#include "EntryPointAnalyzer.h"
#include "AddressAllocator.h"

using namespace std;

class ObjectSymbolTable {
	public:
		ObjectSymbolTable();
		~ObjectSymbolTable();

		void addClass(string name);
		void addInheritance(string child, bool issubclass);
		void propagateInheritance();
		void propagateInheritanceToParent(string childname);
		PropertySymbolTable* find(string name);
		void assertTypeIsValid(Type* type);
		TypeAnalyzer* getAnalyzer();
		void printEntryPoints(EntryPointAnalyzer* entryanalyzer);

	private:
		AddressAllocator alloc;
		PropertySymbolTable* addingclass_symbol;
		std::string addingclass_name;
		bool addingclass_hassubclass;
		map<string, pair<PropertySymbolTable*, string> > classes;
		map<string, pair<PropertySymbolTable*, bool> > inheritances_gathered;
		TypeAnalyzer analyzer;
};

#endif
