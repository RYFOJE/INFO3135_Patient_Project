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
	Ailment() : severity_(0), time_crit_(0), contagiousness_(0) , name_(""){}

	// Getters
	std::string get_name() const;
	score_t get_severity() const;
	score_t get_time_sensitivity() const;
	score_t get_contagiousness() const;
	score_t get_score() const;
};
