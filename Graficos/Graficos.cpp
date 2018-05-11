// Graficos.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#define GLEW_STATIC
#include "GL\glew.h"
#include "GLFW\glfw3.h"
#include "glm\gtx\transform.hpp"
#include "glm\glm.hpp"

#include <iostream>
#include <time.h>

#include "Vertice.h"
#include "Shader.h"
#include "Modelo.h"
#include "nave.h"

using namespace std;

GLfloat red, green, blue;

GLuint posicionID;
GLuint colorID;
GLuint modeloID;
GLuint vistaID;
GLuint proyeccionID;

float camaraX = 0.0f;
float camaraY = 5.0f;
float camaraZ = 10.0f;

vec3 posicionCamara;

mat4 vista;
mat4 proyeccion;

Modelo *camion;
Modelo *cuadrado;
Modelo *tortuga;

Shader *shader;
//Declaraci�n de ventana
GLFWwindow *window;

//Propiedades de la ventana
GLfloat ancho = 1024;
GLfloat alto = 768;

void actualizar() {
	int estadoderecha = glfwGetKey(window, GLFW_KEY_RIGHT);
	if (estadoderecha == GLFW_PRESS) {
		camaraX += 0.1f;
		}
	
	int estadoizq = glfwGetKey(window, GLFW_KEY_LEFT);
	if (estadoizq == GLFW_PRESS) {
		camaraX -= 0.1f;
	}

	int estadoArriba = glfwGetKey(window, GLFW_KEY_UP);
	if (estadoArriba == GLFW_PRESS) {
		camaraY += 0.1f;
	}

	int estadoAbajo = glfwGetKey(window, GLFW_KEY_DOWN);
	if (estadoAbajo == GLFW_PRESS) {
		camaraY -= 0.1f;
	}

	int estadoQ = glfwGetKey(window, GLFW_KEY_Q);
	if (estadoQ == GLFW_PRESS) {
		camaraZ += 0.1f;
	}

	int estadoE = glfwGetKey(window, GLFW_KEY_E);
	if (estadoE == GLFW_PRESS) {
		camaraZ -= 0.1f;
	}

	posicionCamara = vec3(camaraX, camaraY, camaraZ);

	vista = lookAt(posicionCamara, //Posicion de la camara
		vec3(0.0f, 0.0f, 0.0f),		//Posicion del objetivo
		vec3(0.0f, 1.0f, 0.0f));

	//camion->vista = vista;
	//cuadrado->vista = vista;
	tortuga->vista = vista;
};

void dibujar() {
	//cuadrado->dibujar(GL_TRIANGLES);
	//camion->dibujar(GL_TRIANGLES);
	tortuga->dibujar(GL_TRIANGLES);
}

