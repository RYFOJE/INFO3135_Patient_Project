#pragma once

#include <string>


/** TYPEDEFS **/
typedef short score_t; // Not using an unsigned so we can verify integrity of input


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
	Ailment(std::string name = "", score_t severity = 1, score_t time_sensitivity = 1, score_t contagiousness = 1);
	
	// Getters
	const std::string get_name() const;
	const score_t get_severity() const;
	const score_t get_time_sensitivity() const;
	const score_t get_contagiousness() const;
	const score_t get_score() const;

};

/** OPERATORS **/

/** 
* @brief			Compares two Ailments based on their total severity
* @param lhs		The left hand side of the comparison
* @param rhs		The right hand side of the comparison
* @return			The comparison result
*/
auto operator <=> (Ailment const& lhs, Ailment const& rhs) { return calculate_total_severity(lhs) <=> calculate_total_severity(rhs); }