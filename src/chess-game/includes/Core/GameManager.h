#pragma once

class Helper {
public:
	static inline int GetSquareIndex(int position[2], int width) { return position[0] + position[1] * width; };
};