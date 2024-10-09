#pragma once

class Sprite : public Shape {
public:
	Sprite();
	~Sprite();

	int Initialize();
	void Release();
};