
#include <iostream>
#include <sstream>size_
#include <string>

#include "console.hpp"

namespace console
{

	void print_main_menu() {

		using namespace std;

		cout << "****************************************************" << endl;
		cout << "* Welcome to Fanshawe College Medical Center F2023 *" << endl;
		cout << "*                  Ryan  Jennings                  *" << endl;
		cout << "****************************************************" << endl;
		cout << endl; // using two cout just to visualize spacing
		cout << endl;
		cout << "Please Make A Selection" << endl;
		cout << endl;
		cout << "\t1 - Add Patient" << endl;
		cout << "\t2 - Process Next Patient In Queue" << endl;
		cout << "\t3 - Display Queue" << endl;
		cout << "\t4 - View Processed Patients History" << endl;
		cout << "\t5 - Load Queue" << endl;
		cout << "\t6 - Save Queue" << endl;
		cout << "\t0 - Exit" << endl;
	}

	void add_patient_menu() {
		using namespace std;
		
	}

	void add_patient_ailment() {
		
		std::string ailmentName;
		int contagiousness;
		int time_criticality;
		int severity;

		// Read ailments until empty
		while (std::getline(std::cin, ailmentName)) {
			
			if (ailmentName.empty()) return;

		}

	}

	void clear_screen() {
		// Clear the screen
		std::cout << "\033[2J\033[1;1H";// TODO FIX THIS
	}

}
