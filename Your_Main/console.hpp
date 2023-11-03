#pragma once
namespace console {
	
	void print_main_menu();

	// ADD PATIENT MENU

	void add_patient_menu();
	
	void add_patient_ailment();

	// OTHERS

	int read_int();

	void clear_screen();

	void wait_for_enter(std::string const message = "");

}
