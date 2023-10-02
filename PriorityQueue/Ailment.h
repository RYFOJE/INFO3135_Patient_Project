#pragma once

#include <string>

class Ailment
{
public:
	typedef short score_t; // Not using an unsigned so we can verify integrity of input

private:

	std::string name_;

	score_t severity_;
	score_t time_crit_;
	score_t contagiousness_;

public:
	Ailment(std::string name, score_t severity, score_t time_sensitivity, score_t contagiousness);
	Ailment() : severity_(0), time_crit_(0), contagiousness_(0) , name_(""){} // TODO See if there is a better way of applying this code as it is double assigning with default constructor

	// Getters
	const std::string get_name() const;
	const score_t get_severity() const;
	const score_t get_time_sensitivity() const;
	const score_t get_contagiousness() const;
	const score_t get_score() const;


	// Operators

	auto operator==(const Ailment& other) const
	{
		return (name_ == other.name_);
	}

};
