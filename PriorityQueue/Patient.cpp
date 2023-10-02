#include "Patient.h"

/* Patient Constructor */

/// <summary>
/// Creates a patient with a name
/// </summary>
/// <param name="name">The name of the patient</param>
Patient::Patient(std::string name) : name_(name), score_(0) {
	if (name_.empty())
	{
		throw std::invalid_argument("Name cannot be empty");
	}
}


/// <summary>
/// Adds an ailment to the patient and calculates the patient's new risk score
/// </summary>
/// <param name="ailment">The ailment to add</param>
void Patient::add_ailment(Ailment ailment)
{
	score_ += ailment.get_score();
	ailments_.push_back(ailment);
}



/* Patient Getters */

const std::string Patient::get_name() const{
	return name_;
}

LinkedList<Ailment> Patient::get_ailments()
{
	return ailments_;
}
