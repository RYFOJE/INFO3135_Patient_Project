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

		case 2:
			MainProgram::process_next_patient();
			break;

		case 3:
			MainProgram::display_queue();
			break;

		case 4:
			MainProgram::display_processed();
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

		untreatedPatients_.enqueue(tempPatient);
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

void MainProgram::process_next_patient() {
	
	console::clear_screen();

	// If there are no patient to process return empty
	if (untreatedPatients_.empty()) {
		console::wait_for_enter("All patients have been processed");
		return;
	}


	// TODO Keep track of treated patients

	Patient currPatient = untreatedPatients_.dequeue();
	treatedPatients_.push_front(currPatient);

	std::cout << currPatient.get_name() << " moved to patient room!" << std::endl;

	// If that was the last patient left in the list exit
	if (untreatedPatients_.empty()) {
		std::cout << "All patients have been processed" << std::endl;
	}

	else {

		Patient const nextPatient = untreatedPatients_.peek();

		std::cout << "Next in queue: " << nextPatient.get_name();
		std::cout << " with priority score " << nextPatient.get_score() << std::endl;
	}

	// Make the user press enter to go back to the main menu
	console::wait_for_enter();

}

void MainProgram::display_queue() {

	console::clear_screen();

	// If the list is empty
	if (untreatedPatients_.empty()) {
		console::wait_for_enter("Patient list is empty");
		return;
	}


	// Get a list of all the untreated patient
	LinkedList<Patient>& currPatientList = untreatedPatients_.get_patient_list();

	for (int i = 0; i < currPatientList.size(); i++) {

		// GET PATIENT AND PRINT INFO

		Patient currPatient = currPatientList.get_value_at_index(i);

		std::cout << i << " : " << currPatient.get_name() << " - ";
		std::cout << currPatient.get_score() << " - ";

		// PRINT AILMENTS
		LinkedList<Ailment> currAilments = currPatient.get_ailments();

		// TODO Use smart pointer and enhanced for loop maybe
		for (int i = 0; i < currAilments.size(); i++) {
			std::cout << currAilments.get_value_at_index(i).get_name();

			// Add commas until last calue
			if (i < currAilments.size() - 1) {
				std::cout << ", ";
			}

		} // End ailment loop

		std::cout << std::endl;

	} // End Patient loop

	console::wait_for_enter();

}

void MainProgram::display_processed() {

	console::clear_screen();

	// If the list is empty
	if (treatedPatients_.empty()) {
		console::wait_for_enter("No treated patients");
		return;
	}

	for (int i = 0; i < treatedPatients_.size(); i++) {

		// GET PATIENT AND PRINT INFO

		Patient currPatient = treatedPatients_.get_value_at_index(i);

		std::cout << currPatient.get_name() << " - ";
		std::cout << currPatient.get_score() << " - ";

		// PRINT AILMENTS
		LinkedList<Ailment> currAilments = currPatient.get_ailments();

		// TODO Use smart pointer and enhanced for loop maybe
		for (int i = 0; i < currAilments.size(); i++) {
			std::cout << currAilments.get_value_at_index(i).get_name();

			// Add commas until last value
			if (i < currAilments.size() - 1) {
				std::cout << ", ";
			}

		} // End ailment loop

		std::cout << std::endl;

	} // End Patient loop

	console::wait_for_enter();

}