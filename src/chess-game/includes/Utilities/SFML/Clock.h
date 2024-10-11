#pragma once

//------------------------------------------------------------------------------
namespace sfmlw {

//------------------------------------------------------------------------------
class Clock {
public:
	Clock();
	~Clock();

	int Initialize();
	void Release();

	//--------------------------------------------------------------------------
	/* Getters/Setters */
	/* Returns the elapsed time in Milliseconds. */
	inline int GetElapsedTime() const { 
		return m_clock.getElapsedTime().asMilliseconds(); };
	inline void Reset() { m_clock.restart(); };

//------------------------------------------------------------------------------
private:
	sf::Clock m_clock;
};

}