#include "singleton.hpp"
#include "console.hpp"


// HELPERS

Patient add_patient_from_string(std::string const &patient_str) {

	std::istringstream iss(patient_str);

	// TODO ADD ERROR HANDLING

	// Get patient name
	std::string name;
	getline(iss, name, ',');							/* Get with delimeter ',' */

	Patient tempPatient(name);							/* Create a new patient that will be populated from the string */

	unsigned ailmentCount;							
	iss >> ailmentCount;								/* Get the ailment count */

	std::string temp_str;								/* tmp string for removing delimeters */

	// Remove delimeter
	getline(iss, temp_str, ',');

	// Go through all ailments
	for (unsigned int i = 0; i < ailmentCount; i++) {

		std::string ailmentName;
		score_t severity, time_crit, contagiousness;

		getline(iss, ailmentName, ',');					/* Get the ailment name */

		iss >> severity;								/* Get the severity */
		getline(iss, temp_str, ',');					/* Remove the delimeter */

		iss >> time_crit;								/* Get the time_crit */
		getline(iss, temp_str, ',');					/* Remove the delimeter */

		iss >> contagiousness;							/* Get the contagiousness */
		getline(iss, temp_str, ',');					/* Remove the delimeter */

		// Create new ailment for patient and append it to the patients ailments
		tempPatient.add_ailment(Ailment(ailmentName, severity, time_crit, contagiousness));

	}

	return tempPatient;

}


// Singleton Method Implementation

MainProgram::MainProgram() {

	get_main_menu_selection();		/* Load main menu */

}

