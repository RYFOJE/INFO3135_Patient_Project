#include "Patient.h"

/* Patient Constructor */

Patient::Patient(std::string name) : name_(name), score_(0) {
	if (name_.empty())
	{
		throw std::invalid_argument("Name cannot be empty");
	}
}

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

const score_t Patient::get_score() const
{
	return score_;
}
