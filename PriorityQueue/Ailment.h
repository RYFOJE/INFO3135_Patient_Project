﻿#pragma once

#include <string>


/** TYPEDEFS **/
typedef long score_t; // Not using an unsigned so we can verify integrity of input


/** CLASSES **/

/**
 * @brief The Ailment Class will hold 1 specific ailment and hold important information about it
*/
class Ailment
{
	std::string name_;

	score_t severity_;
	score_t time_crit_;
	score_t contagiousness_;

public:
	/**
	 * @brief					Constructor for the Ailment class
	 * @param name				The name of the ailment
	 * @param severity			The severity of the ailment
	 * @param time_sensitivity	The time sensitivity of the ailment
	 * @param contagiousness	The contagiousness of the ailment
	*/
	Ailment(std::string name, score_t severity, score_t time_sensitivity, score_t contagiousness);

	// GETTERS
	const std::string get_name() const { return name_; }
	const score_t get_severity() const { return severity_; }
	const score_t get_time_sensitivity() const { return time_crit_; }
	const score_t get_contagiousness() const { return contagiousness_; }
	const score_t get_score() const;

	bool operator== (const Ailment& other) const {
		return this->get_score() == other.get_score();
	}

	/**
	* @brief			Compares two Ailments based on their total severity
	* @param lhs		The left hand side of the comparison
	* @param rhs		The right hand side of the comparison
	* @return			The comparison result
	*/
	auto operator<=> (const Ailment& other) const {
		return this->get_score() <=> other.get_score();
	}

};

/** OPERATIONS **/


/**
 * @brief					Calculates the total severity of an ailment
 * @param severity			The severity of the ailment
 * @param time_criticality	The time criticality of the ailment
 * @param contagiousness	The contagiousness of the ailment
 * @return					The total severity of the ailment
*/
score_t calculate_total_severity(score_t severity, score_t time_criticality, score_t contagiousness);


/**
 * @brief					Calculates the total severity of an ailment
 * @param ailment			The ailment to calculate the severity of
 * @return					The total severity of the ailment
*/
score_t calculate_total_severity(const Ailment& ailment);