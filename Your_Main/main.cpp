#include "singleton.hpp"

int main(int argc, char* argv[]) {

	// Create a singleton instance
	MainProgram& mainProgram = MainProgram::getInstance();

	// Return 0 to indicate success
	return 0;

}
