#include <algorithm>
#include <random>
#include "WeightedRandom.h"


//Support struct for reverse sorting
struct greater
{
	template<class T>
	bool operator()(T const& left, T const& right) const { return left > right; }
};

WeightedRandom::WeightedRandom()
{

}

void WeightedRandom::Initialize(std::vector<NumberWeight>& _weightList)
{
	maxValue = 0.0;
	clear();

	clear();

	std::vector<NumberWeight>::const_iterator sourceIt = _weightList.begin();

	while (sourceIt != _weightList.end()) //remove any garbage values
	{
		if (sourceIt->Weight > 0.0)
		{
			push_back(*sourceIt);
		}
		sourceIt++;
	}

	std::sort(begin(), end(), greater()); //Put weights in reverse order.
	minValue = at(size() - 1).Weight;

	normalize(0, maxValue);
}

void WeightedRandom::normalize(int _index, double& _previousValue)
{
	//turns weights into ranges.  
	//The cool thing about this is this:
	// A reverse sorted list is already a super heapified complete tree.  So treat it like a heap.
	// Once we normalize it with a rnage (Weight += _previous value) it will turn into a binary tree again with root = 0
	// The numbers with the greatest chance of being hit will appear at the top of the binary tree if we treat it as a binary heap array!

	//Alternatively we could resort the list when done to do a standard binary search on a sorted list.  BUT we have to keep track of root and properly subdivide to ensure we are traversing the probability tree in the same order we set it up!  That's a lot of root = floor(log2(range)) calls which is inefficient
	long leftChildIndex = -1;

	if (getLeftChildIndex(_index, leftChildIndex))
	{
		normalize(leftChildIndex, _previousValue);
		at(_index).Weight += _previousValue;

		long rightChildIndex = -1;

		if (getRightChildIndex(_index, rightChildIndex))
		{
			normalize(rightChildIndex, _previousValue);
		}
	}
}

double WeightedRandom::GetWeightedRandom()
{
	if (size() < 1)
	{
		//should throw assert but...
		return -1.0;
	}
	//Standard random is not so random (it's pseudo random) especially when relying on clock ticks and threaded ops

	std::mt19937 gen(m_dev());
	std::uniform_real_distribution<> dist(minValue, maxValue); 

	double rangeTarget = dist(gen);

	return heapBinarySearch(rangeTarget, 0);
}

double WeightedRandom::heapBinarySearch(double rangeTarget, int _index)
{
	long leftChildIndex = -1;
	if (!getLeftChildIndex(_index, leftChildIndex))
	{
		//this has to be value because there will be no right child also in a complete binary tree
		return at(_index).Number;
	}
	else
	{
		if (rangeTarget > at(_index).Weight)
		{
			long rightChildIndex = -1;

			if (getRightChildIndex(_index, rightChildIndex))
			{
				return heapBinarySearch(rangeTarget, rightChildIndex);
			}
			else //technically this should NEVER happen
			{
				return at(_index).Number;
			}
		}
		else
		{
			if (rangeTarget > at(leftChildIndex).Weight && rangeTarget <= at(_index).Weight)
			{
				return at(_index).Number;
			}
			else
			{
				return heapBinarySearch(rangeTarget, leftChildIndex);
			}
		}
	}
}