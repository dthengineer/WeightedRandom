#include "SuperHeapTree.h"
#include <algorithm>

struct greater
{
	template<class T>
	bool operator()(T const& left, T const& right) const { return left > right; }
};

SuperHeapTree::SuperHeapTree(const std::vector<NumberWeight>& _weights)
{
	superHeapify(_weights);
}


/// <summary>
/// the number list to super heapify.  Put the heaviest weight nodes at top of tree to reduce binary search time
/// </summary>
/// <param name="_weightList">The list of weights that are ordered</param>
void SuperHeapTree::superHeapify(std::vector<NumberWeight>& _weightList)
{
	clear();

	std::vector<NumberWeight>::const_iterator sourceIt = _weights.begin();

	while (sourceIt != _weights.end()) //remove any garbage values
	{
		if (sourceIt->Weight > 0.0)
		{
			push_back(*sourceIt);
		}
		sourceIt++;
	}

	std::sort(begin(), end(), greater()); //Put weights in reverse order.


	long leftChildIndex = -1;
	long rightChildIndex = -1;

	bool leftPopulated = getLeftChildIndex(_index, leftChildIndex);
	bool rightPopulated = getRightChildIndex(_index, rightChildIndex);
	long greatestIndex = -1;


}