void MainProgram::get_main_menu_selection() {
	
	int selection;
	bool isInvalid = false;

	while (true) {								/* This is the main loop of the whole program */
		
		console::clear_screen();
		console::print_main_menu();

		if (isInvalid) {										/* If the previous input was invalid */
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

		case 5:
			MainProgram::load_queue_menu();
			break;

		case 6:
			MainProgram::save_queue_menu();
			break;

		case 0:										/* Exit program */
			return;
			
		default:									/* If the given value is invalid */
			
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
		std::getline(std::cin, patientName);				/* Get the patients name */

		if (patientName.empty()) return;					/* If an empty string was given */

		Patient tempPatient(patientName);

		if (is_duplicate_patient(tempPatient)) {			/* If the patient is a duplicate */
			console::clear_screen();
			console::wait_for_enter("This is a duplicate patient, please retry");
			continue;
		}
		
		add_ailment_menu(tempPatient);						/* Main Menu > Add Patient > Add Ailment */

		untreatedPatients_.enqueue(tempPatient);			/* Add the new user to the list of untreated patients */
	}
}

void MainProgram::add_ailment_menu(Patient& patient) {

	std::string errorMsg;
	bool isInvalid = false;

	while (true) {
		
		console::clear_screen();
		
		if (isInvalid) {									/* If the previous input was invalid */
			std::cout << errorMsg << std::endl;
			std::cout << "Please Try Again." << std::endl;
			isInvalid = false;
		}

		std::string ailmentName;

		std::cout << "Enter Ailment Name (leave blank to finish): ";
		getline(std::cin, ailmentName);
		
		if (ailmentName.empty()) return;					/* If an empty string was returned from the user */

		std::cout << "Enter Severity: ";
		int severity = console::read_int();					/* Get the severity */

		std::cout << "Enter Time Criticality: ";
		int time_criticality = console::read_int();			/* Get the time criticality */

		std::cout << "Enter Contagiousness: ";
		int contagiousness = console::read_int();			/* Get Contagiousness */

		
		try {												/* Use a try catch to see if the ailment is using all valid parameters */
			Ailment tempAilment(ailmentName, severity, time_criticality, contagiousness);
			patient.add_ailment(tempAilment);
		}
		catch (std::invalid_argument& e) {					/* If the ailment was invalid */
			errorMsg = e.what();
			isInvalid = true;
		}

	}
}

void MainProgram::process_next_patient() {
	
	console::clear_screen();

	if (untreatedPatients_.empty()) {						/* If there are no patients left to process */
		console::wait_for_enter("All patients have been processed");
		return;
	}

	//TODO Change this to use references instead
	Patient currPatient = untreatedPatients_.dequeue();		/* Get the next patient to be treated */
	treatedPatients_.push_front(currPatient);				/* Add the patient to your treated patient list*/

	std::cout << currPatient.get_name() << " moved to patient room!" << std::endl;

	// If that was the last patient left in the list exit
	if (untreatedPatients_.empty()) {						/* If there are no patients left to process */
		std::cout << "All patients have been processed" << std::endl;
	}

	else {

		// TODO Use reference
		Patient const nextPatient = untreatedPatients_.peek();	/* Peek at the next patient to be treated */

		std::cout << "Next in queue: " << nextPatient.get_name();
		std::cout << " with priority score " << nextPatient.get_score() << std::endl;
	}

	// Make the user press enter to go back to the main menu
	console::wait_for_enter();

}

void MainProgram::display_queue() {

	console::clear_screen();

	if (untreatedPatients_.empty()) {						/* If the patient queue is empty */
		console::wait_for_enter("Patient list is empty");
		return;
	}

	LinkedList<Patient>& currPatientList = untreatedPatients_.get_patient_list();	/* Get a list of all the untreated patient */

	for (int i = 0; i < currPatientList.size(); i++) {		/* Iterate through all untreated patients */

		// GET PATIENT AND PRINT NAME

		Patient currPatient = currPatientList.get_data_at_index(i);

		std::cout << i << " : " << currPatient.get_name() << " - ";
		std::cout << currPatient.get_score() << " - ";

		// PRINT PATIENTS AILMENTS
		LinkedList<Ailment>& currAilments = currPatient.get_ailments();		/* Get a reference to the linked list for the patients ailments */

		// TODO Use smart pointer and enhanced for loop maybe
		for (int i = 0; i < currAilments.size(); i++) {
			std::cout << currAilments.get_data_at_index(i).get_name();		/* Get the name of the ailment */

			// Add commas until last value
			if (i < currAilments.size() - 1) {								/* Add comma until last ailment */
				std::cout << ", ";
			}

		} // End ailment loop

		std::cout << std::endl;

	} // End Patient loop

	console::wait_for_enter();

}

void MainProgram::display_processed() {

	console::clear_screen();

	if (treatedPatients_.empty()) {											/* If no patients have been treated */
		console::wait_for_enter("No treated patients");
		return;
	}

	for (int i = 0; i < treatedPatients_.size(); i++) {						/* Iterate through all treated patients */

		// GET PATIENT AND PRINT INFO

		Patient currPatient = treatedPatients_.get_data_at_index(i);

		std::cout << currPatient.get_name() << " - ";
		std::cout << currPatient.get_score() << " - ";

		// PRINT AILMENTS
		LinkedList<Ailment> currAilments = currPatient.get_ailments();

		// TODO Use smart pointer and enhanced for loop maybe
		for (int i = 0; i < currAilments.size(); i++) {
			std::cout << currAilments.get_data_at_index(i).get_name();

			// Add commas until last value
			if (i < currAilments.size() - 1) {
				std::cout << ", ";
			}

		} // End ailment loop

		std::cout << std::endl;

	} // End Patient loop

	console::wait_for_enter();

}

void MainProgram::load_queue_menu() {

	console::clear_screen();

	try {

		std::cout << "Enter filepath: ";

		// Get valid file from user
		std::filesystem::path path = console::get_filepath();
		load_from_file(path);

	}
	catch (std::invalid_argument e) {

		console::wait_for_enter(e.what());
		console::clear_screen();

	}

}

void MainProgram::load_from_file(std::filesystem::path const &filePath) {

	std::ifstream file(filePath);


	if (!file.is_open()) {

		throw std::invalid_argument("File not opened");

	}

	// Hold string values
	std::string currLine;

	unsigned int duplicateCount = 0;								/* Holds how many duplicate values were not added */
	unsigned int addedCount = 0;									/* Holds how many total patients have been added */

	while (getline(file, currLine)) {								/* Iterate line by line in the file */

		Patient tempPatient = add_patient_from_string(currLine);	/* Get the current patient to verify and-or add */

		if (is_duplicate_patient(tempPatient)) {					/* Do not add duplicate patients */
			duplicateCount++;
			continue;
		}

		addedCount++;
		untreatedPatients_.enqueue(tempPatient);					/* Add patient to queue */

	}

	file.close();

	console::clear_screen();
	std::cout << addedCount << " patients added to the list." << std::endl;

	if (duplicateCount != 0) {										/* If there has been duplicate values print the count */
		std::cout << duplicateCount << " duplicate patients not added." << std::endl;
	}

	console::wait_for_enter();

}

void MainProgram::save_queue_menu() {
	
	console::clear_screen();

	try {

		std::cout << "Enter filepath: ";

		// Get valid file from user
		std::filesystem::path path = console::get_filepath(false);
		save_to_file(path);

	}
	catch (std::invalid_argument e) {

		console::wait_for_enter(e.what());
		console::clear_screen();

	}
	
}

void MainProgram::save_to_file(std::filesystem::path const& path) {

	std::ofstream ofs(path);
	
	LinkedList<Patient>& currPatientList = untreatedPatients_.get_patient_list();

	for (int i = 0; i < currPatientList.size(); i++) {
		
		Patient currPatient = currPatientList.get_data_at_index(i);

		ofs << currPatient.get_name() << ",";
		ofs << currPatient.get_ailments().size() << ",";

		// Get ailments list
		LinkedList<Ailment>& currAilments = currPatient.get_ailments();

		// TODO Use smart pointer and enhanced for loop maybe
		for (int i = 0; i < currAilments.size(); i++) {

			// Get the current ailment
			Ailment currAilment = currAilments.get_data_at_index(i);
			
			// Print out ailment and data associated to it
			ofs << currAilment.get_name() << ",";
			ofs << currAilment.get_severity() << ",";
			ofs << currAilment.get_time_sensitivity() << ",";
			ofs << currAilment.get_contagiousness();

			// Add commas until last value
			if (i < currAilments.size() - 1) {
				ofs << ", ";
			}

		} // End ailment loop

		ofs << std::endl;
		
	}

	ofs.close();

}

bool MainProgram::is_duplicate_patient(Patient const& patient)
{
	
	LinkedList<Patient>& currPatientList = untreatedPatients_.get_patient_list();	/* Get the list of untreated patients */

	for (int i = 0; i < currPatientList.size(); i++) {								/* Iterate through the list */

		Patient& currPatient = currPatientList.get_data_at_index(i);				/* Get the current patient to compare to */

		if (patient.get_name() == currPatient.get_name())							/* If they are duplicates */
			return true;

	}

	return false;
	
}