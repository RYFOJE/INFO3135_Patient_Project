#pragma once

#include <PriorityQueue.h>
#include <LinkedList.h>
#include <Ailment.h>
#include <Patient.h>

#include <filesystem>
#include <fstream>
#include <sstream>

/**
 * @brief	The MainProgram class will hold the data for the whole program and all 
 *			the methods to run the program.
*/
class MainProgram {
	
public:
	
	// Get the instance of the MainProgram
	static MainProgram& getInstance() {
		static MainProgram instance;
		return instance;
	}

private:

	// Variables
	PriorityQueue<Patient> untreatedPatients_;
	LinkedList<Patient> treatedPatients_;

	// Constructor
	MainProgram();	/* Entry point for the whole program */

	// CONSOLE

	/**
	 * @brief Displays the main menu and wait for input
	 * 
	 *	Main Menu
	 * 
	*/
	void get_main_menu_selection();

	/**
	 * @brief Displays the add patient menu and wait for input
	 * 
	 *	Main Ment > Add Patient
	 * 
	*/
	void add_patient_menu();

	/**
	 * @brief Displays the add ailment menu and wait for input this will be called from the add patient menu
	 * 
	 *	Main Menu > Add Patient > Add Ailment
	 * 
	*/
	void add_ailment_menu(Patient& patient);

	/**
	 * @brief Displays the process next patient menu and wait for input
	 *
	 *	Main Menu > Process Next Patient
	 *
	*/
	void process_next_patient();

	/**
	 * @brief Displays the display queue menu and wait for input
	 *
	 *	Main Menu > Display Queue
	 *
	*/
	void display_queue();

	/**
	 * @brief Displays the display processed menu and wait for input
	 *
	 *	Main Menu > Display Processed
	 *
	*/
	void display_processed();

	/**
	 * @brief Displays the load queue menu and wait for input
	 *
	 *	Main Menu > Load Queue
	 *
	*/
	void load_queue_menu();
	
	/**
	 * @brief Helper function that loads all patients from a file
	*/
	void load_from_file(std::filesystem::path const &path);


	/**
	 * @brief Displays the save queue menu and wait for input
	 * 
	 * Main Menu > Save Queue
	*/
	void save_queue_menu();

	/**
	 * @brief			Helper function that saves all patients to a file
	 * @param path		The path to the file to save to
	*/
	void save_to_file(std::filesystem::path const& path);

	/**
	 * @brief			Helper function that check to see if a patient is a duplicate
	 * @param patient	The patient to check
	 * @return			True if duplicate, false if otherwise
	*/
	bool is_duplicate_patient(Patient const& patient);
	

	// Private copy constructor and assignment operator to prevent copying therefore making it a singleton
	MainProgram(const MainProgram&) = delete;
	MainProgram& operator=(const MainProgram&) = delete;

};