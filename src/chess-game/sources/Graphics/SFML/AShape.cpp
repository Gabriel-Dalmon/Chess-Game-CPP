#include "pch.h"

void sfmlw::AShape::Release()
{
	if (m_shape != nullptr) {
		delete m_shape;
	}
}
