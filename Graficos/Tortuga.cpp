#include "stdafx.h"
#include "Tortuga.h"

Tortuga::Tortuga() {
	//Caparazon arriba
	vertices.push_back({ vec4(-1.0f, 2.0f,-1.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(1.0f, 2.0f, -1.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(1.0f, 1.8f, 1.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(-1.0f, 2.0f,-1.0f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(1.0f, 1.8f, 1.0f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(-1.0f, 1.8f, 1.0f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });

	vertices.push_back({ vec4(1.0f, 2.0f,-1.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(4.0f, 2.0f, -1.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(4.0f, 1.8f, 1.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(1.0f, 2.0f,-1.0f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(4.0f, 1.8f, 1.0f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(1.0f, 1.8f, 1.0f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });

	vertices.push_back({ vec4(-1.0f, 2.0f,-1.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(-4.0f, 2.0f, -1.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(-4.0f, 1.8f, 1.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(-1.0f, 2.0f,-1.0f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(-4.0f, 1.8f, 1.0f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(-1.0f, 1.8f, 1.0f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });

	vertices.push_back({ vec4(-1.0f, 2.0f, -1.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(1.0f, 2.0f, -1.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(1.0f, 1.8f, -3.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(-1.0f, 2.0f, -1.0f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(1.0f, 1.8f, -3.0f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(-1.0f, 1.8f, -3.0f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });

	vertices.push_back({ vec4(1.0f, 2.0f, -1.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(4.0f, 2.0f, -1.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(4.0f, 1.8f, -3.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(1.0f, 2.0f, -1.0f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(4.0f, 1.8f, -3.0f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(1.0f, 1.8f, -3.0f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });

	vertices.push_back({ vec4(-1.0f, 2.0f, -1.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(-4.0f, 2.0f, -1.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(-4.0f, 1.8f, -3.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(-1.0f, 2.0f, -1.0f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(-4.0f, 1.8f, -3.0f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(-1.0f, 1.8f, -3.0f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });

	vertices.push_back({ vec4(-1.0f, 1.0f, 2.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(1.0f, 1.0f, 2.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(1.0f, 1.8f, 1.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(-1.0f, 1.0f, 2.0f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(1.0f, 1.8f, 1.0f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(-1.0f, 1.8f, 1.0f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });

	vertices.push_back({ vec4(1.0f, 1.0f, 2.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(4.0f, 1.0f, 2.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(4.0f, 1.8f, 1.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(1.0f, 1.0f, 2.0f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(4.0f, 1.8f, 1.0f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(1.0f, 1.8f, 1.0f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });

	vertices.push_back({ vec4(-1.0f, 1.0f, 2.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(-4.0f, 1.0f, 2.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(-4.0f, 1.8f, 1.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(-1.0f, 1.0f, 2.0f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(-4.0f, 1.8f, 1.0f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(-1.0f, 1.8f, 1.0f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });

	vertices.push_back({ vec4(-1.0f, 1.0f, -4.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(1.0f, 1.0f, -4.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(1.0f, 1.8f, -3.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(-1.0f, 1.0f, -4.0f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(1.0f, 1.8f, -3.0f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(-1.0f, 1.8f, -3.0f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });

	vertices.push_back({ vec4(1.0f, 1.0f, -4.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(4.0f, 1.0f, -4.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(4.0f, 1.8f, -3.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(1.0f, 1.0f, -4.0f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(4.0f, 1.8f, -3.0f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(1.0f, 1.8f, -3.0f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });

	vertices.push_back({ vec4(-1.0f, 1.0f, -4.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(-4.0f, 1.0f, -4.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(-4.0f, 1.8f, -3.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(-1.0f, 1.0f, -4.0f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(-4.0f, 1.8f, -3.0f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(-1.0f, 1.8f, -3.0f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });

	//Caparazon abajo
	vertices.push_back({ vec4(-1.0f, 0.0f,-1.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(1.0f, 0.0f, -1.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(1.0f, 0.3f, 1.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(-1.0f, 0.0f,-1.0f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(1.0f, 0.3f, 1.0f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(-1.0f, 0.3f, 1.0f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });

	vertices.push_back({ vec4(1.0f, 0.0f,-1.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(4.0f, 0.0f, -1.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(4.0f, 0.3f, 1.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(1.0f, 0.0f,-1.0f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(4.0f, 0.3f, 1.0f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(1.0f, 0.3f, 1.0f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });

	vertices.push_back({ vec4(-1.0f, 0.0f,-1.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(-4.0f, 0.0f, -1.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(-4.0f, 0.3f, 1.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(-1.0f, 0.0f,-1.0f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(-4.0f, 0.3f, 1.0f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(-1.0f, 0.3f, 1.0f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });

	vertices.push_back({ vec4(-1.0f, 0.0f, -1.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(1.0f, 0.0f, -1.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(1.0f, 0.3f, -3.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(-1.0f, 0.0f, -1.0f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(1.0f, 0.3f, -3.0f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(-1.0f, 0.3f, -3.0f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });

	vertices.push_back({ vec4(1.0f, 0.0f, -1.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(4.0f, 0.0f, -1.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(4.0f, 0.3f, -3.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(1.0f, 0.0f, -1.0f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(4.0f, 0.3f, -3.0f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(1.0f, 0.3f, -3.0f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });

	vertices.push_back({ vec4(-1.0f, 0.0f, -1.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(-4.0f, 0.0f, -1.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(-4.0f, 0.3f, -3.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(-1.0f, 0.0f, -1.0f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(-4.0f, 0.3f, -3.0f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(-1.0f, 0.3f, -3.0f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });

	vertices.push_back({ vec4(-1.0f, 1.0f, 2.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(1.0f, 1.0f, 2.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(1.0f, 0.3f, 1.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(-1.0f, 1.0f, 2.0f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(1.0f, 0.3f, 1.0f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(-1.0f, 0.3f, 1.0f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });

	vertices.push_back({ vec4(1.0f, 1.0f, 2.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(4.0f, 1.0f, 2.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(4.0f, 0.3f, 1.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(1.0f, 1.0f, 2.0f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(4.0f, 0.3f, 1.0f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(1.0f, 0.3f, 1.0f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });

	vertices.push_back({ vec4(-1.0f, 1.0f, 2.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(-4.0f, 1.0f, 2.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(-4.0f, 0.3f, 1.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(-1.0f, 1.0f, 2.0f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(-4.0f, 0.3f, 1.0f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(-1.0f, 0.3f, 1.0f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });

	vertices.push_back({ vec4(-1.0f, 1.0f, -4.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(1.0f, 1.0f, -4.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(1.0f, 0.3f, -3.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(-1.0f, 1.0f, -4.0f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(1.0f, 0.3f, -3.0f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(-1.0f, 0.3f, -3.0f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });

	vertices.push_back({ vec4(1.0f, 1.0f, -4.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(4.0f, 1.0f, -4.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(4.0f, 0.3f, -3.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(1.0f, 1.0f, -4.0f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(4.0f, 0.3f, -3.0f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(1.0f, 0.3f, -3.0f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });

	vertices.push_back({ vec4(-1.0f, 1.0f, -4.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(-4.0f, 1.0f, -4.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(-4.0f, 0.3f, -3.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(-1.0f, 1.0f, -4.0f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(-4.0f, 0.3f, -3.0f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(-1.0f, 0.3f, -3.0f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });

	//Cabeza
	vertices.push_back({ vec4(6.0f, 2.0f, -2.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(4.0f, 2.0f, -2.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(4.0f, 2.0f, 0.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	vertices.push_back({ vec4(6.0f, 2.0f, -2.0f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(4.0f, 2.0f, 0.0f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(6.0f, 2.0f, 0.0f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
}