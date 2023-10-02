#include "Ailment.h"
#include <stdexcept>

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


/* Ailment Getters */

std::string Ailment::get_name() const
{
	return name_;
}

Ailment::score_t Ailment::get_severity() const
{
	return severity_;
}

Ailment::score_t Ailment::get_time_sensitivity() const
{
	return time_crit_;
}

Ailment::score_t Ailment::get_contagiousness() const
{
	return contagiousness_;
}

Ailment::score_t Ailment::get_score() const
{
	return (severity_ * time_crit_) + contagiousness_;
}