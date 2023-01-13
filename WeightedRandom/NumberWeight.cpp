#include "NumberWeight.h"

NumberWeight::NumberWeight()
{
	Number = 0.0;
	Weight = 0.0;
}

NumberWeight::NumberWeight(double _number, double _weight)
{
	Number = _number;
	Weight = _weight;
}

NumberWeight::NumberWeight(const NumberWeight& _src)
{
	Number = _src.Number;
	Weight = _src.Weight;
}
