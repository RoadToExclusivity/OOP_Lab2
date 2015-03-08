#include "stdafx.h"
#include "Perform.h"

void Perform(vf &a)
{
	if (!a.size())
	{
		return;
	}
	auto res = minmax_element(a.begin(), a.end());
	float min = *res.first, max = *res.second;
	transform(a.begin(), a.end(), a.begin(), [min, max](float n) -> float
	{
		return (n < 0) ? n * min * max : n;
	});
}