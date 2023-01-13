#pragma once

class NumberWeight
{
public:
	double Number;
	double Weight;

public:
	NumberWeight();
	NumberWeight(double _number, double _weight);
	NumberWeight(const NumberWeight& _src);
	
	friend bool operator<(const NumberWeight& left, const NumberWeight& right) { return left.Weight < right.Weight; } //used by std::sort.  (smallest to largest)
	friend bool operator>(const NumberWeight& left, const NumberWeight& right) { return left.Weight > right.Weight; } //if you use sort and want reverse rose from larget to smallest weight

};
