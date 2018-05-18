#pragma once
#include "Modelo.h"
#include "glm\gtx\transform.hpp"
#include "glm\glm.hpp"

class Camion : public Modelo {
public:

	vec3 coordenadas;
	float angulo;
	int direccion = 0;
	float velocidad = 3;
	Camion();
	void mover(double tiempoDelta);

};