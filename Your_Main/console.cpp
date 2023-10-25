
#include <iostream>
#include <sstream>
#include <string>

#include "console.hpp"

namespace console
{

	void print_main_menu() {

		using namespace std;

		cout << "****************************************************" << endl;
		cout << "* Welcome to Fanshawe College Medical Center F2023 *" << endl;
		cout << "                   Ryan  Jennings                   " << endl;
		cout << "****************************************************" << endl;
		cout << endl; // using two cout just to visualize spacing
		cout << endl;
		cout << "Please Make A Selection" << endl;
		cout << endl;
		cout << "\t\t1 - Add Patient" << endl;
		cout << "\t\t2 - Process Next Patient In Queue" << endl;
		cout << "\t\t3 - Display Queue" << endl;
		cout << "\t\t4 - View Processed Patients History" << endl;
		cout << "\t\t5 - Load Queue" << endl;
		cout << "\t\t6 - Save Queue" << endl;
		cout << "\t\t0 - Exit" << endl;
	}

}
