#include "singleton.hpp"
#include "console.hpp"

MainProgram::MainProgram() {

	// Process Input
	get_main_menu_selection();

}

void MainProgram::get_main_menu_selection() {
	
	int selection;
	bool isInvalid = false;

	while (true) {
		// Clear the screen
		console::clear_screen();

		// Print the main menu on singleton load
		console::print_main_menu();

		if (isInvalid) {
			std::cout << std::endl << "Invalid selection, please try again" << std::endl;
			isInvalid = false;
		}

		else {
			std::cout << std::endl << std::endl;
		}

		std::cout << "> ";
		selection = console::read_int();
		
		switch (selection) {

		case 1:
			MainProgram::add_patient_menu();
			break;

		case 0:
			return;
			
		default:
			
			isInvalid = true;
			break;

		}

	}

}

void MainProgram::add_patient_menu() {

		

	// Read ailments until empty
	while (true) {

		console::clear_screen();
		std::string patientName;

		std::cout << "Enter Patient Name (leave blank to finish):";
		std::getline(std::cin, patientName);

		// If empty return to menu
		if (patientName.empty()) return;

		Patient tempPatient(patientName);

		add_ailment_menu(tempPatient);

	}

}

void MainProgram::add_ailment_menu(Patient& patient) {

	std::string errorMsg;
	bool isInvalid = false;

	while (true) {
		
		console::clear_screen();
		
		// If the last input was invalid, print the error message
		if (isInvalid) {
			std::cout << errorMsg << std::endl;
			std::cout << "Please Try Again." << std::endl;
			isInvalid = false;
		}

		// Get the ailment name and check if empty
		std::string ailmentName;

		std::cout << "Enter Ailment Name (leave blank to finish): ";
		getline(std::cin, ailmentName);
		
		// If empty return patient
		if (ailmentName.empty()) return;

		// Get severity
		std::cout << "Enter Severity: ";
		int severity = console::read_int();

		// Get time criticality
		std::cout << "Enter Time Criticality: ";
		int time_criticality = console::read_int();

		std::cout << "Enter Contagiousness: ";
		int contagiousness = console::read_int();

		
		try {
			Ailment tempAilment(ailmentName, severity, time_criticality, contagiousness);
			patient.add_ailment(tempAilment);
		}
		catch (std::invalid_argument& e) {
			errorMsg = e.what();
			isInvalid = true;
		}

	}
	
}