#include "singleton.hpp"

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>


int main(int argc, char* argv[]) {

	// Create a singleton instance
	MainProgram& mainProgram = MainProgram::getInstance();

	_CrtDumpMemoryLeaks();

	// Return 0 to indicate success
	return 0;

}
