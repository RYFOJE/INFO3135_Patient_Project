#include "Ailment.h"
#include <stdexcept>


/** Functions **/

score_t calculate_total_severity(score_t severity, score_t time_criticality, score_t contagiousness)
{
	return (severity * time_criticality) + contagiousness;
}

score_t calculate_total_severity(const Ailment& ailment)
{
	return calculate_total_severity(ailment.get_severity(), ailment.get_time_sensitivity(), ailment.get_contagiousness());
}


/* Ailment Constructors */

Ailment::Ailment(std::string name, score_t severity, score_t time_sensitivity, score_t contagiousness):
	name_(name),
	severity_(severity),
	time_crit_(time_sensitivity),
	contagiousness_(contagiousness)
{

	if (severity_ < 0) {
		throw std::invalid_argument("Severity must be larger than 0");
	}

	else if (time_crit_ < 0) {
		throw std::invalid_argument("Time sensitivity must be larger than 0");
	}

	else if (contagiousness_ < 0) {
		throw std::invalid_argument("Contagiousness must be larger than 0");
	}
	
	else if (name_.empty()) {
		throw std::invalid_argument("Ailment name cannot be empty");
	}

}

const score_t Ailment::get_score() const {
	return calculate_total_severity(*this);
}