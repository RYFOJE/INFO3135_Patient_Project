
#include <PriorityQueue.h>
#include <LinkedList.h>
#include <Ailment.h>
#include <Patient.h>


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
	MainProgram();

	// Private copy constructor and assignment operator to prevent copying
	MainProgram(const MainProgram&) = delete;
	MainProgram& operator=(const MainProgram&) = delete;


	// CONSOLE

	void get_main_menu_selection();

	void add_patient_menu();

	void add_ailment_menu(Patient& patient);

	void process_next_patient();

	void display_queue();

	void display_processed();

};