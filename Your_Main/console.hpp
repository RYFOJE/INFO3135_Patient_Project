#pragma once

#include <iostream>
#include <sstream>
#include <string>
#include <filesystem>
#include <stdexcept>

namespace console {
	
	void print_main_menu();

	// OTHERS

	/**
	 * @brief	Return an integer from the console
	 * @return	integer written by the user
	*/
	int read_int();

	/**
	 * @brief Clears the console screen
	*/
	void clear_screen();

	/**
	 * @brief			Wait for the user to press enter
	 * @param message	Message to display before waiting for enter
	*/
	void wait_for_enter(std::string const message = "");

	/**
	 * @brief			Get a valid filepath from the user
	 * @param isInput	True if the file is an input file, false if it is an output file
	 * @return			Valid filepath
	*/
	std::filesystem::path get_filepath(bool const isInput = true);

}
