#include "singleton.hpp"
#include "console.hpp"

MainProgram::MainProgram() {
	
	// Print the main menu on singleton load
	console::print_main_menu();

	// Process Input
	get_main_menu_selection();

}

void MainProgram::get_main_menu_selection() {
	
	int selection;

	while (true) {

		std::cout << "> ";
		std::cin >> selection;
		std::cin.ignore();
		

		switch (selection) {

		case 1:
			MainProgram::add_patient_menu();
			break;

		default:
			console::clear_screen();
			console::print_main_menu();
			
			std::cout << std::endl << std::endl << std::endl;
			
			std::cout << "Invalid selection, please try again" << std::endl;
			break;

		}

	}

}

void MainProgram::add_patient_menu() {

	while (true) {
		
		console::clear_screen();
		std::string patientName;

		// Read ailments until empty
		while (true) {

			std::cout << "Enter Patient Name: ";
			std::getline(std::cin, patientName);

			if (patientName.empty()) return;

		}

	}
	
	console::clear_screen();
	console::print_main_menu();

}

void MainProgram::add_ailment_menu(Patient& patient) {

	while (true) {
		
		

	}
	
}