void inicializarTortuga() {
	tortuga = new Modelo();
	srand(time(NULL));

	//Caparazon arriba
	tortuga->vertices.push_back({ vec4(-1.0f, 2.0f,-1.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	tortuga->vertices.push_back({ vec4(1.0f, 2.0f, -1.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	tortuga->vertices.push_back({ vec4(1.0f, 1.8f, 1.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	tortuga->vertices.push_back({ vec4(-1.0f, 2.0f,-1.0f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	tortuga->vertices.push_back({ vec4(1.0f, 1.8f, 1.0f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	tortuga->vertices.push_back({ vec4(-1.0f, 1.8f, 1.0f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });

	tortuga->vertices.push_back({ vec4(1.0f, 2.0f,-1.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	tortuga->vertices.push_back({ vec4(4.0f, 2.0f, -1.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	tortuga->vertices.push_back({ vec4(4.0f, 1.8f, 1.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	tortuga->vertices.push_back({ vec4(1.0f, 2.0f,-1.0f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	tortuga->vertices.push_back({ vec4(4.0f, 1.8f, 1.0f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	tortuga->vertices.push_back({ vec4(1.0f, 1.8f, 1.0f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });

	tortuga->vertices.push_back({ vec4(-1.0f, 2.0f,-1.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	tortuga->vertices.push_back({ vec4(-4.0f, 2.0f, -1.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	tortuga->vertices.push_back({ vec4(-4.0f, 1.8f, 1.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	tortuga->vertices.push_back({ vec4(-1.0f, 2.0f,-1.0f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	tortuga->vertices.push_back({ vec4(-4.0f, 1.8f, 1.0f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	tortuga->vertices.push_back({ vec4(-1.0f, 1.8f, 1.0f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });

	tortuga->vertices.push_back({ vec4(-1.0f, 2.0f, -1.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	tortuga->vertices.push_back({ vec4(1.0f, 2.0f, -1.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	tortuga->vertices.push_back({ vec4(1.0f, 1.8f, -3.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	tortuga->vertices.push_back({ vec4(-1.0f, 2.0f, -1.0f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	tortuga->vertices.push_back({ vec4(1.0f, 1.8f, -3.0f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	tortuga->vertices.push_back({ vec4(-1.0f, 1.8f, -3.0f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });

	tortuga->vertices.push_back({ vec4(1.0f, 2.0f, -1.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	tortuga->vertices.push_back({ vec4(4.0f, 2.0f, -1.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	tortuga->vertices.push_back({ vec4(4.0f, 1.8f, -3.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	tortuga->vertices.push_back({ vec4(1.0f, 2.0f, -1.0f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	tortuga->vertices.push_back({ vec4(4.0f, 1.8f, -3.0f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	tortuga->vertices.push_back({ vec4(1.0f, 1.8f, -3.0f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });

	tortuga->vertices.push_back({ vec4(-1.0f, 2.0f, -1.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	tortuga->vertices.push_back({ vec4(-4.0f, 2.0f, -1.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	tortuga->vertices.push_back({ vec4(-4.0f, 1.8f, -3.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	tortuga->vertices.push_back({ vec4(-1.0f, 2.0f, -1.0f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	tortuga->vertices.push_back({ vec4(-4.0f, 1.8f, -3.0f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	tortuga->vertices.push_back({ vec4(-1.0f, 1.8f, -3.0f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });

	tortuga->vertices.push_back({ vec4(-1.0f, 1.0f, 2.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	tortuga->vertices.push_back({ vec4(1.0f, 1.0f, 2.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	tortuga->vertices.push_back({ vec4(1.0f, 1.8f, 1.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	tortuga->vertices.push_back({ vec4(-1.0f, 1.0f, 2.0f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	tortuga->vertices.push_back({ vec4(1.0f, 1.8f, 1.0f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	tortuga->vertices.push_back({ vec4(-1.0f, 1.8f, 1.0f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });

	tortuga->vertices.push_back({ vec4(1.0f, 1.0f, 2.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	tortuga->vertices.push_back({ vec4(4.0f, 1.0f, 2.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	tortuga->vertices.push_back({ vec4(4.0f, 1.8f, 1.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	tortuga->vertices.push_back({ vec4(1.0f, 1.0f, 2.0f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	tortuga->vertices.push_back({ vec4(4.0f, 1.8f, 1.0f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	tortuga->vertices.push_back({ vec4(1.0f, 1.8f, 1.0f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });

	tortuga->vertices.push_back({ vec4(-1.0f, 1.0f, 2.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	tortuga->vertices.push_back({ vec4(-4.0f, 1.0f, 2.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	tortuga->vertices.push_back({ vec4(-4.0f, 1.8f, 1.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	tortuga->vertices.push_back({ vec4(-1.0f, 1.0f, 2.0f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	tortuga->vertices.push_back({ vec4(-4.0f, 1.8f, 1.0f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	tortuga->vertices.push_back({ vec4(-1.0f, 1.8f, 1.0f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });

	tortuga->vertices.push_back({ vec4(-1.0f, 1.0f, -4.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	tortuga->vertices.push_back({ vec4(1.0f, 1.0f, -4.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	tortuga->vertices.push_back({ vec4(1.0f, 1.8f, -3.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	tortuga->vertices.push_back({ vec4(-1.0f, 1.0f, -4.0f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	tortuga->vertices.push_back({ vec4(1.0f, 1.8f, -3.0f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	tortuga->vertices.push_back({ vec4(-1.0f, 1.8f, -3.0f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });

	tortuga->vertices.push_back({ vec4(1.0f, 1.0f, -4.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	tortuga->vertices.push_back({ vec4(4.0f, 1.0f, -4.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	tortuga->vertices.push_back({ vec4(4.0f, 1.8f, -3.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	tortuga->vertices.push_back({ vec4(1.0f, 1.0f, -4.0f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	tortuga->vertices.push_back({ vec4(4.0f, 1.8f, -3.0f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	tortuga->vertices.push_back({ vec4(1.0f, 1.8f, -3.0f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });

	tortuga->vertices.push_back({ vec4(-1.0f, 1.0f, -4.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	tortuga->vertices.push_back({ vec4(-4.0f, 1.0f, -4.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	tortuga->vertices.push_back({ vec4(-4.0f, 1.8f, -3.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	tortuga->vertices.push_back({ vec4(-1.0f, 1.0f, -4.0f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	tortuga->vertices.push_back({ vec4(-4.0f, 1.8f, -3.0f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	tortuga->vertices.push_back({ vec4(-1.0f, 1.8f, -3.0f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });

	//Caparazon abajo
	tortuga->vertices.push_back({ vec4(-1.0f, 0.0f,-1.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	tortuga->vertices.push_back({ vec4(1.0f, 0.0f, -1.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	tortuga->vertices.push_back({ vec4(1.0f, 0.3f, 1.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	tortuga->vertices.push_back({ vec4(-1.0f, 0.0f,-1.0f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	tortuga->vertices.push_back({ vec4(1.0f, 0.3f, 1.0f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	tortuga->vertices.push_back({ vec4(-1.0f, 0.3f, 1.0f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });

	tortuga->vertices.push_back({ vec4(1.0f, 0.0f,-1.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	tortuga->vertices.push_back({ vec4(4.0f, 0.0f, -1.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	tortuga->vertices.push_back({ vec4(4.0f, 0.3f, 1.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	tortuga->vertices.push_back({ vec4(1.0f, 0.0f,-1.0f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	tortuga->vertices.push_back({ vec4(4.0f, 0.3f, 1.0f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	tortuga->vertices.push_back({ vec4(1.0f, 0.3f, 1.0f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });

	tortuga->vertices.push_back({ vec4(-1.0f, 0.0f,-1.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	tortuga->vertices.push_back({ vec4(-4.0f, 0.0f, -1.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	tortuga->vertices.push_back({ vec4(-4.0f, 0.3f, 1.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	tortuga->vertices.push_back({ vec4(-1.0f, 0.0f,-1.0f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	tortuga->vertices.push_back({ vec4(-4.0f, 0.3f, 1.0f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	tortuga->vertices.push_back({ vec4(-1.0f, 0.3f, 1.0f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });

	tortuga->vertices.push_back({ vec4(-1.0f, 0.0f, -1.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	tortuga->vertices.push_back({ vec4(1.0f, 0.0f, -1.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	tortuga->vertices.push_back({ vec4(1.0f, 0.3f, -3.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	tortuga->vertices.push_back({ vec4(-1.0f, 0.0f, -1.0f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	tortuga->vertices.push_back({ vec4(1.0f, 0.3f, -3.0f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	tortuga->vertices.push_back({ vec4(-1.0f, 0.3f, -3.0f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });

	tortuga->vertices.push_back({ vec4(1.0f, 0.0f, -1.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	tortuga->vertices.push_back({ vec4(4.0f, 0.0f, -1.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	tortuga->vertices.push_back({ vec4(4.0f, 0.3f, -3.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	tortuga->vertices.push_back({ vec4(1.0f, 0.0f, -1.0f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	tortuga->vertices.push_back({ vec4(4.0f, 0.3f, -3.0f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	tortuga->vertices.push_back({ vec4(1.0f, 0.3f, -3.0f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });

	tortuga->vertices.push_back({ vec4(-1.0f, 0.0f, -1.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	tortuga->vertices.push_back({ vec4(-4.0f, 0.0f, -1.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	tortuga->vertices.push_back({ vec4(-4.0f, 0.3f, -3.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	tortuga->vertices.push_back({ vec4(-1.0f, 0.0f, -1.0f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	tortuga->vertices.push_back({ vec4(-4.0f, 0.3f, -3.0f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	tortuga->vertices.push_back({ vec4(-1.0f, 0.3f, -3.0f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });

	tortuga->vertices.push_back({ vec4(-1.0f, 1.0f, 2.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	tortuga->vertices.push_back({ vec4(1.0f, 1.0f, 2.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	tortuga->vertices.push_back({ vec4(1.0f, 0.3f, 1.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	tortuga->vertices.push_back({ vec4(-1.0f, 1.0f, 2.0f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	tortuga->vertices.push_back({ vec4(1.0f, 0.3f, 1.0f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	tortuga->vertices.push_back({ vec4(-1.0f, 0.3f, 1.0f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });

	tortuga->vertices.push_back({ vec4(1.0f, 1.0f, 2.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	tortuga->vertices.push_back({ vec4(4.0f, 1.0f, 2.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	tortuga->vertices.push_back({ vec4(4.0f, 0.3f, 1.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	tortuga->vertices.push_back({ vec4(1.0f, 1.0f, 2.0f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	tortuga->vertices.push_back({ vec4(4.0f, 0.3f, 1.0f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	tortuga->vertices.push_back({ vec4(1.0f, 0.3f, 1.0f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });

	tortuga->vertices.push_back({ vec4(-1.0f, 1.0f, 2.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	tortuga->vertices.push_back({ vec4(-4.0f, 1.0f, 2.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	tortuga->vertices.push_back({ vec4(-4.0f, 0.3f, 1.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	tortuga->vertices.push_back({ vec4(-1.0f, 1.0f, 2.0f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	tortuga->vertices.push_back({ vec4(-4.0f, 0.3f, 1.0f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	tortuga->vertices.push_back({ vec4(-1.0f, 0.3f, 1.0f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });

	tortuga->vertices.push_back({ vec4(-1.0f, 1.0f, -4.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	tortuga->vertices.push_back({ vec4(1.0f, 1.0f, -4.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	tortuga->vertices.push_back({ vec4(1.0f, 0.3f, -3.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	tortuga->vertices.push_back({ vec4(-1.0f, 1.0f, -4.0f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	tortuga->vertices.push_back({ vec4(1.0f, 0.3f, -3.0f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	tortuga->vertices.push_back({ vec4(-1.0f, 0.3f, -3.0f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });

	tortuga->vertices.push_back({ vec4(1.0f, 1.0f, -4.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	tortuga->vertices.push_back({ vec4(4.0f, 1.0f, -4.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	tortuga->vertices.push_back({ vec4(4.0f, 0.3f, -3.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	tortuga->vertices.push_back({ vec4(1.0f, 1.0f, -4.0f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	tortuga->vertices.push_back({ vec4(4.0f, 0.3f, -3.0f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	tortuga->vertices.push_back({ vec4(1.0f, 0.3f, -3.0f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });

	tortuga->vertices.push_back({ vec4(-1.0f, 1.0f, -4.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	tortuga->vertices.push_back({ vec4(-4.0f, 1.0f, -4.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	tortuga->vertices.push_back({ vec4(-4.0f, 0.3f, -3.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	tortuga->vertices.push_back({ vec4(-1.0f, 1.0f, -4.0f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	tortuga->vertices.push_back({ vec4(-4.0f, 0.3f, -3.0f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	tortuga->vertices.push_back({ vec4(-1.0f, 0.3f, -3.0f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });

	//Cabeza
	tortuga->vertices.push_back({ vec4(6.0f, 2.0f, -2.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	tortuga->vertices.push_back({ vec4(4.0f, 2.0f, -2.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	tortuga->vertices.push_back({ vec4(4.0f, 2.0f, 0.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	tortuga->vertices.push_back({ vec4(6.0f, 2.0f, -2.0f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	tortuga->vertices.push_back({ vec4(4.0f, 2.0f, 0.0f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	tortuga->vertices.push_back({ vec4(6.0f, 2.0f, 0.0f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });

	tortuga->vista = vista;
	tortuga->proyeccion = proyeccion;
}

void inicializarCuadrado() {
	cuadrado = new Modelo();
	srand(time(NULL));

	cuadrado->vertices.push_back({ vec4(-1.0f, 1.0f, 1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	cuadrado->vertices.push_back({ vec4(-1.0f, -1.0f, 1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	cuadrado->vertices.push_back({ vec4(1.0f, -1.0f, 1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	cuadrado->vertices.push_back({ vec4(1.0f, 1.0f, 1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	cuadrado->vertices.push_back({ vec4(-1.0f, 1.0f, 1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	cuadrado->vertices.push_back({ vec4(1.0f, -1.0f, 1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	cuadrado->vertices.push_back({ vec4(1.0f, 1.0f, -1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	cuadrado->vertices.push_back({ vec4(1.0f, -1.0f, -1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	cuadrado->vertices.push_back({ vec4(-1.0f, -1.0f, -1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	cuadrado->vertices.push_back({ vec4(1.0f, 1.0f, -1.0f, 1.0f),vec4((float(float(rand() % 101))) / 100,(float(float(rand() % 101))) / 100,(float(float(rand() % 101))) / 100,1.0f) });
	cuadrado->vertices.push_back({ vec4(-1.0f, -1.0f, -1.0f, 1.0f),vec4((float(float(rand() % 101))) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	cuadrado->vertices.push_back({ vec4(-1.0f, 1.0f, -1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	cuadrado->vertices.push_back({ vec4(1.0f, 1.0f, 1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	cuadrado->vertices.push_back({ vec4(1.0f, -1.0f, -1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	cuadrado->vertices.push_back({ vec4(1.0f, 1.0f, -1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	cuadrado->vertices.push_back({ vec4(1.0f, -1.0f, -1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	cuadrado->vertices.push_back({ vec4(1.0f, 1.0f, 1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	cuadrado->vertices.push_back({ vec4(1.0f, -1.0f, 1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	cuadrado->vertices.push_back({ vec4(1.0f, 1.0f, 1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	cuadrado->vertices.push_back({ vec4(1.0f, 1.0f, -1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	cuadrado->vertices.push_back({ vec4(-1.0f, 1.0f, -1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	cuadrado->vertices.push_back({ vec4(1.0f, 1.0f, 1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	cuadrado->vertices.push_back({ vec4(-1.0f, 1.0f, -1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	cuadrado->vertices.push_back({ vec4(-1.0f, 1.0f, 1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	cuadrado->vertices.push_back({ vec4(-1.0f, -1.0f, -1.0f, 1.0f),vec4(float(rand() % 101) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	cuadrado->vertices.push_back({ vec4(-1.0f, -1.0f, 1.0f, 1.0f),vec4((float(float(rand() % 101))) / 100,(float(float(rand() % 101))) / 100,(float(float(rand() % 101))) / 100,1.0f) });
	cuadrado->vertices.push_back({ vec4(-1.0f, 1.0f, 1.0f, 1.0f),vec4((float(float(rand() % 101))) / 100,(float(float(rand() % 101))) / 100,(float(float(rand() % 101))) / 100,1.0f) });
	cuadrado->vertices.push_back({ vec4(-1.0f, -1.0f, -1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	cuadrado->vertices.push_back({ vec4(-1.0f, 1.0f, 1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	cuadrado->vertices.push_back({ vec4(-1.0f, 1.0f, -1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	cuadrado->vertices.push_back({ vec4(1.0f, -1.0f, 1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	cuadrado->vertices.push_back({ vec4(-1.0f, -1.0f, -1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	cuadrado->vertices.push_back({ vec4(1.0f, -1.0f, -1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	cuadrado->vertices.push_back({ vec4(1.0f, -1.0f, 1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	cuadrado->vertices.push_back({ vec4(-1.0f, -1.0f, 1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	cuadrado->vertices.push_back({ vec4(-1.0f, -1.0f, -1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	cuadrado->vista = vista;
	cuadrado->proyeccion = proyeccion;
}

void inicializarCamion() {
	camion = new Modelo();
	srand(time(NULL));

	//caja
	camion->vertices.push_back({ vec4(-3.0f, 2.0f, 1.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	camion->vertices.push_back({ vec4(0.5f, 2.0f, 1.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	camion->vertices.push_back({ vec4(0.5f, -1.0f, 1.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	camion->vertices.push_back({ vec4(-3.0f, 2.0f, 1.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	camion->vertices.push_back({ vec4(0.5f, -1.0f, 1.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	camion->vertices.push_back({ vec4(-3.0f, -1.0f, 1.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });

	camion->vertices.push_back({ vec4(-3.0f, 2.0f, -2.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	camion->vertices.push_back({ vec4(0.5f, 2.0f, -2.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	camion->vertices.push_back({ vec4(0.5f, -1.0f, -2.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	camion->vertices.push_back({ vec4(-3.0f, 2.0f, -2.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	camion->vertices.push_back({ vec4(0.5f, -1.0f, -2.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	camion->vertices.push_back({ vec4(-3.0f, -1.0f, -2.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });

	camion->vertices.push_back({ vec4(-3.0f, 2.0f, 1.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	camion->vertices.push_back({ vec4(-3.0f, 2.0f, -2.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	camion->vertices.push_back({ vec4(0.5f, 2.0f, 1.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	camion->vertices.push_back({ vec4(-3.0f, 2.0f, -2.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	camion->vertices.push_back({ vec4(0.5f, 2.0f, -2.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	camion->vertices.push_back({ vec4(0.5f, 2.0f, 1.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });

	camion->vertices.push_back({ vec4(-3.0f, -1.0f, 1.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	camion->vertices.push_back({ vec4(-3.0f, -1.0f, -2.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	camion->vertices.push_back({ vec4(0.5f, -1.0f, 1.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	camion->vertices.push_back({ vec4(-3.0f, -1.0f, -2.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	camion->vertices.push_back({ vec4(0.5f, -1.0f, -2.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	camion->vertices.push_back({ vec4(0.5f, -1.0f, 1.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });

	camion->vertices.push_back({ vec4(-3.0f, 2.0f, 1.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	camion->vertices.push_back({ vec4(-3.0f, 2.0f, -2.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	camion->vertices.push_back({ vec4(-3.0f, -1.0f, -2.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	camion->vertices.push_back({ vec4(-3.0f, 2.0f, 1.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	camion->vertices.push_back({ vec4(-3.0f, -1.0f, 1.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	camion->vertices.push_back({ vec4(-3.0f, -1.0f, -2.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });

	camion->vertices.push_back({ vec4(0.5f, 2.0f, 1.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	camion->vertices.push_back({ vec4(0.5f, 2.0f, -2.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	camion->vertices.push_back({ vec4(0.5f, -1.0f, -2.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	camion->vertices.push_back({ vec4(0.5f, 2.0f, 1.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	camion->vertices.push_back({ vec4(0.5f, -1.0f, 1.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });
	camion->vertices.push_back({ vec4(0.5f, -1.0f, -2.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 1.0f) });

	//cabina
	camion->vertices.push_back({ vec4(0.5f, 1.0f, 0.5f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	camion->vertices.push_back({ vec4(2.0f, 1.0f, 0.5f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	camion->vertices.push_back({ vec4(2.0f, -1.0f, 0.5f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	camion->vertices.push_back({ vec4(0.5f, 1.0f, 0.5f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	camion->vertices.push_back({ vec4(2.0f, -1.0f, 0.5f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	camion->vertices.push_back({ vec4(0.5f, -1.0f, 0.5f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });

	camion->vertices.push_back({ vec4(0.5f, 1.0f, -1.5f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	camion->vertices.push_back({ vec4(2.0f, 1.0f, -1.5f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	camion->vertices.push_back({ vec4(2.0f, -1.0f, -1.5f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	camion->vertices.push_back({ vec4(0.5f, 1.0f, -1.5f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	camion->vertices.push_back({ vec4(2.0f, -1.0f, -1.5f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	camion->vertices.push_back({ vec4(0.5f, -1.0f, -1.5f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });

	camion->vertices.push_back({ vec4(0.5f, 1.0f, -1.5f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	camion->vertices.push_back({ vec4(2.0f, 1.0f, -1.5f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	camion->vertices.push_back({ vec4(2.0f, 1.0f, 0.5f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	camion->vertices.push_back({ vec4(0.5f, 1.0f, -1.5f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	camion->vertices.push_back({ vec4(2.0f, 1.0f, 0.5f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	camion->vertices.push_back({ vec4(0.5f, 1.0f, 0.5f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });

	camion->vertices.push_back({ vec4(0.5f, -1.0f, -1.5f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	camion->vertices.push_back({ vec4(2.0f, -1.0f, -1.5f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	camion->vertices.push_back({ vec4(2.0f, -1.0f, 0.5f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	camion->vertices.push_back({ vec4(0.5f, -1.0f, -1.5f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	camion->vertices.push_back({ vec4(2.0f, -1.0f, 0.5f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	camion->vertices.push_back({ vec4(0.5f, -1.0f, 0.5f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });

	camion->vertices.push_back({ vec4(2.0f, 1.0f, 0.5f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	camion->vertices.push_back({ vec4(2.0f, 1.0f, -1.5f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	camion->vertices.push_back({ vec4(2.0f, -1.0f, -1.5f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	camion->vertices.push_back({ vec4(2.0f, 1.0f, 0.5f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	camion->vertices.push_back({ vec4(2.0f, -1.0f, -1.5f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	camion->vertices.push_back({ vec4(2.0f, -1.0f, 0.5f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });

	camion->vertices.push_back({ vec4(0.5f, 1.0f, 0.5f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	camion->vertices.push_back({ vec4(0.5f, 1.0f, -1.5f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	camion->vertices.push_back({ vec4(0.5f, -1.0f, -1.5f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	camion->vertices.push_back({ vec4(0.5f, 1.0f, 0.5f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	camion->vertices.push_back({ vec4(0.5f, -1.0f, -1.5f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	camion->vertices.push_back({ vec4(0.5f, -1.0f, 0.5f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });

	//Llantas

	camion->vista = vista;
	camion->proyeccion = proyeccion;
}

void inicializarvista() {
	vista = lookAt(posicionCamara, //Posicion de la camara
		vec3(0.0f, 0.0f, 0.0f),		//Posicion del objetivo
		vec3(0.0f, 1.0f, 0.0f));	//Vector hacia arriba (rotacion camara)
}

void inicializarproyeccion() {
	proyeccion = perspective(45.0f, //Campo de vision (FoV)
		ancho / alto,				//Realcion de aspecto (Apect ratio) 
		0.1f,						//Near clipping (Desde donde renderea)
		150.0f);					//Far clipping (Hasta donde renderea)
}

int main()
{
	//Inicializaci�n de GLFW
	if (!glfwInit()) {
		//Si no se inici� bien, terminar la ejecuci�n
		exit(EXIT_FAILURE);
	}

	//Inicializar la ventana
	window = glfwCreateWindow(ancho, alto, "Graficos", NULL, NULL);
	//Verficar si se cre� bien la ventana
	if (!window) {
		//Cerrar todos los procesos de GLFW
		glfwTerminate();
		//Termina ejecuci�n
		exit(EXIT_FAILURE);
	}

	//Establecer "window" como contexto
	glfwMakeContextCurrent(window);

	//Se trae las funciones de OpenGL Moderno
	glewExperimental = true;
	//Inicializar GLEW
	GLenum glewError = glewInit();
	//Verificar que GLEW se inicializ� bien
	if (glewError != GLEW_OK) {
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	const GLubyte *version = glGetString(GL_VERSION);
	cout << "Version de OpenGL: " << version << endl;

	red = green = blue = 0.5f;

	posicionCamara = vec3(camaraX, camaraY, camaraZ);

	inicializarvista();
	inicializarproyeccion();

	//inicializarCuadrado();
	//inicializarCamion();
	inicializarTortuga();

	//crear instancia del shader
	const char * rutaVertex = "vShaderSimple.shader";
	const char * rutaFragment = "fShaderSimple.shader";

	shader = new  Shader(rutaVertex, rutaFragment);

	//Mapeo de atributos 
	posicionID = glGetAttribLocation(shader->getID(), "posicion");
	colorID = glGetAttribLocation(shader->getID(), "color");
	modeloID = glGetUniformLocation (shader->getID(), "modelo");
	vistaID = glGetUniformLocation(shader->getID(), "vista");
	proyeccionID = glGetUniformLocation(shader->getID(), "proyeccion");

	//Desenlazar el shader
	shader->desenlazarShader();

	//cuadrado->shader = shader;
	//cuadrado->inicializarVertexArray(posicionID, colorID,modeloID,vistaID,proyeccionID);

	//camion->shader = shader;
	//camion->inicializarVertexArray(posicionID, colorID, modeloID, vistaID, proyeccionID);

	tortuga->shader = shader;
	tortuga->inicializarVertexArray(posicionID, colorID, modeloID, vistaID, proyeccionID);

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	//Ciclo de dibujo
	while (!glfwWindowShouldClose(window)) {
		//Establecer el area de render (viewport)
		glViewport(0, 0, ancho, alto);
		//Establecer el color con el que se limpia la pantalla
		glClearColor(red, green, blue, 1);
		//Limpiar la pantalla
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		//rutina de dibujo
		actualizar();
		dibujar();

		//Intercambio de buffers
		glfwSwapBuffers(window);
		//Buscar se�ales de entrada
		glfwPollEvents();
	}

	glfwDestroyWindow(window);
	glfwTerminate();

	return 0;
}
