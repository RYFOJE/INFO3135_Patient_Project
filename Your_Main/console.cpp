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

	int read_int() {

			std::string str;
			std::getline(std::cin, str);

			try {
				return std::stoi(str);
			}
			catch (std::invalid_argument&) {
				return -1;
			}
			


	}

	void wait_for_enter(std::string const message) {

		if (!message.empty()) {
			std::cout << message << std::endl;
		}

		std::cout << "Press Enter to Return...";

		std::string temp = "";
		getline(std::cin, temp);
		console::clear_screen();
		return;

	}

	std::filesystem::path get_filepath() {

		namespace fs = std::filesystem;

		std::string str_fp;

		// Get the file path
		getline(std::cin, str_fp);

		fs::path path(str_fp);

		// If the file exists and can be opened
		if (fs::exists(path) && fs::is_regular_file(path)) {
			return path;
		}

		// If the file is not found
		throw std::invalid_argument("File does not exist.");

	}

}
