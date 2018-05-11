#include "stdafx.h"
#include "Camion.h"

Camion::Camion() {
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