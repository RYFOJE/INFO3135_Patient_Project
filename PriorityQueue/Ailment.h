#pragma once

#include <string>

class Ailment
{
public:
	typedef unsigned short score_t;

private:

	std::string name;

	score_t severity_;
	score_t time_crit;
	score_t contagiousness;
	score_t calculated_score;
	inline void calculate_score();

public:
	Ailment();

	// Getters
	std::string get_name();
	score_t get_severity();
	score_t get_time_sensitivity();
	score_t get_contagiousness();
	score_t get_score();
};
