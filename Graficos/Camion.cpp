#include "stdafx.h"
#include "Camion.h"

Camion::Camion() {

	//Iniciar transformacion
	angulo = 0.0f;
	coordenadas = vec3(0.0f, 0.0f, 0.0f);

	//caja
	vertices.push_back({ vec4(-3.0f, 2.0f, 1.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(0.5f, 2.0f, 1.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(0.5f, -1.0f, 1.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(-3.0f, 2.0f, 1.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(0.5f, -1.0f, 1.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(-3.0f, -1.0f, 1.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });

	vertices.push_back({ vec4(-3.0f, 2.0f, -2.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(0.5f, 2.0f, -2.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(0.5f, -1.0f, -2.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(-3.0f, 2.0f, -2.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(0.5f, -1.0f, -2.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(-3.0f, -1.0f, -2.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });

	vertices.push_back({ vec4(-3.0f, 2.0f, 1.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(-3.0f, 2.0f, -2.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(0.5f, 2.0f, 1.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(-3.0f, 2.0f, -2.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(0.5f, 2.0f, -2.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(0.5f, 2.0f, 1.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });

	vertices.push_back({ vec4(-3.0f, -1.0f, 1.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(-3.0f, -1.0f, -2.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(0.5f, -1.0f, 1.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(-3.0f, -1.0f, -2.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(0.5f, -1.0f, -2.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(0.5f, -1.0f, 1.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });

	vertices.push_back({ vec4(-3.0f, 2.0f, 1.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(-3.0f, 2.0f, -2.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(-3.0f, -1.0f, -2.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(-3.0f, 2.0f, 1.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(-3.0f, -1.0f, 1.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(-3.0f, -1.0f, -2.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });

	vertices.push_back({ vec4(0.5f, 2.0f, 1.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(0.5f, 2.0f, -2.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(0.5f, -1.0f, -2.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(0.5f, 2.0f, 1.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(0.5f, -1.0f, 1.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(0.5f, -1.0f, -2.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });

	//cabina
	vertices.push_back({ vec4(0.5f, 1.0f, 0.5f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(2.0f, 1.0f, 0.5f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(2.0f, -1.0f, 0.5f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(0.5f, 1.0f, 0.5f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(2.0f, -1.0f, 0.5f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(0.5f, -1.0f, 0.5f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });

	vertices.push_back({ vec4(0.5f, 1.0f, -1.5f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(2.0f, 1.0f, -1.5f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(2.0f, -1.0f, -1.5f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(0.5f, 1.0f, -1.5f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(2.0f, -1.0f, -1.5f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(0.5f, -1.0f, -1.5f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });

	vertices.push_back({ vec4(0.5f, 1.0f, -1.5f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(2.0f, 1.0f, -1.5f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(2.0f, 1.0f, 0.5f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(0.5f, 1.0f, -1.5f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(2.0f, 1.0f, 0.5f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(0.5f, 1.0f, 0.5f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });

	vertices.push_back({ vec4(0.5f, -1.0f, -1.5f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(2.0f, -1.0f, -1.5f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(2.0f, -1.0f, 0.5f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(0.5f, -1.0f, -1.5f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(2.0f, -1.0f, 0.5f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(0.5f, -1.0f, 0.5f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });

	vertices.push_back({ vec4(2.0f, 1.0f, 0.5f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(2.0f, 1.0f, -1.5f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(2.0f, -1.0f, -1.5f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(2.0f, 1.0f, 0.5f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(2.0f, -1.0f, -1.5f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(2.0f, -1.0f, 0.5f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });

	vertices.push_back({ vec4(0.5f, 1.0f, 0.5f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(0.5f, 1.0f, -1.5f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(0.5f, -1.0f, -1.5f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(0.5f, 1.0f, 0.5f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(0.5f, -1.0f, -1.5f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(0.5f, -1.0f, 0.5f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });

	//Llantas

	//Mapa UV
}

void Camion::mover(double tiempoDelta) {
	switch (direccion) {
	case 0:
		coordenadas.x += velocidad * tiempoDelta;
		angulo = 90.0f;
		break;
	case 1:
		coordenadas.x -= velocidad * tiempoDelta;
		angulo = 270.0f;
		break;
	case 2:
		coordenadas.z += velocidad * tiempoDelta;
		angulo = 180.0f;
		break;
	case 3:
		coordenadas.z -= velocidad * tiempoDelta;
		angulo = 0.0f;
		break;
	default:
		break;
	}

	modelo = mat4(1.0f); //Matriz identidad
	modelo = translate(modelo, coordenadas);

}