#pragma once

#include <iostream>
#include <sstream>
#include <string>
#include <filesystem>
#include <stdexcept>

namespace console {
	
	void print_main_menu();

	// OTHERS

	int read_int();

	void clear_screen();

	void wait_for_enter(std::string const message = "");

	std::filesystem::path get_filepath();

}
