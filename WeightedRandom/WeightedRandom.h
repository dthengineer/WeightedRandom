#pragma once
#include <vector>
#include <random>
#include "NumberWeight.h"


class WeightedRandom : private std::vector<NumberWeight>
{

//METHODS*****************************************************
public:
	void Initialize(std::vector<NumberWeight>& _weightList);

	double GetWeightedRandom();

private:
	void normalize(int _index, double& _previousValue);

	/// <summary>
	/// returns left child index number in tree IF left child exist.  Otherwise -1
	/// </summary>
	/// <param name="_parentIndex">The index of the parent</param>
	/// <param name="_leftChildIndex">Out: the left child index</param>
	/// <returns>true if left child exists</returns>
	inline bool getLeftChildIndex(long _parentIndex, long& _leftChildIndex)
	{
		_leftChildIndex = (2 * _parentIndex) + 1;
		_leftChildIndex = (_leftChildIndex > size() - 1) ? -1 : _leftChildIndex;
		return _leftChildIndex >= 0;
	}

	/// <summary>
	/// returns right child index number in tree IF right child exist.  Otherwise -1
	/// </summary>
	/// <param name="_parentIndex">The index of the parent</param>
	/// <param name="_rightChildIndex">Out: the right child index</param>
	/// <returns>true if right child exists</returns>
	inline bool getRightChildIndex(long _parentIndex, long& _rightChildIndex)
	{
		_rightChildIndex = (2 * _parentIndex) + 2;
		_rightChildIndex = (_rightChildIndex > size() - 1) ? -1 : _rightChildIndex;
		return _rightChildIndex >= 0;
	}

	/// <summary>
	/// Returns index of parent to this node.  If root, returns -1/false
	/// </summary>
	/// <param name="_childIndex">Index of child</param>
	/// <param name="_parentIndex">Out: the Parent.  If not found -1</param>
	/// <returns>true if parent found.  If false, you are at root or empty list</returns>
	inline bool getParentIndex(long _childIndex, long& _parentIndex) {
		_parentIndex = (_childIndex > 0) ? ((_childIndex - 1) / 2) : -1;
		return _childIndex >= 0;
	}

	double heapBinarySearch(double _target, int _index);

//ATTRIBUTES**************************************************
private:
	//max range value if we add all the weights together
	double maxValue = 0.0;
	double minValue = 0.0;

	static std::random_device m_dev;

};
